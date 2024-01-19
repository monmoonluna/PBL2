#include <iostream>
#include "Canbo.h"
#include "List.h"
#include "Header.h"
#include "HeThong.h"

#include <string>
#include <conio.h>

#include <fstream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>


using namespace std;
LinkedList L;


int main() {
	ShowCur(false);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	HDC hdc = GetDC(GetConsoleWindow());
	ReleaseDC(GetConsoleWindow(), hdc);
	while (true) {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consoleHandle, 0x70);
		display1();
		HeThong ht;
		ht.DangNhap();
		int a = 0, b = 0, Toa_Do_X = 0, Toa_Do_Y = 0, n;
		system("cls");
		wstring namefile;
		do {
			SetConsoleTextAttribute(consoleHandle, 0x70);
			menuTable(53, 7, 62, 10);
			Select_input_method(53, 10);
			setClick(Toa_Do_X, Toa_Do_Y);
			if (59 <= Toa_Do_X <= 111 && Toa_Do_Y == 10) {
				a = 1;
			}
			if (59 <= Toa_Do_X <= 101 && Toa_Do_Y == 13) { a = 2; }
			system("cls");
			switch (a) {
			case 1:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x70);
				menuTable(53, 7, 66, 17);
				SetConsoleTextAttribute(consoleHandle, 0x71);
				writeString(55, 8, L"NHẬP SỐ LƯỢNG CÁN BỘ CẦN THÊM: ");
				wcin >> n;
				gotoxy(55, 8);
				fillColorConsole(55, 8, 100, 8);
				L.input(n);
				system("cls");
				break;
			case 2:
				do {
					SetConsoleTextAttribute(consoleHandle, 0x70);
					menuTable(60, 7, 55, 12);
					select_Data_File(60, 10);
					setClick(Toa_Do_X, Toa_Do_Y);
					if (71 <= Toa_Do_X <= 91 && Toa_Do_Y == 12) { b = 1; }
					if (71 <= Toa_Do_X <= 89 && Toa_Do_Y == 14) { b = 2; }
					if (71 <= Toa_Do_X <= 78 && Toa_Do_Y == 16) { b = 3; }
					system("cls");
					switch (b) {
					case 1:
						L.List_From_File(L"A");
						break;
					case 2:
						L.List_From_File(L"B");
						break;
					case 3:
						menuTable(53, 10, 66, 4);
						SetConsoleTextAttribute(consoleHandle, 0x71);
						writeString(55, 12, L"NHẬP TÊN CƠ QUAN: ");
						getline(wcin, namefile);
						system("cls");
						if (L.List_From_File(namefile) == false) {
							b = 5;
						}
						break;
					}
				} while (b != 1 && b != 2 && b != 3);
				break;
			}
		} while (a != 1 && a != 2);
		int sumNL = L.countNL(), sumCNTT = L.countCNTT(), sumGioi = L.countGioi();
		int sumVeHuu = L.countVeHuu(), sumLamViec = L.countLamViec();
		int x = 2, y = 4, sum;
		if (L.length_Of_List() % 10 == 0) {
			sum = L.length_Of_List() / 10;
		}
		else sum = L.length_Of_List() / 10 + 1;
		do {
			a = 0;
			menu();
			setClick(Toa_Do_X, Toa_Do_Y);
			if (57 <= Toa_Do_X && Toa_Do_X <= 75 && Toa_Do_Y == 8) { a = 1; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 71 && Toa_Do_Y == 10) { a = 2; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 70 && Toa_Do_Y == 12) { a = 3; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 86 && Toa_Do_Y == 14) { a = 4; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 78 && Toa_Do_Y == 16) { a = 5; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 76 && Toa_Do_Y == 18) { a = 6; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 92 && Toa_Do_Y == 20) { a = 7; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 91 && Toa_Do_Y == 22) { a = 8; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 86 && Toa_Do_Y == 24) { a = 9; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 71 && Toa_Do_Y == 26) { a = 10; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 82 && Toa_Do_Y == 28) { a = 11; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 81 && Toa_Do_Y == 30) { a = 12; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 91 && Toa_Do_Y == 32) { a = 13; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 86 && Toa_Do_Y == 34) { a = 14; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 100 && Toa_Do_Y == 36) { a = 15; }
			if (57 <= Toa_Do_X && Toa_Do_X <= 66 && Toa_Do_Y == 38) { a = 16; }
			switch (a) {
			case 1:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ]");
				menuDisplaySt(2, 4, 23, 1, sum);
				L.print_List(1);
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 2:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				L.themCanBo();
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 3:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 1, L"Mã cán bộ cần xóa: ");
				SetConsoleTextAttribute(consoleHandle, 0x71);
				int x;
				wcin >> x;
				L.xoaCanBo(x);
				if (L.length_Of_List() % 10 == 0) {
					sum = L.length_Of_List() / 10;
				}
				else sum = L.length_Of_List() / 10 + 1;
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ]");
				menuDisplaySt(2, 4, 23, 1, sum);
				L.print_List();
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 4:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				menuTable(53, 10, 70, 4);
				writeString(55, 12, L"Mã cán bộ cần chỉnh sửa: ");
				SetConsoleTextAttribute(consoleHandle, 0x71);
				int number;
				wcin >> number;
				L.update(number);
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 5:
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				writeString(75, 42, L"Số lượng cán bộ nữ: ");
				SetConsoleTextAttribute(consoleHandle, 0x71);
				wcout << L.canBoNu() << endl;
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 6:
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				writeString(67, 42, L"Số lượng cán bộ có trình độ tiến sĩ: ");
				SetConsoleTextAttribute(consoleHandle, 0x71);
				wcout << L.tienSi() << endl;
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 7:
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				writeString(65, 42, L"Tổng thu nhập của các cán bộ: ");
				SetConsoleTextAttribute(consoleHandle, 0x71);
				wcout << L.tongThuNhap() << endl;
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 8:
				system("cls");
				if (sumNL == 0) {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(55, 20, L"KHÔNG CÓ CÁN BỘ ĐẾN THỜI ĐIỂM NÂNG LƯƠNG TRONG DANH SÁCH");
					writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				}
				else {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ĐẾN THỜI ĐIỂM NÂNG LƯƠNG ]");
					menuDisplaySt(2, 4, 23, 1, sumNL);
					L.canBoNangLuong();
				}
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 9:
				system("cls");
				if (sumCNTT == 0) {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(55, 20, L"KHÔNG CÓ CÁN BỘ CÔNG NGHỆ THÔNG TIN TRONG DANH SÁCH");
					writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				}
				else {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ CÔNG NGHỆ THÔNG TIN ]");
					menuDisplaySt(2, 4, 23, 1, sumCNTT);
					L.canBoCNTT();
				}
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 10:system("cls");
				if (sumGioi == 0) {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(55, 20, L"KHÔNG CÓ CÁN BỘ GIỎI TRONG DANH SÁCH");
					writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				}
				else {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ GIỎI ]");
					menuDisplaySt(2, 4, 23, 1, sumGioi);
					L.canBoGioi();
				}
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 11:
				system("cls");
				if (sumVeHuu == 0) {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(65, 20, L"KHÔNG CÓ CÁN BỘ VỀ HƯU TRONG DANH SÁCH");
					writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				}
				else {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ VỀ HƯU ]");
					menuDisplaySt(2, 4, 23, 1, sumVeHuu);
					L.canBoVeHuu();
				}
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 12:
				system("cls");
				if (sumLamViec == 0) {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(55, 20, L"KHÔNG CÓ CÁN BỘ ĐANG LÀM VIỆC TRONG DANH SÁCH");
					writeString(127, 3, L"Nhấn [ESC] để quay trở lại menu");
				}
				else {
					SetConsoleTextAttribute(consoleHandle, 0x74);
					writeString(2, 2, L"[ THÔNG TIN CÁN BỘ ĐANG LÀM VIỆC ]");
					menuDisplaySt(2, 4, 23, 1, sumLamViec);
					L.canBoDangLamViec();
				}
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 13:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ THEO MÃ CÁN BỘ ]");
				menuDisplaySt(2, 4, 23, 1, sum);
				L.sxMa();
				L.print_List(2);
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 14:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ THEO TUỔI ]");
				menuDisplaySt(2, 4, 23, 1, sum);
				L.sxTuoi();
				L.print_List(3);
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 15:
				system("cls");
				SetConsoleTextAttribute(consoleHandle, 0x74);
				writeString(2, 2, L"[ THÔNG TIN CÁN BỘ THEO SỐ NĂM CÔNG TÁC ]");
				menuDisplaySt(2, 4, 23, 1, sum);
				L.soNamCongTac();
				L.sxNamCongTac();
				L.print_List(4);
				while (true) {
					if (setKeyBoard() == 5) {
						system("cls");
						break;
					}
				}
				break;
			case 16:
				if (b == 0) {
					system("cls");
					wstring name1;
					wcin.ignore();
					SetConsoleTextAttribute(consoleHandle, 0x70);
					menuTable(53, 10, 66, 4);
					SetConsoleTextAttribute(consoleHandle, 0x71);
					writeString(55, 12, L"NHẬP TÊN CƠ QUAN MỚI: ");
					getline(wcin, name1);
					L.save_List_to_File(name1);
					break;
				}
				else if (b == 1) { L.save_List_to_File(L"A"); }
				else if (b == 2) { L.save_List_to_File(L"B"); }
				else L.save_List_to_File(namefile);
				break;
			}
		} while (a != 16);
		system("cls");
	}
}
