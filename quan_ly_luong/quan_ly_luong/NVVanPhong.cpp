#include "NhanVien.h"
#include "NVVanPhong.h"
#define TienLuongMotNgay 100000

size_t NVVanPhong::count_VP = 0;
float TongTienLuong_VP = 0;

NVVanPhong::NVVanPhong() {};

void NVVanPhong::Nhap()  {
	NhanVien::Xuat();
	cout << "Nhap so ngay lam viec: ";
	cin >> SoNgayLamViec;
	cout << "Nhap so tien tro cap: ";
	cin >> TroCap;
};

float NVVanPhong::TinhLuong() {
	return Luong = LuongCoBan + SoNgayLamViec * TienLuongMotNgay;
};

string NVVanPhong::HoTen_t() {
	return HoTen;
};

void NVVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "So ngay lam viec: " << SoNgayLamViec << endl;
	cout << "So tien tro cap: " << (size_t)TroCap << endl;
	cout << "Tien luong: " << (size_t)NVVanPhong::TinhLuong() << endl;
};

size_t NVVanPhong::SoNhanVien() {
	return count_VP;
};

void XZuatMang(NVVanPhong NVVanPhong_t[]) {
	cout << "Danh sach nhan vien san xuat:" << endl;
	size_t n = NVVanPhong::SoNhanVien();
	for (size_t i = 0; i < n; i++)
	{
		cout << "STT: " << i + 1 << endl;
		NVVanPhong_t[i].Xuat();
		cout << endl;
		TongTienLuong_VP += NVVanPhong_t[i].TinhLuong();
	}
};

float TongLuong_VP() {
	return TongTienLuong_VP;
};

void TimKiem_VP(NVVanPhong NVVanPhong_t []) {
	string ten_t;
	cout << "Nhap ten nguoi can tim: ";
	cin.ignore();
	getline(cin, ten_t);
	size_t n = NVVanPhong::SoNhanVien();
	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(NVVanPhong_t[i].HoTen_v().c_str(), ten_t.c_str()) == 0)
		{
			NVVanPhong_t[i].Xuat();
			cout << endl;
		}
	}
};

NVVanPhong::~NVVanPhong() {};