#include <iostream>
using namespace std;
main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c;
	if ((a + b < c) || (a + c < b) || (b + c < a))
		cout << "Not a triangle" << endl;
	else
		if ((a != c) || (a != b))
			cout << "Not an equal triangle" << endl;
		else
		{
			d = (sqrt((a * a) - (a / 2) * (a / 2)));
			e = (d * a) / 2;
			if ((a >= b) && (b >= c) && (b >= d)) cout << "h = " << d << " " << b << " " << c << "S = " << e;
				else if ((a >= c) && (c >= b)) cout << "h = " << d << " " << b << " " << c << " " << a << "S = " << e;
					else if ((b >= a) && (c >= a)) cout << "h = " << d << " " << a << " " << c << " " << b << "S = " << e;
						else if ((b >= c) && (c >= a)) cout << "h = " << d << " " << a << " " << c << " " << b << "S = " << e;
							else if ((c >= a) && (a >= b)) cout << "h = " << d << " " << b << " " << a << " " << c << "S = " << e;
								else if ((c >= b) && (b >= a)) cout << "h = " << d << " " << a << " " << b << " " << c << "S = " << e;
					
		}
	system("pause");
}
