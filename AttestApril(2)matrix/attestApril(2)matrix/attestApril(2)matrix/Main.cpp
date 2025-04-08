#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
    int n = 0, m = 0;
    cout << "Enter amount of rows " << endl;
    cin >> n;
    cout << "Enter amount of columns " << endl;
    cin >> m;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    input_matrix(a, n, m);
    output_matrix(a, n, m);
    cout << endl;
    output_desired(a, n, m);
}