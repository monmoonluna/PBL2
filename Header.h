
#include <iostream>
#include <Windows.h>

#include <conio.h>
#include <string>
#include <strsafe.h>
#include <chrono>
#include <fstream>

using namespace std;

// Nối 2 chuỗi
inline wstring conCat(wstring s1, wstring s2)
{
	return s1 + L'_' + s2 + L".txt";
}

//Làm ẩn con trỏ chuột
inline void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

//Ghi lỗi và thoát ra ( dùng trong bắt sự kiện chuột)
inline VOID WriteError(LPSTR lpszMessage) {
	printf("%s\n", lpszMessage);
	ExitProcess(0);
}

//Di chuyển con trỏ chuột đến tọa độ (x, y)
inline void gotoxy(short x, short y)
{
	// Khởi tạo handle của cửa sổ console.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD   Cursor_an_Pos = { x, y };
	SetConsoleCursorPosition(hConsole, Cursor_an_Pos);
}

// Viết kí tự tại vị trí có tọa độ (x, y)
inline void wirteChar(int x, int y, const wchar_t* z) {
	gotoxy(x, y);
	wcout << z;
}

// Viết chuỗi có màu sắc tại vị trí có tọa độ (x, y)
inline void writeString(int x, int y, const wchar_t* s)
{
	gotoxy(x, y);
	wcout << s;
}

// Vẽ khung có màu và kích thước m*n tại vị trí có tọa độ (x, y)
inline void menuBar(int x, int y, int m, int n)
{
	int i, j;
	//textcolor(color);
	for (i = x; i <= x + m; i++)
		for (j = y; j <= y + n; j++)
		{
			if (i == x || i == x + m)
			{
				if (j == y && i != x + m)
					wirteChar(i, j, L"┌");

				else if (j == y && i != x)
					wirteChar(i, j, L"┐");
				else if (j == y + n && i != x + m)
					wirteChar(i, j, L"└");
				else if (j == y + n && i != x)
					wirteChar(i, j, L"┘");
				else wirteChar(i, j, L"│");
			}
			else if (j == y || j == y + n)
				wirteChar(i, j, L"─");
		}
}

// Vẽ bảng tại vị trí có tọa độ (x, y)
inline void menuTable(int x, int y, int m, int n)
{
	int i, j;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x70);
	for (i = x; i <= x + m; i++)
		for (j = y; j <= y + n; j++)
		{
			if (i == x || i == x + m)
			{
				if (j == y && i != x + m)
					wirteChar(i, j, L"╔");

				else if (j == y && i != x)
					wirteChar(i, j, L"╗");
				else if (j == y + n && i != x + m)
					wirteChar(i, j, L"╚");
				else if (j == y + n && i != x)
					wirteChar(i, j, L"╝");
				else wirteChar(i, j, L"║");
			}
			else if (j == y || j == y + n)
				wirteChar(i, j, L"═");
		}
}
// Bảng hiện sinh viên tại tọa độ (x, y)
inline void menuDisplaySt(int x, int y, int sl, int number = 1, int sum = 1) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j;
	int c = 164;
	//textcolor(2);
	SetConsoleTextAttribute(consoleHandle, 0x70);
	for (i = x; i <= x + c; i++)
		for (j = y; j <= y + sl; j++)
		{
			if (i == x || i == x + 5 || i == x + 35 || i == x + 55 || i == x + 65 || i == x + 74 || i == x + 90 || i == x + 99 || i == x + 105 || i == x + 115 || i == x + 125 || i == x + 135 || i == x + 144 || i == x + 155 || i == x + c)
			{
				if (j == y && i != x && i != x + c)
					wirteChar(i, j, L"┬");
				else if (j == y && i != x + c)
					wirteChar(i, j, L"┌");
				else if (j == y && i != x)
					wirteChar(i, j, L"┐");
				else if (j == y + 2 && i != x && i != x + c)
					wirteChar(i, j, L"┼");
				else if (j == y + 2 && i != x + c)
					wirteChar(i, j, L"├");
				else if (j == y + 2 && i != x)
					wirteChar(i, j, L"┤");
				else if (j == y + sl && i != x && i != x + c)
					wirteChar(i, j, L"┴");
				else if (j == y + sl && i != x + c)
					wirteChar(i, j, L"└");
				else if (j == y + sl && i != x)
					wirteChar(i, j, L"┘");
				else wirteChar(i, j, L"│");
			}
			else if (j == y || j == y + 2 || j == y + sl)
				wirteChar(i, j, L"─");
		}
	// TODO: insert return statement here
	SetConsoleTextAttribute(consoleHandle, 0x71);
	writeString(x + 2, y + 1, L"Mã");
	writeString(x + 16, y + 1, L"Họ và tên");
	writeString(x + 42, y + 1, L"Quê quán");
	writeString(x + 56, y + 1, L"Giới tính");
	writeString(x + 66, y + 1, L"Năm sinh");
	writeString(x + 78, y + 1, L"Chuyên môn");
	writeString(x + 91, y + 1, L"Trình độ");
	writeString(x + 101, y + 1, L"HSL");
	writeString(x + 107, y + 1, L"Phụ cấp");
	writeString(x + 117, y + 1, L"Ăn trưa");
	writeString(x + 126, y + 1, L"Thực lĩnh");
	writeString(x + 136, y + 1, L"Vào nghề");
	writeString(x + 145, y + 1, L"Tăng lương");
	writeString(x + 156, y + 1, L"Xếp loại");

	SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(x, y - 1, L"------------------------");
	writeString(x + 110, y - 1, L"Nhấn ESC để quay trở lại menu sinh viên");
	writeString(x + 3, y + 24, L"Nhấn nút [->] để tới trang tiếp theo, [<-] để quay về trang trước!!");
	writeString(x + 135, y - 2, L"Trang: ");
	wcout << number << L"/" << sum;
}
// Tô màu tại vị trí (x1, y1) đến (x2, y2)
inline void fillColorConsole(int x1, int y1, int x2, int y2) {
	// Lấy handle của cửa sổ console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Xác định màu nền là xám
	int attributes = 0x70;

	// Vòng lặp lặp qua tất cả các điểm trong vùng được chỉ định.
	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {
			// Tô màu console tại tọa độ (x, y).
			SetConsoleTextAttribute(consoleHandle, attributes);
			WriteConsole(consoleHandle, " ", 1, NULL, NULL);
		}
		gotoxy(x1, y);
	}
}

//sự kiện chuột
inline int setClick(int& a, int& b) {
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode)) {
		WriteError(const_cast<LPSTR>("SetConsoleMode"));
		return 1;
	}

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode)) {
		WriteError(const_cast<LPSTR>("SetConsoleMode"));
		return 1;
	}
	int tam = 0;
	while (tam == 0) {
		if (!ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead)) {
			WriteError(const_cast<LPSTR>("ReadConsoleInput"));
			return 1;
		}

		for (i = 0; i < cNumRead; i++) {
			if (irInBuf[i].EventType == MOUSE_EVENT) {
				if (irInBuf[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
					int x = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
					int y = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
					a = x;
					b = y;
					tam = 1;
					break;
				}
			}
		}
	}
}

//sự kiện bàn phím
inline int setKeyBoard() {
	while (true) {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			return 2; //lên
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			return 1; //xuống
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			return 3; //TRÁI
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			return 4; //PHẢI
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			return 5; //ESC
		}
	}
	return 0;
}



// in thông tin console 1
inline void information(int x, int y) {
	// Lấy handle của cửa sổ console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Thiết lập màu văn bản và nền
	SetConsoleTextAttribute(consoleHandle, 0x70);
	writeString(x + 16, y, L"TRƯỜNG ĐẠI HỌC BÁCH KHOA - ĐHĐN");
	fillColorConsole(x + 17, y, 84, y);
	gotoxy(54, y);
	fillColorConsole(54, y, x + 15, y);

	writeString(x + 14, y + 1, L"ĐỀ TÀI: CHƯƠNG TRÌNH QUẢN LÝ CÁN BỘ");
	fillColorConsole(x + 15, y + 1, 80, y + 1);
	gotoxy(54, y + 1);
	fillColorConsole(54, y + 1, x + 13, y + 1);

	gotoxy(54, y + 2);
	fillColorConsole(54, y + 2, 53 + 61, y + 2);

	//SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(x + 10, y + 3, L"Sinh viên:");
	fillColorConsole(x + 15, y + 3, 109, y + 3);
	gotoxy(54, y + 3);
	fillColorConsole(54, y + 3, x + 9, y + 3);

	//SetConsoleTextAttribute(consoleHandle, 0x71);
	writeString(x + 10, y + 4, L"Huỳnh Thúy Minh Nguyệt");
	fillColorConsole(x + 15, y + 4, 97, y + 4);
	gotoxy(54, y + 4);
	fillColorConsole(54, y + 4, x + 9, y + 12);

	writeString(x + 10, y + 5, L"102220159");
	fillColorConsole(x + 15, y + 5, 110, y + 5);
	//SetConsoleTextAttribute(consoleHandle, 0x74);
	gotoxy(54, y + 6);
	fillColorConsole(54, y + 6, 53 + 61, y + 6);

	writeString(x + 10, y + 7, L"Sinh viên:");
	fillColorConsole(x + 15, y + 7, 109, y + 7);
	//SetConsoleTextAttribute(consoleHandle, 0x71);
	writeString(x + 10, y + 8, L"Đào Lê Hạnh Nguyên");
	fillColorConsole(x + 15, y + 8, 101, y + 8);

	writeString(x + 10, y + 9, L"102220242");
	fillColorConsole(x + 15, y + 9, 110, y + 9);

	gotoxy(54, y + 10);
	fillColorConsole(54, y + 10, 53 + 61, y + 10);

	writeString(x + 10, y + 11, L"Giảng viên hướng dẫn:  ThS Nguyễn Văn Nguyên");
	fillColorConsole(x, y + 12, 60, y + 12);
	gotoxy(0, y + 14);
}

// in thông tin console 2
inline void Select_input_method(int x, int y) {
	// Lấy handle của cửa sổ console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Thiết lập màu văn bản và nền
	SetConsoleTextAttribute(consoleHandle, 0x71);
	writeString(x + 6, y, L"1> TẠO VÀ NHẬP MỘT DANH SÁCH CÁN BỘ MỚI TỪ BÀN PHÍM");
	writeString(x + 6, y + 3, L"2> XỬ LÝ THÔNG TIN DANH SÁCH CÁN BỘ CÓ SẴN");
}

// in thông tin console 3
inline void select_Data_File(int x, int y) {
	// Lấy handle của cửa sổ console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Thiết lập màu văn bản và nền
	SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(x + 11, y, L"CƠ QUAN CẦN XỬ LÝ THÔNG TIN CÁN BỘ");
	SetConsoleTextAttribute(consoleHandle, 0x71);
	writeString(x + 11, y + 2, L"1> ĐẠI HỌC BÁCH KHOA");
	writeString(x + 11, y + 4, L"2> ĐẠI HỌC KINH TẾ");
	writeString(x + 11, y + 6, L"3> KHÁC");
}

// in menu
inline void menu() {
	// Lấy handle của cửa sổ console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Thiết lập màu văn bản và nền
	SetConsoleTextAttribute(consoleHandle, 0x70);

	menuTable(53, 4, 66, 36);

	SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(74, 6, L"QUẢN LÝ THÔNG TIN CÁN BỘ: ");
	SetConsoleTextAttribute(consoleHandle, 0x71);
	int x = 57;
	writeString(x, 8, L"1. Hiển thị cán bộ");
	writeString(x, 10, L"2. Thêm cán bộ");
	writeString(x, 12, L"3. Xóa cán bộ");
	writeString(x, 14, L"4. Chỉnh sửa thông tin cán bộ");
	writeString(x, 16, L"5. Số lượng cán bộ nữ");
	writeString(x, 18, L"6. Số lượng tiến sĩ");
	writeString(x, 20, L"7. Tổng số lương của toàn bộ cán bộ");
	writeString(x, 22, L"8. Cán bộ đến thời điểm nâng lương");
	writeString(x, 24, L"9. Cán bộ Công nghệ thông tin");
	writeString(x, 26, L"10. Cán bộ giỏi");
	writeString(x, 28, L"11. Cán bộ năm nay về hưu");
	writeString(x, 30, L"12. Cán bộ đang làm việc");
	writeString(x, 32, L"13. Hiển thị cán bộ theo mã cán bộ");
	writeString(x, 34, L"14. Hiển thị cán bộ theo tuổi");
	writeString(x, 36, L"15. Hiển thị cán bộ theo số năm công tác");
	writeString(x, 38, L"16. THOÁT");
}

//bảng chỉnh sửa
inline void fixTable() {
	// Lấy handle của cửa sổ console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Thiết lập màu văn bản và nền
	SetConsoleTextAttribute(consoleHandle, 0x70);

	//ve them bang ma can bo can chinh sua

	menuTable(53, 4, 66, 32);

	SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(74, 6, L"QUẢN LÝ THÔNG TIN CÁN BỘ: ");
	SetConsoleTextAttribute(consoleHandle, 0x71);
	int x = 57;
	writeString(x, 8, L"1. MÃ");
	writeString(x, 10, L"2. HỌ VÀ TÊN");
	writeString(x, 12, L"3. QUÊ QUÁN");
	writeString(x, 14, L"4. GIỚI TÍNH");
	writeString(x, 16, L"5. NĂM SINH");
	writeString(x, 18, L"6. CHUYÊN MÔN");
	writeString(x, 20, L"7. TRÌNH ĐỘ");
	writeString(x, 22, L"8. HỆ SỐ LƯƠNG");
	writeString(x, 24, L"9. PHỤ CẤP");
	writeString(x, 26, L"10. ĂN TRƯA");
	writeString(x, 28, L"11. THỰC LĨNH");
	writeString(x, 30, L"12. NĂM VÀO NGHỀ");
	writeString(x, 32, L"13. NĂM TĂNG LƯƠNG");
	writeString(x, 34, L"14. XẾP LOẠI");
}

inline void display1() {
	// Lấy handle của cửa sổ console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Thiết lập màu văn bản và nền
	SetConsoleTextAttribute(consoleHandle, 0x74);
	menuBar(56, 3, 57, 4);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	writeString(57, 5, L"     CHÀO MỪNG BẠN ĐẾN VỚI ỨNG DỤNG QUẢN LÝ CÁN BỘ      ");

	gotoxy(57, 4);
	fillColorConsole(57, 4, 112, 4);
	gotoxy(57, 6);
	fillColorConsole(57, 6, 112, 6);
	gotoxy(0, 3);
	fillColorConsole(0, 4, 55, 8);

	SetConsoleTextAttribute(consoleHandle, 0x70);
	//khung tên đăng nhập
	menuBar(68, 10, 32, 2);
	gotoxy(0, 11);
	fillColorConsole(80, 11, 99, 12);

	//khung mật khẩu
	menuBar(68, 13, 32, 2);
	gotoxy(0, 14);
	fillColorConsole(75, 14, 99, 15);

	//viết chữ
	SetConsoleTextAttribute(consoleHandle, 0x78);
	writeString(69, 11, L"Tên đăng nhập");
	writeString(69, 14, L"Mật khẩu");
	writeString(78, 20, L"\033[4mQuên mật khẩu\033[0m");

	SetConsoleTextAttribute(consoleHandle, 0x77);
	writeString(91, 20, L".");

	//khung đăng nhập
	SetConsoleTextAttribute(consoleHandle, 0x78);
	menuBar(68, 16, 32, 2);
	//đăng nhập
	SetConsoleTextAttribute(consoleHandle, 0x87);
	writeString(80, 17, L"ĐĂNG NHẬP");
	SetConsoleTextAttribute(consoleHandle, 0x80);
	writeString(69, 17, L"           ");
	writeString(89, 17, L"           ");

	gotoxy(0, 10);
	fillColorConsole(0, 10, 67, 19);

	gotoxy(0, 20);
	fillColorConsole(0, 20, 77, 22);

}

inline wstring toUpperCase(const wstring& input) {
	wstring result;
	locale loc("vi_VN.UTF-8");  // Chọn locale tiếng Việt, có thể thay đổi tùy theo hệ thống
	const ctype<wchar_t>& facet = use_facet<ctype<wchar_t>>(loc);

	for (wchar_t ch : input) {
		result += facet.toupper(ch);
	}

	return result;
}