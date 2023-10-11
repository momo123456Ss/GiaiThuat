//Bài 1. Quản lý một danh sách có tối đa 100 phần tử, mỗi phần tử trong danh sách có kiểu int.
//(danh sách không có thứ tự)
//a.Khai báo cấu trúc danh sách
//b.Viết thủ tục nhập danh sách.
//c.Viết thủ tục xuất danh sách ra màn hình
//d.Viết thủ tục tìm một phần tử trong danh sách.Tính độ phức tạp của thuật toán
//e.Viết thủ tục thêm một phần tử vào cuối danh sách.
//f.Viết thủ tục xoá phần tử cuối danh sách.
//g.Viết thủ tục xoá phàn tử tại vị trí thứ i trong danh sách.Tính độ phức tạp của thuật toán
//h.Viết thủ tục thêm một phần tử vào danh sách tại vị trí i.Tính độ phức tạp của thuật toán.
//i.Tìm một phần tử trong danh sách.Nếu tìm thấy, xoá phần tử đó.Tính độ phức tạp của thuật toán.


//Làm theo danh sách đặc

#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int a[MAX];
void input(int& n);
void output(int n);
void timkiem(int phantu, int n);
void themvaocuoi(int phantu, int n);
int search(int x,int n);
void insert_last(int x, int& n);
void delete_last(int& n);
void delete_i(int vitri, int& n);
void insert_i(int vitri, int x, int& n);
int search_X(int x, int n, int vitri);
void delete_X(int x, int vitri, int& n);
int main()
{
	int chon, n,phantu,x;
	int a[MAX];
	int vitri=0;
	bool in = false;
	do
	{
		system("cls");
		cout << "1.Nhap mang\n"
			<< "2.Xuat mang\n"
			<< "3.Tim kiem\n"
			<< "4.Them cuoi\n"
			<< "5.Xoa cuoi\n"
			<< "6.Xoa tai vi tri thu i\n"
			<< "7.Them vao tai vi tri thu i\n"
			<< "8.Tim  va xoa\n"
			<< "9.Thoat\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			input(n);
			in = true;
			break;
		case 2:
			if (in)
			{
				output(n);
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 3:
			if (in)
			{/*
				cout << "Nhap phan tu muon tim kiem : "; cin >> phantu;
				timkiem(phantu,n);*/
				cout << "Nhap gia tri can tim : "; cin >> x;
				if (search(x,n))
					cout << "Phan tu co trong danh sach\n";
				else
				{
					cout << "Mang ko co \n";
				}
				cin.ignore();
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 4:
			if (in)
			{
				cout << "Nhap phan tu can them vao cuoi  : "; cin >>  x;
				insert_last(x,n);
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 5:
			if (in)
			{
				delete_last(n);
				cout << "Xoa thanh cong !!!" << endl;
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 6:
			if (in)
			{
				cout << "Nhap vi tri muon xoa : "; cin >> vitri;
				delete_i(vitri, n);

			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 7:
			if (in)
			{
				cout << "Nhap vi tri muon them : "; cin >> vitri;
				cout << "Nhap phan tu muon them : "; cin >> x;
				insert_i(vitri, x,n);

			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 8:
			if (in)
			{
				cout << "Nhap phan tu muon xoa : "; cin >> x;
				delete_X(x,vitri,n);

			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		}
		_getch();
		cin.ignore();
	} while (chon>=1 && chon<=8);
}
void input(int& n)
{
	do {
		cout << "Nhap so luong phan tu : "; cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap sai!!" << endl;
	} while (n <= 0 || n > MAX);
		cout << "Nhap " << n << " so nguyen: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void output(int n)
{
	cout << "Mang dang luu tru : ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void timkiem(int phantu, int n)
{
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (phantu == a[i])
		{
			check = true;
		}
	}
	if (check)
	{
		cout << "Co phan tu " << phantu << " trong danh sach\n";
	}
	else
	{
		cout << "Ko tim thay \n";
	}
}
int search(int x,int n)//co x xuat hien tra ve 1 , ko co tra ve 0
{
	int i = 0;
	while (i<n && a[i] !=x)
	{
		i++;
	}
	if (i < n)
		return 1;
	return 0;
}
void insert_last(int x,int &n)
{
	a[n++] = x;
}
void delete_last(int& n)
{
	if (n == MAX)
	{
		cout << "Xoa ko thanh cong\n";
	}
	n--;
}
void delete_i(int vitri, int& n)
{
	for (int i = vitri; i < n; i++)
	{
		a[i] = a[i + 1];
		n--;
		break;
	}
}
void insert_i(int vitri, int x, int& n)
{
	n++;
	for (int i = n-1; i > vitri; i--)
	{
		a[i] = a[i - 1];
	}
	a[vitri] = x;
}
void delete_X(int x, int vitri, int& n)
{

	for (int i = search_X(x, n, vitri); i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
int search_X(int x, int n,int vitri)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
		vitri = i;
	}
		 return vitri;
}