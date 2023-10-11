#include <iostream>
using namespace std;
int main() {
	int n;
	int a[50] = { 0 };
	cout << "Nhap so luong phan tu : "; cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << "A[" << i << "]: ";
		cin >> a[i];
	}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (a[i] + a[j] > a[k]
					&& a[i] + a[k] > a[j]
					&& a[j] + a[k] > a[i]) {
					cout << "(" << a[i] << "," << a[j] << "," << a[k] << ")" << endl;
					res++;
				}
			}
		}
	}
	cout << "So luong tam giac la : ";
	cout << res;
	return 0;
}
