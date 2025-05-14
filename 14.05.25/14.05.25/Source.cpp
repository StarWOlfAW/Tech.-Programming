#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;



struct student
{
	char surname[20];
	char name[15];
	int age;
	int grade;
};

int from_file_to_arr(student *dat);
void output_arr(student* a, int k);
void max_age(student* a, int k);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	student a[10000];
	int k = from_file_to_arr(a);
	output_arr(a, k);
	max_age(a,k);
	system("pause");
	return 0;
}
int from_file_to_arr(student *dat)
{
	int k = 0;
	ifstream f;
	f.open("d:\\fiile.txt");
	
	while (f.peek() != EOF)
	{
		f >> dat[k].surname;
		f >> dat[k].name;
		f >> dat[k].age;
		f >> dat[k].grade;
		k++;
	}
	f.close();
	return k;
}
void output_arr(student *a, int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << a[i].surname << " " << a[i].name << " Возраст - " << a[i].age << " Оценка - " << a[i].grade << endl;
	}

}
void max_age(student* a, int k)
{
	int posn = 0, max = a->age;
	for (int i = 0; i < k; i++)
	{
		if (max < a[i].age)
		{
			max = a[i].age;
			posn = i;
		}
	}
	cout << " Возраст макс : " << max;
}