#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
	int info;
	node* link = NULL;
};
node* first = NULL; //First không phải là phần tử đầu tiên mà là chứa địa chỉ của phần tử đầu tiên
node* sp;
void init();
node* search(int x);
void delete_all();
void insert_first_TangDan(int x);
void process_list();
void swap(int& x, int& y);
void searchDelete(int x);
int main()
{
	int choose, x, n = 0, in = 0; //n là số lượng phần tử trong danh sách
	do
	{

		system("cls");
		cout << "1.Khoi tao danh sach. \n2.Them 1 phan tu.\n"
			<< "3.Xuat danh sach. \n4.Tim mot phan tu.\n"
			<< "5.Xoa 1 phan tu.\n6.Giai phong vung nho.\n7.Thoat.\n";
		cout << "\nMoi chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1 :
			if (in == 1)
			{
				cout << "Mang da khoi tao roi!!\n";
			}
			else
			{
				init();
				in = 1;
				cout << "Khoi tao danh sach thanh cong!!\n";
			}
			break;
		case 2:
			if (in == 1)
			{
				cout << "Nhap phan tu can them vao danh sach: "; cin >> x;
				insert_first_TangDan(x);
				cout << "Them phan tu " << x << " thanh cong!!\n";
			}
			else
			{
				cout << "Vui long khoi tao danh sach\n";
			}
			break;
		case 3:
			if (in == 1)
			{
				process_list();
			}
			else
			{
				cout << "Vui long khoi tao danh sach\n";
			}
			break;
		case 4 :
			if (in == 1)
			{
				cout << "Nhap phan tu muon tim: "; cin >> x;
				node* tmp = search(x); //Hàm search trả về NULL hoặc địa chỉ ô nhớ chứa giá trị x
				if (tmp != NULL)
					cout << "Dia chi o nho cua phan tu chua x: " << tmp << endl;
				else cout << "Khong tim thay " << x << endl;
			}
			else
			{
				cout << "Vui long khoi tao danh sach\n";
			}
			break;
		case 5:
			if (in == 1)
			{
				cout << "Nhap vao phan tu muon xoa : ";
				cin >> x;
				node* tmp = search(x); //Hàm search trả về NULL hoặc địa chỉ ô nhớ chứa giá trị x
				if (tmp != NULL) {
					searchDelete(x);
					cout << "Success!\n";
				}
				else
				{
					cout << "Phan tu khong ton tai\n";
				}
			}
			else
			{
				cout << "Vui long khoi tao danh sach\n";
			}
			break;
		case 6:
			if (in == 1)
			{
				delete_all();
				in = 0;
			}
			else
			{
				cout << "Vui long khoi tao danh sach\n";
			}
			break;
		}
		_getch();
	} while (choose >= 1 && choose <= 6);
	return 0;
}
void init()
{
	sp = NULL;
}
void process_list()
{
	node* p = first;
	cout << "Cac phan tu trong danh sach: \n";
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
}
void insert_first_TangDan(int x)
{
	node* p = new node; //Tạo 1 phần tử mới
	if (p == NULL) return;
	p->info = x; //Gán giá trị x của biến info của p
	p->link = first; //Gán địa chỉ ô nhớ của first cho con trỏ link của p
	first = p; //Gán địa chỉ ô nhớ của p cho biến first
	node* q = NULL;
	while (p->link != NULL)
	{
		q = p->link;
		while (q != NULL)
		{
			if (p->info > q->info)
				swap(p->info, q->info);
			q = q->link;
		}
		p = p->link;
	}
}
void delete_all()
{
	if (first != NULL) {
		node* p = first; //Gán địa chỉ ô nhớ của phần tử đầu tiên cho p
		while (p != NULL) //Duyệt tới phần tử cuối cùng trong danh sách
		{
			first = first->link; //Gán địa chỉ ô nhớ của phần tử tiếp theo cho biến first
			delete p; //Thu hồi địa chỉ vùng nhớ con trỏ p
			p = first; //gán địa chỉ ô nhớ của first cho p
		}
	}
}
node* search(int x)
{
	node* p = first;
	//Nếu p chưa trỏ tới cuối mảng và chưa tìm thấy x thì xét phần tử tiếp theo
	while (p != NULL && p->info != x) {
		if (p->info > x) return NULL;
		p = p->link; //Trỏ p đến phần tử tiếp theo trong danh sách
	}
	return p;
}
void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void searchDelete(int x)
{
	node* p, * q;
	q = NULL;
	if (first == NULL)
	{
		cout << "Danh sach rong\n";
		return;
	}
	p = first;
	while (p != NULL && p->info != x)
	{
		q = p;
		p = p->link;
	}
	if (p == NULL)
	{
		cout << "Khong co trong danh sach\n";
		return;
	}
	if (q == NULL)
		first = first->link;
	else
		q->link = p->link;
	delete p;
}