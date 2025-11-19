#include "NVVanPhong.h"
#include "NVSanXuat.h"
#include "QuanLy.h"
#include <typeinfo>
#include <numeric>
#include <vector>
#pragma once

class CongTy : public QuanLy, public NVSanXuat, public NVVanPhong
{
private:
	vector<QuanLy> NhanVienQuanLy;
	vector<NVSanXuat> NhanVienSanXuat;
	vector<NVVanPhong> NhanVienVanPhong;
	vector<NhanVien*> DSNhanVien;
	vector<float> LuongCongTy;
public:
	CongTy();
	string TenNhanVien();
	void Nhap();
	float TongLuongCongTy();
	void TimKiemNhanVien();
	void Xuat();
	~CongTy();
};