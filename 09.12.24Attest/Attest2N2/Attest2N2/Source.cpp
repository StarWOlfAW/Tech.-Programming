#include "Header.h"
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	const int n = 100;
	int* a = new int[n], i = 0;
	int c = countsame(a, n);
	int* b = new int[c];
	inp_mass2(a, n);
	output_mass(a, n);
