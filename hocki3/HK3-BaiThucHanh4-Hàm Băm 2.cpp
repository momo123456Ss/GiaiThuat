//#include <iostream>
//#include <conio.h>
//using namespace std;
//#define M 20
//struct Node
//{
//	int key;
//	int next;
//};
//Node T[M];
//int r = M - 1;
//void init();
//int h(int x);
//int insert(int x);
//int search(int x);
//void outputHashTable();
//int delete1phantu(int x);
//int main()
//{
//	int chon;
//	int in = false;
//	int x;
//	int del = false;
//	do
//	{
//		system("cls");
//		cout << "1.Khoi tao\n2.Them 1 pt\n3.Tim kiem 1 pt\n4.Xuat HashTable\n5.Xoa 1 phan tu\n6.Thoat\nBan Chon : ";
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			init();
//			in = true;
//			cout << "Khoi tao thanh cong\n";
//			break;
//		case 2:
//			if (in)
//			{
//				cout << "Nhap gia tri can them : "; cin >> x;
//				insert(x);
//				cout << "Them thanh cong\n";
//			}
//			else
//			{
//				cout << "Vui long khoi tao \n";
//			}
//			break;
//		case 3:
//			if (in)
//			{
//				cout << "Nhap gia tri can tim : "; cin >>x;
//				if (search(x))
//					cout << "Gia tri " <<x<< " can tim co trong mang bam\n";
//				else
//					cout << "Gia tri "<<x<<" khong co trong mang bam\n";
//			}
//			else
//			{
//				cout << "Vui long khoi tao \n";
//			}
//			break;
//		case 4 :
//			if (in) {
//				cout << "Xuat HashTable" << endl;
//				outputHashTable();
//			}
//			else
//			{
//				cout << "Vui long khoi tao \n";
//			}
//			break;
//		case 5 : 
//			if (in) {
//				cout << "Nhap phan tu can xoa : "; cin >> x;
//				if (delete1phantu(x))
//					cout << "Xoa thanh cong \n";
//				else
//					cout << "Xoa that bai\n";
//			}
//			else
//			{
//				cout << "Vui long khoi tao \n";
//			}
//			break;
//		default:
//			cout << "Thoat\n";
//			break;
//		}
//		_getch();
//	} while (chon >= 1 && chon <= 5);
//	return 0;
//}
//void init()
//{
//	for (int i = 0; i < M; i++)
//	{
//		T[i].key = -1;
//		T[i].next = -1;
//	}
//}
//int h(int x)
//{
//	return (x % 10);
//}
//int search(int x)
//{
//	int i = h(x);
//	while (x != T[i].key && i != -1)
//	{
//		i = T[i].next;
//		if (x == T[i].key)
//			return i;
//		else
//			return -1;
//	}
//}
//int insert(int x)
//{
//	int i, j;
//	i = h(x);
//	if ((T[i].key != x) && (T[i].key != -1))
//	{
//		do {
//			j = i;
//			i = T[i].next;
//		} while ((T[i].key != x) && (i != -1));
//		if (i == -1)
//		{
//			while (r != -1 && T[r].key != -1) r--;
//			if (r < 10) return -1;
//			if (r != -1) T[j].next = r;
//			i = r;
//		}
//	}
//	if (i != -1 && T[i].key != x)
//		T[i].key = x;
//	return i;
//}
//void outputHashTable()
//{
//	for (int i = 0; i < M; i++)
//	{
//		cout << "T[" << i << "]: " << T[i].key << " " << endl;
//	}
//	
//}
//int delete1phantu(int x)
//{
//	int i = search(x);
//	if (i != -1)
//	{
//		int j = i;
//		while (T[i].next != -1)
//		{
//			i = T[i].next;
//			T[j].key = T[i].key;
//			if (T[i].next == -1)
//				T[j].next = -1;
//			j = i;
//		}
//		T[j].key = -1;
//		T[j].next = -1;
//		return 1;
//	}
//	return 0; //Xoa that bai
//}