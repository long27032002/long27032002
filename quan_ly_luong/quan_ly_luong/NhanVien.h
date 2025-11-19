#include <iostream>
#include <string>
#pragma once
using namespace std;

class NhanVien
{
private:
	friend class QuanLy;
protected:
	string HoTen;
	string NgaySinh;
	float Luong;
	static float LuongCoBan;
public:
	NhanVien();
	virtual void Nhap();
	string HoTen_v();
	string NgaySinh_v();
	virtual void Xuat();
	~NhanVien();
};

