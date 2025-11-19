#include "NVSanXuat.h"
#define DonGia 2000

size_t NVSanXuat::count_SX = 0;
float TongTienLuong_SX = 0;

NVSanXuat::NVSanXuat() {
	count_SX++;
};

void NVSanXuat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so san pham: ";
	cin >> SoSanPham;
};

float NVSanXuat::TinhLuong() {
	return Luong = LuongCoBan + SoSanPham * DonGia;
};

string NVSanXuat::Hoten_t() {
	return HoTen;
};

size_t NVSanXuat::SoNhanVien() {
	return count_SX;
};

void NVSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "So san pham san xuat: " << SoSanPham << endl;
	cout << "Tien luong: " << (size_t)NVSanXuat::TinhLuong() << "vnd" << endl;
};

void XuatMang(NVSanXuat NVSanXuat_t[]) {
	cout << "Danh sach nhan vien san xuat:" << endl;
	size_t n = NVSanXuat::SoNhanVien();
	for (size_t i = 0; i < n; i++)
	{
		cout << "STT: " << i + 1 << endl;
		NVSanXuat_t[i].Xuat();
		cout << endl;
		TongTienLuong_SX += NVSanXuat_t[i].TinhLuong();
	}
};

float TongLuong_SX() {
	return TongTienLuong_SX;
};

void TimKiem_SX(NVSanXuat NVSanXuat_t[]) {
	string ten_t;
	cout << "Nhap ten nguoi cam tim: ";
	cin.ignore();
	getline(cin, ten_t);
	size_t n = NVSanXuat::SoNhanVien();
	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(NVSanXuat_t[i].HoTen_v().c_str(), ten_t.c_str()) == 0)
		{
			NVSanXuat_t[i].Xuat();
			cout << endl;
		}
	}
};

NVSanXuat::~NVSanXuat() {};