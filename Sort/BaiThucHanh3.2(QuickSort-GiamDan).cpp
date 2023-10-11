#include <iostream>
#include<conio.h>
#include <time.h>
#include <fstream>
using namespace std;
#define MAX 100
void nhapmang(int a[], int& n);
void xuatmang(int a[], int n);
void QuickSort(int a[], int left, int right);
void hoanvi(int& x, int& y);
int main()
{
	int a[MAX], n, left, right;
	nhapmang(a, n);
	left = 0;
	right = n - 1;
	QuickSort(a, left, right);
	xuatmang(a, n);
	system("pause");
}
void nhapmang(int a[], int& n)
{
	do {
		cout << "So luong phan tu mang : ";
		cin >> n;
	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
void hoanvi(int& x, int& y)
{
	int tam = x;
	x = y;
	y = tam;
}

void QuickSort(int a[], int left, int right)
{
	int i, j, x;
	x = a[(left + right) / 2]; //Chọn phần tử giữa làm giá trị mốc
	i = left;
	j = right;
	while (i <= j)
	{
		while (a[i] > x) i++;
		while (a[j] < x) j--;
		if (i <= j) {
			hoanvi(a[i], a[j]); //đổi chỗ a[i] và a[j]
			i++; j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}
void xuatmang(int a[], int n)
{
	cout << "Mang a sau khi sap giam dan : \n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}