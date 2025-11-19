#include "NhanVien.h"
#include <string>
#include <cstring>
#pragma once

class NVVanPhong : public NhanVien
{
private:
	int SoNgayLamViec;
	float TroCap;
	static size_t count_VP;
	static float TongTienLuong_VP;
public:
	NVVanPhong();
	void Nhap();
	float TinhLuong();
	static size_t SoNhanVien();
	string HoTen_t();
	void Xuat();
	~NVVanPhong();
};

void TimKiem_VP(NVVanPhong []);
static float TongLuong_VP();
void XuatMang();