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
void InterchangeSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
				hoanvi(a[i], a[j]);
}
void xuatmang(int a[], int n)
{
	cout << "Mang a sau khi sap tang : \n";
	for (int i = 0; i < n; i++)
		cout << a[i];
}
int main()
{
	int a[100], n;
	nhapmang(a, n);
	InterchangeSort(a, n);
	xuatmang(a, n);
	system("pause");
}