#include <iostream>
using namespace std;
int main()
{
	int max = 0, s1 = 0, s2 = 1, i, a, k;
	for (i = 1; i < 12212; i++)
	{
		a = i;
		s1 = 0; s2 = 1;
		while (a)
		{
			k = a % 10;
			s1 = s1 + k;
			s2 = s2 * k;
			a = a / 10;
		}
		if ((s1 == s2) and (max < i))
			max = i;
	}
	cout << "Maximum is " << max << " ";
	system("pause");
	return 0;
}
