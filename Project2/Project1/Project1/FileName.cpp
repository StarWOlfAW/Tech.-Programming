#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int a, a2 = 0, b = 0, s, b2, z;
	cout << "Enter your number " << endl;
	cin >> a;
	b = a;
	s = a;
	b2 = a;
	while (a)
		{
			a2++;
			a = a / 10;
			b = b * 10 + a % 10;
		}
	z = (b2 / (pow(10, a2) / 2));
	if (((z%10) == 9) && (s == b)) {
		cout << "Beautiful" << endl;
	}
	else cout << "Not so beautiful" << endl;
	system("pause");
	return 0;
}
