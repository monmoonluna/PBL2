#include <iostream>
#include <Windows.h>
#include "HeThong.h"
#include "Header.h"
#include <conio.h>
#include <sstream> // istringstream: Lớp này được sử dụng để đọc dữ liệu từ một chuỗi.
#include <fstream> // thư viện thao tác với các tệp


using namespace std;

wstring HeThong::getPassword() {
	wstring password;
	char ch;
	while ((ch = _getch()) != '\r') { // Đọc cho đến khi nhấn Enter ('\r')
		if (ch == '\b' && password.length() > 0) { // Xử lý phím Backspace
			wcout << "\b \b";
			password.pop_back();
		}
		else if (ch != '\b') { // Nếu không phải Backspace, thêm vào mật khẩu
			wcout << '*'; // Hiển thị * thay vì ký tự thực
			password.push_back(ch);
		}
	}
	return password;
}

wstring HeThong::getName() {
	wstring name;
	char ch;
	while ((ch = _getch()) != '\r') { // Đọc cho đến khi nhấn Enter ('\r')
		if (ch == '\b' && name.length() > 0) { // Xử lý phím Backspace
			wcout << "\b \b";
			name.pop_back();
		}
		else if (ch != '\b') { // Nếu không phải Backspace, thêm vào mật khẩu
			wcout << ch; // Hiển thị * thay vì ký tự thực
			name.push_back(ch);
		}
	}
	return name;
}

bool HeThong::DangNhap()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true) {
		int x, y;
		setClick(x,y);
		if (x >= 78 && x <= 91 && y == 20) { QuenMatKhau(); break; }
		wstring a, b;
		while (true) {
			setClick(x, y);
			if (x <= 100 && x >= 68 && y <= 12 && y >= 10) {
				gotoxy(69, 11);
				fillColorConsole(69, 11, 99, 11);
				a = getName();
				break;
			}
			if (x >= 78 && x <= 91 && y == 20) { QuenMatKhau(); break; }
		}
		while (true) {
			setClick(x, y);
			if (x <= 100 && x >= 68 && y >= 13 && y <= 15) {
				gotoxy(69, 14);
				fillColorConsole(69, 14, 99, 14);
				b = getPassword(); break;
			}
			if (x >= 78 && x <= 91 && y == 20) { QuenMatKhau(); break; }
		}
		setClick(x, y);
		if (x >= 78 && x <= 91 && y == 20) { QuenMatKhau(); break; }
		while ((x < 68 || x>100) && (y < 16 || y>18)) {
			setClick(x, y);
		}
		wfstream infile;
		infile.open("dangnhap.txt", ios_base::in);
		if (!infile.is_open()) {
			menuTable(53, 10, 66, 4);
			writeString(57, 12, L"KHÔNG THỂ MỞ TỆP TIN.");
			if (_getch()) system("cls");
			return false;
		}
		int n, i = 1;
		infile >> n;
		infile.ignore();
		while (i != n +1) {
			wstring line1, line2;
			getline(infile, line1);
			getline(infile, line2);
			if (a == line1 && b == line2) { break; }
			i = i + 1;
		}
		if (i >= n+1) {
			SetConsoleTextAttribute(consoleHandle, 0x74);
			writeString(67, 9, L"\x1b[1mThông tin đăng nhập không chính xác");
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
			SetConsoleTextAttribute(consoleHandle, 0x70);
		}
		else { break; }
	}
}


bool HeThong::QuenMatKhau()
{
	system("cls");
	menuTable(53, 10, 70, 4);
	writeString(57, 12, L"Nhập tên đăng nhập: ");
	wstring a;
	getline(wcin, a);
	wfstream infile;
	infile.open("dangnhap.txt", ios_base::in);
	if (!infile.is_open()) {
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"KHÔNG THỂ MỞ TỆP TIN.");
		if (_getch()) system("cls");
		return false;
	}
	int n, i = 1;
	infile >> n;
	infile.ignore();
	while (i != n+1) {
		wstring line1, line2;
		getline(infile, line1);
		getline(infile, line2);
		if (a == line1) { break; }
		i = i + 1;
	}
	if (i >= n+1) {
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Không tồn tại tài khoản này.");
		while (true) {
			if (setKeyBoard() == 5) {
				system("cls");
				break;
			}
		}
		display1();
		DangNhap();
	}
	else {
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Yêu cầu đã được xem xét, mật khẩu tài khoản sẽ được cấp lại sau.");
		while (true) {
			if (setKeyBoard() == 5) {
				system("cls");
				break;
			}
		}
		display1();
		DangNhap();
	}
}