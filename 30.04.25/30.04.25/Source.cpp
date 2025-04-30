#include <iostream>
#include <cstring>

using namespace std;
const int m = 5;
struct Student
{
	char name[30];
	int age;
	int grades[m];
};

using namespace std;
void output_Student(Student* s);
void input_Student_mas(Student* s, int n);
void input_Student(Student* s);
void output_Student_mas(Student* s, int n);
void sort_by_age(Student* s,int n);
void sort_by_name(Student* s, int n);
void sort_by_ggrades(Student* s, int n);

int main()
{
	const int n = 3;
	Student* a = new Student[n];
	input_Student_mas(a, n);
	output_Student_mas(a, n);
	cout << endl;
	sort_by_age(a, n);
	cout << "Increasing: " << endl;
	output_Student_mas(a, n);
	sort_by_name(a, n);
	cout << "Increasing: " << endl;
	output_Student_mas(a, n);
	sort_by_ggrades(a, n);
	cout << "Increasing: " << endl;
	output_Student_mas(a, n);
	delete a;
	system("pause");
	return 0;
}
void output_Student(Student* s)
{
	cout << "Name: " << s->name << endl << "Age: " << s->age << endl << "Grades: ";
	for (int i = 0; i < m; i++)
		cout << s->grades[i] << ", ";
}
void input_Student_mas(Student* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Input data of student " << i + 1 << " " << endl;
		input_Student(&s[i]);
	}
}
void input_Student(Student* s)
{
	cout << "Enter name " << endl;
	cin >> s->name;
	cout << "Enter age " << endl;
	cin >> s->age;
	cout << "Input grades " << endl;
	for (int g = 0; g < m; g++)
		cin >> s->grades[g];
}
void output_Student_mas(Student* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "         " << i + 1 << " Student       " << endl;
		output_Student(&s[i]);
		cout << endl;
	}
}
void sort_by_age(Student* s, int n)
{
	Student temp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (s[j].age > s[j + 1].age)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
}
void sort_by_name(Student* s, int n)
{
	Student temp;
	for (int i= 0; i < n-1; i++)
		for (int j = 0; j < n-1; j++)
		{
			if (strcmp(s[j].name, s[j + 1].name) == -1)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
}
void sort_by_ggrades(Student* s, int n)
{
	Student temp;
	
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int sum1 = 0, sum2 = 0;
			for (int g = 0; g < m; g++)
			{
				if (s[j].grades[g] >3) sum1++;
				if (s[j+1].grades[g]>3) sum2++;
			}
			if (sum1 > sum2)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
}