#pragma once
#include <iostream>
#include "CanBo.h"

using namespace std;

class Node {
private:
	CanBo data;
	Node* next;
public:
	Node() {
		next = NULL;
	}
	friend class LinkedList;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList(); //hàm dựng
	~LinkedList(); //hàm hủy

	int length_Of_List(); //độ dài của list
	CanBo get_Node(int position); //lấy node tại 1 vị trí
	bool delete_Node(CanBo a);
	bool add_Node(CanBo newCanBo);
	bool isEmpty();
	int find_Node(CanBo a);
	int find_Node(int a);
	void print_List(int x=1);
	void save_List_to_File(wstring a);
	bool List_From_File(wstring a);

	void soNamCongTac();
	void input(int n);
	int canBoNu();
	int tienSi();
	long long tongThuNhap();
	void canBoNangLuong();
	bool update(int number);
	int countNL();
	void canBoCNTT();
	int countCNTT();
	void canBoGioi();
	int countGioi();
	void canBoVeHuu();
	int countVeHuu();
	void canBoDangLamViec();
	int countLamViec();
	void xoaCanBo(int Ma);
	void themCanBo();
	void sxMa();
	void sxTuoi();
	void sxNamCongTac();
	int namHienTai() {
		time_t now = time(nullptr);
		struct tm tm_now;
		localtime_s(&tm_now, &now);
		int year = tm_now.tm_year + 1900;
		return year;
	}
};