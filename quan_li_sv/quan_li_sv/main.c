#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#pragma warning(disable:4996)


typedef enum {
	ID,
	NAME,
} type;

typedef struct {
	char mssv[11];
	char hoten[30];
	char ngaysinh[11];
	int gt;
	char lop[10];
	char khoa[10];
} sinhvien_t;

sinhvien_t* dssv;

sinhvien_t input() {
	sinhvien_t tmp;
	printf("Nhap mssv: ");
	fflush(stdin);
	fgets(tmp.mssv, sizeof(tmp.mssv), stdin);
	printf("Nhap ho va ten: ");
	fflush(stdin);
	fgets(tmp.hoten, sizeof(tmp.hoten), stdin);
	printf("Nhap ngay sinh: ");
	fflush(stdin);
	fgets(tmp.ngaysinh, sizeof(tmp.ngaysinh), stdin);
	printf("Gioi tinh:(nam:1/nu:0) ");
	scanf_s("%d", &tmp.gt);
	printf("Nhap lop: ");
	//fflush(stdin);
	_flushall();
	fgets(tmp.lop, sizeof(tmp.lop), stdin);
	printf("Nhap khoa: ");
	fflush(stdin);
	fgets(tmp.khoa, sizeof(tmp.khoa), stdin);
	return tmp;
}

int _size() {
	return sizeof(*dssv) / sizeof(sinhvien_t);
}

void Add(sinhvien_t tmp, unsigned p) {
	for (size_t i = 0; i < _size(); i++)
	{
		if (strcmp(tmp.mssv, *(dssv + i)->hoten) == 0) {
			abort();
		}
	}
	if (p == 0)
	{
		dssv = (sinhvien_t*)realloc(dssv, (_size() + 1));
		*(dssv + (_size() - 1)) = tmp;
	}
	else if (p < 0 && p < _size()) {
		dssv = (sinhvien_t*)realloc(dssv, (_size() + 1));
		int i;
		for (i = p; i < _size() - 2; i++)
		{
			*(dssv + i + 1) = *(dssv + i);
			*(dssv + p) = tmp;
		}
	}
}

void remove_v(const char str) {
	for (size_t i = 0; i < _size(); i++)
	{
		if (strcmp(str, *(dssv + i)->mssv) == 0) {
			for (size_t j = i;  j < _size()-1;  j++)
			{
				*(dssv + j) = *(dssv + j + 1);
			}
			abort(0);
		}
	}
}

void remove_t(unsigned int p) {
	for (size_t j = p; j < _size() - 1; j++)
	{
		*(dssv + j) = *(dssv + j + 1);
	}
}

sinhvien_t search(const char str) {
	int mem = 0, ch = 0;
	for (size_t i = 0; i < _size(); i++)
	{
		if (strcmp((dssv+i)->mssv, str) == 0)
		{
			mem = i;
		}
		else if (strcmp((dssv + i)->hoten, str) == 0)
		{
			ch = i;
		}
	}
	if (mem)
	{
		return *(dssv + mem);
	}
	else if (ch) {
		return *(dssv + ch);
	}
	else {
		printf("Khong tim thay sinh vien hop le!\n");
		sinhvien_t tmp = { "", "", "", 0, "", "" };
		return tmp;
	}
}

void print() {
	for (size_t i = 0; i < _size(); i++)
	{
		printf("\n*****  Danh sach sinh vien  *****\n");
		printf("---------------------------------\n");
		printf("MSSV: %s\n", (dssv + i)->mssv);
		printf("Ho ten: %s\n", (dssv + i)->hoten);
		printf("Ngay/thang/nam sinh: %s\n", (dssv + i)->ngaysinh);
		if ((dssv + i)->gt)
		{
			printf("Gioi tinh: nam\n");
		}
		else {
			printf("Gioi tinh: nu\n");
		}
		printf("Lop: %s\n", (dssv + i)->lop);
		printf("Khoa: %s\n", (dssv + i)->khoa);
		printf("---------------------------------\n");
	}
}

int main() {
	dssv = (sinhvien_t*)malloc(sizeof(sinhvien_t));
	*dssv = input();
	print();
}