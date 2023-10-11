#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#define MAX 50
using namespace std;
struct SanPham
{
	string ma;
	string tensp;
	string donvi;
	double giamua;
	double giaban;
};
void xuat(SanPham a[MAX], int n);
void docsp(ifstream& ifs, SanPham& sp);
int soluong(ifstream& ifs, SanPham a[MAX]);
void indanhsach(SanPham a[MAX], int n);
void intheomasp(SanPham a[MAX], int n, string chonmasp);
bool KiemtraMaSP(SanPham a[MAX], string chonmasp, int n);
void NhapThemSP(SanPham& sp, int& n, string chonmasp, SanPham a[MAX]);
int timvitri(SanPham a[MAX], int n, string chonmasp);
void XoaSP(SanPham a[MAX], string chonmasp, int& n, ofstream& ofs);
void Hoanvi_MaSP(SanPham a[MAX], int i, int j);
void Hoanvi_TenSP(SanPham a[MAX], int i, int j);
void Hoanvi_DonViTinh(SanPham a[MAX], int i, int j);
void Hoanvi_giamua(SanPham a[MAX], int i, int j);
void Hoanvi_giaban(SanPham a[MAX], int i, int j);
void SapxeptheoTenSP(SanPham a[MAX], int n);
void SapxeptheoGiaBan(SanPham a[MAX], int n);
int vitriYeuCau(SanPham a[MAX], int n,double giatu,double giaden);
void Giatien(SanPham a[MAX], int n,double giatu, double giaden);
void GiatienMua(SanPham a[MAX], int n, double giatu, double giaden);
int main()
{
	int n = 0;
	int m = 0;
	int chon;
	double giatu = 0;
	double giaden = 0;
	string chonmasp;
	SanPham sp;
	SanPham a[MAX];
	ifstream ifs;
	ofstream ofs;
	ifs.open("sanpham.txt");
	n = soluong(ifs, a);
	if (ifs.is_open())
	{
		do
		{
			system("cls");
			cout << "1: In danh sach SanPham\n";
			cout << "2: In SanPham theo MaSP\n";
			cout << "3: Them vao danh sach 1 SanPham\n";
			cout << "4: Xoa san pham theo MaSP\n";
			cout << "5: In danh sach theo TenSP tang dan\n";
			cout << "6: In danh sach theo gia ban giam dan\n";
			cout << "7: In danh sach cac San pham theo Gia Ban\n";
			cout << "8: In danh sach cac San pham theo Gia Mua\n";
			cout << "0: Thoat\n";
			cout << "Chon: ";
			cin >> chon;
			if (chon == 0)
				break;
			else

				if ((chon < 1) || (chon > 8))
					cout << "Chon sai chon lai\n";
				else
				{
					switch (chon)
					{
					case 1://In danh sách SanPham						
						indanhsach(a, n);
						break;
					case 2:	//In sinh viên theo MSSV	
						cout << "\tBan da chon in SanPham theo MaSP\n";
						cin.ignore();
						intheomasp(a, n, chonmasp);
						break;
					case 3://Them 1 SanPham
						cin.ignore();
						cout << "Ban da chon them 1 SanPham\n";
						NhapThemSP(sp, n, chonmasp, a);
						break;
					case 4://Xóa khỏi danh sách 1 san pham
						cin.ignore();
						cout << "\tBan da chon xoa SanPham\n";
						XoaSP(a, chonmasp, n, ofs);
						break;
					case 5://In danh sách theo tênSP tăng dần
						cout << "Ban chon sap xep theo TenSP tang dan " << endl;
						SapxeptheoTenSP(a, n);
						break;
					case 6://In danh sách theo Giá Bán tăng dần
						cout << "Ban chon sap xep theo gia ban giam dan " << endl;
						SapxeptheoGiaBan(a, n);
						break;
					case 7://Theo yeu cau
						cout << "Tim GiaBan san pham theo yeu cau " << endl;
						cout << "Hay nhap Gia Ban Nho Nhat : " ;
						cin >> giatu;
						cout << "Hay nhap Gia Ban Lon Nhat : " ;
						cin >> giaden;
						cout << "Cac san pham co gia tu " << giatu << " den " << giaden <<" : "<<endl;
						Giatien(a, n, giatu, giaden);
						break;
					case 8://Theo yeu cau
						cout << "Tim GiaMua san pham theo yeu cau " << endl;
						cout << "Hay nhap Gia Mua Nho Nhat : ";
						cin >> giatu;
						cout << "Hay nhap Gia Mua Lon Nhat : ";
						cin >> giaden;
						cout << "Cac san pham co gia Mua tu " << giatu << " den " << giaden << " : " << endl;
						GiatienMua(a, n, giatu, giaden);
						break;
					}
				}
			system("pause");
		} while (chon != 0);
	}
	ofs.close();
	ifs.close();
	delete[]a;
}
void xuat(SanPham a[MAX], int n,ofstream& ofs)
{
	for (int i = 0; i < n; i++)
	{
		ofs << a[i].ma << "#" << a[i].tensp << "#" << a[i].donvi<< "#" << a[i].giamua << "#" << a[i].giaban<< endl;
	}
}
void docsp(ifstream& ifs, SanPham &sp)
{
	getline(ifs, sp.ma, '#');
	getline(ifs, sp.tensp, '#');
	getline(ifs, sp.donvi, '#');
	ifs >> sp.giamua;
	ifs.ignore(1);
	ifs >> sp.giaban;
	ifs.ignore(1);
}
int soluong(ifstream& ifs, SanPham a[MAX])
{
	//đọc tất cả danh sách san pham từ file
	int i = 0;
	while (!ifs.eof())
	{
		docsp(ifs, a[i]);
		i++;
	}
	return i - 1;//trả về giá trị là số sanpham trong danh sách
}
void indanhsach(SanPham a[MAX], int n)
{
	cout << "In Danh Sach " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "MaSP:\t" << a[i].ma << "\tTenSP:\t" << a[i].tensp << "          DonViTinh\t" << a[i].donvi << "\tGiaMua\t" << a[i].giamua << "\tGiaBan\t" << a[i].giaban << endl;
	}
}
void intheomasp(SanPham a[MAX], int n, string chonmasp)
{
	cout << "Nhap MaSP : ";
	getline(cin, chonmasp);
	for (int i = 0; i < n; i++)
	{
		if (chonmasp == a[i].ma)
		{
			cout << "MaSP:\t" << a[i].ma << "\tTenSP:\t" << a[i].tensp << "\tDonViTinh\t" << a[i].donvi << "\tGiaMua\t" << a[i].giamua << "\tGiaBan\t" << a[i].giaban << endl;
			break;
		}
	}
}
bool KiemtraMaSP(SanPham a[MAX], string chonmasp, int n)
{
	bool check = true;
	for (int i = 0; i < n; i++)
	{
		if (chonmasp == a[i].ma)
		{
			check = false;
			break;
		}
	}
	return check;
}
void NhapThemSP(SanPham& sp, int& n, string chonmasp, SanPham a[MAX])
{
	//nhap thông tin SanPham đầy đủ
	ofstream ofs;
	ofs.open("sanpham.txt", ios::app);
	cout << "\tNhap MaSP can bo sung : ";
	getline(cin, chonmasp);
	KiemtraMaSP(a, chonmasp, n);
	if (KiemtraMaSP(a, chonmasp, n) == true)
	{
		sp.ma = chonmasp;
		cout << "Nhap TenSP : ";
		getline(cin, sp.tensp);
		cout << "DonViTinh : ";
		getline(cin, sp.donvi);
		cout << "Gia Mua : ";
		cin >> sp.giamua;
		cout << "Gia Ban : ";
		cin >> sp.giaban;
		a[n].ma = sp.ma;
		a[n].tensp = sp.tensp;
		a[n].donvi = sp.donvi;
		a[n].giamua = sp.giamua;
		a[n].giaban = sp.giaban;
		n++;
	}
	else if (KiemtraMaSP(a, chonmasp, n) == false)
	{
		cout << "MaSP bi Trung !! " << endl;
	}
	ofs << sp.ma << "#" << sp.tensp << "#" << sp.donvi << "#" << sp.giamua << "#" << sp.giaban << endl;
	cout << "\t==> Tat ca thong tin vua nhap da duoc luu lai\n";
	cout << "\t==> SanPham da duoc them vao cuoi danh sach\n";
	//luu lại tổng số SanPham khi nhập sinh viên mới
	ofs.close();
}
int timvitri(SanPham a[MAX], int n, string chonmasp)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].ma == chonmasp) return i;
	}
	return -1;
}
void XoaSP(SanPham a[MAX], string chonmasp, int& n, ofstream& ofs)
{
	//Xóa đi sinh vien vừa nhập MSSV
	int vitri = 0;
	//ofs.open("sanpham.txt");
	cout << "Nhap MSSV can xoa : ";
	getline(cin, chonmasp);
	vitri = timvitri(a, n, chonmasp);
	if (vitri > -1)
	{
		ofs.open("sanpham.txt");
		if (ofs.is_open()==true) 
		{
			for (int i = vitri; i < n; i++)
			{
				{
					a[i].ma = a[i + 1].ma;
					a[i].tensp = a[i + 1].tensp;
					a[i].donvi = a[i + 1].donvi;
					a[i].giamua = a[i + 1].giamua;
					a[i].giaban = a[i + 1].giaban;
					
				}
			}
			n--;
			cout << "Xoa thanh cong!! " << endl;
			xuat(a, n, ofs);
		}
	}
	if (ofs.is_open() == false)
	{
		cout << "Ko co MaSP trong danh sach " << endl;
	}
}
void Hoanvi_MaSP(SanPham a[MAX], int i, int j)
{
	string tam;
	tam = a[i].ma;
	a[i].ma = a[j].ma;
	a[j].ma = tam;
}
void Hoanvi_TenSP(SanPham a[MAX], int i, int j)
{
	string tam;
	tam = a[i].tensp;
	a[i].tensp = a[j].tensp;
	a[j].tensp = tam;
}
void Hoanvi_DonViTinh(SanPham a[MAX], int i, int j)
{
	string tam;
	tam = a[i].donvi;
	a[i].donvi = a[j].donvi;
	a[j].donvi = tam;
}
void Hoanvi_giamua(SanPham a[MAX], int i, int j)
{
	double tam;
	tam = a[i].giamua;
	a[i].giamua = a[j].giamua;
	a[j].giamua = tam;
}
void Hoanvi_giaban(SanPham a[MAX], int i, int j)
{
	double tam;
	tam = a[i].giaban;
	a[i].giaban = a[j].giaban;
	a[j].giaban = tam;
}
void SapxeptheoTenSP(SanPham a[MAX], int n)
{
	//Sắp xếp thứ tự san pham theo tênSP
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i].tensp) > (a[j].tensp))
			{
				Hoanvi_MaSP(a, i, j);
				Hoanvi_TenSP(a, i, j);
				Hoanvi_DonViTinh(a, i, j);
				Hoanvi_giamua(a, i, j);
				Hoanvi_giaban(a, i, j);
			}
		}
	}
	indanhsach(a, n);
}
void SapxeptheoGiaBan(SanPham a[MAX], int n)
{
	//Sắp xếp thứ tự san pham theo tênSP
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i].giaban) < (a[j].giaban))
			{
				Hoanvi_MaSP(a, i, j);
				Hoanvi_TenSP(a, i, j);
				Hoanvi_DonViTinh(a, i, j);
				Hoanvi_giamua(a, i, j);
				Hoanvi_giaban(a, i, j);
			}
		}
	}
	indanhsach(a, n);
}
void Giatien(SanPham a[MAX], int n, double giatu, double giaden)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].giaban >= giatu && a[i].giaban <= giaden)
		{
			cout << "MaSP:\t" << a[i].ma << "\tTenSP:\t" << a[i].tensp << "\tDonViTinh\t" << a[i].donvi << "\tGiaMua\t" << a[i].giamua << "\tGiaBan\t" << a[i].giaban << endl;
		}
	}
}
void GiatienMua(SanPham a[MAX], int n, double giatu, double giaden)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].giamua >= giatu && a[i].giamua <= giaden)
		{
			cout << "MaSP:\t" << a[i].ma << "\tTenSP:\t" << a[i].tensp << "\tDonViTinh\t" << a[i].donvi << "\tGiaMua\t" << a[i].giamua << "\tGiaBan\t" << a[i].giaban << endl;
		}
	}
}