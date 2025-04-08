#include "Header.h"
#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
int main()
{
	char str[80];
	cout << "Enter string: " << endl;
	input(str);
	cout << "Result: " << endl;
	output(str);
	words(str);
	system("pause");
	return 0;
}