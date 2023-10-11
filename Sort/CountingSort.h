#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Countingsort
{
public:
	int getn();
	void input();
	void output();
	void Sort(int kq[], int n);
	void Sort_DES(int kq[], int n);
private:
	int a[100];
	int n;
	int k;
	int kt;
};
int Countingsort::getn()
{
	return n;
}
void Countingsort::input()
{
	do {
		cout << "So luong phan tu mang: ";
		cin >> n;
	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (k < a[i])
			k = a[i];
	}
}
void Countingsort::output()
{
	cout << "Mang a sau co cac gia tri sau :\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void Countingsort::Sort(int kq[], int n)
{
	int i, j;
	int* c = new int[k + 1];
	for (i = 0; i <= k; i++)
	{
		c[i] = 0;
	}
	for (j = 0; j < n; j++)
	{
		c[a[j]]++;
	}
	int kt = 0;
	for (j = 0; j <= k; j++)
	{
		while (c[j] > 0)
		{
			kq[kt++] = j;
			c[j]--;
		}
	}
	delete[]c;
}
void Countingsort::Sort_DES(int kq[], int n)
{
	int i, j;
	int* c = new int[k + 1];
	for (i = 0; i <= k; i++)
	{
		c[i] = 0;
	}
	for (j = 0; j < n; j++)
	{
		c[a[j]]++;
	}
	kt = 0;
	for (j = k; j >=0 ; j--)
	{
		while (c[j] > 0)
		{
			kq[kt++] = j;
			c[j]--;
		}
	}
	delete[]c;
}