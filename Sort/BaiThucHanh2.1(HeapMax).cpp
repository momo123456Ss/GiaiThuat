#include <iostream>
#include <conio.h>
using namespace std;
void nhapmang(int a[], int& n);
void shift(int a[], int i, int n);
void HeapSort(int a[], int n);
void xuatmang(int a[], int n);
int main()
{
	int a[100], n;
	nhapmang(a, n);
	HeapSort(a, n);
	xuatmang(a, n);
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
		cout << "\na["<<i<<"]=";
		cin >> a[i];
	}
}
void shift(int a[], int i, int n)
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
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0) // tạo heap ban đầu
	{
		shift(a, i, n - 1); i--;
	}
	int right = n - 1; // right là vị trí cuối Heap đang xét
	while (right > 0)
	{
		if (a[0] > a[right])
			swap(a[0], a[right]); // hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
		right--; // giới hạn lại phần tử cuối đang xét
		if (right > 0) // Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
			shift(a, 0, right); // tạo Heap lại tại vị trí 0
	}
}
void xuatmang(int a[], int n)
{
	cout << "Mang a sau khi sap tang:\n";
	for (int i = 0; i < n; i++)
		cout << a[i]<<" ";
	cout << endl;
}