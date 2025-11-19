#include "QuanLy.h"

size_t	QuanLy::count_QL = 0;
float TongTienLuong_QL = 0;

QuanLy::QuanLy() {
	HeSoChucVu = 0;
	Thuong = 0;
	count_QL++;
};

void QuanLy::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap he so chuc vu: ";
	cin >> HeSoChucVu;
	cout << "Nhap tien thuong: ";
	cin >> Thuong;
};

string QuanLy::HoTen_v() {
	return HoTen;
};

string QuanLy::NgaySinh_v() {
	return NgaySinh;
};

float QuanLy::HeSoChucVu_v() {
	return HeSoChucVu;
};

float QuanLy::Thuong_v() {
	return Thuong;
};

float QuanLy::TinhLuong() {
	return Luong = LuongCoBan * HeSoChucVu + Thuong;
};

void QuanLy::Xuat() {
	NhanVien::Xuat();
	cout << "He so chuc vu: " << HeSoChucVu << endl;
	cout << "Tien thuong: " << (size_t)Thuong << "vnd" << endl;
	cout << "Tien luong: " << (size_t)QuanLy::TinhLuong() << "vnd" << endl;
};

size_t QuanLy::SoNhanVien() {
	return count_QL;
};

void XuatMang(QuanLy QuanLy_t[]) {
	cout << "Danh sach nhan vien quan li:" << endl;
	size_t n = QuanLy::SoNhanVien();
	for (size_t i = 0; i < n; i++)
	{
		cout << "STT: " << i + 1 << endl;
		QuanLy_t[i].Xuat();
		cout << endl;
		TongTienLuong_QL += QuanLy_t[i].TinhLuong();
	}
};

float TongLuong_QL() {
	return TongTienLuong_QL;
};

void TimKiem(QuanLy QuanLy_t[]) {
	string ten_t;
	cout << "Nhap ten nguoi cam tim: ";
	cin.ignore();
	getline(cin, ten_t);
	size_t n = QuanLy::SoNhanVien();
	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(QuanLy_t[i].HoTen_v().c_str(), ten_t.c_str()) == 0)
		{
			QuanLy_t[i].Xuat();
			cout << endl;
		}
	}
};

QuanLy::~QuanLy() {
	HeSoChucVu = 0;
	Thuong = 0;
};