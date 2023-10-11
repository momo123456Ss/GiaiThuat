#include<iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node* sp;// đỉnh stack, node đầu dslk
Node* front, * rear;
//stack
void init();
void Push(int x);
int Pop(int& x);
int isEmpty();
void processlist();
//Queue
void init_Queue();
int isEmptyQueue();
void processlistQueue();
void pushQueue(int x);
void popQueue(int& x);
//
void delete_all();
int convert10_2(int tp);
int main()
{
	int choose, x, n = 0, in = 0; //n là số lượng phần tử trong danh sách
	do
	{

		system("cls");
		cout << "1.Khoi tao danh sach. \n2.Them 1 phan tu.\n"
			<< "3.Xuat danh sach. \n4.Kiem tra rong.\n"
			<< "5.Xoa 1 phan tu.\n6.Doi 10 sang 2.\n7.Thoat.\n";
		cout << "\nMoi chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init_Queue();
			in = 1;
			cout << "Khoi tao danh sach thanh cong\n";
			break;
		case 2:
			if (in == 1)
			{
				cout << "Nhap phan tu can them: "; cin >> x;
				pushQueue(x);
			}
			else
			{
				cout << "Vui long khoi tao danh sach!!\n";
			}
			break;
		case 3:
			if (in == 1)
			{
				cout << "Xuat danh sach\n";
				processlistQueue();
			}
			else
			{
				cout << "Vui long khoi tao danh sach!!\n";
			}
			break;
		case 4:
			if (in == 1)
			{
				if (isEmptyQueue())
				{
					cout << "Danh sach co phantu\n";
				}
				else
				{
					cout << "Danh sach rong\n";
				}
			}
			else
			{
				cout << "Vui long khoi tao danh sach!!\n";
			}
			break;
		case 5:
			if (in == 1)
			{
				cout << "Nhap phan tu muon xoa: ";
				popQueue(x);
				cout << "Phan tu vua lay ra: " << x << endl;
			}
			else
			{
				cout << "Vui long khoi tao danh sach!!\n";
			}
			break;
		case 6:
			cout << "Nhap so he 10: "; cin >> x;
			cout << convert10_2(x) << endl;
			
		}
		_getch();
	} while (choose >= 1 && choose <= 6);
	delete_all();
	return 0;
}
void init()
{
	sp = NULL;
}
void Push(int x)
{
	Node* p;
	p = new Node;
	if (!p) return;
	p->info = x;
	p->link = sp;
	sp = p;
}
int Pop(int& x)
{
	if (!isEmpty())
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
int convert10_2(int tp) {
	init();
	while (tp != 0 )
	{
		int du = tp % 2;
		Push(du);
		tp /= 2;
	}
	int np = 0;
	int x;
	while (!isEmpty())
	{
		Pop(x);
		np = np * 10 + x;
	}
	return np;
}
//Queue
void init_Queue()
{
	front = rear = NULL;
}
int isEmptyQueue()
{
	if (front != NULL) return 1;
	return 0;
}
void processlist()
{
	Node* p = sp;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
}
void processlistQueue()
{
	Node* p = front;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
}
void pushQueue(int x)
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
void popQueue(int& x)
{
	if (front == NULL) return;
	Node* p = front;
	x = p->info;
	front = front->link;
	if (front == NULL)
		rear = NULL;
	delete p;
}
void delete_all()
{
		if (sp != NULL) {
			Node* p = sp; //Gán địa chỉ ô nhớ của phần tử đầu tiên cho p
			while (p != NULL) //Duyệt tới phần tử cuối cùng trong danh sách
			{
				sp = sp->link; //Gán địa chỉ ô nhớ của phần tử tiếp theo cho biến first
				delete p; //Thu hồi địa chỉ vùng nhớ con trỏ p
				p = sp; //gán địa chỉ ô nhớ của first cho p
			}
		}
}