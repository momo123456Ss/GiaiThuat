#include <iostream>
#include <conio.h>
using namespace std;
#define M 11
struct Node
{
	int key;
	Node* next;
};
Node* heads[M];
Node* z;
void init();
Node* insert(int k);
Node* search(int k);
void outputBucket(Node* b);
void outputHashTable();
void delBucket(Node*& b);
void delHashTable();
int Remove(int k);
int DemSoLuongPhanTu(Node* b);
int main()
{
	int chon;
	int in = false;
	int k;
	int del = false;
	do
	{
		system("cls");
		cout << "1.Khoi tao\n2.Them 1 pt\n3.Tim kiem 1 pt\n4.Xuat 1 Bucket\n5.Xuat HashTable\n6.Xoa 1 Bucket\n7.Xoa HashTable\n8.Xoa 1 phan tu\n9.Dem so luong phan tu Heads\n10.Thoat\nBan Chon : ";
		cin >> chon;
			switch (chon)
			{
			case 1 :
				init();
				in = true;
				cout << "Khoi tao thanh cong\n";
				break;
			case 2:
				if (in)
				{
					cout << "Nhap gia tri can them : "; cin >> k;
					insert(k);
					cout << "Them thanh cong\n";
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			case 3:
				if (in)
				{
					cout << "Nhap gia tri can tim : "; cin >> k;
					if (search(k) == z)
						cout << "Gia tri can tim ko ton tai\n";
					else
						cout << "Gia tri can tim co ton tai\n";
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			case 4:
				if (in)
				{
					cout << "Ban can xuat gia tri Bucket thu : "; cin >> k;
					cout << "Heads[" << k << "]: ";
					outputBucket(heads[k]);
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			case 5:
				if (in)
				{
					outputHashTable();
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			case 6 :
				if (in)
				{
					cout << "Ban can xoa Bucket : "; cin >> k;
					delBucket(heads[k]);
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			case 7:
				if (in)
				{
					delHashTable();
					del = true;
					cout << "Da delete Hash Table" << endl;
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			case 8:
				if (in)
				{
					cout << "Nhap phan tu can xoa : "; cin >> k;
					Remove(k);
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			case 9:
				if (in)
				{
					cout << "Nhap Heads de dem so luong gia tri : "; cin >> k;
					cout << "Soluong Gia tri Heads[" << k << "]: " << DemSoLuongPhanTu(heads[k]) << endl;
				}
				else
				{
					cout << "Vui long khoi tao \n";
				}
				break;
			default:
				if (del)
				{
					cout << "Thoat\n";	break;
				}
				else 
				{
					cout << "Mang Bam chua dc huy cap phat" << endl;
				}
				break;
			}
			_getch();
	} while (chon>= 1&&chon<= 9);
	return 0;
}
void init()
{
	z = new Node;
	z->next = z;
	for (int i = 0; i < M; i++)
		heads[i] = z;
}
Node* insert(int k)
{
	Node* t = heads[k % M];
	Node* x = new Node;
	x->key = k;
	z->key = k;
	if (t->key >= k)
	{
		x->next = t;
		heads[k % M] = x;
	}
	else
	{
		Node* p = t->next;
		while (p->key < k)
		{
			t = t->next;
			p = t->next;
		}
		t->next = x;
		x->next = p;
	}
	return x;
}
Node* search(int k)
{
	Node* t = heads[k % M];
	z->key = k;
	while (t->key < k)
	{
		t = t->next;
	}
	if (t->key != k)
		return z;
	return t;
}
void outputBucket(Node* b)
{
	Node* t = b;
	while (t != z)
	{
		cout << t->key << ' ';
		t = t->next;
	}
	cout << endl;
}
void outputHashTable()
{
	
	for (int i = 0; i < M; i++)
	{
		cout << "Head[" << i << "] : ";
		outputBucket(heads[i]);
	}
}
void delBucket(Node*& b)
{
	Node* t = b;
	if (t != z)
	{
		Node* p = t;
		t= t->next;
		delete p;
	}
	b = z;
}
void delHashTable()
{
	for (int i = 0; i < M; i++)
	{
		delBucket(heads[i]);
	}
}
int Remove(int k)
{
	Node* t = heads[k % M];
	Node* prev = NULL;
	z->key = k;
	if (t == NULL)
	{
		cout << "No Element found at key " << k << endl;
		return 1;
	}
	while (t->key < k)
	{
		prev = t;
		t = t->next;
	}
	if (t->key = k)
	{
		prev->next = t->next;
		delete t;
	}
	else
	{
		heads[k % M] = NULL;
	}
	cout << "Element Deleted" << endl;
	return 1;
}
int DemSoLuongPhanTu(Node* b)
{
	int count = 0;
	Node* t = b;
	while (t != z)
	{
		count++;
		t = t->next;
	}
	return count;
}