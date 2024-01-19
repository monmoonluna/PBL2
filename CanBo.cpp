#include <iostream>
#include "Canbo.h"
#include "List.h"
#include "Header.h"

#include <string.h>
#include <conio.h>

#include <ctime>
#include <locale>

#include <iomanip>
#include <cctype> // toupper(): Hàm này chuyển đổi một ký tự sang chữ hoa.
#include <fstream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

int CanBo::count = 0;
int CanBo::countNu = 0;
int CanBo::countTS = 0;
long long CanBo::tongTN = 0;
int CanBo::NangLuong = 0;
int CanBo::CNTT = 0;
int CanBo::Gioi = 0;
int CanBo::VeHuu = 0;
int CanBo::LamViec = 0;




int namHienTai() {
	time_t now = time(nullptr);
	struct tm tm_now;
	localtime_s(&tm_now, &now);
	int year = tm_now.tm_year + 1900;
	return year;
}

CanBo::CanBo()
{
	Ma = 0;
	GioiTinh = 0;
	NamSinh = 0;
	Tuoi = 0;
	NamVaoNghe = 0;
	NamVeHuu = 0;
	NamCongTac = 0;
	PhuCap = 0;
	AnTrua = 0;
	ThucLinh = 0;
	NamTangLuong = 0;
	HoTen = L"";
	Que = L"";
	XepLoai = L"";
	ChuyenMon = L"";
	TrinhDo = L"";
	HeSoLuong = 0;
}

CanBo::CanBo(const CanBo& a)
{
	Ma = a.Ma;
	GioiTinh = a.GioiTinh;
	NamSinh = a.NamSinh;
	Tuoi = a.Tuoi;
	NamVaoNghe = a.NamVaoNghe;
	NamVeHuu = a.NamVeHuu;
	NamCongTac = a.NamCongTac;
	PhuCap = a.PhuCap;
	AnTrua = a.AnTrua;
	ThucLinh = a.ThucLinh;
	NamTangLuong = a.NamTangLuong;
	HoTen = a.HoTen;
	Que = a.Que;
	XepLoai = a.XepLoai;
	ChuyenMon = a.ChuyenMon;
	TrinhDo = a.TrinhDo;
	HeSoLuong = a.HeSoLuong;
}

CanBo::~CanBo()
{
}

const CanBo& CanBo::operator = (const CanBo& a)
{
	Ma = a.Ma;
	GioiTinh = a.GioiTinh;
	NamSinh = a.NamSinh;
	Tuoi = a.Tuoi;
	NamVaoNghe = a.NamVaoNghe;
	NamVeHuu = a.NamVeHuu;
	NamCongTac = a.NamCongTac;
	PhuCap = a.PhuCap;
	AnTrua = a.AnTrua;
	ThucLinh = a.ThucLinh;
	NamTangLuong = a.NamTangLuong;
	HoTen = a.HoTen;
	Que = a.Que;
	XepLoai = a.XepLoai;
	ChuyenMon = a.ChuyenMon;
	TrinhDo = a.TrinhDo;
	HeSoLuong = a.HeSoLuong;
	return *this;
}

bool CanBo::operator != (CanBo a)
{
	if (Ma != a.Ma) return true;
	if (GioiTinh != a.GioiTinh) return true;
	if (NamSinh != a.NamSinh) return true;
	if (Tuoi != a.Tuoi) return true;
	if (NamVaoNghe != a.NamVaoNghe) return true;
	if (NamVeHuu != a.NamVeHuu) return true;
	if (NamCongTac != a.NamCongTac) return true;
	if (PhuCap != a.PhuCap) return true;
	if (AnTrua != a.AnTrua) return true;
	if (ThucLinh != a.ThucLinh) return true;
	if (NamTangLuong != a.NamTangLuong) return true;
	if (HoTen != a.HoTen) return true;
	if (Que != a.Que) return true;
	if (XepLoai != a.XepLoai) return true;
	if (ChuyenMon != a.ChuyenMon) return true;
	if (TrinhDo != a.TrinhDo) return true;
	if (HeSoLuong != a.HeSoLuong) return true;
	return false;
}

wistream& operator >> (wistream& in, CanBo& a)
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x70);
	menuTable(53, 7, 66, 17);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	writeString(55, 9, L"Mã cán bộ: ");
	wcin >> a.Ma;
	wcin.ignore();
	writeString(55, 10, L"Họ tên: ");
	getline(wcin, a.HoTen);
	writeString(55, 11, L"Quê quán: ");
	getline(wcin, a.Que);
	writeString(55, 12, L"Giới tính (Nam: 1, Nữ: 0): ");
	wcin >> a.GioiTinh;
	int x = 13;
	while (a.GioiTinh != 0 && a.GioiTinh != 1) {
		gotoxy(55, 13);
		fillColorConsole(55, 13, 114, 13);
		SetConsoleTextAttribute(consoleHandle, 0x71);
		writeString(55, 13, L"Giới tính không hợp lệ, vui lòng nhập lại giới tính: ");
		wcin >> a.GioiTinh;
		x = 14;
	}
	writeString(55, x, L"Năm sinh: ");
	wcin >> a.NamSinh;
	int y = x + 1;
	while (a.NamSinh >= namHienTai() || a.NamSinh < 1000) {
		gotoxy(55, x + 1);
		fillColorConsole(55, x + 1, 114, x + 1);
		SetConsoleTextAttribute(consoleHandle, 0x71);
		writeString(55, x + 1, L"Năm sinh không hợp lệ, vui lòng nhập lại năm sinh: ");
		wcin >> a.NamSinh;
		y = x + 2;
	}
	writeString(55, y, L"Chuyên môn: ");
	wcin.ignore();
	getline(wcin, a.ChuyenMon);
	a.ChuyenMon = toUpperCase(a.ChuyenMon);
	writeString(55, y + 1, L"Trình độ: ");
	getline(wcin, a.TrinhDo);
	a.TrinhDo = toUpperCase(a.TrinhDo);
	writeString(55, y + 2, L"Hệ số lương: ");
	setprecision(10);
	wcin >> a.HeSoLuong;
	writeString(55, y + 3, L"Phụ cấp: ");
	wcin >> a.PhuCap;
	writeString(55, y + 4, L"Ăn trưa: ");
	wcin >> a.AnTrua;
	int z = y + 6;
	writeString(55, y + 5, L"Năm vào nghề: ");
	wcin >> a.NamVaoNghe;
	while (a.NamVaoNghe <= a.NamSinh || a.NamVaoNghe > namHienTai()) {
		gotoxy(55, y + 6);
		fillColorConsole(55, y + 6, 114, y + 6);
		SetConsoleTextAttribute(consoleHandle, 0x71);
		writeString(55, y + 6, L"Năm vào nghề không hợp lệ, vui lòng nhập lại năm vào nghề: ");
		wcin >> a.NamVaoNghe;
		z = y + 7;
	}
	a.NamTangLuong = a.NamVaoNghe + 2;
	writeString(55, z, L"Xếp loại: ");
	wcin >> a.XepLoai;
	a.XepLoai = toUpperCase(a.XepLoai);
	(a.GioiTinh == 0) ? (a.countNu++) : (a.countNu = a.countNu);
	(a.TrinhDo == L"TIẾN SĨ") ? (a.countTS++) : (a.countTS = a.countTS);
	a.TinhThucLinh();
	(namHienTai()==a.NamTangLuong) ? (a.NangLuong++) : (a.NangLuong = a.NangLuong);
	(a.ChuyenMon == L"CNTT") ? (a.CNTT++) : (a.CNTT = a.CNTT);
	(a.XepLoai == L"GIỎI") ? (a.Gioi++) : (a.Gioi = a.Gioi);
	(((a.GioiTinh) == 0 && namHienTai() - a.NamSinh == 56) || ((a.GioiTinh) == 1 && namHienTai() - a.NamSinh == 60)) ? (a.VeHuu++) : (a.VeHuu = a.VeHuu);
	(((a.GioiTinh) == 0 && namHienTai() - a.NamSinh != 56) || ((a.GioiTinh) == 1 && namHienTai() - a.NamSinh != 60)) ? (a.LamViec++) : (a.LamViec = a.LamViec);
	return in;
}

void output(int x, int y, const CanBo& a) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	gotoxy(x + 2, y + 1);
	wcout << a.Ma;
	gotoxy(x + 6, y + 1);
	wcout << a.HoTen;
	gotoxy(x + 42, y + 1);
	wcout << a.Que;
	gotoxy(x + 56, y + 1);
	if (a.GioiTinh == 0)
		wcout << L"Nữ";
	else wcout << L"Nam";
	gotoxy(x + 66, y + 1);
	wcout << a.NamSinh;
	gotoxy(x + 78, y + 1);
	wcout << a.ChuyenMon;
	gotoxy(x + 91, y + 1);
	wcout << a.TrinhDo;
	gotoxy(x + 101, y + 1);
	wcout << a.HeSoLuong;
	gotoxy(x + 107, y + 1);
	wcout << a.PhuCap;
	gotoxy(x + 117, y + 1);
	wcout << a.AnTrua;
	gotoxy(x + 126, y + 1);
	wcout << a.ThucLinh;
	gotoxy(x + 136, y + 1);
	wcout << a.NamVaoNghe;
	gotoxy(x + 145, y + 1);
	if ((namHienTai() - a.NamVaoNghe) % 2 == 0)
		wcout << namHienTai();
	else
		wcout << namHienTai() + 1;
	gotoxy(x + 156, y + 1);
	wcout << a.XepLoai;
}
wostream& operator << (wostream& out, const CanBo& a)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 0x71);
	int x = 2;
	int y = 6;
	// TODO: insert return statement here
	gotoxy(x + 2, y + 1);
	wcout << a.Ma;
	gotoxy(x + 6, y + 1);
	wcout << a.HoTen;
	gotoxy(x + 42, y + 1);
	wcout << a.Que;
	gotoxy(x + 56, y + 1);
	if (a.GioiTinh == 0)
		wcout << L"Nữ";
	else wcout << L"Nam";
	gotoxy(x + 66, y + 1);
	wcout << a.NamSinh;
	gotoxy(x + 78, y + 1);
	wcout << a.ChuyenMon;
	gotoxy(x + 91, y + 1);
	wcout << a.TrinhDo;
	gotoxy(x + 101, y + 1);
	wcout << a.HeSoLuong;
	gotoxy(x + 107, y + 1);
	wcout << a.PhuCap;
	gotoxy(x + 117, y + 1);
	wcout << a.AnTrua;
	gotoxy(x + 126, y + 1);
	wcout << a.ThucLinh;
	gotoxy(x + 136, y + 1);
	wcout << a.NamVaoNghe;
	gotoxy(x + 145, y + 1);
	if ((namHienTai() - a.NamVaoNghe) % 2 == 0)
		wcout << namHienTai();
	else
		wcout << namHienTai() + 1;
	gotoxy(x + 156, y + 1);
	wcout << a.XepLoai;
	return out;
}