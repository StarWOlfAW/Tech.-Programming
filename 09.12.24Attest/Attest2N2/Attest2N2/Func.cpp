#include "Header.h"
#include <iostream>
#include <ctime>
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
void excludesame(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		int current = a[i];
		for (int d = i; d < n - 1; d++)
		{
			if (a[d + 1] == current)
				a[d + 1] = -23478956;
		}
	}
}
void typein(int* a, int* b, int c, int n)
{
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != -23478956)
		{
			b[r] = a[i];
			r++;
		}
	}
}
int countsame(int* a, int n)
{
	int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == -23478956)
				sum++;
		}
		int r;
		r = n - sum;
	return (r);
}
