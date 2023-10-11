//Bài 2: Quản lý một danh sách có thứ tự có tối đa 100 phần tử, mỗi phần tử trong danh sách có kiểu
//int.
//a.Khai báo cấu trúc danh sách
//b.Viết thủ tục thêm một phần tử vào danh sách
//c.Viết thủ tục xuất các phần tử trong danh sách
//d.Viết thủ tục tìm một phần tử trong danh sách(dùng phương pháp tìm kiếm tuần tự).Đánh giá
//độ phức tạp của thuật toán.
//e.Viết thủ tục tìm một phần tử trong danh sách(dùng phương pháp tìm kiếm nhị phân).Đánh giá
//độ phức tạp của thuật toán.
//f.Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, xoá phần tử này.
#include <iostream>
#include <conio.h>
using namespace std;
#define MAXSIZE  100
void insert(int a[], int& n, int x);
void input(int a[], int& n);
void output(int a[], int &n);
bool checkArray(int a[], int n);
int Search(int a[], int &n, int x);
int BinarySearch(int a[], int n, int x);
void delete_i(int a[], int& n, int x);
int main()
{
	int n, x,chon;
	int a[MAXSIZE];
	bool in = false;
	do
	{
		system("cls");
		cout<< "1.Nhap mang\n"
			<< "2.Them phan tu\n"
			<< "3.Tim kiem (Tuan Tu)\n"
			<< "4.Tim kiem (Nhi Phan)\n"
			<< "5.Tim phan tu va xoa\n"
			<< "6.Xuat Mang\n"
			<< "7.Thoat\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			do {
				do {
					cout << "Nhap so luong phan tu N : "; cin >> n;
					if (n <= 0 || n > MAXSIZE)
						cout << "Nhap sai!!";
				} while (n <= 0 || n > MAXSIZE);
				input(a, n);
				if (!checkArray(a, n))
				{
					cout << "Mang vua nhap khong co thu tu tang dan " << endl;;
				}
				else
				{
					in = true;
				}
			} while (!in);
			break;
		case 2:
			if (in)
			{
				if (n == MAXSIZE) {
					cout << "Mang day " << endl;
				}
				else {
					cout << "Nhap phan tu muon them : "; cin >> x;
					insert(a, n, x);
					cout << "Mang da them thanh cong.Vui long kiem tra!!" << endl;
				}
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 3:
			if (in)
			{
				cout << "Nhap phan tu muon tim : "; cin >> x;
				cout<<"Vi tri cua "<<x<<" la : "<<Search(a, n, x) <<endl ;
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 4:
			if (in)
			{
				cout << "Nhap phan tu muon tim : "; cin >> x;
				cout << "Vi tri cua " << x << " la : " << BinarySearch(a, n, x) << endl;
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 5:
			if (in)
			{
				cout << "Nhap phan tu muon xoa : "; cin >> x;
				delete_i(a, n, x);
				cout << "Da Xoa !!" << endl;
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		case 6:
			if (in)
			{
				output(a, n);
			}
			else
			{
				cout << "Vui long nhap du lieu cho mang truoc khi thuc hien yeu cau khac\n";
			}
			break;
		}
		_getch();
		cin.ignore();
	} while (chon >= 1 && chon <= 6);
}
void insert(int a[], int& n, int x)
{
	int j = n - 1;
	while (j>=0 && x<a[j])
	{
		a[j + 1] = a[j];
		j--;
	}
	a[j + 1] = x;
}
void input(int a[], int& n)
{
	cout << "Nhap " << n << " so nguyen: ";
	for (int i = 0; i < n; i++)
	{
		
			cin >> a[i];
		
	}
}
bool checkArray(int a[], int n)
{
	//b1 : duyet i = 0 den n - 2 , moi lan duyet thuc hien :
	//so sanh a[i] voi a[i+1].Neu a[i] < a[i+1] thi i++;
	//Nguoc lai a[i] < a[i+1] thi tra ket qua la mang khong tang dan
	//Tra ve ket qua mang tang dan
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}
int Search(int a[], int &n, int x)
{//Tim kiem tuan tu
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i; // x trong danh sách a, và nằm ở vị trí i
	return -1; // không tìm thấy x trong danh sách a;
}
int BinarySearch(int a[], int n, int x)
{//Tim kiem nhi phan
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x) return mid;
		if (x > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1; // không tìm thấy x trong danh sách a;
}
void output(int a[], int &n)
{
	cout << "Mang dang luu tru : ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void delete_i(int a[], int& n,int x)
{
	int vitri = Search(a, n, x);
	if (vitri > -1) {
		for (int i = Search(a, n, x); i < n-1; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
	}
	else
	{
		cout << "Khong tim thay phan tu!!" << endl;
	}
}