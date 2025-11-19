#include "NhanVien.h"
#pragma once

class QuanLy : public NhanVien
{
private:
	float HeSoChucVu;
	float Thuong;
	static size_t count_QL;
	static float TongTienLuong_QL;
public:
	QuanLy();
	void Nhap();
	string HoTen_v();
	string NgaySinh_v();
	float HeSoChucVu_v();
	float Thuong_v();
	float TinhLuong();
	static size_t SoNhanVien();
	void Xuat();
	~QuanLy();
};

void TimKiem_QL(QuanLy []);
float TongLuong_QL();
void XuatMang(QuanLy []);