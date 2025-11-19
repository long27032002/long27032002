#include "CongTy.h"

CongTy::CongTy() {};

void CongTy::Nhap() {
	int lua_chon;
	while (true)
	{
		cout << "----------MENU----------" << endl;
		cout << "1. Nhap thong tin nhan vien quan ly." << endl;
		cout << "2. Nhap thong tin nhan vien san xuat." << endl;
		cout << "3. Nhap thong tin nhan vien van phong." << endl;
		cout << "4. Thoat." << endl;
		cout << "Nhap lua chon: ";
		cin >> lua_chon;
		switch (lua_chon)
		{
		case 1: {
			cout << "Ban dang nhap nhan vien quan li: " << endl;
			NhanVien* temp = new QuanLy;
			temp->Nhap();
			DSNhanVien.push_back(temp);
			LuongCongTy.push_back(((QuanLy*)temp)->TinhLuong());
			break;
		}
		case 2: {
			cout << "Ban dang nhap thong tin nhan vien san xuat: " << endl;
			NhanVien* temp = new NVSanXuat;
			temp->Nhap();
			DSNhanVien.push_back(temp);
			LuongCongTy.push_back(((NVSanXuat*)temp)->TinhLuong());
			break;
		}
		case 3: {
			cout << "Ban dang nhap nhan vien van phong: " << endl;
			NhanVien* temp = new NVVanPhong;
			temp->Nhap();
			DSNhanVien.push_back(temp);
			LuongCongTy.push_back(((NVVanPhong*)temp)->TinhLuong());
			break;
		}
		case 4: {
			goto end;
			break;
		}
		default: {
			cout << "Ban da nhap sai lua chon\nXin moi nhap lai!";
			break;
		}
		}
	}
	end:;
};

void CongTy::TimKiemNhanVien() {
	string Ten_v;
	bool kiemtra = false;
	int count_v = 0;
	cout << "Nhap ten nhan vien can tim: ";
	cin.ignore();
	getline(cin, Ten_v);
	for (size_t i = 0; i < DSNhanVien.size(); i++)
	{
		if (DSNhanVien[i]->HoTen_v() == Ten_v)
		{
			DSNhanVien[i]->Xuat();
			kiemtra = true;
			count_v++;
		}
	}
	if (kiemtra == false)
	{
		cout << "Khong co nhan vien nao ten \"" << Ten_v << "\"." << endl;
	}
	else {
		cout << "Co tat ca " << count_v << " nhan vien co ten \"" << Ten_v << "\"." << endl;
	}
};

float CongTy::TongLuongCongTy() {
	return accumulate(LuongCongTy.begin(), LuongCongTy.end(), 0);
};

void CongTy::Xuat() {
	cout << "----------Danh sach nhan vien cua cong ty----------" << endl;
	for (size_t i = 0; i < DSNhanVien.size(); i++)
	{
		DSNhanVien[i]->Xuat();
		cout << endl;
	}
	//int count=0;
	//count = QuanLy::SoNhanVien() + NVSanXuat::SoNhanVien() + NVVanPhong::SoNhanVien();
	cout << "**Cong ty co tat ca " << DSNhanVien.size() << " nhan vien." << endl;
};

CongTy::~CongTy() {};