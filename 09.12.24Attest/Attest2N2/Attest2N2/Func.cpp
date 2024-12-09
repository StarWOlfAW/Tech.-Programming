#include "Header.h"
#include <iostream>
using namespace std;
void output_mass(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
}
void inp_mass2(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = ((rand() % 31) - 20);
	}
}