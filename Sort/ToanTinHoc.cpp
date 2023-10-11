#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
float exponential(int n, float x)
{
    float sum = 1.0f; // initialize sum of series

    for (int i = n - 1; i > 0; --i)
        sum = 1 + x * sum / i;

    return sum;
}

int main() {
    int n = 10;
    float x = 1.0f;
    int mu = 0;
    cout << "e^x = " << fixed << setprecision(5) << exponential(n, x) << endl;
    cout << "Nhap mu : "; cin >> mu;
    cout << endl;
    cout << fixed << setprecision(5) << pow(exponential(n, x), mu) << endl;
    system("pause");
    _getch();
}