#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

enum class TYPE {
	ID = 0,
	NAME = 1,
};

struct ngaysinh
{
	int ngay;
	int thang;
	int nam;

	ngaysinh() {
		ngay = 0;
		thang = 0;
		nam = 0;
	};

	ngaysinh(const int a, const int b, const int c) {
		ngay = a;
		thang = b;
		nam = c;
	};

	void print() const {
		if (ngay < 10)
		{
			cout << "0" << ngay;
		}
		else
		{
			cout << ngay;
		}
		if (thang < 10)
		{
			cout << ".0" << thang;
		}
		else {
			cout << "." << thang;
		}
		cout << "." << nam;
	}

	~ngaysinh() {
		ngay = 0;
		thang = 0;
		nam = 0;
	};
};

class sinhvien
{
public:
	string MSSV;
	string hoten;
	ngaysinh ns;
	string gioitinh;
	string tenlop;
	string khoa;
public:
	sinhvien() {};
	string lay_mssv();
	string lay_ten();

	~sinhvien() {};
};

string sinhvien::lay_mssv() {
	return MSSV;
};

string sinhvien::lay_ten() {
	return hoten;
};

class DSsinhvien : public sinhvien
{
private:
	vector<sinhvien> dssv;
public:
	DSsinhvien();
	DSsinhvien(const string mssv_t, const string hoten_t, ngaysinh ns_t, const string gt, const string lop, const string khoa_t);
	void add(sinhvien&, const size_t);
	bool remove(const string);
	void remove(const size_t);
	sinhvien search(const string);
	size_t number();
	void printf() {
		cout << "**********   Danh sach sinh vien   **********" << endl;
		for (size_t i = 0; i < dssv.size(); i++)
		{
			cout << "MSSV: " << (dssv.begin()+i)->MSSV << endl;
			cout << "Ho va ten: " << dssv[i].hoten << endl;
			cout << "Ngay sinh: "; dssv[i].ns.print();
			cout << "Gioi tinh: " << dssv[i].gioitinh << endl;
			cout << "Lop: " << dssv[i].tenlop << endl;
			cout << "Khoa: " << dssv[i].khoa << endl;
			cout << "----------------------------------" << endl;
		}
	};
	friend ostream& operator <<(ostream& os, const DSsinhvien);
	void save(const string);
	void load(const string);
	void sort(TYPE);
	~DSsinhvien();
};

DSsinhvien::DSsinhvien()
{
}

DSsinhvien::~DSsinhvien()
{
}


DSsinhvien::DSsinhvien(const string mssv_t, const string hoten_t, ngaysinh ns_t, const string gt, const string lop, const string khoa_t) {
	MSSV = mssv_t;
	hoten = hoten_t;
	ns = ns_t;
	gioitinh = gt;
	tenlop = lop;
	khoa = khoa_t;
};

void DSsinhvien::add(sinhvien& sv_t, const size_t p) {
	for (auto i = dssv.begin(); i <= dssv.end(); i++)
	{
		if (i->lay_mssv() == sv_t.lay_mssv())
		{
			return;
		}
	}

	if (p==0)
	{
		dssv.push_back(sv_t);
	}
	else if (p <= dssv.size() + 1)
	{
		dssv.insert(dssv.begin() + p - 1, sv_t);
	}
};
bool DSsinhvien::remove(const string mssv_t) {
	auto i = dssv.begin();
	for (; i <= dssv.end(); i++)
	{
		if (i->lay_mssv() == mssv_t)
		{
			return false;
		}
	}
	if (dssv.back().lay_mssv() == mssv_t)
	{
		dssv.pop_back();
	}
	else if (i == dssv.end()) {
		return false;
	}
	else
	{
		dssv.erase(i);
	}
	return true;
};

void DSsinhvien::remove(const size_t p) {
	dssv.erase(dssv.begin() + p - 1);
};

sinhvien DSsinhvien::search(const string s) {
	if (dssv.back().lay_mssv() == s || dssv.back().lay_ten() == s)
	{
		return dssv.back();
	}
	else {
		for (auto i = dssv.begin(); i <= dssv.end(); i++)
		{
			if (i->lay_mssv() == s)
			{
				return *i;
				break;
			}
		}
	}
};

size_t DSsinhvien::number() {
	return dssv.size();
}

ostream& operator << (ostream& os, const DSsinhvien dssv_t) {
	os << "**********   Danh sach sinh vien   **********" << endl;
	for (size_t i = 0; i < dssv_t.dssv.size(); i++)
	{
		cout << "MSSV: " << (dssv_t.dssv.begin() + i)->MSSV << endl;
		cout << "Ho va ten: " << dssv_t.dssv[i].hoten << endl;
		cout << "Ngay sinh: "; dssv_t.dssv[i].ns.print();
		cout << "Gioi tinh: " << dssv_t.dssv[i].gioitinh << endl;
		cout << "Lop: " << dssv_t.dssv[i].tenlop << endl;
		cout << "Khoa: " << dssv_t.dssv[i].khoa << endl;
		cout << "----------------------------------" << endl;
	}
	return os;
};

void DSsinhvien::save(const string) {
};

void DSsinhvien::load(const string) {
};

void DSsinhvien::sort(TYPE type_t) {
	if (type_t == TYPE::ID)
	{
		sinhvien tmp;
		for (auto i = dssv.begin(); i <= dssv.end(); i++)
		{
			for (auto j = i+1; j <= dssv.end(); j++)
			{
				if (i->MSSV > j->MSSV)
				{
					tmp = *i;
					*i = *j;
					*j = tmp;
				}
			}
		}
	} 
	else if (type_t == TYPE::NAME)
	{
		sinhvien tmp;
		for (auto i = dssv.begin(); i <= dssv.end(); i++)
		{
			for (auto j = i + 1; j <= dssv.end(); j++)
			{
				if (i->hoten > j->hoten)
				{
					tmp = *i;
					*i = *j;
					*j = tmp;
				}
			}
		}
	}
	else {
		return;
	}
};


int main() {

}