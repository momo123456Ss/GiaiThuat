#include <iostream>
#include <fstream>
using namespace std;
// khai bao ma tran bang mang hai chieu
# define max 20
int a[max][max];
int n; // so dinh cua do thi
char vertex[max+1];
// khai bao TapE
int E1[max];
int E2[max];
int wE[max];
int nE = 0; // so phan tu tap E
// khai bao TapE
int T1[max];
int T2[max];
int wT[max];
int nT = 0; // so phan tap T
void kruskal();
void prim(int s);
void taoE();
void SapXepE();
void swap(int& x, int& y);
void outputCayKhungToiThieu();
int TonTai(int d, int D[], int nD);
void XoaViTriE(int i);
void XoaCanhE(int u, int v);
void xuatE();
void inputformfile()
{
	ifstream ifs;
	ifs.open("kruscol_prim.txt");
	if (ifs.is_open())
	{
		cout << "doc file thanh cong\n";
		ifs >> n;
		for (int  i = 0; i < n; i++)
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
void outputMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	int choose, s;
	do
	{
		system("cls");
		cout << "1: Doc File, Tao E\n";
		cout << "2: Xuat E\n";
		cout << "3: Sap xep E, Xuat E\n";
		cout << "4: Kruscol, Xuat cay khung toi thieu\n";
		cout << "5: Prim, Xuat cay khung toi thieu\n";
		cout << "0: Thoat \n";
		cout << "Chon: ";
		cin >> choose;
		if (choose == 0)
			break;
		else

			if ((choose < 1) || (choose > 5))
				cout << "Chon sai chon lai\n";
			else
			{
				switch (choose)
				{
				case 1:
					inputformfile();
					outputMatrix();
					taoE();
					break;
				case 2:
					xuatE();
					break;
				case 3:
					SapXepE();
					xuatE();
					break;
				case 4:
					kruskal();
					outputCayKhungToiThieu();
					break;
				case 5:
					cout << "Nhap dinh bat dau: "; cin >> s;
					prim(s);
					outputCayKhungToiThieu();
					break;
				}
			}
	system("pause");
	} while (choose != 0);
	system("pause");
}
// Hàm Kruskal
void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
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
// Hàm Prim
void prim(int s) // s là đỉnh bắt đầu
{
	int u = s,min, d1 ,d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++) {
			if (a[u][v] != 0) {
				if (TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
			}
		}
		for (int i = 0; i < nE; i++) {
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i]; 
				d1 = E1[i];
				d2 = E2[i]; 
				break;
			}
		}
		for (int i = 0; i < nE; i++) {
			if (TonTai(E2[i], T2, nT) == 0) {
				if (min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
			}

			T1[nT] = d1;
			T2[nT] = d2;
			wT[nT] = a[d1][d2];
			a[d1][d2] = 0; a[d2][d1] = 0;
			nT++;
			XoaCanhE(d1, d2);
			u = d2;
		}
	}
}
