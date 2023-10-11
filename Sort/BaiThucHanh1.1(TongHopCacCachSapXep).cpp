//Sap xep day so giam dan bang selection,interchange,bubble
//Dao nguoc mang
#include <iostream>
#include<conio.h>
#include <time.h>
#include <fstream>
#define MAX 100
using namespace std;
void inputfile(int a[], int& n);
void nhapmang(int a[], int& n);
void xuatmang(int a[], int n);
void hoanvi(int& x, int& y);
void SelectionSort(int a[], int n);
void SelectionSort_GiamDan(int a[], int n);
void InterchangeSort(int a[], int n);
void InterchangeSort_GiamDan(int a[], int n);
void BubbleSort(int a[], int n);
void BubbleSort_GiamDan(int a[], int n);
void daonguoc(int a[], int n);
void daonguoc2(int a[], int n);
void HeapSort_MAX(int a[], int n);
void HeapSort_MIN(int a[], int n);
void shift_MAX(int a[], int i, int n);
void shift_MIN(int a[], int i, int n);
void QuickSort_GiamDan(int a[], int left, int right);
void QuickSort_TangDan(int a[], int left, int right);
int main()
{
	clock_t s1, e1, s, e;
	double d1, d;
	int a[MAX], n,chon, left,right;	
	bool in = false;
	do {
		system("cls");
		cout << "1.Khoi tao mang\n";
		cout << "2.SelectionSort\n";
		cout << "3.InterchangeSort\n";
		cout << "4.BubbleSort\n";
		cout << "5.SelectionSort_GiamDan\n";
		cout << "6.InterchangeSort_GiamDan\n";
		cout << "7.BubbleSort_GiamDan\n";
		cout << "8.Dao nguoc mang\n";
		cout << "9.Dao nguoc mang(left-right)\n";
		cout << "10.Xep tang dan HeapMAX\n";\
		cout << "11.Xep giam dan HeapMIN\n";
		cout << "12.Xep Tang Dan QuickSort\n";
		cout << "13.Xep Giam Dan QuickSort\n";
		cout << "14.Thoat\n";
		cout << "Ban chon : "; cin >> chon;
		switch (chon)
		{
		case 1:
			inputfile(a, n);
			//nhapmang(a, n);
			left = 0;
			right = n - 1;
			xuatmang(a, n);
			in = true;
			break;
		case 2:
			if (in) 
			{
				s1 = clock();
				s = clock();
				SelectionSort(a, n);
				e1 = clock();
				cout << "SelectionSort\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1-s1) * 1.0 / CLOCKS_PER_SEC;
				d= (e-s)*1.0/ CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;

			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 3:
			if (in)
			{
				s1 = clock();
				s = clock();
				InterchangeSort(a, n);
				e1 = clock();
				cout << "InterchangeSort\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 4:
			if (in)
			{
				s1 = clock();
				s = clock();
				BubbleSort(a, n);
				e1 = clock();
				cout << "BubbleSort\n";
				xuatmang(a, n); 
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 5:
			if (in)
			{
				s1 = clock();
				s = clock();
				SelectionSort_GiamDan(a, n);
				e1 = clock();
				cout << "SelectionSort_GiamDan\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 6:
			if (in)
			{
				s1 = clock();
				s = clock();
				InterchangeSort_GiamDan(a, n);
				e1 = clock();
				cout << "InterchangeSort_GiamDan\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 7:
			if (in)
			{
				s1 = clock();
				s = clock();
				BubbleSort_GiamDan(a, n);
				e1 = clock();
				cout << "BubbleSort_GiamDan\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 8:
			if (in)
			{
				s1 = clock();
				s = clock();
				daonguoc(a,n);
				e1 = clock();
				cout << "Dao nguoc mang\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 9:
			if (in)
			{
				s1 = clock();
				s = clock();
				daonguoc2(a, n);
				e1 = clock();
				cout << "Dao nguoc mang (left-right)\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 10:
			if (in)
			{
				s1 = clock();
				s = clock();
				HeapSort_MAX(a, n);
				e1 = clock();
				cout << "Sap xep tang dan HeapMAX\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 11:
			if (in)
			{
				s1 = clock();
				s = clock();
				HeapSort_MIN(a, n);
				e1 = clock();
				cout << "Sap xep giam dan HeapMIN\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 12:
			if (in)
			{
				s1 = clock();
				s = clock();
				QuickSort_TangDan(a,left,right);
				e1 = clock();
				cout << "Sap xep tang dan QuichSort\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;
		case 13:
			if (in)
			{
				s1 = clock();
				s = clock();
				QuickSort_GiamDan(a, left, right);
				e1 = clock();
				cout << "Sap xep giam dan QuichSort\n";
				xuatmang(a, n);
				e = clock();
				d1 = (e1 - s1) * 1.0 / CLOCKS_PER_SEC;
				d = (e - s) * 1.0 / CLOCKS_PER_SEC;
				cout << "\nThoi gian thuc thi la : " << d1 << endl;
				cout << "Thoi gian thuc thi va xuat la : " << d << endl;
			}
			else
			{
				cout << "Vui long khoi tao mang\n";
			}
			break;

		}
		_getch();
	} while (chon >=1 && chon <=13);
	system("pause");
}
void nhapmang(int a[], int& n)
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
}
void xuatmang(int a[], int n)
{
	cout << "Mang a : ";
	for (int i = 0; i < n; i++)
		cout <<  a[i] <<" ";
}
void hoanvi(int& x, int& y)
{
	int tam = x;
	x = y;
	y = tam;
}
void SelectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i)
			hoanvi(a[min], a[i]);
	}
}
void InterchangeSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
				hoanvi(a[i], a[j]);
}
void BubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				hoanvi(a[j], a[j - 1]);
}
void SelectionSort_GiamDan(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[min])
				min = j;
		if (min != i)
			hoanvi(a[min], a[i]);
	}
}
void InterchangeSort_GiamDan(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[j] > a[i])
				hoanvi(a[i], a[j]);
}
void BubbleSort_GiamDan(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (a[j] > a[j - 1])
				hoanvi(a[j], a[j - 1]);
}
void daonguoc(int a[],int n)
{
	for (int i = 0; i < n / 2; ++i) {
		hoanvi(a[i], a[n - i - 1]);
	}
}
void daonguoc2(int a[], int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		hoanvi(a[left], a[right]);
		left++;
		right--;
	}
}
void inputfile(int a[], int& n)
{
	ifstream inF;
	inF.open("data.txt");
	if (inF.is_open())
	{
		inF >> n;
		for (int i = 0; i < n; i++)
		{
			inF >> a[i];
		}
		inF.close();
		cout << "Mo file thanh cong\n";
	}
	else
	{
		cout << "Khong mo file dc" << endl;
	}
}
void shift_MAX(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) // nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j + 1 < n) // nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình
		if (a[j] < a[j + 1]) // nếu vị trí j không tồn tại phần tử a[j] <a[j+1]
			j++;
	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift_MAX(a, j, n);
	}
}
void HeapSort_MAX(int a[], int n)

{
	int i = n / 2;
	while (i >= 0) // tạo heap ban đầu
	{
		shift_MAX(a, i, n - 1); i--;
	}
	int right = n - 1; // right là vị trí cuối Heap đang xét
	while (right > 0)
	{
		if (a[0] > a[right])
			swap(a[0], a[right]); // hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
		right--; // giới hạn lại phần tử cuối đang xét
		if (right > 0) // Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
			shift_MAX(a, 0, right); // tạo Heap lại tại vị trí 0
	}
}
void HeapSort_MIN(int a[], int n)

{
	int i = n / 2;
	while (i >= 0) // tạo heap ban đầu
	{
		shift_MIN(a, i, n - 1); i--;
	}
	int right = n - 1; // right là vị trí cuối Heap đang xét
	while (right > 0)
	{
		if (a[0] < a[right])
			hoanvi(a[0], a[right]); // hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
		right--; // giới hạn lại phần tử cuối đang xét
		if (right > 0) // Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
			shift_MIN(a, 0, right); // tạo Heap lại tại vị trí 0
	}
}
void shift_MIN(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) // nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j + 1 < n) // nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình
		if (a[j] > a[j + 1]) // nếu vị trí j không tồn tại phần tử a[j] <a[j+1]
			j++;
	if (a[i] <= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift_MIN(a, j, n);
	}
}
void QuickSort_TangDan(int a[], int left, int right)
{
	int i, j, x;
	x = a[(left + right) / 2]; //Chọn phần tử giữa làm giá trị mốc
	i = left;
	j = right;
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			hoanvi(a[i], a[j]); //đổi chỗ a[i] và a[j]
			i++; j--;
		}
	}
	if (left < j)
		QuickSort_TangDan(a, left, j);
	if (i < right)
		QuickSort_TangDan(a, i, right);
}
void QuickSort_GiamDan(int a[], int left, int right)
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
		QuickSort_GiamDan(a, left, j);
	if (i < right)
		QuickSort_GiamDan(a, i, right);
}