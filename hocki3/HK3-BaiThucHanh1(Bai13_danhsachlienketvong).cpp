#include<iostream>
#include <conio.h>
using namespace std;
struct node
{
	int info;
	node* link = NULL;
};
node* first = NULL;
void init();
void process_list();
void insert_first(int x);
void insert_last(int x);
int delete_last();
int delete_first();
int count_node();
void delete_all();
void delete_at_node(int x);
node* search(int x);
int main()
{
	int chon, x, in = 0;
	do {
		system("cls");
		cout << "1.Khoi tao\n2.Them dau danh sach\n3.Them cuoi danh sach\n4.Xoa dau\n5.Xoa cuoi\n6.Xuat danh sach\n7.Dem so luong PhanTu\n8.Xoa NODE bat ky\n9.Xoa toan bo\n10.Thoat\nBan chon : \n"; cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			in = 1;
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			if (in)
			{
				cout << "Nhap phan tu can them : "; cin >> x;
				insert_first(x);
				cout << "Them thanh cong\n";
			}
			else
				cout << "Khoi tao danh sach\n";
			break;
		case 3:
			if (in)
			{
				cout << "Nhap phan tu can them : "; cin >> x;
				insert_last(x);
				cout << "Them thanh cong\n";
			}
			else
				cout << "Khoi tao danh sach\n";
			break;
		case 4:
			if (in)
			{
				delete_first();
				cout << "Xoa thanh cong\n";
			}
			else
				cout << "Khoi tao danh sach\n";
			break;
		case 5 :
			if (in)
			{
				delete_last();
				cout << "Xoa thanh cong\n";
			}
			else
				cout << "Khoi tao danh sach\n";
			break;
		case 6 : 
			if (in)
			{
				cout << "Xuat danh sach \n";
				process_list();
			}
			else
			{
				cout << "Khoi tao danh sach \n";
			}
			break;
		case 7 :
			if (in)
			{
				cout << "So luong phan tu trong node : " << count_node() << endl;
			}
			else
			{
				cout << "Khoi tao danh sach \n";
			}
			break;
		case 8:
			if (in)
			{
				cout << "Nhap phan tu muon xoa : "; cin >> x;
				node* tmp = search(x);
				cout << tmp << endl;
				delete_at_node(x);
			}
			else
			{
				cout << "Khoi tao danh sach \n";
			}
			break;
		case 9:
			if (in)
			{
				delete_all();
			}
			else
			{
				cout << "Khoi tao danh sach \n";
			}
			break;
		default:
			break;
		}
		_getch();
	} while (chon >= 1 && chon <= 9);
	delete_all();
	return 0;
}
void process_list()//xuất danh sách
{
	node* p = first;
	if (p != NULL)
	{
		do
		{
			cout << p->info << " ";
			p = p->link;
		} while (p != first);
	}
	else
	{
		cout << "Danh sach rong\n";
	}
}
void insert_first(int x)//chèn đàu
{
	node* p = new node;
	if (!p) return;
	p->info = x;
	p->link = first;
	node* q = first;
	if (q != NULL)
	{
		while (q->link != first)
			q = q->link;
		q->link = p;
	}
	else
		p->link = p;
	first = p;
}
int delete_first()//xóa đầu
{
	if (first != NULL) {
		node* p = first;
		node* q = first;
		while (q->link != first)
			q = q->link;
		if (p != q)
		{
			first = first->link;
			q->link = first;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void insert_last(int x)//chèn cuối
{
	node* p = new node;
	if (!p) return;
	p->info = x;
	node* k = first;
	if (k != NULL)
	{
		while (k->link != first)
			k = k->link;
		k->link = p;
		p->link = first;
	}
	else
	{
		p->link = p;
		first = p;
	}
}
int delete_last()
{//xóa cuối
	if (first != NULL)
	{
		node* p, * q;
		p = first;
		q = NULL;
		while (p->link != first)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
			q->link = first;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void init()
{
	first = NULL;
}
int count_node()
{
	int count = 0;
	node* p = first;
	if (p != NULL)
	{
		do
		{
			p = p->link;
			count++;
		} while (p != first);
	}
	return count;
}
void delete_all()
{
	while(first != NULL) 
	{
		node* p = first;
		node* q = first;
			while (q->link != first)
				q = q->link;
			if (p != q)
			{
				first = first->link;
				q->link = first;
			}
			else
				first = NULL;
			delete p;
	}
}
void delete_at_node(int x)
{
	if (first != NULL)
	{
		node* p, * q;
		p = first;
		q = NULL;
		while (p->link != first && p->info != x)
		{
			q = p;
			p = p->link;
		}
		if (p->info == x)
		{
			if (p == first)
				delete_first();
			else
			{
				q->link = p->link;
				delete p;
			}
		}
		return;
	}
}
//bool isEmpty()
//{
//	return first = NULL;
//}
node* search(int x)
{
	node* p = first;
	//Nếu p chưa trỏ tới cuối mảng và chưa tìm thấy x thì xét phần tử tiếp theo
	while (p != NULL && p->info != x)
		p = p->link; //Trỏ p đến phần tử tiếp theo trong danh sách
	return p;
}