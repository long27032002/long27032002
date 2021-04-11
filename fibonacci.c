#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() 
{
	int a, b, n=1;

	printf("Chuong trinh tinh cac so fibonacci trong 1 khoang:\n");
	printf("Nhap 2 so nguyen cua khoang gia tri:\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("Cac so Fibonacci trong khoang (%d;%d) la:\n",a ,b);
	
	while (1)
	{
		n++;
		if (a < Fibonacci(n) && Fibonacci(n)<b)
		{
			printf("%d\n", Fibonacci(n));
		}
	   1
	}
	printf("Xin cam on!!!");
	return 0;
}
