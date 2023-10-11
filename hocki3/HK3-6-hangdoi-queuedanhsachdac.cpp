#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 100
void init(int a[], int& front, int& rear);
int Pop(int a[], int& front, int& rear, int& x);
int Push(int a[], int& front, int& rear, int x);
int Pushs(int a[], int& front, int& rear, int x);
int Pops(int a[], int& x, int& front, int& rear);
int isEmpty(int a[], int front, int rear);
int isFull(int a[], int front, int rear);
void Xuat(int a[], int front, int rear);
int main()
{
	int a[MAX];
	int front, chon,rear,x; // front vị trí lấy ra, rear vị trí thêm vào
	int in = 0;
	do
	{
		system("cls");
		cout << "Menu\n1.Khoi tao hang doi\n2.Them 1 phan tu vao queue\n3.Lay 1 phan tu tu queue\n4.Kiem tra rong\n5.Kiem tra day\n6.Thoat\nBan chon : "; cin >> chon;
		switch (chon)
		{
		case 1:
			init(a, front, rear);
			in = 1;
			cout << "Khoi tao thanh cong \n";
			break;
		case 2:
			if (in)
			{
				cout << "Nhap gia tri can them vao queue : "; cin >> x;
				Pushs(a,front,rear,x);
				cout << "Them vao queue thanh cong \n";
			}
			else
				cout << "Khoi tao queue\n";
			break;
		case 3:
			if (in)
			{
				if (Pop(a,front,rear,x))
				{
					cout << "Lay phan tu thanh cong\n";
				}
				else
					cout << "Ko lay dc phan tu\n";
			}
			else
				cout << "Khoi tao queue\n";
			break;
		case 4:
			if (in)
			{
				if (isEmpty(a,front,rear))
					cout << "Hang doi queue rong\n";
				else
				{
					cout << "Hang doi queue co phan tu\n";
					Xuat(a,front ,rear);
				}
			}
			else
				cout << "Khoi tao queue\n";
			break;
		case 5:
			if (in)
			{
				if (isFull(a, front, rear)) {
					cout << "Hang doi day\n";
				}
				else {
					cout << "Hang doi co phan tu\n";
					Xuat(a, front, rear);
				}
			}
			else
				cout << "Ko co phan tu trong hang doi ko thu xoa\n";
			break;
		default:
			cout << "Exit\n";
			break;
		}
		_getch();
	} while (chon >= 1 && chon <= 5);
}
void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
int Push(int a[], int& front, int& rear, int x) 
{
	if (rear - front == MAX-1) // hang đợi đầy
		return 0;
	else
	{
		if (front == -1) // hang đợi rỗng front = 0; if (rear == MAX - 1) // hang đợi bị tràn
		{
			front = 0;
			if(rear == MAX - 1)
				for (int i = front; i <= rear; i++) { // thực hiện dời tịnh tiến các phần tử trong hàng
					a[i - front] = a[i];
				}
			rear = MAX - 1 - front;
			//rear nhận giá trị mới, sau khi tinh tiến
			front = 0; // front nhận giá trị mới, sau khi tịnh tiến
		}
		a[++rear] = x;
		return 1;
	}
}
int Pop(int a[], int& front, int& rear, int& x)
{
	if (front == -1) // hàng đợi rỗng
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
			// trường hợp hang đợi có 1 phần tử, sau khi xóa hang rỗng
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}
int Pushs(int a[], int& front, int& rear, int x)
{
	if ((rear - front == MAX - 1) || (rear - front == -1))// hàng đợi bị đầy
	{
		return 0;
	}
	else
	{
		if (front == -1) // xét hang đợi rỗng
			front = 0; // khi đó rear =-1;
		if (rear == MAX - 1) // hang đợi bị tràn
			rear = -1; // hang đợi tràn, vòng giá trị rear xuống -1
		a[++rear] = x; // tang rear lên 1 giá trị, và thêm phần tử mới tại rear
			return 1;
	}
}
int Pops(int a[], int& x ,int& front, int& rear)
{
	if (front != -1)
	{
		x = a[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front++;
			if (front > MAX - 1) front = 0;
		}
		return 1;
	} return 0;
}
void Xuat(int a[],int front , int rear)
{
	for (int i = front; i <= rear; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int isEmpty(int a[], int front, int rear)
{
	if (front == -1)
		return 1;
	return 0;
}
int isFull(int a[], int front, int rear)
{
	if ((rear - front == MAX - 1) || (rear - front == -1))
		return 1;
	return 0;
}