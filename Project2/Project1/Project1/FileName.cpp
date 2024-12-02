#include <iostream>;
#include <ctime>;
using namespace std;
int average(int* a, int n); int abovezero(int* a, int n); int abovezero2(int* a, int n); int coldest(int* a, int n); int process1(int* a, int n); void output_mass(int* a, int n); void inp_mass2(int* a, int n);
int main()
{
	srand(time(0));
	const int n = 31;
	int* a = new int[n], i = 0;
	inp_mass2(a, n);
	output_mass(a, n);
		//process(a, n);
	cout << " >>> " << average(a, n) << " >1 " << abovezero(a, n) << " >2 " << abovezero2(a, n);
	//output_mass(a, n);
	system("pause");
	return 0;

}
int process1(int* a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int average(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = a[i] + sum;
	int average = sum / 31;
	return average;
}
int abovezero(int* a, int n)
{
	int col = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			col = col + 1;
	}
	return col;
}
int abovezero2(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			a[i]++;
			break;
			return i, a[i];
		}
		
	}
}
int coldest(int* a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < max)
			max = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
			return i;
	}
}
int daysaverage(int* a, int n)
{
	int sum = 0, s2 = 0;
	for (int i = 0; i < n; i++)
		sum = a[i] + sum;
	int average = sum / 31;
	for (int i = 0; i < n; i++)
		if (a[i] > average)
			s2++;
	return s2;
}
void output_mass(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
}
void inp_mass2(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 31 - 20;
	}
}
