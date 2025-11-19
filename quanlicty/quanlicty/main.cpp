#include <iostream>
#include <string>
#include <vector>
#define luong_co_ban 1499000.0
using namespace std;

typedef enum
{
	khong_chuc_vu,
	Giam_doc,
	Truong_phong,
	Nhan_vien,
} ChucVu;

struct NhanVien
{
	string Ho_Ten;
	size_t tuoi;
	ChucVu chuc_vu;
	float hesoluong;

	NhanVien() {
		Ho_Ten = "";
		tuoi = 0;
		chuc_vu = ChucVu::khong_chuc_vu;
		hesoluong = 0.0f;
	}

	void nhap() {
		cout << endl << "Nhap ho va ten: ";
		cin.ignore();
		getline(cin, Ho_Ten);
		while (true)
		{
			cout << "Nhap tuoi: ";
			cin >> tuoi;
			if ( tuoi < 20 || tuoi > 100)
			{
				cout << "Nhap lai tuoi nhan vien!!!" << endl;
			}
			else
			{
				break;
			}
		}
		int lua_chon = 0;
		cout << "Chon chuc vu:" << endl;
		cout << "1.Giam doc." << endl;
		cout << "2.Truong phong." << endl;
		cout << "3.Nhan vien." << endl;
		cout << "Nhap lua chon: ";
		cin >> lua_chon;
		switch (lua_chon)
		{
		case 1: {
			chuc_vu = ChucVu::Giam_doc;
			break;
		}

		case 2: {
			chuc_vu = ChucVu::Truong_phong;
			break;
		}

		case 3: {
			chuc_vu = ChucVu::Nhan_vien;
			break;
		}

		default: {
			chuc_vu = ChucVu::khong_chuc_vu;
			break;
		}
		}
		while (true)
		{
			cout << "Nhap he so luong: ";
			cin >> hesoluong;
			if (hesoluong < 0)
			{
				cout << "Vui long nhap he so luong lon hon 0." << endl;
				cout << "Vui long nhap lai!!!" << endl;
			}
			else
			{
				break;
			}
		}
		cout << "Nhap thong tin thanh cong!" << endl;
	}

	void xuat() {
		cout << endl << "Ho va ten: " << Ho_Ten << endl;
		cout << "Tuoi: " << tuoi << endl;
		cout << "Chuc vu: ";
		switch (chuc_vu)
		{
		case ChucVu::khong_chuc_vu: {
			cout << "khong co chuc vu." << endl;
			break;
		}

		case ChucVu::Giam_doc: {
			cout << "Giam doc." <<  endl;
		}

		case ChucVu::Truong_phong: {
			cout << "Truong phong." << endl;
		}

		case ChucVu::Nhan_vien: {
			cout << "Nhan vien." << endl;
		}
		}
		cout << "He so luong: " << hesoluong << endl;
	}

	float luong() {
		float luong = 0.0f;
		switch (chuc_vu)
		{
		case ChucVu::Giam_doc: {
			luong = luong_co_ban * (hesoluong + 0.5);
			break;
		}
		case ChucVu::Truong_phong:
		{
			luong = luong_co_ban * (hesoluong + 0.3);
			break;
		}
		case ChucVu::Nhan_vien: {
			luong = luong_co_ban * (hesoluong + 0.2);
			break;
		}
		default:
			break;
		}
		return luong;
	}

	~NhanVien() {
		Ho_Ten = "";
		tuoi = 0;
		chuc_vu = ChucVu::khong_chuc_vu;
		hesoluong = 0.0f;
	}
};

int main() {
	vector<NhanVien> dsnv;
	size_t soluongnv = 0;
	while (true)
	{
		cout << "Nhap so luong nhan vien: ";
		cin >> soluongnv;
		if (soluongnv < 0)
			cout << "Nhap lai so luong nhan vien!";
		else
			break;
	}

	for (size_t i = 0; i < soluongnv; i++)
	{
		NhanVien nv_t;
		nv_t.nhap();
		dsnv.push_back(nv_t);
	}

	cout << endl << "********** DANH SACH NHAN VIEN **********";
	for (size_t i = 0; i < soluongnv; i++)
	{
		dsnv[i].xuat();
	}
	cout << endl;

	float max = dsnv[0].luong();
	size_t index = 0;
	for (size_t i = 1; i < soluongnv; i++)
	{
		if (max < dsnv[i].luong())
		{
			max = dsnv[i].luong();
			index = i;
		}
	}

	cout << endl << "*****  NHAN VIEN CO MUC LUONG CAO NHAT  *****";
	dsnv[index].xuat();
}