#include <iostream>
#include <conio.h>
using namespace std;
# define MAX 100
int a[MAX];
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void BubbleSort(int a[], int n);
void InterchangeSort(int a[], int n);
void swap(int& a, int& b);
void xuatmang(int a[], int n);
void capnhat(int a[], int n);
void QuickSort(int a[], int left, int right);
void HeapSort(int a[], int n);
void shift(int a[], int i, int n);
int Search(int a[], int n, int X);
int BinarySearch(int a[], int n, int X);
int GetRandom(int min, int max);
void mergeSort(int arr[], int left, int right);
int main()
{
	int n = 0,choose,X; // n là tổng số phần tử hiện có trong danh sách, 0 <= n < MAX
	int left = 0;
	int right = n - 1;
	int l = 0;
	int r = n - 1;

	int a[MAX] = { 0 };
	srand(time(0));
	do
	{

		system("cls");
		cout << "1.Random. \n2.Xuat mang a[i]. \n"
			<< "3.SelectionSort. \n4.InsertionSort. \n"
			<< "5.BubbleSort. \n6.InterchangeSort. \n"
			<< "7.QuickSort\n8.HeapSort \n9.Tim Kiem Nhi Phan\n"
			<< "10.Tim kiem tuan tu. \n11.MergeSort. \n12.Thoat\n";
		cout << "\nMoi chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Nhap so luong phan tu: "; cin >> n;
			capnhat(a,n);
			cout << "Random!!!\n";
			break;
		case 2:
			xuatmang(a,n);
			break;
		case 3: 
			cout << "Sap xep Giam Dan SelectionSort \n";
			SelectionSort(a, n);
			xuatmang(a,n);
			break;
		case 4:
			cout << "Sap xep Tang Dan InsertionSort \n";
			InsertionSort(a, n);
			xuatmang(a, n);
			break;
		case 5:
			cout << "Sap xep Giam Dan BubbleSort \n";
			BubbleSort(a, n);
			xuatmang(a, n);
			break;
		case 6:
			cout << "Sap xep Giam Dan InterchangeSort \n";
			InterchangeSort(a, n);
			xuatmang(a, n);
			break;
		case 7:
			cout << "Sap xep Giam Dan QuickSort \n";
			QuickSort(a,left,right);
			xuatmang(a, n);
			break;
		case 8:
			cout << "Sap xep Tang Dan HeapSort \n";
			HeapSort(a, n);
			xuatmang(a, n);
			break;
		case 9:
			cout << "Nhap gia tri can tim: "; cin >> X;
			cout << "Vi tri cua " << X << " : " << BinarySearch(a, n, X) << endl;;
			break;
		case 10:
			cout << "Nhap gia tri can tim: "; cin >> X;
			cout << "Vi tri cua " << X << " : " << Search(a, n, X) << endl;;
			break;
		case 11:
			mergeSort(a, left, right);
			xuatmang(a,n);
			break;
		default:
			cout << "Ban chon thoat.\n";
			break;
		}
		_getch();

	} while (choose >= 1 && choose <= 10);
	return 0;
}

void SelectionSort(int a[], int n)
{
	int min_pos, i, j;
	for (i = 0; i < n-1 ; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n ; j++)
		{
			if (a[j] > a[min_pos])
			{
				min_pos = j; // min_pos là vị trí chứa giá tri hiện nhỏ nhất
				swap(a[min_pos], a[i]);
			}
		}
	}
}
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void capnhat(int a[], int n)
{
	for (int i = 0; i < n ; i++)
	{
		a[i] = GetRandom(1,25);
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void InsertionSort(int a[], int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i]; // biến x lưu giá trị a[i]
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] < a[j])
			{// xét điều kiện phần tử sau nhỏ hơn phần tửtrước
				swap(a[j], a[j - 1]);
			} // hoán vị a[j] với a[j-1]
	}
}
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j]) 
			{
				swap(a[i], a[j]);
			} // đổi chỗ a[i] và a[j]
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
	//	68			Gọi thực thi thủ tục QuickSort : QuickSort(a, 0, n1);
		if (i <= j) {
			swap(a[i], a[j]);
				i++; j--;
		}
	}
	if (left < j) QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) // nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j + 1 < n) // nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình
		if (a[j] < a[j + 1]) // nếu vị trí j không tồn tại phần tử a[j] <a[j+1]
			j++;
	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0) // tạo heap ban đầu
	{
		shift(a, i, n - 1); 
		i--;
	}
	int right = n - 1; // right là vị trí cuối Heap đang xét
	while (right > 0)
	{
		swap(a[0], a[right]); // hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
		right--; // giới hạn lại phần tử cuối đang xét
		if (right > 0) // Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
			shift(a, 0, right); // tạo Heap lại tại vị trí 0
	}
}
//void merge(int arr[], int l, int m, int r)
//{
//	int i, j, k;
//	int n1 = m-l + 1;
//	int n2 = r-m;
//	int L[n1], R[n2];
//	/* Copy dữ liệu sang các mảng tạm */
//	for (i = 0; i < n1; i++)
//	{
//		L[i] = arr[l + i];
//	}
//	for (j = 0; j < n2; j++)
//	{
//		R[j] = arr[m + 1 + j];
//	}
//			/* Gộp hai mảng tạm vừa rồi vào mảng arr*/
//	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
//	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
//	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
//	while (i < n1 && j < n2)
//	{
//		if (L[i] <= R[j])
//		{
//			arr[k] = L[i];
//			i++;
//		}
//		else {
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//	/* Copy các phần tử còn lại của mảng L vào arr nếu có */
//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//	/* Copy các phần tử còn lại của mảng R vào arr nếu có */
//	while (j < n2) {
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
		int m = l + (r - l) / 2;
		// Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		//merge(arr, l, m, r);
	}
}
//mergeSort(arr, 0, arr_size - 1);
int Search(int a[], int n, int X)
{
	int i = 0;
	while (i < n && a[i] != X)
		i++;
	if (i < n)
		return i; // x trong danh sách a, và nằm ở vị trí i
	return -1; // không tìm thấy x trong danh sách a;
}
int BinarySearch(int a[], int n, int X)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == X) return mid;
		if (X > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1; // không tìm thấy x trong danh sách a;
}
int GetRandom(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}