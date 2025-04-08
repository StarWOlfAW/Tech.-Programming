#include "Header.h"
#include <iostream>
#include <ctime>

using namespace std;

void input_matrix(float** a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 9 + 1;
}
void output_matrix(float** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void mult(float** a, float** b, float** res, int n) 
{
    float s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            s = 0.0f;
            for (int p = 0; p < n; p++)
                s += a[i][p] * b[p][j];
            res[i][j] = s;
        }
}

bool equal(float** a, float** b, int n) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (abs(a[i][j] - b[i][j]) > 0.1) // If  float goes wrong a litle bit
                return false;
    return true;
}
void coeff(float** a, float k, float** res, int n) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = k * a[i][j];
}

void minus(float** a, float** b, float** res, int n) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void plusm(float** a, float** b, float** res, int n) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = a[i][j] + b[i][j];
}
float** create_matrix(int n) 
{
    float** m = new float* [n];
    for (int i = 0; i < n; i++)
        m[i] = new float[n];
    return m;
}
void free_matrix(float** m, int n) 
{
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
}
