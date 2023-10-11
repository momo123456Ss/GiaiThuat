//n=7 , 12 3 4 20 6 8 19
//pivot x = a[0]
//i=left = 0 , j = n - 1 = 6
#include <iostream>
#include <fstream>
using namespace std;
class QuickSort
{
public:
	int getn();
	void input();
	void output();
	void Sort(int left,int right);
	void Sort_DES(int left, int right);
	void hoanvi(int& x, int& y);
	void Sort_Pivot0(int left, int right);
	void inputfile();
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
		cout << "Nhap so luong phan tu : ";
		cin >> n;
		if (n <= 0 || n > 200)
			cout << "Nhap lai \n";
	} while (n <= 0 || n > 200);
	cout << "Nhap " << n << " so nguyen : \n";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
} 
void QuickSort::output()
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] : " << a[i]<< endl;
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
		while (a[i] < x) i++;
		while (a[j] > x) j--;
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
void QuickSort::hoanvi(int& x, int& y)
{
	int tam = x;
	x = y;
	y = tam;
}
void QuickSort::Sort_DES(int left, int right)
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
		Sort_DES(left, j);
	if (i < right)
		Sort_DES(i, right);
}
void QuickSort::inputfile()
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
void QuickSort::Sort_Pivot0(int left, int right)
{
	int i, j, x;
	i = left;
	j = right;
	x = a[left]; //Chọn phần tử giữa làm giá trị mốc
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
		Sort_Pivot0(left, j);
	if (i < right)
		Sort_Pivot0(i, right);
}