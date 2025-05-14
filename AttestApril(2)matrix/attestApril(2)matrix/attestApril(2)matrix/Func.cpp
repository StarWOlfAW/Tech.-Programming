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
void output_desired(int** a, int n, int m)
{
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                cout << a[top][i] << " ";
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                cout << a[i][right] << " ";
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    cout << a[bottom][i] << " ";
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    cout << a[i][left] << " ";
                }
                left++;
            }
        }
    /*for (int i = m; i < m /2; i--)
        {
            for (int k = i; k > n-i; k--)
                cout << a[k-1][i-1] << " ";
        }*/
   /* for (int i = 0; i < m /2; i++)
    {
         for (int k = i; k < m; k++)
            cout << a[k][i] << " "
        cout << endl;
        }*/
    /*for (int i = n-1; i >= 0; i--)
    {
        for (int k = n - i - 1; k < n; k++)
            cout <<a[i][k];
        cout << endl;
    }*/
    /*for (int i = n-1; i>=0; i--)
    {
        for (int k = 0; k <= i; k++)
            cout << a[i][k] << " ";
        cout << endl;
    }*/
   /* for (int i = n; i >n/2; k < i; k++)
    {
        for(int k = n-i; k <i; k++)
            cout << a[i-1][k] << " ";
        cout << endl;
    }*/


    /*for (int j = 0; j < m; j++)
{
    cout << a[0][j] << " ";
}


for (int i = 1; i < n - 1; i++)
{
    cout << a[i][m - 1] << " ";
}


if (n > 1)
{
    for (int j = m - 1; j >= 0; j--)
    {
        cout << a[n - 1][j] << " ";
    }
}


if (m > 1)
{
    for (int i = n - 2; i >= 1; i--)
    {
        cout << a[i][0] << " ";
    }
}*/
}
