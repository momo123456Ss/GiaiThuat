#include<iostream>
#include <conio.h>
#include <fstream>
using namespace std;
//Khai Báo Cấu Trúc Ma Trận Kề
#define MAX 20
char vertex[MAX][MAX];
int a[MAX][MAX]; // mảng hai chiều
int n; // số đỉnh của đồ thị
int C[100]; // lưu trữ đỉnh chưa xét; 
// 1 là chưa xét; 0 là đã xét
int dfs[100];// lưu danh sách phần tử đã duyệt
int ndfs = 0; // chỉ số lưu đỉnh đã xét
int bfs[100];// lưu danh sách phần tử đã duyệt
int nbfs = 0; // chỉ số lưu đỉnh đã xét
void inputMatrixFile(int a[][MAX], int& n)
{
	ifstream ifs;
	ifs.open("baithuchanh6.2.txt");
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		ifs >> vertex[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ifs >> a[i][j];
		}
	}
	ifs.close();
}
struct Node
{
	int info;
	Node* link;
};
Node* sp;
//stack

void Push(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int Pop(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
//Khởi Tạo Mảng Rỗng
void init()
{
	sp = NULL;
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
			cin >> a[i][j];
	}
}
//Xuất Ma Trận
void output()
{
	cout << "Bang Danh Sach Ke\n";
	cout << "  ";
	for (int i = 0; i < n; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << vertex[i] << " ";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
// Hàm khởi tạo đỉnh chưa xét = 1
void initEdgesStatus()
{
	for (int i = 0; i < n; i++) // n là số đỉnh của đồ thị
		C[i] = 1;
}
// Thuật giải DFS sử dụng STACK
void process_Stack() {
	Node* p = sp;
	if (p = NULL) {
		cout << "Stack rong\n";
	}
	return;
	cout << "Stack hien tai (tu dinh stack):\n";
	while (p != NULL)
	{
		cout << p->info << "\n";
		p = p->link;
	}
	cout << endl;
}
void DFS(int s) //s là đỉnh bắt đầu
{
	initEdgesStatus();
	init();
	Push(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (!isEmpty())
	{
		if (v == n)
			Pop(u);
		for (v = 0; v < n; v++) {
			if (a[u][v] != 0 && C[v] == 1)
			{
				Push(u);
				Push(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}
// Hàm xuất DFS
void output_DFS()
{
	cout << "Ket qua duyet DPS:\n";
	for (int i = 0; i < ndfs; i++)
		cout << vertex[dfs[i]] << " ";
	cout << endl;
}

//Queue
Node* front, * rear;
void initQueue()
{
	front = rear = NULL;
}
int isEmptyQueue()
{
	if (front == NULL) 
		return 1;
	return 0;

}
void pushQ(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
void popQ(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
	}
}
void process_Queue()
{
	while (front != NULL)
	{
		Node* p = front;
		cout << "Hang doi dang luu tru: \n";
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
	}
}
// Thuật giải BFS sử dụng QUEUE
void BFS(int v) // v là đỉnh bắt đầu
{
	initEdgesStatus();
	initQueue();
	int w, p;
	pushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && a[p][w] >= 1)
			{
				pushQ(w);
				C[w] = 0;
			}
	}
}
// Hàm xuất BFS
void output_BFS()
{
	cout << "Ket qua duyet BFS:\n";
	for (int i = 0; i < nbfs; i++) // n là số đỉnh của đồ thị
		cout << vertex[bfs[i]] <<" ";
	cout << endl;
}
// Hàm tìm x
void Search_by_BFS(int x, int v) // v là đỉnh bắt đầu
{
	int w, p;
	int nbfs = 0;
	int tongwT = 0;
	int dem = 0;
	int weigth[MAX] = { 0 };
	initEdgesStatus();
	initQueue();
	pushQ(v);
	C[v] = 0;
	while (!isEmptyQueue())
	{
		popQ(p);
		if (x == p)
		{
			cout << x << " Ton Tai\n";
			cout << "Duong di tu dinh " << vertex[v] << " den dinh " << vertex[x] << endl;
			cout << "BFS: \n";
			for (int i = 0; i < nbfs; i++) {// n là số đỉnh của đồ thị
				cout << vertex[bfs[i]] << " ";
			}
			cout << endl;
			cout << "Trong so cua duong di la: \n";
			for (int i = 0; i < nbfs; i++){
				tongwT += weigth[i];
			}
			cout << tongwT << endl;
			return;
		}
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++) {
			if (C[w] && a[p][w] != 0)
			{
				pushQ(w);
				C[w] = 0;
				weigth[dem++] = a[p][w];
			}
		}
	}
}
void Search_by_DFS(int x, int s)
{
	int weigth[MAX] = { 0 };
	int dem = 0;
	int tongwT = 0;
	initEdgesStatus();
	init();
	Push(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (!isEmpty())
	{
		if (v == n)
			Pop(u);
		//if (x == u) {
		//	cout << x << " Ton Tai\n";
		//	cout << "Duong di tu dinh " << vertex[s] << " den dinh " << vertex[x] << endl;
		//	cout << "DFS: \n";
		//	for (int i = 0; i < ndfs; i++) {// n là số đỉnh của đồ thị
		//		cout << vertex[dfs[i]] << " ";
		//		tongwT += weigth[i];
		//	}
		//	cout << endl;
		//	cout << "Trong so cua duong di la: \n";
		//	cout << tongwT << endl;
		//	return;
		//}
		for (v = 0; v < n; v++) {
			if (a[u][v] != 0 && C[v] == 1)
			{
				Push(u);
				Push(v);
				if (x == v) {
					cout << x << " Ton Tai\n";
					cout << "Duong di tu dinh " << vertex[s] << " den dinh " << vertex[x] << endl;
					cout << "DFS: \n";
					for (int i = 0; i < ndfs; i++) {// n là số đỉnh của đồ thị
						cout << vertex[dfs[i]] << " ";
						tongwT += weigth[i];
					}
					cout << endl;
					cout << "Trong so cua duong di la: \n";
					cout << tongwT << endl;
					return;
				}
				weigth[dem++] = a[u][v];
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}
void main()
{
	int choose,s,v,x;
	do
	{
		system("cls");
		cout << "1: Doc File\n";
		cout << "2: Duyet theo DFS\n";
		cout << "3: Duyet theo BFS\n";
		cout << "4: Tim dinh cua do thi BFS\n";
		cout << "5: Tim dinh cua do thi DFS\n";
		cout << "0: Thoat \n";
		cout << "Chon: ";
		cin >> choose;
		if (choose == 0)
			break;
		else

			if ((choose < 1) || (choose > 5))
				cout << "Chon sai chon lai\n";
			else
			{
				switch (choose)
				{
				case 1:
					inputMatrixFile(a, n);
					output();
					break;
				case 2:
					cout << "Nhap dinh bat dau\n"; cin >> s;
					DFS(s);
					output_DFS();
					break;
				case 3:
					cout << "Nhap dinh bat dau\n"; cin >> s;
					BFS(s);
					output_BFS();
					break;
				case 4:
					cout << "Nhap dinh muon tim\n"; cin >> x;
					cout << "Nhap dinh bat dau tim\n"; cin >> v;
					Search_by_BFS(x, v);
					break;
				case 5:
					cout << "Nhap dinh muon tim\n"; cin >> x;
					cout << "Nhap dinh bat dau tim\n"; cin >> v;
					Search_by_DFS(x, v);
					break;
				}
			}
		system("pause");
	} while (choose != 0);
	system("pause");
}