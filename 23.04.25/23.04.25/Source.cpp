#include <iostream>
#include <string>

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
void young_age(Student* s);
void lowest_sum(Student* s);
bool best(Student* s);





int main()
{
	const int n = 3;
	Student* a = new Student[n];
	input_Student_mas(a,n);
	output_Student_mas(a, n);
	cout << endl;
	//young_age(a);
	//lowest_sum(a);
	for (int i = 0; i < n; i++)
		if (best(&a[i]))
		{
			output_Student(&a[i]);
			cout << endl;
		}
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
	for (int i =0; i < n; i++)
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
		cout << "         " << i+1 <<" Student       " << endl;
		output_Student(&s[i]);
		cout << endl;
	}
}
void young_age(Student* s)
{
	int min_age = s->age;
	int card = 0;
	for (int i = 0; i < 3; i++)
	{
		if (s[i].age < min_age)
			card = i;
	}
	cout << "Youngest student ";
	output_Student(&s[card]);
}
void lowest_sum(Student* s)
{
	int lowest = 0, sum = 0;
	int card = 0;
	for (int g = 0; g < m; g++)
		lowest += s->grades[g];
	for (int i = 0; i < 3; i++)
	{
		for (int g = 0; g < m; g++)
			sum += s[i].grades[g];
		if (sum < lowest)
			card = i;
	}
	cout << "Student with lowest " << endl;
	output_Student(&s[card]);
}
bool best(Student* s)
{
	for (int g = 0; g < m; g++)
	{
		if (s->grades[g] == 2)
			return true;
	}
	return false;
}