#include<iostream>
#include<conio.h>
using namespace std;
# define MAX 100
void init(int a[], int& sp);
int Push(int a[], int& sp, int x);
int Pop(int a[], int& sp, int& x);
int isFull(int a[], int sp);
int isEmpty(int a[], int sp);
void xuat(int a[], int sp);
int thapsangnhi(int a[], int& sp, int tp);
int main()
{
	int a[MAX];
	int sp; // đỉnh stack
	int chon, x, in = 0;
	int tp;
	do {
		system("cls");
		cout << "1.Khoi tao stack \n2.Them 1 phan tu vao stack\n3.Lay 1 phan tu\n4.Kiem tra day\n5.Kiem tra rong\n6.Xuat phan tu tu stack\n"
			<< "7.Thap sang nhi\n8.Thoat\nBan chon :	"; cin >> chon;
		switch (chon)
		{
		case 1:
			in = 1;
			init(a, sp);
			cout << "Khoi tao thanh cong \n";
			break;
		case 2:
			if (in)
			{
				cout << "Nhap gia tri vao stack\n";
				cin >> x;
				if (Push(a, sp, x))
					cout << "Them thanh cong\n";
				else
					cout << "Them ko thanh cong\n";
			}
			else
			{
				cout << "Khoi tao stack\n";
			}
			break;
		case 3:
			if (in)
			{
				if (Pop(a, sp, x))
					cout << "Phan tu vua lay ra tu stack " << x << endl;
				else
					cout << "Lay phan tu ko thanh cong\n";
			}
			else
			{
				cout << "Khoi tao stack\n";
			}
			break;
		case 4:
			if (in)
			{
				if (isFull(a, sp))
					cout << "Stack day\n " << x << endl;
				else
					cout << "Stack chua day\n";
			}
			else
			{
				cout << "Khoi tao stack\n";
			}
			break;
		case 5:
			if (in)
			{
				if (isEmpty(a, sp))
					cout << "Stack rong\n " << x << endl;
				else
					cout << "Stack co phan tu\n";
			}
			else
			{
				cout << "Khoi tao stack\n";
			}
			break;
		case 6:
			if (in)
			{
				if (!isEmpty(a, sp))
				{
					cout << "Cac phan tu trong stack : ";
					xuat(a, sp);
				}
				else
					cout << "Stack rong\n";
			}
			else
				cout << "Stack chua khoi tao\n";
			break;
		case 7:
			if (in)
			{
				cout << "Nhap phan tu muon chuyen sang nhi phan : "; cin >> x;
				int np = thapsangnhi(a, sp, x);
				if (np == INT_MIN)
					cout << "Ko chuyen dc sang nhi phan \n";
				else
					cout << "Nhi phan la : " << thapsangnhi(a, sp, x) << endl;
			}
			else
				cout << "Stack chua khoi tao\n";
			break;
		default:
			cout << "Thoat\n";
			break;
		}
		_getch();
	} while (chon >= 1 && chon <= 7);
}
void init(int a[], int& sp)
{
	sp = -1;
}
int Push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int& sp, int& x)
{
	if (sp != -1) // khi stack khác rỗng
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
void xuat(int a[], int sp)
{
	for (int i = sp; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int thapsangnhi(int a[], int& sp, int tp)
{
	init(a, sp);
	while (tp != 0)
	{
		int tmp = tp % 2;
		if (!Push(a, sp, tmp))
		{
			return INT_MIN;
		}
		tp /= 2;
	}
	int np = 0;
	while (!isEmpty(a, sp))
	{
		int so;
		if (!Pop(a, sp, so))
			return INT_MIN;
		np = np * 10 + so;
	}
	return np;
}
