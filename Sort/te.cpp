#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;
int thisIsMagic(int ngay, int thang, int nam) {
	if (thang < 3) {
		nam--;
		thang+= 12;
	}
	return 365 * nam + nam / 4 - nam / 100 + nam / 400 + (153 * thang - 457) / 5 + ngay - 306;
}
int main()
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t baygio = time(0);

	cout << "So giay ke tu 1/1/1970 la: " << baygio << endl;

	tm* ltm = localtime(&baygio);

	// in cac thanh phan cua cau truc tm struct.
	cout << "Nam: " << 1900 + ltm->tm_year << endl;
	cout << "Thang: " << 1 + ltm->tm_mon << endl;
	cout << "Ngay: " << ltm->tm_mday << endl;
	cout << "Thoi gian: " << 1 + ltm->tm_hour << ":";
	cout << 1 + ltm->tm_min << ":";
	cout << 1 + ltm->tm_sec << endl;
	int numberOfDays = thisIsMagic(29, 12, 2021) - thisIsMagic(4, 11, 2021);
	cout << numberOfDays;
}