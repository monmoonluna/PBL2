#pragma once
#include <string>
using namespace std;

class CanBo {
private:
	static int count, countNu, countTS, NangLuong, CNTT, Gioi, VeHuu, LamViec;
	static long long tongTN;
	int Ma, GioiTinh, NamSinh, Tuoi, NamVaoNghe, NamVeHuu, NamCongTac, PhuCap, AnTrua, ThucLinh, NamTangLuong;
	wstring HoTen, Que, XepLoai, ChuyenMon, TrinhDo;
	float HeSoLuong;
	friend class LinkedList;
public:
	void TinhThucLinh() {
		ThucLinh = (HeSoLuong + PhuCap) * 1490000 + AnTrua;
		tongTN += ThucLinh;
	};
	CanBo();
	CanBo(const CanBo& a);
	~CanBo();
	const CanBo& operator = (const CanBo& a);
	friend wistream& operator >> (wistream& in, CanBo& a);
	friend wostream& operator << (wostream& out, const CanBo& a);
	bool operator != (CanBo a);
	friend void output(int x, int y, const CanBo& a);
};