#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

template<typename T>
void xuat(T vct) {
	for (size_t i = 0; i < vct.size(); i++)
	{
		cout << vct[i];
	}
}

class emailminlen : public runtime_error
{
public:
	emailminlen() : runtime_error("\n Email phai co it nha 8 ki tu!\n") {};
};

class emailmaxlen :  public runtime_error
{
public:
	emailmaxlen() : runtime_error("\n Email chi duoc  co nhieu nhat 24 ki tu\n") {};
};

class LessThanZero : public runtime_error
{
public:
	LessThanZero() : runtime_error("\n So duoc nhap be hon 0\n") {};
};

int main() {
	/*int x;
	cout << "Nhap mot so lon hon 0: ";
	cin >> x;
	try
	{
		if (x<0)
		{
			throw LessThanZero();
		}
	}
	catch (const LessThanZero& exception)
	{
		cout << exception.what();
	}*/
	string email; // EMAIL
	vector<char> Emailinput;
	cout << "Nhap va email cua ban: ";
	cin >> email;
	copy(email.begin(), email.end(), back_inserter(Emailinput));
	xuat(Emailinput);
	try
	{
		if (Emailinput.size() < 8)
		{
			throw emailminlen();
		}

		if (Emailinput.size() > 24)
		{
			throw emailmaxlen();
		}
	}
	catch (const emailminlen& A)
	{
		cout << A.what();
	}
	catch (const emailmaxlen& exception)
	{
		cout << exception.what();
	}
	system("pause");
	return 0;
}