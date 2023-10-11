#include <iostream>
using namespace std;
void nhapmang(int a[], int& n)
{
	do {
		cout << "\n So luong phan tu mang:";
		cin >> n;
	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		cout << "\na[“<<i<<”]=";
		cin >> a[i];
	}
}
void hoanvi(int& x, int& y)
{
	int tam = x;
	x = y;
	y = tam;
}
void BubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				hoanvi(a[j], a[j - 1]);
}
void xuatmang(int a[], int n)
{
	cout << "Mang a sau khi sap tang : \n";
	for (int i = 0; i < n; i++)
		cout << a[i];
}
void main()
{
	int a[100], n;
	nhapmang(a, n);
	BubbleSort(a, n);
	xuatmang(a, n);
	system("pause");
}