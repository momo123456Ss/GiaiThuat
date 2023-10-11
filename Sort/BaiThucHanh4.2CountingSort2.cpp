#include <iostream>
using namespace std;
struct SanPham
{
	char masp[100];
	char tensp[10];
	int soluong;
};
void input1(SanPham& p, int n,int k);
void inputList(SanPham* list, int n, int k);
void output1(SanPham p);
void outputList(SanPham* list, int n);
void countingSortAsc(SanPham* a, SanPham* b, int n, int k);
int main()
{
	SanPham* ds;
	SanPham* kq;
	SanPham* a;
	int n,k;
	k = 0;
	do
	{
		cout << "Nhap so luong san pham : "; cin >> n;
	} while (n<=0);
	ds = new SanPham[n];
	kq = new SanPham[n];
	inputList(ds, n,k);
	outputList(ds, n);
	k = INT_MIN;
	for (int i = 0; i < n; i++)
		if (ds[i].soluong > k)
			k = ds[i].soluong;
	countingSortAsc(ds, kq, n, k);
	outputList(kq, n);
	delete[]ds;
	delete[]kq;
}
void input1(SanPham &p,int n,int k )
{
	cin.ignore();
	cout << "Nhap ma san pham: ";
	cin.getline(p.masp, 100);
	cout << "Nhap ten san pham: ";
	cin.getline(p.tensp, 100);
	cout << "Nhap so luong: ";
	cin >> p.soluong;
}
void output1(SanPham p)
{
	cout << "Ma san pham : " << p.masp << endl;
	cout << "Ten san pham : " << p.tensp << endl;
	cout << "So luong : " << p.soluong << endl;
}
void inputList(SanPham* list, int n,int k)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin san pham thu " << i << endl;
		input1(*(list + i),n,k);
	}
}
void outputList(SanPham* list, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Xuat thong tin san pham thu " << i << endl;
		output1(list[i]);
	}
}
void countingSortAsc(SanPham* a, SanPham* kq, int n, int k)
{
	SanPham* c = new SanPham[k + 1];
	int* c2 = new int[k + 1];
	for (int i = 0; i <= k; i++)
	{
		c2[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		c2[a[i].soluong]++;
		c[a[i].soluong] = a[i];
	}
	int kt = 0;
	for (int i = 0; i <= k; i++)
	{
		while (c2[i] > 0)
		{
			kq[kt++] = c[i];
			c2[i]--;
		}
	}
	delete[] c;
	delete[]c2;
}
