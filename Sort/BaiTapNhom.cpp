#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <conio.h>
#pragma warning(disable:4996)
time_t baygio = time(0);
tm* ltm = localtime(&baygio);
using namespace std;
#define MAX 20
char vertex[MAX+1][MAX+1];
int a[MAX][MAX]; // mảng hai chiều
int n; // số đỉnh của đồ thị
int C[100]; // lưu trữ đỉnh chưa xét; 
// 1 là chưa xét; 0 là đã xét
int bfs[100];// lưu danh sách phần tử đã duyệt
int nbfs = 0; // chỉ số lưu đỉnh đã xét
int B[MAX][MAX];
int m; // so dinh cua do thi
// khai bao TapE
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // so phan tu tap E
// khai bao TapE
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; // so phan tap T
struct Node
{
	int info;
	Node* link;
};
Node* sp;
Node* front, * rear;
struct Day
{
	int ngay = 0;
	int thang = 0;
	int nam = 0;
};
typedef struct Day DAY;
void Doc_Ngay_Thang_Nam(ifstream& filein, DAY &date)
{
	filein >> date.ngay;
	filein.seekg(1, 1);
	filein >> date.thang;
	filein.seekg(1, 1);
	filein >> date.nam;
}
struct ChienDich
{
    string machiendich;
    string tenchiendich;
	DAY ngaybatdau;
	DAY ngayketthuc;
};
typedef struct ChienDich CHIENDICH;
struct TinhNguyenVien
{
    string matinhnguyenvien;
    string holot;
    string ten;
	DAY ngaythangnamsinh;
    int sodienthoai;
	string machiendichcuatinhnguyenvien;
};
typedef struct TinhNguyenVien TINHNGUYENVIEN;
//Khai bao cau truc node 
struct node1
{
	TINHNGUYENVIEN data;
	struct node1* pNext{};
};
typedef struct node1 NODE1; 
struct node2
{
	CHIENDICH data2;
	struct node2* pNext2{};
};
typedef struct node2 NODE2;
//KHAI BAO CAU TRUC DANH SACH LIEN KET DON 
struct list1 //cua Tinh nguyen vien
{
	NODE1* pHead;
	NODE1* pTail;
};
typedef struct list1 LIST1;
struct list2//cua Chien Dich
{
	NODE2* pHead2;
	NODE2* pTail2;
};
typedef struct list2 LIST2;
//Khoi tao danh sach lien ket cac tinh nguyen vien
void KhoiTaoDanhSachTNV(LIST1 &l)//Cua Tinh Nguyen Vien
{
	l.pHead = NULL;
	l.pTail = NULL;
}
//Khoi tao danh sach lien ket cac chien dich
void KhoiTaoDanhSachChienDich(LIST2& l2)
{
	l2.pHead2 = NULL;
	l2.pTail2 = NULL;
}
//Khoi tao 1 node de chuan bi them vao danh sach tinh nguyen vien
NODE1* KhoiTaoNode(TINHNGUYENVIEN x)//cua Tinh Nguyen Vien
{
	NODE1* p = new NODE1;
	if (p == NULL)
	{
		cout << "Cap phat that bai\n";
		return NULL;
	}
	p->data = x;// dua du lieu tinh nguyen vien x vao danh sach lien ket
	p->pNext = NULL;//khoi tao node p nhung node p chua co lien ket
	return p;
}
//Khoi tao 1 node de chuan bi them vao danh sach chien dich
NODE2* KhoiTaoNodeChienDich(CHIENDICH x)
{
	NODE2* g = new NODE2;
	if (g == NULL)
	{
		cout << "Cap phat that bai\n";
		return NULL;
	}
	g->data2 = x;// dua du lieu chien dich x vao danh sach lien ket
	g->pNext2 = NULL;//khoi tao node p nhung node p chua co lien ket
	return g;
}
//ham them 1 node vao dau danh sach
void ThemDau(LIST1& l, NODE1* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
//ham them 1 node cuoi danh sach tinh nguyen vien
void ThemCuoi(LIST1& l, NODE1* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
//ham them 1 node cuoi danh sach chien dich
void ThemCuoiChienDich(LIST2& l2, NODE2* p)
{
	if (l2.pHead2 == NULL)
	{
		l2.pHead2 = l2.pTail2 = p;
	}
	else
	{
		l2.pTail2->pNext2 = p;
		l2.pTail2 = p;
	}
}
//kiem tra trung matinhnguyenvien
bool checkmatnv(LIST1 l, string matnv)
{
	for (NODE1* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (matnv == i->data.matinhnguyenvien) {
			return true;
		}
	}
	return false;
}
//ham doc dulieu chien dich
void Doc_ChienDich(ifstream& filein, CHIENDICH& cd)
{
	getline(filein, cd.machiendich, '#');
	getline(filein, cd.tenchiendich, '#');
	Doc_Ngay_Thang_Nam(filein, cd.ngaybatdau);
	filein.seekg(1, 1);
	Doc_Ngay_Thang_Nam(filein, cd.ngayketthuc);
	filein.seekg(1, 1);
	filein.ignore(1);
}
//ham doc du lieu 1 tinhnguyenvien tu File
void Doc_1TinhNguyenVien(ifstream& filein, TINHNGUYENVIEN& tnv)
{
	//doc Ma Tinh Nguyen Vien
	getline(filein, tnv.matinhnguyenvien, '#'); //doc den # thi dung
	getline(filein, tnv.holot, '#');
	getline(filein, tnv.ten, '#');
	Doc_Ngay_Thang_Nam(filein, tnv.ngaythangnamsinh);
	filein.seekg(1, 1);
	filein >> tnv.sodienthoai;
	filein.ignore(1);
	getline(filein, tnv.machiendichcuatinhnguyenvien);
}
//ham xuat 1 tinh nguyen vien
void Xuat(TINHNGUYENVIEN tnv)
{
	cout << "\nMaTinhNguyenVien: " << tnv.matinhnguyenvien;
	cout << "\nHoLot: " << tnv.holot;
	cout << "\nTen: " << tnv.ten;
	cout << "\nNgaySinh: " << tnv.ngaythangnamsinh.ngay << "/" << tnv.ngaythangnamsinh.thang << "/" << tnv.ngaythangnamsinh.nam;
	cout << "\nPhone: " << tnv.sodienthoai;
	cout << "\nMaChienDich: " << tnv.machiendichcuatinhnguyenvien<< endl;
}
//ham xuat 1 chien dich
void XuatCD(CHIENDICH cd)
{
	cout << "\nMaChienDich: " << cd.machiendich;
	cout << "\nTenChienDich: " << cd.tenchiendich;
	cout << "\nNgayBatdau: " << cd.ngaybatdau.ngay << "/" << cd.ngaybatdau.thang << "/" << cd.ngaybatdau.nam;
	cout << "\nNgayKetthuc: " << cd.ngayketthuc.ngay << "/" << cd.ngayketthuc.thang << "/" << cd.ngayketthuc.nam;
}
//ham doc danh sach tinh nguyen vien tu file
void Doc_DanhSachTinhNguyenVien(ifstream& filein, LIST1& l)
{//doc den cuoi file thi dung
	while (!filein.eof())
	{//doc thong tin 1 tnv
		TINHNGUYENVIEN tnv;
		Doc_1TinhNguyenVien(filein, tnv);
		// tao 1 node tnv
		NODE1* p = KhoiTaoNode(tnv);
		// them tinh nguyen vien  vao danh sach lien ket don 
		ThemCuoi(l, p);
	}	
}
//doc danh sach chien dich
void Doc_DanhSachChienDich(ifstream& filein, LIST2& l)
{//doc den cuoi file thi dung
	while (!filein.eof())
	{//doc thong tin 1 tnv
		CHIENDICH cd;
		Doc_ChienDich(filein, cd);
		// tao 1 node tnv
		NODE2* g = KhoiTaoNodeChienDich(cd);
		// them tinh nguyen vien  vao danh sach lien ket don 
		ThemCuoiChienDich(l, g);
	}
}
//Ham xuat danh sach tnv 
void Xuat_DanhSachTNV(LIST1 l)
{
	int dem = 1;
	for (NODE1 *k = l.pHead; k != NULL;k= k ->pNext)
	{
		cout << "\n\tTinh Nguyen Vien Thu " << dem++;
		Xuat(k->data);
	}
}
//Xuất ds chiến dịch
void Xuat_DanhSachCD(LIST2 l2)
{
	int dem = 1;
	for (NODE2* u = l2.pHead2; u != NULL; u = u->pNext2)
	{
		cout << "\n\n\t\tChien Dich Thu " << dem++;
		XuatCD(u->data2);
	}
	cout << endl;
}
//Hàm giải phóng vùng nhớ ds tình nguyện viên
void GiaiPhongVungNho(LIST1 l)
{
	NODE1* p = NULL;
	while (l.pHead!=NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
//Hàm giải phóng vùng nhớ ds chiến dịch
void GiaiPhongVungNhoCD(LIST2 l2)
{
	NODE2* p = NULL;
	while (l2.pHead2 != NULL)
	{
		p = l2.pHead2;
		l2.pHead2 = l2.pHead2->pNext2;
		delete p;
	}
}
//thêm 1 tình nguyện viện
TINHNGUYENVIEN* NhapTNV(ofstream &fileout, LIST1& l, string matnv)
{
	TINHNGUYENVIEN* tnv = new TINHNGUYENVIEN;
	NODE1* p = new NODE1;
	cin.ignore();
	cout << "Nhap ma tinh nguyen vien: ";
	getline(cin,matnv);
	if (checkmatnv(l,matnv) == true) 
	{
		cout << "Ma tinh nguyen vien da ton tai\n";
	}
	else if (checkmatnv(l, matnv) == false)
	{
		tnv->matinhnguyenvien = matnv;
		cout << "Nhap Ho Lot: ";
		getline(cin, tnv->holot);
		cout << "Nhap Ten: ";
		getline(cin, tnv->ten);
		cout << "Nhap Ngay-Thang-Nam Sinh: " << endl;
		cout << "Nhap Ngay: ";
		cin >> tnv->ngaythangnamsinh.ngay;
		cout << "Nhap Thang: ";
		cin >> tnv->ngaythangnamsinh.thang;
		cout << "Nhap Nam: ";
		cin >> tnv->ngaythangnamsinh.nam;
		cout << "Nhap So Dien Thoai: ";
		cin >> tnv->sodienthoai;
		cin.ignore();
		cout << "Nhap MaChienDich(MaChienDich Muon Tham Gia): ";
		getline(cin, tnv->machiendichcuatinhnguyenvien);
		ThemCuoi(l, p);
		fileout << "\n" << tnv->matinhnguyenvien << "#" << tnv->holot << "#" << tnv->ten << "#" << tnv->ngaythangnamsinh.ngay << "/" << tnv->ngaythangnamsinh.thang << "/" << tnv->ngaythangnamsinh.nam << "#" << tnv->sodienthoai << "#" << tnv->machiendichcuatinhnguyenvien;
		return tnv;
	}
}
//Ham hoan vi cua Tinhnguyenvien
void Hoan_Vi_TNV(TINHNGUYENVIEN& x, TINHNGUYENVIEN& y)
{
	TINHNGUYENVIEN tmp = x;
	x = y;
	y = tmp;
}
void Hoan_Vi_CD(CHIENDICH& x, CHIENDICH& y)
{
	CHIENDICH tmp = x;
	x = y;
	y = tmp;
}
//Hàm tìm tình nguyện viên nhỏ tuổi nhất
void Xuat_ThongTinTinhNguyenVienNhoTuoiNhat(ifstream &filein,LIST1& l)
{
	int MINTuoi = l.pHead->data.ngaythangnamsinh.nam;
	for (NODE1 *k = l.pHead->pNext; k != NULL; k = k ->pNext)
	{
		if (MINTuoi < k->data.ngaythangnamsinh.nam)
		{
			MINTuoi = k->data.ngaythangnamsinh.nam;
		}
	}
	for (NODE1 *k = l.pHead; k!=NULL ;  k = k->pNext)
	{
		if (MINTuoi == k->data.ngaythangnamsinh.nam)
		{
			cout << "\nMaTinhNguyenVien: " << k->data.matinhnguyenvien;
			cout << "\nHoLot: " << k->data.holot;
			cout << "\nTen: " << k->data.ten;
			cout << "\nNgaySinh: " << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam;
			cout << "\nPhone: " << k->data.sodienthoai;
			cout << "\nMaChienDich: " << k->data.machiendichcuatinhnguyenvien << endl;
		}
	}
}
//Ham tim Tinh Nguyen Vien theo Ma Tinh Nguyen Vien
void TimTNV_MaTNV(LIST1 l, string ma)
{
	for (NODE1 *k = l.pHead;k != NULL ; k = k->pNext)
	{
		if (ma == k->data.matinhnguyenvien)
		{
			Xuat(k->data);
			cout << endl;
		}
	}
}
//Ham tim kiem Tinh Nguyen Vien theo so dien thoai
void TimTNV_Phone(LIST1 l, int phone)
{
	for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (phone == k->data.sodienthoai)
		{
			Xuat(k->data);
			cout << endl;
		}
	}
}
//Ham tim MaChienDich theo TenChienDich
string TimMaChienDich(LIST2 l, string tencd)
{
	for (NODE2* k = l.pHead2; k != NULL; k = k->pNext2)
	{
		if (tencd == k->data2.tenchiendich)
		{
			return k->data2.machiendich;
		}
	}
}
//Ham tim Thong Tin theo TenCD
void TimTNV_TenCD(LIST1 l, string macd)
{
	for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (macd == k->data.machiendichcuatinhnguyenvien)
		{
			Xuat(k->data);
			cout << endl;
		}

	}
}
//Hàm cập nhật thông tin tình nguyện viên
void CapNhatThongTinTNV(LIST1 l, string matnv, ofstream& fileout)
{
	int chon;
	string hotnv, tentnv, macdtnv;
	int sdttnv, ngaysinhtnv, thangsinhtnv, namsinhtnv;
		for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
		{
			if (matnv == k->data.matinhnguyenvien)
			{
				cout << "Thong tin tinh nguyen vien:\n";
				Xuat(k->data);
				cout << endl;
				cout << "Noi dung can cap nhat:\n";
				cout << "1: Cap Nhat Ho Lot\n";
				cout << "2: Cap Nhat Ten\n";
				cout << "3: Cap Nhat SDT\n";
				cout << "4: Cap Nhat NgayThangNam Sinh\n";
				cout << "5: Cap Nhat MaChienDich\n";
				cout << "Chon: ";
				cin >> chon;
				switch (chon)
				{
				case 1:
					cin.ignore();
					cout << "Nhap Ho Lot muon cap nhat lai : ";
					getline(cin, hotnv);
					fileout.open("D:/Test/Test/log.txt", ios::app);
					fileout << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "#" << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << "#HoLotBefore:" << k->data.holot << "#HoLotAfter:" << hotnv << endl;
					fileout.close();
					k->data.holot = hotnv;
					fileout.open("tinhnguyenvien.txt", ios::ate);
					for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
					{
						if (k == l.pHead) {
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
						else
						{
							fileout << endl;
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
					}
					fileout.close();
					cout << "Cap nhat thanh cong vui long kiem tra log.txt de xem chi tiet\n";
					break;
				case 2:
					cin.ignore();
					cout << "Nhap Ten muon cap nhat lai : ";
					getline(cin, tentnv);
					fileout.open("D:/Test/Test/log.txt", ios::app);
					fileout << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "#" << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << "#TenBefore:" << k->data.ten << "#TenAfter:" << tentnv << endl;
					fileout.close();
					k->data.ten = tentnv;
					fileout.open("tinhnguyenvien.txt", ios::ate);
					for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
					{
						if (k == l.pHead) {
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
						else
						{
							fileout << endl;
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
					}
					fileout.close();
					cout << "Cap nhat thanh cong vui long kiem tra log.txt de xem chi tiet\n";
					break;
				case 3:
					cin.ignore();
					cout << "Nhap SDT muon cap nhat lai : ";
					cin >> sdttnv;
					fileout.open("D:/Test/Test/log.txt", ios::app);
					fileout << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "#" << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << "#PhoneBefore:" << k->data.sodienthoai << "#PhoneAfter:" << sdttnv << endl;
					fileout.close();
					k->data.sodienthoai = sdttnv;
					fileout.open("tinhnguyenvien.txt", ios::ate);
					for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
					{
						if (k == l.pHead) {
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
						else
						{
							fileout << endl;
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
					}
					fileout.close();
					cout << "Cap nhat thanh cong vui long kiem tra log.txt de xem chi tiet\n";
					break;
				case 4:
					cin.ignore();
					cout << "Nhap NgaySinh muon cap nhat lai : \n";
					cout << "Ngay: ";
					cin >> ngaysinhtnv;
					cout << "Thang: ";
					cin >> thangsinhtnv;
					cout << "Nam: ";
					cin >> namsinhtnv;
					fileout.open("D:/Test/Test/log.txt", ios::app);
					fileout << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "#" << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << "#BirthBefore:" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#BirthAfter:" << ngaysinhtnv << "/" << thangsinhtnv << "/" << namsinhtnv << endl;
					fileout.close();
					k->data.ngaythangnamsinh.ngay = ngaysinhtnv;
					k->data.ngaythangnamsinh.thang = thangsinhtnv;
					k->data.ngaythangnamsinh.nam = namsinhtnv;
					fileout.open("tinhnguyenvien.txt", ios::ate);
					for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
					{
						if (k == l.pHead) {
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
						else
						{
							fileout << endl;
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
					}
					fileout.close();
					cout << "Cap nhat thanh cong vui long kiem tra log.txt de xem chi tiet\n";
					break;
				case 5:
					cin.ignore();
					cout << "Nhap MaCD muon cap nhat lai : ";
					getline(cin, macdtnv);
					fileout.open("D:/Test/Test/log.txt", ios::app);
					fileout << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "#" << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << "#MaChienDichBefore:" << k->data.machiendichcuatinhnguyenvien << "#MaChienDichAfter:" << macdtnv << endl;
					fileout.close();
					k->data.machiendichcuatinhnguyenvien = macdtnv;
					fileout.open("tinhnguyenvien.txt", ios::ate);
					for (NODE1* k = l.pHead; k != NULL; k = k->pNext)
					{
						if (k == l.pHead) {
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
						else
						{
							fileout << endl;
							fileout << k->data.matinhnguyenvien << "#" << k->data.holot << "#" << k->data.ten << "#" << k->data.ngaythangnamsinh.ngay << "/" << k->data.ngaythangnamsinh.thang << "/" << k->data.ngaythangnamsinh.nam << "#" << k->data.sodienthoai << "#" << k->data.machiendichcuatinhnguyenvien;
						}
					}
					fileout.close();
					cout << "Cap nhat thanh cong vui long kiem tra log.txt de xem chi tiet\n";
					break;
				}
			}
		}
	}
//Ham in danh sach TinhNguyenVien co tuoi <20 va Ten Giam dan
void DanhSachTNV_20(ifstream &filein, LIST1 &l)
{
	int NamHienTai = (1900 + ltm->tm_year);
	for (NODE1 *j = l.pHead; j!= NULL; j = j ->pNext)
	{
		for (NODE1* h = j->pNext; h != NULL; h = h->pNext)
		{
			if (j->data.ten < h->data.ten)
			{
				Hoan_Vi_TNV(j->data, h->data); 
			}
		}
	}
	for (NODE1* j = l.pHead; j != NULL; j = j->pNext)
	{
		if ((NamHienTai - j->data.ngaythangnamsinh.nam) < 20)
		{
			Xuat(j->data);
		}
	}
}
//Xep TNV theo ma chien dich , cung ma chien dich thi xep theo TuoiTNV giam dan
void DanhSachTNV_MaCD(ifstream& filein, LIST1& l)
{
	int NamHienTai = (1900 + ltm->tm_year);
	for (NODE1* j = l.pHead; j != NULL; j = j->pNext)
	{
		for (NODE1* h = j->pNext; h != NULL; h = h->pNext)
		{
			if ((j->data.machiendichcuatinhnguyenvien < h->data.machiendichcuatinhnguyenvien))
			{
				Hoan_Vi_TNV(j->data, h->data);
			}
			else if ((j->data.machiendichcuatinhnguyenvien == h->data.machiendichcuatinhnguyenvien) 
				&& (NamHienTai - j->data.ngaythangnamsinh.nam) 
				< (NamHienTai - h->data.ngaythangnamsinh.nam))
			{
				Hoan_Vi_TNV(j->data, h->data);
			}
		}
	}
	Xuat_DanhSachTNV(l);
}
//Ham Tinh So Ngay trong Nam
int SoNgay(int ngay, int thang, int nam) {
	if (thang < 3) {
		nam--;
		thang += 12;
	}
	return 365 * nam + nam / 4 - nam / 100 + nam / 400 + (153 * thang - 457) / 5 + ngay - 306;
}
//tim ma chien dich co so ngay dien ra nhieu nhat
string TimMaChienDich_SoNgayNhieuNhat(LIST2 l)
{
	string macdtnv;
	for (NODE2* k = l.pHead2; k != NULL; k = k->pNext2)
	{
		for (NODE2* h = k->pNext2; h != NULL; h = h->pNext2)
		{
			if ((SoNgay(k->data2.ngayketthuc.ngay, k->data2.ngayketthuc.thang, k->data2.ngayketthuc.nam) 
				- SoNgay(k->data2.ngaybatdau.ngay, k->data2.ngaybatdau.thang, k->data2.ngaybatdau.nam)) 
				> (SoNgay(h->data2.ngayketthuc.ngay, h->data2.ngayketthuc.thang, h->data2.ngayketthuc.nam) 
					- SoNgay(h->data2.ngaybatdau.ngay, h->data2.ngaybatdau.thang, h->data2.ngaybatdau.nam)))
			{
				macdtnv = k->data2.machiendich;
			}
			macdtnv = h->data2.machiendich;
		}
	}
	return macdtnv;
}
//In DS Tinh nguyen vien theo ma chien dich
void DSTNV_TenCD(LIST1 l, LIST2 l2)
{
	for (NODE2* k = l2.pHead2; k != NULL; k = k->pNext2)
	{
		for (NODE2* h = k->pNext2; h != NULL; h = h->pNext2)
		{
			if (k->data2.tenchiendich > h->data2.tenchiendich)
			{
				Hoan_Vi_CD(k->data2, h->data2);
			}
		}
	}
	for (NODE2* k = l2.pHead2; k != NULL; k = k->pNext2)
	{
		for (NODE1* h = l.pHead; h != NULL; h = h->pNext)
		{
			if (k->data2.machiendich == h->data.machiendichcuatinhnguyenvien) {
				Xuat(h->data);
			}
		}
	}
}
//Xep danh sach theo matinhnguyenvien giam dan
void XepTNV_GiamDan(LIST1 l)
{
	for (NODE1 *i = l.pHead; i!=NULL; i=i->pNext)
	{
		for (NODE1* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (i->data.matinhnguyenvien > j->data.matinhnguyenvien)
				Hoan_Vi_TNV(i->data, j->data);
		}
	}
}
void inputMatrixFile(int a[][MAX], int& n);
void output();
void initEdgesStatus();
void initQueue();
int isEmptyQueue();
void pushQ(int x);
void popQ(int& x);
void Search_by_BFS(int x, int v);
void kruskal();
void swap(int& x, int& y);
void taoE();
void SapXepE();
void outputCayKhungToiThieu();
int TonTai(int d, int D[], int nD);
void inputformfile();
void outputMatrix();
void xuatE();
void XoaViTriE(int i);
void XoaCanhE(int u, int v);
int main()
{ 
	LIST1 l;
	LIST2 l2;
	int in1 = -1;
	int in2 = -1;
	string ma , tencd, macd, macd2, matnv;
	int phone,x,v;
	TINHNGUYENVIEN tnv;
	CHIENDICH cd;
	int choose;
	ifstream filein;
	ofstream fileout;
	do
	{
		system("cls");
		cout << "1: In danh sach TinhNguyenVien + Khoi tao mang Tinh Nguyen Vien\n";
		cout << "2: In danh sach ChienDich + Khoi tao mang ChienDich\n";
		cout << "3: Them 1 tinh nguyen vien vao cuoi danh sach\n";
		cout << "4: Tim Tinh Nguyen Vien co tuoi nho nhat\n";
		cout << "5: Tim TinhNguyenVien Theo MaTinhNguyenVien-TenChienDich-SoDienThoai\n";
		cout << "6: Cap nhat thong tin Tinh Nguyen Vien thong qua MaTinhNguyenVien\n";
		cout << "7: In danh sach tinh nguyen vien co tuoi <20 va Xep Theo Ten Giam Dan \n";
		cout << "8: In danh sach tinh nguyen vien theo ma chien dich , cung ma chien dich thi xep theo tuoi giam dan \n";
		cout << "9: In Danh Sach Tinh Nguyen Vien co thoi gian Chien Dich dien ra nhieu ngay nhat \n";
		cout << "10: In Danh Sach Tinh Nguyen Vien theo Ten Chien Dich \n";
		cout << "11: Tim trong so khoang cach dia ly giua 2 chien dich \n";
		cout << "12: Giai phong vung nho \n";
		cout << "0: Thoat \n";
		cout << "Chon: ";
		cin >> choose;
		if (choose == 0)
			break;
		else

			if ((choose < 1) || (choose > 12))
				cout << "Chon sai chon lai\n";
			else
			{
				switch (choose)
				{
				case 1:
					filein.open("tinhnguyenvien.txt");
					KhoiTaoDanhSachTNV(l);
					Doc_DanhSachTinhNguyenVien(filein, l);
					Xuat_DanhSachTNV(l);
					in1 = 1;
					filein.close();
					break;
				case 2:
					filein.open("chiendich.txt");
					KhoiTaoDanhSachChienDich(l2);
					Doc_DanhSachChienDich(filein, l2);
					Xuat_DanhSachCD(l2);
					in2 = 1;
					filein.close();
					break;
				case 3:
					if (in1 == 1 && in2 == 1) {
						fileout.open("tinhnguyenvien.txt", ios::app);
						NhapTNV(fileout, l,matnv);
						fileout.close();
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 4:
					if (in1 == 1 && in2 == 1) {
						filein.open("tinhnguyenvien.txt");
						Xuat_ThongTinTinhNguyenVienNhoTuoiNhat(filein, l);
						filein.close();
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 5 :
					if (in1 == 1 && in2 == 1) {
						filein.open("tinhnguyenvien.txt");
						cout << "1: Tim Tinh Nguyen Vien theo Ma Tinh Nguyen Vien\n";
						cout << "2: Tim Tinh Nguyen Vien theo SoDienThoai\n";
						cout << "3: Tim ChienDich theo TenCD\n";
						cout << "Chon: ";
						cin >> choose;
						switch (choose)
						{
						case 1:
							cin.ignore();
							cout << "Nhap ma tinh nguyen vien muon tim kiem: ";
							getline(cin, ma);
							TimTNV_MaTNV(l, ma);
							break;
						case 2:
							cin.ignore();
							cout << "Nhap SoDienThoai muon tim kiem: ";
							cin >> phone;
							TimTNV_Phone(l, phone);
							break;
						case 3:
							cin.ignore();
							cout << "Nhap TenCD: ";
							getline(cin, tencd);
							macd = TimMaChienDich(l2, tencd);
							TimTNV_TenCD(l, macd);
							break;
						}
						filein.close();
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 6:
					if (in1 == 1 && in2 == 1) {
						cin.ignore();
						cout << "Nhap MaTNV muon cap nhat thong tin: ";
						getline(cin, matnv);
						CapNhatThongTinTNV(l, matnv, fileout);
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 7:
					if (in1 == 1 && in2 == 1) {
						filein.open("tinhnguyenvien.txt");
						DanhSachTNV_20(filein, l);
						filein.close();
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 8:
					if (in1 == 1 && in2 == 1) {
						filein.open("tinhnguyenvien.txt");
						DanhSachTNV_MaCD(filein, l);
						filein.close();
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 9:
					if (in1 == 1 && in2 == 1) {
						filein.open("tinhnguyenvien.txt");
						macd = TimMaChienDich_SoNgayNhieuNhat(l2);
						TimTNV_TenCD(l, macd);
						filein.close();
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 10:
					if (in1 == 1 && in2 == 1) {
						filein.open("tinhnguyenvien.txt");
						DSTNV_TenCD(l, l2);
						filein.close();
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				case 11:
					inputMatrixFile(a, n);
					output();
					cout << "Nhap chien dich muon tim\n"; cin >> x;//chien dich muon tim
					cout << "Nhap chien dich bat dau xuat phat\n"; cin >> v;//chiến dịch bắt đầu xuất phát
					Search_by_BFS(x, v);
					/*output();
					taoE();
					SapXepE();
					xuatE();
					kruskal();
					outputCayKhungToiThieu();*/
					break;
				case 12:
					if (in1 == 1 && in2 == 1) {
						cout << "Giai Phong Vung Nho Thanh Cong." << endl;
						GiaiPhongVungNho(l);
						GiaiPhongVungNhoCD(l2);
						in1 = -1;
						in2 = -1;
					}
					else
					{
						cout << "Vui long khoi tao 2 mang." << endl;
					}
					break;
				}
			}
		system("pause");
	} while (choose != 0);
	system("pause");
	return 0;
}
void inputMatrixFile(int a[][MAX], int& n)
{
	string machiendich;
	ifstream filein;
	filein.open("bandochiendich.txt");
	filein >> n;
	for (int i = 0; i < n; i++)
	{
		filein >> vertex[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			filein >> a[i][j];
		}
	}
	filein.close();
}
void output()
{
	cout << "Bản Đồ Trọng Số Địa Lý Với :\n";
	cout << " | ";
	for (int i = 0; i < n; i++)
	{
		cout <<i<<": "<< vertex[i] << " | ";
	}
	cout << endl;
	cout << "--- ";
	for (int i = 0; i < n; i++)
	{
		cout << i << " ";
	}
	cout << "-";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		cout << i << ": ";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
}
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
			cout << "Duong di tu dinh " << vertex[v] << " den dinh " << vertex[x] << endl;
			cout << "BFS: ";
			for (int i = 0; i < nbfs; i++) {// n là số đỉnh của đồ thị
				cout << vertex[bfs[i]] << " ";
			}
			cout << endl;
			cout << endl;
			cout << "Trong so cua duong di la: ";
			for (int i = 0; i < nbfs; i++) {
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
int isEmptyQueue()
{
	if (front == NULL)
		return 1;
	return 0;

}
void initQueue()
{
	front = rear = NULL;
}
void initEdgesStatus()
{
	for (int i = 0; i < n; i++) // n là số đỉnh của đồ thị
		C[i] = 1;
}
void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1) {
			continue;
		}
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1) {
			continue;
		}
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}
void taoE()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}
void xuatE()
{
	for (int i = 0; i < nE; i++)
	{
		cout << "Canh (" << vertex[E1[i]] << "," << vertex[E2[i]] << "," << wE[i] << ")\n";
	}
}
void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void SapXepE()
{
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}
void outputCayKhungToiThieu()
{
	int tong = 0;
	cout << "Cay khung toi thieu:\n";
	for (int i = 0; i < nT; i++)
	{
		cout << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i] << endl;
		tong += wT[i];
	}
	cout << endl;
	cout << "Tong = " << tong << endl;;
}
int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void XoaViTriE(int i)
{
	for (int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}
void XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if (E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}
void inputformfile()
{
	ifstream ifs;
	ifs.open("bandochiendich.txt");
	if (ifs.is_open())
	{
		cout << "doc file thanh cong\n";
		ifs >> n;
		for (int i = 0; i < n; i++)
		{
			ifs >> vertex[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				ifs >> a[i][j];
			}
		}
	}
	else
	{
		cout << "ko mo dc file\n";
	}
}