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
}