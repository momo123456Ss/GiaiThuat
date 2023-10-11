#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
	int info;
	node* next, * previous;
};
node* first, * last = NULL;
void init();
void process_list();
void process_list_begin_last();
node* search(int x);
node* search_list_begin_last(int x);
void insert_first(int x);
void insert_last(int x);
int delete_first();
int delete_last();
int count_node();
void delete_all();
bool isEmpty(node* first, node* last);
void searchDelete(int x);
// tìm phần tử chèn để tiến hành chèn sau chèn trước
node* search_close_gt(int x);
void insertPreviousNode(int x, int value);
void insertNextNode(int x, int value);
void deleteAfterNode(int x);
int main()
{
	int chon, x, in = 0;
	int value;
	do {
		system("cls");
		cout << "1.Khoi tao danh sach\n2.Them vao dau danh sach\n3.Them vao cuoi danh sach\n4.Tim kiem\n5.Xuat danh sach dau ve cuoi\n6.Xuat danh sach cuoi ve dau\n7.Xoa phantu dau\n8.Xoa phantu cuoi\n9.Dem so phan tu\n10.Xoa 1 phan tu\n11.Them phan tu truoc node\n12.Them phan tu sau node\n13.Delete After Node\n14.Thoat\nBan chon :	";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			in = 1;
			cout << "Qua trinh khoi tao thanh cong \n";
			break;
		case 2:
			if (in)
			{
				cout << "Phan tu can them vao\n";
				cin >> x;
				insert_first(x);
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 3 :
			if (in)
			{
				cout << "Phan tu can them vao\n";
				cin >> x;
				insert_last(x);
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 4 :
			if (in)
			{
				int x;
				cout << "Gia tri can tim : ";
				cin >> x;
				node* tmp = search(x);
				if (search(x) != NULL)
				{
					cout << "Gia tri : " << x << " co trong danh sach.\n";
					cout << "Dia chi vung nho cua : " << x << " la : " << tmp << endl;
				}
				else cout << "Gia tri : " << x << " khong co trong danh sach.\n";
			}
			else cout << "Please choose the Initialization list first!\n";
			break;
		case 5 : 
			if (in)
			{
				process_list();
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 6 : 
			if (in)
			{
				process_list_begin_last();
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 7:
			if (in)
			{
				delete_first();
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 8 : 
			if (in)
			{
				delete_last();
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 9 : 
			if (in)
			{
				cout << "Danh sach dang co " << count_node() << " phan tu " << endl;
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 10:
			if (in)
			{
				cout << "Nhap phan tu can xoa: "; cin >> x;
				searchDelete(x);
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 11:
			if (in)
			{
				cout << "Nhap phan tu x: "; cin >> x;
				cout << "Nhap value: "; cin >> value;
				insertPreviousNode(x, value);
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 12:
			if (in)
			{
				cout << "Nhap phan tu x: "; cin >> x;
				cout << "Nhap value: "; cin >> value;
				insertNextNode(x, value);
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		case 13:
			if (in)
			{
				cout << "Nhap phan tu x : "; cin >> x;
				deleteAfterNode(x);
			}
			else
			{
				cout << "Khoi tao danh sach\n";
			}
			break;
		default:
			cout << "Thoat\n";
			break;
		}
		_getch();
	} while (chon >= 1 && chon <= 13);
	delete_all();
	return 0;
}
void init()
{
	first = NULL;
	last = NULL;
}
void process_list()
{//duyệt đầu -> cuối
	node* p;
	p = first;
	if (p == NULL)
	{
		cout << "Danh sach rong\n";
		return;
	}
	cout << "Cac phan tu trong danh sach tu dau den cuoi \n";
	while (p!=NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}
void process_list_begin_last()
{//duyệt từ cuối lên đầu
	cout << "Danh sach tu cuoi ve dau \n";
	node* p;
	p = last;
	while (p!=NULL)
	{
		cout << p->info << " ";
		p = p->previous;
	}
	cout << endl;
}
node* search(int x)
{//đi từ đầu đến cuối
	node* p;
	p = first;
	while (p!=NULL&&p->info!=x)
	{
		p = p->next;
	}
	return p;
}
node* search_list_begin_last(int x)
{//đi từ cuối lên đầu
	node* p;
	p = last;
	while (p!=NULL&&p->info!=x)
	{
		p = p->previous;
	}
	return p;
}
void insert_first(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
		first->previous = p;
	else//danh sách rỗng trc khi thêm p
		last = p;
	//sau khi thêm p , danh sách có 1 phần tử
	first = p;
}
void insert_last(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
	{
		last->next = p;
	}
	else
		first = p;
	last = p;
}
int delete_first()
{
	if (first != NULL)
	{
		node* p = first;
		first = first->next;
		if (first != NULL) // trường hợp ds khác rỗng phần tử nào
			first->previous = NULL;
		else
			last = NULL; // trường hợp	ds không còn phần tử nào
		delete p;
			return 1;
	}
	return 0;
}
int delete_last()
{
	if (last != NULL)
	{
		node* p = last;
		last = last->previous;
		if (last != NULL) // trường hợp ds khác rỗng nào
			last->next = NULL;
		else
			first = NULL;
		// trường hợp ds không còn phần tử nào
		delete p;
		return 1;
	}
	return 0;
}
int count_node()
{
	int count = 0;
	node* p = first;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
void delete_all()
{
	if (first != NULL)
	{
		node* p = first;
		while (p != NULL)
		{
			first = first->next;
			delete p;
			p = first;
		}
	}
	/*node* p = first;
	first = first->next;
	first = NULL;
	p = first;
	delete p;*/
}
bool isEmpty(node* first, node* last)
{
	return (first == NULL) ? true : false;
}
void searchDelete(int x)
{
	if (first == NULL) return;
	node* p = first;
	while (p != NULL && p->info != x)
		p = p->next;
	if (p == NULL)
	{
		cout << x << " khong co trong danh sach\n";
		return;
	}
	if (p == first)
		delete_first();
	else if (p == last)
		delete_last();
	else
	{
		p->previous->next = p->next;
		p->next->previous = p->previous;
		delete p;
	}
	cout << "Da tim thay\n";
}
void insertPreviousNode(int x,int value)
{
	node* p = search(x);
	if (p == NULL)
	{
		cout << "Khong tim thay " << x << endl;;
		p = search_close_gt(x);
	}
	if (p != NULL)
	{
		cout << "Thuc hien them vao trc (Previous) phan tu " << p->info << endl;
		node* left_p = p->previous;
		node* q = new node;
		q->info = value;
		q->previous = left_p;
		q->next = p;
		p->previous = q;
		left_p->next = q;
	}
}
node* search_close_gt(int x)
{
	node* p = first;
	node* tmp = NULL;
	while (p != NULL)
	{
		if (p->info>x)
			if (tmp == NULL || (tmp != NULL && p->info < tmp->info))
			{
				tmp = p;
			}
		p = p->next;
	}
	return tmp;
}
void insertNextNode(int x, int value)
{
	node* p = search(x);
	if (p == NULL)
	{
		cout << "Khong tim thay " << x << endl;;
		p = search_close_gt(x);
	}
	if (p != NULL)
	{
		cout << "Thuc hien them vao sau (Next) phan tu " << p->info << endl;
		node* q = new node;
		q->info = value;
		q->next = p->next;
		q->previous = p;
		p->next = q;
		p->next->previous = q;
	}
}
void deleteAfterNode(int x)
{
	if (first == NULL) return;
	node* p = first;
	while (p != NULL && p->info != x)
		p = p->next;
	if (p == NULL)
	{
		cout << x << " khong co trong danh sach\n";
		return;
	}
	if (p == last)
		return;
	node* q = p->next;
	if (q->next == NULL)
		p->next = NULL;
	else
	{
		p->next = q->next;
		q->next->previous = p;
	}
	delete q;
}