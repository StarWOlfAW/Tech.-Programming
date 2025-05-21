#include "Header.h"
#include <iostream>
#include <ctime>

using namespace std;

void input_matrix(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 90 + 10;
}
void output_matrix(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
bool is_arithmetic_progression(int* row, int m)
{
    if (m <= 2) return true;

    int d = row[1] - row[0];
    for (int j = 2; j < m; j++)
    {
        if (row[j] - row[j - 1] != d)
            return false;
    }
    return true;
}

int count_arithmetic_rows(int** a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (is_arithmetic_progression(a[i], n))
            count++;
    }
    return count;
}