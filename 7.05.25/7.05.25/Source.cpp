#include <iostream>

using namespace std;

void input(char* filename);
void output(char* filename);
void insert(char *filename);
void abs_complex(char* filename);
void delete_abs_complex(char* filename);

struct complex
{
	double Re, Im;
};

int main()
{
	char filename[80] = "d:\\file.dat";
	input(filename);
	//insert(filename);
	cout << "File contains" << endl;
	output(filename);
	delete_abs_complex(filename);
	output(filename);
	system("pause");
	return 0;
}
void input(char *filename)
{
	FILE* f; complex number;
	fopen_s(&f, filename, "wb");
	int n;
	cout << "Enter amount of complex numbers" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Input number " << endl;
		cin >> number.Re; cin >> number.Im;
		fwrite(&number, sizeof(number), 1, f);
	}
	fclose(f);
}
void output(char* filename)
{
	FILE* f;	complex number;
	fopen_s(&f, filename, "rb");
	while (fread(&number, sizeof(number), 1, f))
		cout << number.Re << " + " << number.Im << "i" << endl;
	fclose(f);
}
void insert(char* filename)
{
	FILE* f; complex number;
	fopen_s(&f, filename, "ab");
	int n;
	cout << "Enter amount of complex numbers" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Input number " << endl;
		cin >> number.Re; cin >> number.Im;
		fwrite(&number, sizeof(number), 1, f);
	}
	fclose(f);
}
void abs_complex(char* filename)
{
	FILE* f; complex number; complex current;
	fopen_s(&f, filename, "rb");
	(fread(&number, sizeof(number), 1, f));
	int max = sqrt(number.Re * number.Re + number.Im * number.Im);
	while (fread(&number, sizeof(number), 1, f))
	{
		if (max < (sqrt(number.Re * number.Re + number.Im * number.Im)))
		{
			max = (sqrt(number.Re * number.Re + number.Im * number.Im));
			current = number;
		}
	}
	cout << "max: " << max << " that number: " << current.Re << " + " << current.Im << "i" << endl;
}
void delete_abs_complex(char* filename)
{
	FILE* f; complex number; fopen_s(&f, filename, "rb");
	(fread(&number, sizeof(number), 1, f));
	int max = sqrt(number.Re * number.Re + number.Im * number.Im);
	int counter = 0, current = 0;
	fopen_s(&f, filename, "rb");
	while (fread(&number, sizeof(number), 1, f))
	{
		counter++;
		if (max < (sqrt(number.Re * number.Re + number.Im * number.Im)))
		{
			max = (sqrt(number.Re * number.Re + number.Im * number.Im));
			current = counter;
		}
	}
	fopen_s(&f, filename, "r+");
	for (int i = 0; i < current; i++)
	{
		(fread(&number, sizeof(number), 1, f));
	}
	number.Im = '\0'; number.Re = '\0';
}