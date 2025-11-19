#include "NhanVien.h"
#pragma once

class NVSanXuat : public NhanVien
{
private:
	int SoSanPham;
	static size_t count_SX;
	static float TongTienLuong_SX;
public:
	NVSanXuat();
	void Nhap();
	float TinhLuong();
	void Xuat();
	string Hoten_t();
	static size_t SoNhanVien();
	~NVSanXuat();
};

void TimKiem_SX(NVSanXuat[]);
float TongLuong_SX();
void XuatMang(NVSanXuat []);