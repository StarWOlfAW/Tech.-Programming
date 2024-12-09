#include <iostream>;
#include <ctime>;
using namespace std;
int average(int* a, int n); int abovezero(int* a, int n); int abovezero2(int* a, int n); int coldest(int* a, int n); int hottest(int* a, int n); void output_mass(int* a, int n); void inp_mass2(int* a, int n); int coldest(int* a, int n);int daysaverage(int* a, int n);
int closesttoaverage(int* a, int n); int coldestsecond(int* a, int n); int coldestafter(int* a, int n); int swap(int* a, int n); int averagebefore(int* a, int n); int twoofcoldest(int* a, int n);
int main()
{
	srand(time(0));
	const int n = 31;
	int* a = new int[n], i = 0;
	inp_mass2(a, n);
	//output_mass(a, n);
	//process(a, n);
	cout << " >>> " << average(a, n) << " >1 " << abovezero(a, n) << " >2 " << abovezero2(a, n) << " >3 " << coldest(a, n) << " >4 " <<daysaverage(a,n) << " >5 " << closesttoaverage(a, n);
	//void inp_mass2(int* a, int n);
	//output_mass(a, n);
	system("pause");
	return 0;

}
int hottest(int* a, int n)
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
int closesttoaverage(int* a, int n)
{
	int sum = 0, s2 = 0, diff = 77, c = 0;
	for (int i = 0; i < n; i++)
		sum = a[i] + sum;
	int average = sum / 31;
	for (int i = 0; i < n; i++)
	{
		if ((abs(a[i] - average)) < diff)
			c = i;
	}
	return c;
}
int coldestsecond(int* a, int n)
{
	int min = a[0];
	for (int i = 15; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	for (int i = 15; i < n; i++)
	{
		if (a[i] == min)
			return i;
	}
}
int coldestafter(int* a, int n)
{
	int min = a[0],sr = 0, max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < max)
			max = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
			sr = i;
	}
	for (int i = sr; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int swap(int* a, int n)
{
	int min = a[0], sr = 0, max = a[0], imin = 0, imax = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	}
	for (int i = sr; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			imin = i;
		}
	}
	a[imin] = max;
	a[imax] = min;
	return a[imin], a[imax];
}
int averagebefore(int* a, int n)
{
	int min = a[0], sum = 0, sr = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			sr = i;
		}
	}
	for (int i = sr; i > 0; i--)
		sum = a[i] + sum;
	int average = sum / 31;
	return average;
}
int twoofcoldest(int* a, int n)
{
	int min = a[0], first = 40, second = 40;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < first)
		{
			second = first;
			first = a[i];
		}
	}
	return first, second;
}
void left(int* a, int n)
{
	int first = a[0];
	for (int i = 0; i < n-1; i++)
	{
		a[i] = a[i+1];
	}
	a[n - 1] = first;
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
		a[i] = ((rand() % 31) - 20);
	}
}
