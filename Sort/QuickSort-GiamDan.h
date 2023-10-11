#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class QuickSort
{
public:
	int getn();
	void input();
	void output();
	void Sort(int left, int right);
	void Sort_GiamDan(int left, int right);

private:
	int a[200];
	int n;
};
int QuickSort::getn()
{
	return n;
}
void QuickSort::input()
{
	do
	{
		cout << "Nhap so luong phan tu\n";
		cin >> n;
		if (n <= 0 || n > 200)
			cout << "Nhap lai \n";
	} while (n <= 0 || n > 200);
	cout << "Nhap " << n << " so nguyen : ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void QuickSort::output()
{
	cout << "Mang : ";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]" << a[i] << endl;
	}
}
void QuickSort::Sort(int left, int right)
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
		Sort(left, j);
	if (i < right)
		Sort(i, right);
}
void hoanvi(int& x, int& y)
{
	int tam = x;
	x = y;
	y = tam;
}
