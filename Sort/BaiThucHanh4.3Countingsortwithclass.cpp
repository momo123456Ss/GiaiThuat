#include <iostream>
#include "CountingSort.h"
using namespace std;
int main()
{
	int b[100], size,n;
	Countingsort x;
	x.input();
	x.output();
	size = x.getn();
	x.Sort(b,size);
	cout << "Mang sau khi sap xep tang dan \n";
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	x.Sort_DES(b, size);
	cout << "Mang sau khi sap xep giam dan \n";
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}