#include <iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int info; // lưu trữ giá trị của phần tử, giá trị khóa của node
	Node* left; // left lưu địa chỉ phần tử bên trái (cây con trái)
	Node* right; //right lưu trữ địa chỉ phần tử bên phải (cây con phải)
};
// cấu trúc 1 node
Node* root;
void init()
{
	root = NULL;
}
// root là biến toàn cục;
Node* search(Node* p, int x);
Node* search_Dequy(Node* p, int x);
//Tim 1 node
Node* FindNode(Node* root, int x);
void duyetLRN(Node* p);
void duyetNLR(Node* p);
void duyetLNR(Node* p);
void InsertNode(Node*& p, int x);
//Tim kiem 1 node va xoa
int Delete(Node*& T, int x);
void searchStandFor(Node*& p, Node*& q);
//Xoa toan bo node
void DestroyTree(Node*& p);
void XuatCayNhiPhan(Node* p, int space);
int demNode(Node* p);
int TrungBinhCong(Node* p);//trung bình cộng
void NLR_NoRe(Node* p);
void LRN_NoRe(Node* p);
//Stack bang danh sach lien ket don
struct NodeS
{
	int info;
	NodeS* link;
};
NodeS* st;// dinh cua stack
void initStack()
{
	st = NULL;
}
bool isEmptyS() 
{
	return st == NULL;
}
void pushS(int x)
{
	NodeS* p = new NodeS;
	if (!p) return;
	p->info = x;
	p->link = st;
	st = p;
}
void popS(int& x)
{
	NodeS* p = st;
	x = st->info;
	st = p->link;
	delete p;
}
void LNR_KhongDeQuy(Node* p);
int tong = 0;
int main()
{
	int choose, x, in = 0;
	Node* p = NULL;
	do
	{

		system("cls");
		cout << "1.Khoi tao danh sach. \n2.Them 1 node cay nhi phan tim kiem. \n"
			<< "3.Xoa 1 node cay nhi phan tim kiem. \n4.Tim kiem 1 node. \n"
			<< "5.Duyet NLR. \n6.Duyet LRN. \n"
			<< "7.Duyet LNR\n8.Xoa toan bo node \n9.Xuat toan bo cay nhi phan\n"
			<< "10.Dem so Node\n11.Tinh trung binh cong cac phan tu\n12.Duyet LNR khong de quy Stack\n";

		cout << "\nMoi chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init();
			in = 1;
			cout << "Khoi tao thanh cong!!\n";
			break;
		case 2: 
			if (in == 1)
			{
				cout << "Them 1 node : "; cin >> x;
				InsertNode(p, x);
				cout << "Them thanh cong!!\n";
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 3:
			if (in == 1)
			{
				cout << "Xoa 1 node : "; cin >> x;
				if (Delete(p, x)) {
					cout << "Xoa thanh cong!!\n";
				}
				else
				{
					cout << "Xoa khong thanh cong!!\n";
				}
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 4:
			if (in == 1)
			{
				cout << "Nhap node muon tim kiem : "; cin >> x;
				cout << "Dia chi cua Node can tim: " << search_Dequy(p,x) << endl;
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 5:
			if (in == 1)
			{
				cout << "Duyet Node Left Right\n ";
				duyetNLR(p);
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 6:
			if (in == 1)
			{
				cout << "Duyet  Left Right Node\n ";
				duyetLRN(p);
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 7:
			if (in == 1)
			{
				cout << "Duyet  Left Node Right\n ";
				duyetLNR(p);
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 8:
			if (in == 1)
			{
				DestroyTree(p);
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 9:
			if (in == 1)
			{
				XuatCayNhiPhan(p, 0);
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 10:
			if (in == 1)
			{
				cout << "so luong node trong cay nhi phan: " << demNode(p) << endl;
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 11:
			if (in == 1)
			{
				cout << "Trung binh cong cac phan tu: " << TrungBinhCong(p)/demNode(p) << endl;
				tong = 0;
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		case 12:
			if (in == 1)
			{
				LRN_NoRe(p);
			}
			else
			{
				cout << "Vui long khoi tao cay nhi phan \n";
			}
			break;
		default:
			cout << "Ban chon thoat.\n";
			break;
		}
		_getch();

	} while (choose >= 1 && choose <= 12);
	return 0;
}
Node* search(Node* p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				p = p->left;
			else // p->info<x
				p = p->right;
	}
	return NULL;
}
Node* search_Dequy(Node* p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}
void InsertNode(Node *&p, int x)
{
	if (p == NULL) {
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else {
		if (p->info == x){
			cout << "Node da ton tai!!\n";
			return; // đã có node có giá trị x
		}
		else if (p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
void duyetLNR(Node* p)//Left node Right
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}
void duyetNLR(Node* p)// node Left Right
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
void duyetLRN(Node* p)//Left Right node
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}
void searchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->info == q->info;
			p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(Node*& T, int x)
{
	if (T == NULL) return 0;
	if (T->info == x)
	{
		Node* p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else // có 2 con
			searchStandFor(p,T->right);
		delete p;
		return 1;
	}
	if (T->info < x) return Delete(T->right, x);
	if (T->info > x) return Delete(T->left, x);
}
Node* FindNode(Node* root, int x)
{
	if (root)
	{
		if (root->info == x) // Tìm thấy
			return root;
		if (x < root->info)
			return FindNode(root->left, x); // Tìm cây con bên trái
		return FindNode(root->right, x); // Tìm cây con bên phải
	}
	return NULL; // Không tìm thấy
}
void DestroyTree(Node*& p)
{
	if (p)
	{
		DestroyTree(p->left);
		DestroyTree(p->right);
		p = NULL;
		delete p;
	}
}
void XuatCayNhiPhan(Node* p,int space)
{
	int count = 10;
	if (p == NULL) return;
	space += count;
	XuatCayNhiPhan(p->right,space);
	cout << endl;
	for (int i = count; i < space; i++)
		cout << " ";
	cout << p->info << " ";
	XuatCayNhiPhan(p->left, space);
}
int demNode(Node* p)
{
	if (p != NULL) {
		if (p->left == NULL && p->right == NULL)
		{
			return 1;
		}
		else {
			return 1 + demNode(p->left) + demNode(p->right);
		}
	}
	else
	{
		return 0;
	}
}
int TrungBinhCong(Node* p)//Right node Left
{
	if(p != NULL)
	{
		tong += p->info;
		TrungBinhCong(p->left);
		TrungBinhCong(p->right);
	}
	return tong;
}
void LNR_KhongDeQuy(Node* p)
{
	initStack();
	Node* curr = p;
	while (curr != NULL || !isEmptyS())
	{
		while (curr != NULL)
		{
			pushS(curr->info);
			curr = curr->left;
		}
		int x;
		popS(x);
		cout << x << " ";
		curr = search(p, x);
		curr = curr->right;
	}
}
void NLR_NoRe(Node* p)
{
	initStack();
	if (p == NULL) return;
	Node* curr = p;
	pushS(p->info);
	while (!isEmptyS())
	{
		int x; 
		popS(x);
		cout << x << " ";
		curr = search(p, x);
		if (curr->right != NULL)
		{
			curr = curr->right;
			pushS(curr->info);
		}
		curr = search(p, x);
		if (curr->left != NULL)
		{
			curr = curr->left;
			pushS(curr->info);
		}
	}
}
void LRN_NoRe(Node* p)
{
	initStack();
	if (p == NULL) return;
	Node* curr = p;
	pushS(p->info);
	while (!isEmptyS())
	{
		int x;
		popS(x);
		cout << x << " ";
		curr = search(p, x);
		if (curr->right != NULL)
		{
			curr = curr->right;
			pushS(curr->info);
		}
		curr = search(p, x);
		if (curr->left != NULL)
		{
			curr = curr->left;
			pushS(curr->info);
		}
	}
}