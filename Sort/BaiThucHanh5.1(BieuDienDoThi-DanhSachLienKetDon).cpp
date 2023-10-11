#include<iostream>
using namespace std;
//Khai Báo Cấu Trúc Ma Trận Kề
#define MAX 20
int A[MAX][MAX]; // mảng hai chiều
int n; // số đỉnh của đồ thị
//Khởi Tạo Mảng Rỗng
void init()
{
	n = 0;
}
//Nhập Ma Trận
void input()
{
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
//Xuất Ma Trận
void output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] <<" ";
		cout << endl;
	}
}
int main()
{
	init();
	input();
	output();
	system("pause");
}
