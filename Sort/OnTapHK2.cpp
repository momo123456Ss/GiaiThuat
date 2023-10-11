#include <fstream>
#include <string>
#include<ctime>;
#include <iostream>
using namespace std;
#define MAX 30
void doc(int**& p, int& c, int& r, ifstream& ifs);
void ghi(int** p, int& c, int& r, ofstream& ofs);
void tangdanhang(int** p, int& c, int& r, ofstream& ofs, ifstream& ifs);
void hoanvi(int& a, int& c);
void sepxeptang(int** p, int r, int c, ofstream& ofs, ifstream& ifs);
void sepxeptangtheocot(int** p, int r, int c, ofstream& ofs, ifstream& ifs);
int main()
{
	int** a, r, c, ** p,**b;
	ofstream ofs, ofs1;
	ifstream ifs, ifs1;
	ifs.open("matran.txt");
	if (ifs.is_open())
	{
		ifs >> r >> c;
	}
	a = new int* [r];
	for (int i = 0; i < r; i++)
	{
		a[i] = new int[c];
	}
		doc(a, c, r, ifs);
	ifs.close();
	ifs.open("matran.txt");
	ofs.open("matran2.txt");
	p = new int* [r];
	for (int i = 0; i < r; i++)
	{
		p[i] = new int[c];
	}
	ofs << r << " " << c << endl;
	sepxeptang(p, r, c,ofs,ifs);
	ifs.close();
	ofs.close();
	ifs.open("matran.txt");
	ofs.open("matran3.txt");
	b = new int* [r];
	for (int i = 0; i < r; i++)
	{
		b[i] = new int[c];
	}
	ofs << r << " " << c << endl;
	sepxeptangtheocot(b, r, c, ofs, ifs);
	ifs.close();
	ofs.close();
	return 0;
}
void doc(int**& p, int& c, int& r, ifstream& ifs)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			p[i][j] = { 0 };
			ifs >> p[i][j];
		}
	}
}
void ghi(int** p, int& c, int& r, ofstream& ofs)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			ofs << p[i][j] << "\t";
		}
		ofs << endl;
	}
}
void tangdanhang(int** p, int& c, int& r, ofstream& ofs, ifstream& ifs)
{
	int** h = { 0 };
	h = new int* [r];
	for (int i = 0; i < r; i++)
	{
		h[i] = new int[c];
	}
	ifs.open("matran.txt");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			p[i][j] = { 0 };
			ifs >> p[i][j];
			/*p[i][j] = h[i][j];
			if (h[i][j] < p[i][j])
			{
				hoanvi(h[i][j], p[i][j]);
			}*/
		}
	}
	//ghi ket qua ra file 
	ghi(p, c, r, ofs);
}
void hoanvi(int& a, int& c)
{
	int tmp = a;
	a = c;
	c = tmp;
}
void sepxeptang(int** p, int r, int c,ofstream& ofs, ifstream& ifs)
{
	doc(p, c, r, ifs);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			for (int k = j + 1; k < c; k++)
			{
				if (p[i][j] > p[i][k])
				{
					int tam = p[i][j];
					p[i][j] = p[i][k];
					p[i][k] = tam;
				}
			}
		}
	}
	ghi(p, c, r, ofs);
}
void sepxeptangtheocot(int** p, int r, int c, ofstream& ofs, ifstream& ifs)
{
	doc(p, c, r, ifs);
	for (int i = 0; i < c;i++)
	{
		for (int j = 0; j < r - 1; j++)
		{
			for (int k = j + 1; k < r; k++)
			{
				
				if (p[j][i] > p[k][i])
				{
					int tam = p[j][i];
					p[j][i] = p[k][i];
					p[k][i] = tam;
				}
			}
		}
	}
	ghi(p, c, r, ofs);
}