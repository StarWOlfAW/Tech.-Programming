#include "Header.h"
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	const int n = 15;
	int* a = new int[n], i = 0;
	inp_mass2(a, n);
	output_mass(a, n);
	excludesame(a, n);
	int c = countsame(a, n);
	int* b = new int[c];
	cout << " >>>>> " << c << "    ";
	output_mass(a, n);
	cout << "    ";
	typein(a, b, c, n);
	output_mass(b, c);
	system("pause");
	return 0;
}
