#include <iostream>
#include "List.h"
#include "Header.h"

#include <string>
#include <conio.h>

#include <ctime> // time()
#include <locale> // định dạng ngày và giờ theo địa phương: localtime()

#include <iomanip> // setprecision() cung cấp các hàm và toán tử định dạng (manipulator) để định dạng đầu ra. 
#include <sstream> // istringstream: Lớp này được sử dụng để đọc dữ liệu từ một chuỗi.
#include <fstream> // thư viện thao tác với các tệp
#include <codecvt> // chuyển đổi mã từ UTF-8 sang UTF-16
#include <Windows.h>

using namespace std;


LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	Node* temp = NULL;
	while (this->head) {
		temp = this->head;
		this->head = this->head->next;
		free(temp);
	}
}

int LinkedList::length_Of_List()
{
	int lenght = 0;
	Node* temp = this->head;
	for (temp; temp != NULL; temp = temp->next)
	{
		++lenght;
	}
	return lenght;
}

CanBo LinkedList::get_Node(int position)
{
	int k = 1;
	Node* temp = this->head;
	while (k != position && temp != NULL) {
		temp = temp->next;
		++k;
	}

	return temp->data;
}

bool LinkedList::delete_Node(CanBo a)
{
	int position = find_Node(a);
	int k = 0;
	if (head == NULL || position == -1) {
		return false;
	}
	Node* temp = head;
	if (head->next == NULL || position == 1) {
		this->head = this->head->next;
	}
	else {
		while (temp != NULL && k != position - 1)
		{
			temp = temp->next;
			++k;
		}
		temp->next = temp->next->next;
	}
	return true;
}

bool LinkedList::add_Node(CanBo newCanBo)
{
	if (this->isEmpty()) {
		head = new Node();
		head->data = newCanBo;
		head->next = NULL;
	}
	else if (this->find_Node(newCanBo) == -1) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		Node* newNode = new Node();
		newNode->data = newCanBo;
		newNode->next = NULL;
		temp->next = newNode;
	}
	else {
		return false;  // Node already exists
	}
	return true;
}

bool LinkedList::isEmpty()
{
	if (this->head == NULL) return true;
	return false;
}

int LinkedList::find_Node(CanBo a)
{
	Node* temp = this->head;
	int position = 1;
	for (temp; temp != NULL; temp = temp->next) {
		if ((temp->data != a) == false)
		{
			return position;
		}
		++position;
	}
	return -1;
}

int LinkedList::find_Node(int a)
{
	Node* temp = this->head;
	int position = 1;
	for (temp; temp != NULL; temp = temp->next) {
		if ((temp->data.Ma != a) == false)
		{
			return position;
		}
		++position;
	}
	return -1;
}

void LinkedList::print_List(int x)
{
	int sum;
	if (this->length_Of_List() % 10 == 0) {
		sum = this->length_Of_List() / 10;
	}
	else sum = this->length_Of_List() / 10 + 1;
	const wchar_t* name = L"[ THÔNG TIN CÁN BỘ ]";
	if (x == 2) name = L"[ THÔNG TIN CÁN BỘ THEO MÃ CÁN BỘ ]";
	else if (x == 3) name = L"[ THÔNG TIN CÁN BỘ THEO TUỔI ]";
	else if (x == 4) name = L"[ THÔNG TIN CÁN BỘ THEO SỐ NĂM CÔNG TÁC ]";
	Node* temp = head;
	Node** first = new Node * [sum]; //lưu node đầu page
	int a = 0, page = 1, tam = 0;
	while (tam == 0) {
		while (temp != NULL) {
			for (int i = 1; i <= 10; i++) {
				if (temp != NULL) {
					a = a + 2;
					output(2, a + 4, temp->data);
					if (a == 2) { first[page] = temp; }
					temp = temp->next;
				}
			}
			if (setKeyBoard() == 4 && temp != NULL) //ấn qua phải
			{
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, name);
				page++;
				menuDisplaySt(2, 4, 23, page, sum);
				a = 0;
			}
			else if (setKeyBoard() == 3 && temp != NULL && page - 1 > 0)//ấn qua trái
			{
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, name);
				page--;
				menuDisplaySt(2, 4, 23, page, sum);
				temp = first[page];
				a = 0;
			}
			else if (setKeyBoard() == 4 && temp == NULL) { break; } //ấn qua phải ở trang cuối
			else if (setKeyBoard() == 3 && page - 1 <= 0) { break; } //ấn qua trái ở trang đầu
			else if (setKeyBoard() == 5) { system("cls"); tam = 1; break; }//thoát
			else if (setKeyBoard() == 1 || setKeyBoard() == 2) {
				a = 0;
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, name);
				menuDisplaySt(2, 4, 23, page, sum);
				temp = first[page];
			}
		}
		if (tam == 0) {
			int thu = 0;
			while (true) {
				if (setKeyBoard() == 5) {
					system("cls");
					tam = 1;
					break;
				}
				else if (setKeyBoard() == 3 && page == sum &&page!=1) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, name);
					menuDisplaySt(2, 4, 23, sum - 1, sum);
					page--;
					temp = first[sum - 1];
					a = 0;
					break;
				}
				else if (setKeyBoard() == 3 && page == 1 &&page!=sum) {
					while (true) {
						if (setKeyBoard() == 4) {
							system("cls");
							HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
							SetConsoleTextAttribute(consoleHandle, 0x74);
							writeString(2, 2, name);
							menuDisplaySt(2, 4, 23, 2, sum);
							page = 2;
							if (first[page]->data.Ma == 0) { thu = 1; }
							else temp = first[2];
							a = 0;
							break;
						}
						else if (setKeyBoard() == 5) {
							system("cls");
							tam = 1;
							break;
						}
					}
				}
				break;
			}
			if (thu == 1) { continue; }
		}
	}
}

void LinkedList::save_List_to_File(wstring a)
{
	wfstream outfile;
	outfile.open(conCat(a, L"data"), ios::out);
	locale location(locale(), new codecvt_utf8<wchar_t>);
	outfile.imbue(location);
	Node* temp = head;
	outfile << length_Of_List() << endl;
	for (temp; temp != NULL; temp = temp->next) {

		outfile << temp->data.Ma << endl;
		outfile << temp->data.HoTen << endl;
		outfile << temp->data.Que << endl;
		outfile << ((temp->data.GioiTinh == 0) ? (L"Nữ") : (L"Nam")) << endl;
		outfile << temp->data.NamSinh << endl;
		outfile << temp->data.ChuyenMon << endl;
		outfile << temp->data.TrinhDo << endl;
		outfile << temp->data.HeSoLuong << endl;
		outfile << temp->data.PhuCap << endl;
		outfile << temp->data.AnTrua << endl;
		outfile << temp->data.ThucLinh << endl;
		outfile << temp->data.NamVaoNghe << endl;
		outfile << ((namHienTai() - temp->data.NamVaoNghe) % 2 == 0 ? (namHienTai()) : (namHienTai() + 1)) << endl;
		outfile << temp->data.XepLoai << endl;
	}
	outfile.close();
}
// Hàm chuyển đổi wstring sang kiểu bool

bool wstringToBool(const wstring& str) {
	return (str == L"Nữ") ? false : true;
}
// Hàm chuyển đổi wstring sang kiểu int

int wstringToInt(const wstring& str) {
	wistringstream iss(str);
	int value;
	iss >> value;
	return value;
}

wstring wstringToWstring(const wstring& str) {
	return str; // Không cần chuyển đổi, trả về trực tiếp
}

bool LinkedList::List_From_File(wstring a) {
	wfstream infile;
	infile.open(conCat(a, L"data"), ios_base::in);
	infile.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
	if (!infile.is_open()) {
		menuTable(53, 10, 66, 4);
		writeString(57, 12, L"KHÔNG THỂ MỞ TỆP TIN.");
		if (_getch()) system("cls");
		return false;
	}

	int n;
	infile >> n;

	// Check if the list is empty
	if (head == nullptr) {
		head = new Node; // Assuming Node has a default constructor
	}

	Node* temp = head;

	for (int i = 1; i <= n; i++) {
		// Check if temp->next is nullptr, create a new node if needed
		if (temp->next == nullptr) {
			temp->next = new Node; // Assuming Node has a default constructor
		}
		infile >> temp->data.Ma;
		infile.ignore();
		getline(infile, temp->data.HoTen);
		getline(infile, temp->data.Que);
		wstring gioiTinhStr;
		infile >> gioiTinhStr;
		temp->data.GioiTinh = wstringToBool(gioiTinhStr);
		infile >> temp->data.NamSinh;
		infile.ignore();
		getline(infile, temp->data.ChuyenMon);
		getline(infile, temp->data.TrinhDo);
		infile >> temp->data.HeSoLuong;
		infile >> temp->data.PhuCap;
		infile >> temp->data.AnTrua;
		infile >> temp->data.ThucLinh;
		infile >> temp->data.NamVaoNghe;
		infile >> temp->data.NamTangLuong;
		infile.ignore();
		getline(infile, temp->data.XepLoai);
		(temp->data.GioiTinh == 0) ? (temp->data.countNu++) : (temp->data.countNu = temp->data.countNu);
		(temp->data.TrinhDo == L"TIẾN SĨ") ? (temp->data.countTS++) : (temp->data.countTS = temp->data.countTS);
		temp->data.TinhThucLinh();
		(namHienTai() == temp->data.NamTangLuong) ? (temp->data.NangLuong++) : (temp->data.NangLuong = temp->data.NangLuong);
		(temp->data.ChuyenMon == L"CNTT") ? (temp->data.CNTT++) : (temp->data.CNTT = temp->data.CNTT);
		(temp->data.XepLoai == L"GIỎI") ? (temp->data.Gioi++) : (temp->data.Gioi = temp->data.Gioi);
		(((temp->data.GioiTinh) == 0 && namHienTai() - temp->data.NamSinh == 56) || ((temp->data.GioiTinh) == 1 && namHienTai() - temp->data.NamSinh == 60)) ? (temp->data.VeHuu++) : (temp->data.VeHuu = temp->data.VeHuu);
		(((temp->data.GioiTinh) == 0 && namHienTai() - temp->data.NamSinh != 56) || ((temp->data.GioiTinh) == 1 && namHienTai() - temp->data.NamSinh != 60)) ? (temp->data.LamViec++) : (temp->data.LamViec = temp->data.LamViec);
		if (i != n) {
			temp = temp->next;
		}
		else { temp->next = NULL; }
	}

	infile.close();
	return true;
}

void LinkedList::soNamCongTac()
{
	Node* temp = head;
	for (temp; temp != NULL; temp = temp->next)
	{
		temp->data.NamCongTac = namHienTai() - temp->data.NamVaoNghe;
	}

}

void LinkedList::input(int n)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i <= n; i++) {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CanBo a;
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(77, 8, L"THÔNG TIN CÁN BỘ ");
		wcout << i;
		SetConsoleTextAttribute(consoleHandle, 0x71);
		wcin >> a;
		this->add_Node(a);
		gotoxy(55, 8);
		fillColorConsole(55, 8, 118, 23);
	}
}

int LinkedList::canBoNu()
{
	return head->data.countNu;
}

int LinkedList::tienSi()
{
	return head->data.countTS;
}

long long LinkedList::tongThuNhap()
{
	return head->data.tongTN;
}

void LinkedList::canBoNangLuong()
{
	int sum;
	if (head->data.NangLuong % 10 == 0) {
		sum = head->data.NangLuong / 10;
	}
	else sum = head->data.NangLuong / 10 + 1;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	Node* temp = head;
	Node** first = new Node * [sum]; //lưu node đầu page
	for (int k = 1; k <= this->length_Of_List(); k++) {
		first[k] = new Node;
	}
	int a = 0; // cách dòng
	int b = 0, page = 1, tam = 0;
	while (tam == 0) {
		while (temp != NULL) {
			while (b < 10 && temp != NULL) {
				if ((namHienTai() - temp->data.NamVaoNghe) % 2 == 0 && temp != NULL) {
					a = a + 2;
					output(2, a + 4, temp->data);
					if (a == 2) { first[page] = temp; }
					b++;
				}
				temp = temp->next;
			}
			if (setKeyBoard() == 4 && b >= 10 && page != sum) {
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ĐẾN THỜI ĐIỂM NÂNG LƯƠNG  ]");
				page++;
				menuDisplaySt(2, 4, 23, page, sum);
				a = 0;
				b = 0;
			}
			else if (setKeyBoard() == 3 && temp != NULL && page - 1 > 0)//ấn qua trái
			{
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ĐẾN THỜI ĐIỂM NÂNG LƯƠNG  ]");
				page--;
				menuDisplaySt(2, 4, 23, page, sum);
				temp = first[page];
				a = 0;
				b = 0;
			}
			else if (setKeyBoard() == 4 && page == sum) { break; } //ấn qua phải ở trang cuối
			else if (setKeyBoard() == 3 && page - 1 <= 0) { break; } //ấn qua trái ở trang đầu
			else if (setKeyBoard() == 5) { system("cls"); tam = 1; break; }//thoát
		}
		if (tam == 0) {
			int thu = 0;
			while (true) {
				if (setKeyBoard() == 5) {
					system("cls");
					tam = 1;
					break;
				}
				else if (setKeyBoard() == 3 && page == sum &&page!=1) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ĐẾN THỜI ĐIỂM NÂNG LƯƠNG  ]");
					menuDisplaySt(2, 4, 23, sum - 1, sum);
					page--;
					temp = first[sum - 1];
					a = 0;
					b = 0;
					break;
				}
				else if (page == 1 && page != sum && setKeyBoard() == 4) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ĐẾN THỜI ĐIỂM NÂNG LƯƠNG  ]");
					menuDisplaySt(2, 4, 23, 2, sum);
					page++;
					a = 0;
					b = 0;
					if (first[page]->data.Ma == 0) {
						thu = 1;
					}
					else { temp = first[page]; }
					break;
				}
			}
			if (thu == 1) { continue; }
		}
	}
}

bool LinkedList::update(int number)
{	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
	int position=find_Node(number);
	if (position == -1) { 
		menuTable(53, 10, 70, 4);
		writeString(55, 12, L"Không tồn tại cán bộ có mã như trên."); return false; }
	system("cls");
	CanBo update = get_Node(position);
	xoaCanBo(number);
	SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
	SetConsoleTextAttribute(consoleHandle, 0x71);
	fixTable();
	int x, y,a=15;
	while (a==15) {
		setClick(x, y);
		if (57 <= x && x <= 62 && y == 8) a = 1;
		if (57 <= x && x <= 69 && y == 10) a = 2;
		if (57 <= x && x <= 68 && y == 12) a = 3;
		if (57 <= x && x <= 69 && y == 14) a = 4;
		if (57 <= x && x <= 68 && y == 16) a = 5;
		if (57 <= x && x <= 70 && y == 18) a = 6;
		if (57 <= x && x <= 68 && y == 20) a = 7;
		if (57 <= x && x <= 71 && y == 22) a = 8;
		if (57 <= x && x <= 67 && y == 24) a = 9;
		if (57 <= x && x <= 68 && y == 26) a = 10;
		if (57 <= x && x <= 70 && y == 28) a = 11;
		if (57 <= x && x <= 73 && y == 30) a = 12;
		if (57 <= x && x <= 75 && y == 32) a = 13;
		if (57 <= x && x <= 69 && y == 34) a = 14;
	}
	wstring newname;
	switch (a) {
	case 1:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại mã: ");
		int ma;
		wcin >> ma;
		update.Ma = ma;
		break;
	case 2:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại họ và tên: ");
		wcin.ignore();
		getline(wcin, newname);
		update.HoTen = newname;
		break;
	case 3:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại quê quán: ");
		wcin.ignore();
		getline(wcin, newname);
		update.Que = newname;
		break;
	case 4:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại giới tính (Nam: 1, Nữ: 0): ");
		int gt;
		wcin >> gt;
		while (gt != 0 && gt != 1) {
			gotoxy(57, 12);
			SetConsoleTextAttribute(consoleHandle, 0x71);
			writeString(57, 12, L"Giới tính không hợp lệ, vui lòng nhập lại giới tính: ");
			wcin >> gt;
		}
		update.GioiTinh = gt;
		break;
	case 5:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại năm sinh: ");
		int ns;
		wcin >> ns;
		while (ns>namHienTai()) {
			gotoxy(57, 12);
			SetConsoleTextAttribute(consoleHandle, 0x71);
			writeString(57, 12, L"Năm sinh không hợp lệ, vui lòng nhập lại năm sinh: ");
			wcin >> ns;
		}
		update.NamSinh = ns;
		break;
	case 6:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại chuyên môn: ");
		wcin.ignore();
		getline(wcin, newname);
		update.ChuyenMon = toUpperCase(newname);
		break;
	case 7:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại trình độ: ");
		wcin.ignore();
		getline(wcin, newname);
		update.TrinhDo = toUpperCase(newname);
		break;
	case 8:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại hệ số lương: ");
		float hsl;
		wcin >> hsl;
		update.HeSoLuong = hsl;
		break;
	case 9:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại phụ cấp: ");
		int pc;
		wcin >> pc;
		update.PhuCap = pc;
		break;
	case 10:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại ăn trưa: ");
		int at;
		wcin >> at;
		update.AnTrua = at;
		break;
	case 11:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại thực lĩnh: ");
		int tl;
		wcin >> tl;
		update.ThucLinh = tl;
		break;
	case 12:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại năm vào nghề: ");
		int nvn;
		wcin >> nvn;
		while (nvn > namHienTai()) {
			gotoxy(57, 12);
			SetConsoleTextAttribute(consoleHandle, 0x71);
			writeString(57, 12, L"Năm vào nghề không hợp lệ, vui lòng nhập lại năm vào nghề: ");
			wcin >> nvn;
		}
		update.NamVaoNghe = nvn;
		break;
	case 13:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại năm tăng lương: ");
		int ntl;
		wcin >> ntl;
		update.NamTangLuong = ntl;
		break;
	case 14:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
		SetConsoleTextAttribute(consoleHandle, 0x71);
		menuTable(53, 10, 70, 4);
		writeString(57, 12, L"Nhập lại xếp loại: ");
		wcin.ignore();
		getline(wcin, newname);
		update.XepLoai = toUpperCase(newname);
		break;
	}
	add_Node(update);
	return false;
}

int LinkedList::countNL() {
	int sum;
	if (head->data.NangLuong % 10 == 0) {
		sum = head->data.NangLuong / 10;
	}
	else sum = head->data.NangLuong / 10 + 1;
	return sum;
}

void LinkedList::canBoCNTT()
{
	int sum;
	if (head->data.CNTT % 10 == 0) {
		sum = head->data.CNTT / 10;
	}
	else sum = head->data.CNTT / 10 + 1;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	Node* temp = head; 
	Node** first = new Node * [sum]; //lưu node đầu page
	for (int k = 1; k <= this->length_Of_List(); k++) {
		first[k] = new Node;
	}
	int a = 0; // cách dòng
	int b = 0, page = 1, tam = 0;
	while (tam == 0) {
	while (temp != NULL) {
		while (b < 10 && temp != NULL) {
			if (temp->data.ChuyenMon == L"CNTT" && temp != NULL) {
				a = a + 2;
				output(2, a + 4, temp->data);
				if (a == 2) { first[page] = temp; }
				b++;
			}
			temp = temp->next;
		}if (setKeyBoard() == 4 && b >= 10 && page != sum) {
			system("cls");
			SetConsoleTextAttribute(consoleHandle, 0x74);
			writeString(2, 2, L"[ THÔNG TIN CÁN BỘ CÔNG NGHỆ THÔNG TIN  ]");
			page++;
			menuDisplaySt(2, 4, 23, page, sum);
			a = 0;
			b = 0;
		}
		else if (setKeyBoard() == 3 && temp != NULL && page - 1 > 0)//ấn qua trái
		{
			system("cls");
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 0x74);
			writeString(2, 2, L"[ THÔNG TIN CÁN BỘ CÔNG NGHỆ THÔNG TIN  ]");
			page--;
			menuDisplaySt(2, 4, 23, page, sum);
			temp = first[page];
			a = 0;
			b = 0;
		}
		else if (setKeyBoard() == 4 && page == sum) { break; } //ấn qua phải ở trang cuối
		else if (setKeyBoard() == 3 && page - 1 <= 0) { break; } //ấn qua trái ở trang đầu
		else if (setKeyBoard() == 5) { system("cls"); tam = 1; break; }//thoát
	}
	if (tam == 0) {
		int thu = 0;
		while (true) {
			if (setKeyBoard() == 5) {
				system("cls");
				tam = 1;
				break;
			}
			else if (setKeyBoard() == 3 && page == sum && page!=1) {
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ CÔNG NGHỆ THÔNG TIN  ]");
				menuDisplaySt(2, 4, 23, sum - 1, sum);
				page--;
				temp = first[sum - 1];
				a = 0;
				b = 0;
				break;
			}
			else if (page == 1 && page !=sum && setKeyBoard() == 4) {
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ CÔNG NGHỆ THÔNG TIN  ]");
				menuDisplaySt(2, 4, 23, 2, sum);
				page++; 
				a = 0;
				b = 0;
				if (first[page]->data.Ma == 0) thu = 1;
				else temp = first[page];
				break;				
			}
		}
	if (thu == 1) { continue; }
	}
	}
}

int LinkedList::countCNTT() {
	int sum;
	if (head->data.CNTT % 10 == 0) {
		sum = head->data.CNTT / 10;
	}
	else sum = head->data.CNTT / 10 + 1;
	return sum;
}

void LinkedList::canBoGioi()
{
	int sum;
	if (head->data.Gioi % 10 == 0) {
		sum = head->data.Gioi / 10;
	}
	else sum = head->data.Gioi / 10 + 1;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	Node* temp = head;
	Node** first = new Node * [sum]; //lưu node đầu page
	for (int k = 1; k <= this->length_Of_List(); k++) {
		first[k] = new Node;
	}

	int a = 0; // cách dòng
	int b = 0, page = 1, tam = 0;

	while (tam == 0) {
	while (temp != NULL) {
		while (b < 10 && temp != NULL) {
			if (temp->data.XepLoai == L"GIỎI" && temp != NULL) {
				a = a + 2;
				output(2, a + 4, temp->data);
				if (a == 2) { first[page] = temp; }
				b++;
			}
			temp = temp->next;
		}if (setKeyBoard() == 4 && b >= 10 && page != sum) {
			system("cls");
			SetConsoleTextAttribute(consoleHandle, 0x74);
			writeString(2, 2, L"[ THÔNG TIN CÁN BỘ GIỎI  ]");
			page++;
			menuDisplaySt(2, 4, 23, page, sum);
			a = 0;
			b = 0;
		}
		else if (setKeyBoard() == 3 && temp != NULL && page - 1 > 0)//ấn qua trái
		{
			system("cls");
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 0x74);
			writeString(2, 2, L"[ THÔNG TIN CÁN BỘ GIỎI  ]");
			page--;
			menuDisplaySt(2, 4, 23, page, sum);
			temp = first[page];
			a = 0;
			b = 0;
		}
		else if (setKeyBoard() == 4 && page == sum) { break; } //ấn qua phải ở trang cuối
		else if (setKeyBoard() == 3 && page - 1 <= 0) { break; } //ấn qua trái ở trang đầu
		else if (setKeyBoard() == 5) { system("cls"); tam = 1; break; }//thoát
	}
	if (tam == 0) {
		int thu = 0;
			while (true) {
				if (setKeyBoard() == 5) {
					system("cls");
					tam = 1;
					break;
				}
				else if (setKeyBoard() == 3 && page == sum &&page!=1) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ GIỎI  ]");
					menuDisplaySt(2, 4, 23, sum - 1, sum);
					page--;
					temp = first[sum - 1];
					a = 0;
					b = 0;
					break;
				}
				else if (page == 1 && page != sum && setKeyBoard() == 4) {
						system("cls");
						HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(consoleHandle, 0x74);
						writeString(2, 2, L"[ THÔNG TIN CÁN BỘ GIỎI  ]");
						menuDisplaySt(2, 4, 23, 2, sum);
						page++;
						a = 0;
						b = 0;
						if (first[page]->data.Ma == 0) {
							thu = 1;
						}
						else{ temp = first[page];}
						break;
					}
				}
			if (thu == 1) { continue; }
			}
	}
}

int LinkedList::countGioi() {
	int sum;
	if (head->data.Gioi % 10 == 0) {
		sum = head->data.Gioi / 10;
	}
	else sum = head->data.Gioi / 10 + 1;
	return sum;
}

void LinkedList::canBoVeHuu()
{
	int sum;
	if (head->data.VeHuu % 10 == 0) {
		sum = head->data.VeHuu / 10;
	}
	else sum = head->data.VeHuu / 10 + 1;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	Node* temp = head;
	Node** first = new Node * [sum]; //lưu node đầu page
	for (int k = 1; k <= this->length_Of_List(); k++) {
		first[k] = new Node;
	}

	int a = 0; // cách dòng
	int b = 0, page = 1, tam = 0;
	while (tam == 0) {
		while (temp != NULL) {
			while (b < 10 && temp != NULL) {
				if (((temp->data.GioiTinh) == 0 && namHienTai() - temp->data.NamSinh == 56) || ((temp->data.GioiTinh) == 1 && namHienTai() - temp->data.NamSinh == 60)) {
					a = a + 2;
					output(2, a + 4, temp->data);
					if (a == 2) { first[page] = temp; }
					b++;
				}
				temp = temp->next;
			}
			if (setKeyBoard() == 4 && b >= 10 && page != sum) {
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU ]");
				page++;
				menuDisplaySt(2, 4, 23, page, sum);
				a = 0;
				b = 0;
			}
			else if (setKeyBoard() == 3 && temp != NULL && page - 1 > 0)//ấn qua trái
			{
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU  ]");
				page--;
				menuDisplaySt(2, 4, 23, page, sum);
				temp = first[page];
				a = 0;
				b = 0;
			}
			else if (setKeyBoard() == 4 && page == sum) { break; } //ấn qua phải ở trang cuối
			else if (setKeyBoard() == 3 && page - 1 <= 0) { break; } //ấn qua trái ở trang đầu
			else if (setKeyBoard() == 5) { system("cls"); tam = 1; break; }//thoát
		}
		if (tam == 0) {
			while (true) {
				if (setKeyBoard() == 5) {
					system("cls");
					tam = 1;
					break;
				}
				else if (setKeyBoard() == 3 && page == sum &&page!=1) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU  ]");
					menuDisplaySt(2, 4, 23, sum - 1, sum);
					page--;
					temp = first[sum - 1];
					a = 0;
					b = 0;
					break;
				}
				else if (page == 1 && page != sum && setKeyBoard() == 4) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU  ]");
					menuDisplaySt(2, 4, 23, 2, sum);
					page++;
					a = 0;
					b = 0;
					temp = first[page];
					break;
				}
			}
		}
	}
}

int LinkedList::countVeHuu() {
	int sum;
	if (head->data.VeHuu % 10 == 0) {
		sum = head->data.VeHuu / 10;
	}
	else sum = head->data.VeHuu / 10 + 1;
	return sum;
}

void LinkedList::canBoDangLamViec()
{
	int sum;
	if (head->data.LamViec % 10 == 0) {
		sum = head->data.LamViec / 10;
	}
	else sum = head->data.LamViec / 10 + 1;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	Node* temp = head;
	Node** first = new Node * [sum]; //lưu node đầu page
	for (int k = 1; k <= this->length_Of_List(); k++) {
		first[k] = new Node;
	}

	int a = 0; // cách dòng
	int b = 0, page = 1, tam = 0;
	while (tam == 0) {
		while (temp != NULL) {
			while (b < 10 && temp != NULL) {
				if (((temp->data.GioiTinh) == 0 && namHienTai() - temp->data.NamSinh < 56) || ((temp->data.GioiTinh) == 1 && namHienTai() - temp->data.NamSinh < 60)) {
					a = a + 2;
					output(2, a + 4, temp->data);
					if (a == 2) { first[page] = temp; }
					b++;
				}
				temp = temp->next;
			}
			if (setKeyBoard() == 4 && b >= 10 && page != sum) {
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU ]");
				page++;
				menuDisplaySt(2, 4, 23, page, sum);
				a = 0;
				b = 0;
			}
			else if (setKeyBoard() == 3 && temp != NULL && page - 1 > 0)//ấn qua trái
			{
				system("cls");
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU  ]");
				page--;
				menuDisplaySt(2, 4, 23, page, sum);
				temp = first[page];
				a = 0;
				b = 0;
			}
			else if (setKeyBoard() == 4 && page == sum) { break; } //ấn qua phải ở trang cuối
			else if (setKeyBoard() == 3 && page - 1 <= 0) { break; } //ấn qua trái ở trang đầu
			else if (setKeyBoard() == 5) { system("cls"); tam = 1; break; }//thoát
		}
		if (tam == 0) {
			while (true) {
				if (setKeyBoard() == 5) {
					system("cls");
					tam = 1;
					break;
				}
				else if (setKeyBoard() == 3 && page == sum &&page!=1) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU  ]");
					menuDisplaySt(2, 4, 23, sum - 1, sum);
					page--;
					temp = first[sum - 1];
					a = 0;
					b = 0;
					break;
				}
				else if (page == 1 && page != sum && setKeyBoard() == 4) {
					system("cls");
					HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU  ]");
					menuDisplaySt(2, 4, 23, 2, sum);
					page++;
					a = 0;
					b = 0;
					temp = first[page];
					break;
				}
			}
		}
	}
}

int LinkedList::countLamViec() {
	int sum;
	if (head->data.LamViec % 10 == 0) {
		sum = head->data.LamViec / 10;
	}
	else sum = head->data.LamViec / 10 + 1;
	return sum;
}

void LinkedList::xoaCanBo(int Ma)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	Node* current = head;
	Node* prev = nullptr;
	bool found = false;

	if (current == nullptr) {
		SetConsoleTextAttribute(consoleHandle, 0x71);
		writeString(1, 1, L"Không thể xóa bởi vì danh sách rỗng.");
		wcout<< endl;
		return;
	}

	do {
		if (current->data.Ma == Ma) {
			found = true;
			break;
		}

		prev = current;
		current = current->next;
	} while (current != nullptr);

	if (!found) {
		gotoxy(2, 1);
		fillColorConsole(2, 1, 100, 1);
		SetConsoleTextAttribute(consoleHandle, 0x74);
		writeString(2, 1, L"Không tìm thấy cán bộ cần xóa.");
		wcout<< endl;
		return;
	}
	if (current->data.GioiTinh == 0) current->data.countNu--;
	if (current->data.TrinhDo == L"TIẾN SĨ") current->data.countTS--;
	current->data.tongTN -= current->data.ThucLinh;
	if (current == head) {
		prev = head;
		head = current->next;
		delete prev;
		return;
	}

	if (current->next == nullptr) {
		prev->next = nullptr;
		delete current;
		return;
	}

	prev->next = current->next;
	delete current;
}

void LinkedList::themCanBo()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CanBo a;
	SetConsoleTextAttribute(consoleHandle, 0x74);
	writeString(77, 8, L"THÔNG TIN CÁN BỘ ");
	SetConsoleTextAttribute(consoleHandle, 0x71);
	wcin >> a;
	add_Node(a);
}

void LinkedList::sxMa()
{
	for (Node* temp = head; temp != NULL; temp = temp->next) {
		for (Node* temp1 = head; temp1 != NULL; temp1 = temp1->next) {
			if (temp1->next != NULL && temp1->data.Ma > temp1->next->data.Ma) {
				CanBo tam = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = tam;
			}
		}
	}
}

void LinkedList::sxTuoi()
{
	for (Node* temp = head; temp != NULL; temp = temp->next) {
		for (Node* temp1 = head; temp1 != NULL; temp1 = temp1->next) {
			if (temp1->next != NULL && temp1->data.NamSinh < temp1->next->data.NamSinh) {
				CanBo tam = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = tam;
			}
		}
	}
}

void LinkedList::sxNamCongTac()
{
	soNamCongTac();
	for (Node* temp = head; temp != NULL; temp = temp->next) {
		for (Node* temp1 = head; temp1 != NULL; temp1 = temp1->next) {
			if (temp1->next != NULL && temp1->data.NamCongTac > temp1->next->data.NamCongTac) {
				CanBo tam = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = tam;
			}
		}
	}
}