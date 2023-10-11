#include <iostream>
#include <fstream>
#include <string>
#include<ctime>
#include<iomanip>
#define MAX 50
using namespace std;

struct DonHang
{
	string DH;
	string TenKH;
	double TongTien;
	bool TinhTrang;
};
int menuSelect();
void nhapDonHang(DonHang a[], int& n);
void inDonHang(DonHang a[], int n);
int timDonHang(DonHang a[], int n, string madh);
DonHang saochepDH(DonHang d);
void sapxepTang(DonHang a[], int n);
void xoaDonHang(DonHang a[], int& n, string madh);
void luuDSDonHang(DonHang a[], int n);
void docDSDonHangTuFile(DonHang a[], int& n);
void donhangChuaXuly(DonHang a[], int n);
int main()
{
	int chon, n = 0;
	string madh;
	int pos = 0;
	DonHang a[MAX];
	do
	{
		chon = menuSelect();
		switch (chon)
		{
		case 1 : 
			nhapDonHang(a, n);
			inDonHang(a, n);
			break;
		case 2 :
			sapxepTang(a, n);
			cout << "Don hang da sap xep theo Tong Tien tang dan " << endl;
			inDonHang(a, n);
			break;
		case 3 :
			cin.ignore();
			cout << "Nhap MaDH can tim: ";
			getline(cin, madh);
			pos = timDonHang(a, n, madh);
			if (pos >= 0)
			{
				for (int i = 0; i < n; i++)
				{
					cout << "MaDH: " << a[pos].DH << "\tTen khach hang: " << a[pos].TenKH << "\tTong tien: " << a[pos].TongTien << "\tTinh trang don hang: " << (a[pos].TinhTrang ? "Da Xu Ly" : "ChuaXu Ly") << endl;
				}
			}
			else
			{
				cout << "Ko tim thay " << endl;
			}
			break;
		case 4 :
			donhangChuaXuly(a, n);
			break;
		case 5 :
			cin.ignore();
			cout << "Nhap MaDH can xoa: ";
			getline(cin, madh);
			xoaDonHang(a, n, madh);
			inDonHang(a, n);
			break;
		case 6 :
			luuDSDonHang(a, n);
			break;
		case 7 :
			docDSDonHangTuFile(a, n);
			inDonHang(a, n);
			break;
		default:
			break;
		}
		cout << "Nhan Enter de tiep tuc" << endl;
		system("pause");
	} while (chon > 0 && chon <= 7);
	system("pause");
	return 0;
}
int menuSelect()
{
	int chon;
	do
	{
		cout << "1.Nhap danh sach don hang\n";
		cout << "2.Sap xep don hang theo Tong Tien\n";
		cout << "3.Tim don hang\n";
		cout << "4.In danh sach don hang chua xu ly\n";
		cout << "5.Xoa don hang\n";
		cout << "6.Luu danh sach don hang ra File\n";
		cout << "7.Doc danh sach don hang tu file\n";
		cout << "0.Ket thuc\n";
		cout << "Ban chon : ";
		cin >> chon;
	} while (chon < 0 || chon > 7);
	return chon;
}
void nhapDonHang(DonHang a[], int& n)
{
	string madh;
	
		cin.ignore();
		do {//vong lap nhap va kiem tra ma don hang
			cout << "MaDH (nhap 0 de dung): ";
			getline(cin, madh);
			if (madh == "0") return;
			if (timDonHang(a, n, madh) == -1)
			{
				a[n].DH = madh;
				break;
			}
			else
			{
				cout << "MaDH co roi , vui long nhap lai\n";
			}
		} while (true);
		cout << "TenKH : ";
		getline(cin, a[n].TenKH);
		cout << "Tong Tien : ";
		cin >> a[n].TongTien;
		cout << "Tinh Trang don hang : ";
		cin >> a[n].TinhTrang;
		n++;
}
int timDonHang(DonHang a[], int n, string madh)
{
	//tim thay tra ve vi tri trong mang,ko thay tra ve -1
	for (int i = 0; i < n ; i++)
		if (a[i].DH == madh)
			return i;
		return -1;
}
void inDonHang(DonHang a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "MaDH: " << a[i].DH << "\tTen khach hang: " << a[i].TenKH << "\tTong tien: " << a[i].TongTien << "\tTinh trang don hang: " << (a[i].TinhTrang ? "Da Xu Ly" : "ChuaXu Ly") << endl;
	}
}
void sapxepTang(DonHang a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].TongTien > a[j].TongTien)
			{
				//Hoan doi gia tri 2 don hang
				DonHang tam = saochepDH(a[i]);
				a[i] = saochepDH(a[j]);
				a[j] = saochepDH(tam);
			}
		}
	}
}
DonHang saochepDH(DonHang d)
{
	DonHang t;
	t.DH = d.DH;
	t.TenKH = d.TenKH;
	t.TongTien = d.TongTien;
	t.TinhTrang = d.TinhTrang;
	return t;
}
void donhangChuaXuly(DonHang a[], int n)
{
	for (int i = 0; i < n; i++)
		if (!a[i].TinhTrang)
		{
			cout << "MaDH: " << a[i].DH << "\tTen khach hang: " << a[i].TenKH << "\tTong tien: " << a[i].TongTien << "\tTinh trang don hang: " << (a[i].TinhTrang ? "Da Xu Ly" : "ChuaXu Ly") << endl;
		}
}
void xoaDonHang(DonHang a[], int& n,string madh)
{
	int pos = timDonHang(a, n, madh);
	if (pos >= 0)
	{
		for (int i = pos + 1; i < n; i++)
			a[i - 1] = saochepDH(a[i]);
		n--;
	}
}
void luuDSDonHang(DonHang a[], int n)
{
	if (n == 0) return;
	string fileName;
	cin.ignore();
	cout << "Nhap ten tap tin: ";
	getline(cin, fileName);
	ofstream out;
	out.open(fileName);
	if (out.is_open())
	{
		out << a[0].DH << "#" << a[0].TenKH << "#" << a[0].TongTien << "#" << a[0].TinhTrang;
		for (int i = 1; i < n; i++)
		{
			out << endl<< a[i].DH << "#" << a[i].TenKH << "#" << a[i].TongTien << "#" << a[i].TinhTrang;
		}
		out.close();
	}
}
void docDSDonHangTuFile(DonHang a[], int& n)
{
	n = 0;
	string fileName;
	cin.ignore();
	cout << "Nhap ten tap tin: ";
	getline(cin, fileName);
	ifstream in;
	in.open(fileName);
	if (in.is_open())
	{
		while (!in.eof())//chua den cuoi tap tin
		{
			getline(in, a[n].DH, '#');
			getline(in, a[n].TenKH, '#');
			in >> a[n].TongTien;
			in.ignore(1);
			in >> a[n].TinhTrang;
			in.ignore(1);
		}
		in.close();
	}
}
