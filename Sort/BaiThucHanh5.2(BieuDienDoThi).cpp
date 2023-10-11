#include<iostream>
using namespace std;
// Khai báo cấu trúc danh sách cho 1 danh sách
#define max 100
struct node
{
	int info;
	node* link;
};
node* first[max]; // mảng danh sách
int n; // so dinh tren do thi
//Khởi tạo mảng danh sách rỗng
void init()
{
	for (int i = 0; i < n; i++)
		first[i] = NULL;
}
//Thêm một phần tử vào trong danh sách
void insert_first(node*& f, int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = f;
	f = p;
}
//Nhập mảng danh sách
void input()
{
	int d, x, m;
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nnhap dinh thu " << i + 1 << " : ";
		cin >> d;
		insert_first(first[i], d);
		cout << "nhap vao so dinh ke cua " << d << " : ";
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			insert_first(first[i], x);
		}
	}
}
//Xuất thông tin 1 danh sách
void output_list(node* f)
{
	if (f != NULL)
	{
		node* p = f;
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
	}
	//Xuất thông tin mảng danh sách
}
void output()
{
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			cout << endl << "Danh sach thu " << i + 1 << ": ";
			output_list(first[i]);
		}
	else
		cout << "rong";
}
int main()
{
	init();
	input();
	output();
	system("pause");
}