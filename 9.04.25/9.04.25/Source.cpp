#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

struct point
{
	double x, y;
};

void input_point(point* A);
void output_point(point* A);
void output_pointm(point* A, int n);
void input_pointm(point* A, int n);
void quarters(point* A, int n);
double len(point* A, point* B);
void maxlen(point* A, int n);

int main()
{
	srand(time(0));
	const int n = 10;
	point* A = new point[n];
	input_pointm(A,n);
	output_pointm(A,n);
	//quarters(A, n);
	maxlen(A, n);
}
void input_point(point* A)
{
	A->x = rand() % 19 - 9;
	A->y = rand() % 19 - 9;

}
void output_point(point* A)
{
	cout << "(" << A->x << "; " << A->y << ")" << endl;
}
void input_pointm(point* A, int n)
{
	for (int i = 0; i < n; i++)
		input_point(&A[i]);
}
void output_pointm(point* A, int n)
{
	for (int i = 0; i < n; i++)
		output_point(&A[i]);
}
void quarters(point* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i].x > 0 and A[i].y > 0) cout << "Point " << i+1 << " is in quarter 1" << endl;
		if (A[i].x > 0 and A[i].y < 0) cout << "Point " << i+1 << " is in quarter 4" << endl;
		if (A[i].x < 0 and A[i].y < 0) cout << "Point " << i+1 << " is in quarter 3" << endl;
		if (A[i].x < 0 and A[i].y > 0) cout << "Point " << i+1 << " is in quarter 2" << endl;
		if (A[i].x == 0.0 and A[i].y == 0.0) cout << "Point " << i+1 << " is at the center" << endl;
	}
}
double len(point* A,point* B)
{
	double length;
	length = sqrt((A->x - B->x) * (A->x - B->x) + (A->y - B->y) * (A->y - B->y));
	return length;
}
void maxlen(point* A, int n)
{
	double max = 0.0;
	int first = 0, second = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (len(&A[i], &A[j]) > max) 
			{
				max = len(&A[i], &A[j]);
				first = i;
				second = j;
			}
	cout << "Max length " << max << endl;
	cout << "That points ";  output_point(&A[first]);
	cout << "Second point "; output_point(&A[second]);
}