#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
	int info;
	node* link = NULL;
};

node* first = NULL; //First không phải là phần tử đầu tiên mà là chứa địa chỉ của phần tử đầu tiên

//Function prototype
void init(int& n);
void process_list(); //Duyệt tùng phần tử trong danh sách
node* search(int x); //Tìm kiếm giá trị x, trả về địa chỉ phần tử chứa x hoặc NULL
void insert_first(int x); //Thêm 1 phần tử vào đầu danh sách
void insert_last(int x); //Thêm 1 phần tử vào cuối danh sách
//int insert_at(int i,int x); //Thêm 1 phần tử tại vị trí thứ i
int insert_after(int x, int value);
void delete_first(); //Xóa phần tử đầu tiên
void delete_last(); //Xóa phần tử cuối cùng
void delete_all(); //Xóa toàn bộ phần tử khi kết thúc chương trình
int delete_after_node(int x);
int delete_at_node(int x);
bool is_prime(int x);
int number_of_node();
int number_of_prime();
void sapxepTang();
void swap(int& x, int& y);
void searchDelete(int x);
int main()
{
	//menu
	int choose, x, n = 0; //n là số lượng phần tử trong danh sách
	do
	{

		system("cls");
		cout << "1.Xuat danh sach. \n2.Tim gia tri x trong danh sach. \n"
			<< "3.Them 1 phan tu vao dau danh sach.\n4.Them 1 phan tu vao cuoi danh sach.\n"
			<< "5.Xoa phan tu dau tien.\n6.Xoa phan tu cuoi cung.\n7.Them vao sau 1 phan tu bat ky\n"
			<< "8.Xoa 1 node sau 1 phan tu.\n9.Dem so luong phantu.\n10.Dem so nguyen to.\n11.Xoa 1 phan tu\n"
			<< "12.Xep Tang dan\n13.Thoat\n";
		cout << "\nMoi chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (first != NULL)
				process_list();
			break;
		case 2:
			if (first != NULL)
			{
				int x;
				cout << "Nhap vao gia tri can tim: ";
				cin >> x;
				node* tmp = search(x); //Hàm search trả về NULL hoặc địa chỉ ô nhớ chứa giá trị x
				if (tmp != NULL)
					cout << "Dia chi o nho cua phan tu chua x: " << tmp << endl;
				else cout << "Khong tim thay " << x << endl;
			}
			break;
		case 3:

			cout << "Nhap vao gia tri: ";
			cin >> x;
			insert_first(x);
			break;
		case 4:
			cout << "Nhap vao gia tri: ";
			cin >> x;
			insert_last(x);
			break;
		case 5:
			if (first != NULL)
				delete_first();
			break;
		case 6:
			if (first != NULL)
				delete_last();
			break;
		case 7:
			if (first != NULL)
			{
				int value;
				cout << "Nhap vao gia tri can them sau: ";
				cin >> x;
				cout << "Nhap vao gia tri: ";
				cin >> value;
				if (insert_after(x, value))
					cout << "Success!\n";
				else cout << "Fail\n";
			}
			break;
		case 8:
			if (first != NULL)
			{
				cout << "Nhap vao gia tri : ";
				cin >> x;
				if (delete_after_node(x))
					cout << "Success!\n";
				else cout << "Fail\n";
			}
			break;
		case 9:
			if (first != NULL)
			{
				int count = number_of_node();
				cout << count << " phan tu trong danh sach.\n";
			}
			break;
		case 10:
			if (first != NULL)
			{
				int count = number_of_prime();
				cout << count << " so nguyen to trong danh sach.\n";
			}
			break;
		case 11:
			if (first != NULL)
			{
				cout << "Nhap vao gia tri muon xoa : ";
				cin >> x;
				searchDelete(x);
				cout << "Success!\n";
			}
			break;
		case 12:
			if (first != NULL)
			{
				cout << "Sap xep tang dan\n ";
				sapxepTang();
				process_list();
				
			}
			break;
		default:
			cout << "Ban chon thoat.\n";
			break;
		}

		if (first == NULL) //Danh sách đang rỗng
			cout << "Danh sach dang rong";
		_getch();

	} while (choose >= 1 && choose <= 12);
	delete_all();
	return 0;
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

node* search(int x)
{
	node* p = first;
	//Nếu p chưa trỏ tới cuối mảng và chưa tìm thấy x thì xét phần tử tiếp theo
	while (p != NULL && p->info != x)
		p = p->link; //Trỏ p đến phần tử tiếp theo trong danh sách
	return p;
}

void insert_first(int x)
{
	node* p = new node; //Tạo 1 phần tử mới
	if (p == NULL) return;
	p->info = x; //Gán giá trị x của biến info của p
	p->link = first; //Gán địa chỉ ô nhớ của first cho con trỏ link của p
	first = p; //Gán địa chỉ ô nhớ của p cho biến first
}

void insert_last(int x)
{
	node* tmp = new node; //Tạo 1 phần tử mới
	tmp->info = x; //Gán giá trị x cho biến info của tmp
	tmp->link = NULL;
	if (first == NULL) //Chưa có phần tử đầu thì gán địa chỉ ố nhớ cho biến first
		first = tmp;
	else
	{
		node* p = first; //Gán địa chỉ ô nhớ của first cho biến p
		while (p->link != NULL) //Duyệt tới địa chỉ ô nhớ của phần tử cuối cùng
			p = p->link;
		p->link = tmp; //Gán địa chỉ ô nhớ phần tử mới cho con trỏ link ở phần tử cuối cùng
	}
}

//int insert_at(int i, int x)
//{
//	if (i < 0 || i >= n) //condition: 0 <= i < n
//		return 0;
//	else
//	{
//		node* tmp = new node; //Tạo 1 vùng nhớ mới
//		tmp->info = x; //Gán giá trị x cho biến info của tmp
//		int pos = 0; //Đếm vị trí trong danh sách, bắt đầu từ vị trí thứ nhất
//		node* p, * q = NULL;
//		p = first;
//		while (pos < i && p->link != NULL) //Duyệt tới phần tử cuối cùng trong danh sách
//		{
//			q = p; //Gán địa chỉ ô nhớ của p cho q
//			p = p->link; //Gán địa chỉ ô nhớ biến link của p cho p
//			++pos;
//		}
//		if (p != first) //Nếu p là phần tử đầu tiên thì không tồn tại q
//		{
//			q->link = tmp;
//			tmp->link = p;
//		}
//		else //Trường hợp p là phần tử đầu tiên
//		{
//			tmp->link = first; //Gán địa chỉ ô nhớ của first cho biến link của tmp
//			first = tmp; //Gán địa chỉ ô nhớ của tmp cho biến first
//		}
//		return 1; //Thực hiện thành công quá trình thêm phần tử tại i
//	}
//}

int insert_after(int x, int value)
{
	node* p = search(x);
	if (p != NULL)
	{
		node* tmp = new node;
		tmp->info = value;
		tmp->link = p->link;
		p->link = tmp;
		return 1;
	}
	else return 0;
}

void delete_first()
{
	node* p = first; //Lưu lại địa chỉ ô nhớ của phần tử đầu tiên
	first = first->link; //Phần tử tiếp theo sẽ được đặt làm phần tử đầu tiên
	//Gán địa chỉ ô nhớ của phần tử tiếp theo cho con trỏ first
	delete p; //Thu hồi lại địa chỉ ô nhớ của phần tử đầu tiên.
}

void delete_last()
{
	//Tìm địa chỉ ô nhớ của phần tử cuối cùng và địa chỉ ô nhớ của phần tử áp cuối(nếu có)
	//Gán giá trị NULL cho biến link của q
	//Thu hồi vùng nhớ phần tử cuối cùng con trỏ p
	node* p, * q = NULL;
	p = first; //Gán địa chỉ ô nhớ của phần tử đầu tiên cho biến p
	while (p->link != NULL) //Kiểm tra xem p đã trỏ đến địa chỉ ô nhớ của phần tử cuối cùng
	{
		q = p; //Gán địa chỉ ô nhớ của p cho q 
		p = p->link; //Gán địa chỉ ô nhớ của phần tử tiếp theo cho p
	}
	if (p != first) //Nếu như p là phần tử đầu thì không tồn tại q
		q->link = NULL; //Gán giá trị NULL cho biến link của q
	else first = NULL;
	delete p;
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
int delete_after_node(int x)//xoa 1 node phia sau x
{
	if (first != NULL)
	{
		node* kq = search(x);
		if (kq == NULL) 
			return 0;
		if (kq->link == NULL)
		{
			return 0;
		}
		else
		{
			node* p = kq->link;
			kq->link = p->link;
			delete p;
			return 1;
		}
	}
	return 0;
}
int delete_at_node(int x) {
	node* p, * q = NULL;
	p = first; 
	while (p->link != NULL) 
	{
		q = p;
		p = p->link; 
		if (p == search(x)) {
			delete p;
			return 1;
		}
	}
	return 0;
}
bool is_prime(int x)
{
	if (x <= 1)
		return false;
	for (int i = 2; i <= sqrt((double)x); i++)
		if (x % i == 0)
			return false;
	return true;
}

int number_of_prime()
{
	node* p = first;
	int count = 0;
	while (p != NULL) //Duyệt từng phần tử
	{
		if (is_prime(p->info))
			++count;
		p = p->link;
	}
	return count;
}
int number_of_node()
{
	node* p = first;
	int count = 0;
	while (p != NULL) //Duyệt từng node 1 
	{
		++count;
		p = p->link;
	}
	return count;
}
void sapxepTang()
{
	node* p, * q;
	p = first;
	while (p->link != NULL)
	{
		q = p->link;
		while (q!=NULL)
		{
			if (p->info > q->info)
				swap(p->info, q->info);
			q = q->link;
		}
		p = p->link;
	}
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