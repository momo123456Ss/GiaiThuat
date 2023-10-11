#include <iostream>
#include "2051010290_HuynhHiepThien.h"
using namespace std;
int main()
{
	QuickSort q;
	int left, right;
	int a[200];
	//q.input();
	q.inputfile();
	int n = q.getn();
	left = 0;
	right = n - 1;
	cout << "Mang ban dau : \n";
	q.output();
	/*cout << "Xep tang dan Quick Sort" << endl;
	q.Sort(0, n - 1);
	q.output();
	cout << "Xep giam dan Quick Sort" << endl;
	q.Sort_DES(0, n - 1);
	q.output();*/
	cout << "Xep tang dan dan Quick Sort Pivot = 0 " << endl;
	q.Sort_Pivot0(0, n - 1);
	q.output();
}