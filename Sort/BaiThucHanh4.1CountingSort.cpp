#include<iostream>
using namespace std;
void nhapmang(int a[], int& n, int& k);
void countingsort(int a[], int b[], int k, int n, int& kt);
void xuatmang(int b[], int kt);
void countingsort_giamdan(int a[], int b[], int k, int n, int& kt);
int main()
{
	int n, k = 0, kt;
	int a[100];
	int b[100];
	nhapmang(a, n, k);
	countingsort(a, b, k, n, kt);
	xuatmang(b, kt);
	countingsort_giamdan(a, b, k, n, kt);
	xuatmang(b, kt);
	system("pause");
}
void nhapmang(int a[], int& n, int& k)
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
void countingsort(int a[], int b[], int k, int n, int& kt)
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
	for (j = 0; j <= k; j++)
	{
		while (c[j] > 0)
		{
			b[kt++] = j;
			c[j]--;
		}
	}
	delete[]c;
}
void xuatmang(int b[], int kt)
{
	cout << "Mang a sau khi sap xep:\n";
	for (int i = 0; i < kt; i++)
		cout << b[i] << " ";
	cout << endl;
}
void countingsort_giamdan(int a[], int b[], int k, int n, int& kt)
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
	for (j = k; j >= 0; j--)
	{
		while (c[j] > 0)
		{
			b[kt++] = j;
			c[j]--;
		}
	}
	delete[]c;
}