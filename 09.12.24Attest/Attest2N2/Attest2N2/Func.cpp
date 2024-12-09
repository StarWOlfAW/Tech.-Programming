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
void excludesame(int* a, int* b, int n)
{

}
int countsame(int* a, int n)
{
	int sum = 0, c = 0;

	for (int i = 0; i < n; i++)
	{
		int same = a[i];
		for (int i = 1; i < n - 1; i++)
		{
			if (a[i] == same)
				sum++;
		}
	}
	return (n - c);
}
