#include<iostream>
#include <conio.h>
#include <fstream>
using namespace std;
//Khai Báo Cấu Trúc Ma Trận Kề
#define MAX 20
char vertex[MAX];
int a[MAX][MAX]; // mảng hai chiều 
int n; // số đỉnh của đồ thị
int C[MAX]; // lưu trữ đỉnh chưa xét; 
// 1 là chưa xét; 0 là đã xét
int dfs[MAX];// lưu danh sách phần tử đã duyệt
int ndfs = 0; // chỉ số lưu đỉnh đã xét
struct Node
{
	int info;// thu tu dinh
	Node* link;
};
Node* first[MAX];
Node* sp;
//stack
void init();
void Push(int x);
int Pop(int& x);
Node* createNode(int x);
void insert_first(Node*& f, int x);
void inputlist();
//Xuất Ma Trận
void outputList();
// Hàm khởi tạo đỉnh chưa xét = 1
void initEdgesStatus();
// Thuật giải DFS sử dụng STACK
void init_Stack();
int isEmpty_Stack();
void DFS(int s) //s là đỉnh bắt đầu
{
	initEdgesStatus();
	init_Stack();
	Push(s);
	int dem = 0;
	int tongwT = 0;
	int weigth[MAX] = { 0 };
	dfs[ndfs++] = s;
	C[s] = 0;
	int  u = s;
	Node* p = first[u];
	while (!isEmpty_Stack())
	{
		if (p->link == NULL) {
			Pop(u);
		}
		p = first[u];
		while(p->link != NULL){
			if (C[p->info] == 1)
			{
				Push(u);
				Push(p->info);
				dfs[ndfs++] = p->info;
				C[p->info] = 0;
				u = p->info;
				break;
			}
			p = p->link;
		}
	}
	return;
}
void search_by_DFS(int x,int s) //s là đỉnh bắt đầu
{
	initEdgesStatus();
	init_Stack();
	Push(s);
	int dem = 0;
	int tongwT = 0;
	int weigth[MAX] = { 0 };
	dfs[ndfs++] = s;
	C[s] = 0;
	int  u = s;
	Node* p = first[u];
	while (!isEmpty_Stack())
	{
		if (p->link == NULL) {
			Pop(u);
		}
		p = first[u];
		while (p->link != NULL) {
			if (C[p->info] == 1)
			{
				Push(u);
				Push(p->info);
				if (x == p->info) {
					cout << endl << x << " Ton Tai\n";
					cout << "Duong di tu dinh " << vertex[s] << " den dinh " << vertex[x] << endl;
					cout << "DFS: \n";
					for (int i = 0; i < ndfs; i++) {// n là số đỉnh của đồ thị
						cout << vertex[dfs[i]] << " ";
						tongwT += weigth[i];
					}
					cout << endl;
					cout << "Trong so cua duong di la: \n";
					ndfs = 0;
					cout << tongwT << endl;
					return;
				}
				weigth[dem++] = a[u][p->info];
				dfs[ndfs++] = p->info;
				C[p->info] = 0;
				u = p->info;
				break;
			}
			p = p->link;
		}
	}
	return;
}
// Hàm xuất DFS
void output_DFS();
void output_Array(int a[], int n);
int main()
{
	Node* p;
	int choose,x,v;
	int in = 0;
	do
	{
		system("cls");
		cout << "1: Nhap cac dinh ke \n";
		cout << "2: Ket qua duyet theo DFS, tai dinh bat ky\n";
		cout << "3: Tim dinh bang DFS\n";
		cout << "0: Thoat \n";
		cout << "Chon: ";
		cin >> choose;
		if (choose == 0)
			break;
		else

			if ((choose < 1) || (choose > 3))
				cout << "Chon sai chon lai\n";
			else
			{
				switch (choose)
				{
				case 1:
					inputlist();
					outputList();

					
					in = 1;
					break;
				case 2:
					if (in == 1) {
						cout << "Nhap dinh bat dau : "; cin >> x;
						DFS(x);
						output_Array(dfs, ndfs);
						ndfs = 0;
					}
					else
					{
						cout << "Vui long nhap cac dinh ke\n";
					}
					break;
				case 3:
					cout << "Nhap dinh muon tim\n"; cin >> x;
					cout << "Nhap dinh bat dau tim\n"; cin >> v;
					search_by_DFS(x, v);
				}
			}
		system("pause");
	} while (choose != 0);
}
int isEmpty_Stack()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node* p = new Node;
	if (p == NULL) return;
	p->info = x;
	p->link = sp;
	sp = p;
}
int Pop(int& x)
{
	if (!isEmpty_Stack())
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
void init()
{
	for (int i = 0; i < n; i++)
		first[i] = NULL;
}
void init_Stack()
{
	for (int i = 0; i < n; i++)
		sp = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	if (!p) return NULL;
	p->info = x;
	p->link = NULL;
	return p;
}
void insert_first(Node*& f, int x)
{
	Node* p = createNode(x);
	if (!p) return;
	if (f == NULL)
		f = p;
	else
	{
		p->link = f;
		f = p;
	}
}
void inputlist()
{
	do {
		cout << "Nhap so luong dinh cua do thi: ";
		cin >> n;
	} while (n <= 0 || n > MAX);
	cout << "Nhap ten cua cac dinh trong do thi: ";
	for (int i = 0; i < n; i++) {
		cin >> vertex[i];
	}
	for (int i = 0; i < n; i++) {
		//dua dinh dang xet vao danh sach
		//insert_first(first[i], i);
		// dua cac dinh ke voi dinh i vao ds
		cout << "Nhap cac dinh ke voi dinh " << i << " ket thuc nhan -1: ";
		int x;
		do {
			cin >> x;
			if (x == -1) break;
			insert_first(first[i], x);
			a[i][x] = 1;
		} while (x != -1);
	}
}
void outputList()
{/*
	for (int i = 0; i < n; i++)
	{
		cout << "Danh sach ke thu " << vertex[i] << ": ";
		Node* q = first[i];
		while (q->link != NULL)
		{
			cout << vertex[q->info] << " ";
			q = q->link;
		}
		cout << endl;
	}*/
	cout << endl;
	cout << "Bang danh sach ke:\n";
	cout << "  ";
	for (int i = 0; i < n; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << vertex[i] << " ";
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void initEdgesStatus()
{
	for (int i = 0; i < n; i++) // n là số đỉnh của đồ thị
		C[i] = 1;
}
void output_DFS()
{
	cout << "Ket qua duyet DPS:\n";
	for (int i = 0; i < ndfs; i++)
		cout << vertex[dfs[i]] << " ";
	cout << endl;
}
void output_Array(int a[], int n)
{
	cout << "Ket qua duyet DPS:\n";
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
	cout << endl;
}