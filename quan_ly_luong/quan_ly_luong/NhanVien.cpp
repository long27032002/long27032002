#include "NhanVien.h"

float NhanVien::LuongCoBan = 1000000;

NhanVien::NhanVien() {};

void NhanVien::Nhap() {
	cout << "Nhap ho va ten: ";
	cin.ignore();
	getline(cin, HoTen);
	cout << "Nhap ngay sinh: ";
	cin.ignore();
	getline(cin, NgaySinh);
};

string NhanVien::HoTen_v() {
	return HoTen;
};

string NhanVien::NgaySinh_v() {
	return NgaySinh;
};

void NhanVien::Xuat() {
	cout << "Ho va ten: " << HoTen << endl;
	cout << "Ngay sinh: " << NgaySinh << endl;
	cout << "Muc luong co ban: " << (size_t)LuongCoBan << endl;
};

NhanVien::~NhanVien() {};
