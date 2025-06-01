#include "Header.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;
int menu()
{
    system("cls");
    int c;
    cout << "Choose what to do" << endl;
    cout << "0 - exit" << endl;
    cout << "1 - Outuput all characters cards" << endl;
    cout << "2 - Add character card" << endl;
    cout << "3 - Delete character card" << endl;
    cout << "4 - Change character card" << endl;
    cout << "5 - Characters with latest obtained date" << endl;
    cout << "6 - Sort by date descending" << endl;
    cout << "7 - sort by date ascending" << endl;
    cout << "8 - Sort by name descending" << endl;
    cout << "9 - sort by name ascending" << endl;
    cout << "10 - Sort by minimum garanted 5*" << endl;
    cout << "11 - sort by maximum garanted 5*" << endl;
    cout << "12 - Sort by base possibility" << endl;
    cout << "13 - Sort by current possibility" << endl;
    cout << "14 - Sort by rarity" << endl;
    cout << "15 - Sort by type" << endl;
    cout << "16 - Sort by speciality" << endl;
    cout << "Choose:  ";
    cin >> c;
    return c;
}

void update_character(characters* a, int n)
{
    characters dat;
    int id, i;
    cout << "Enter character card id: "; cin >> id;
    for (i = 0; i < n; i++)
        if (a[i].id == id)
            break;
    if (i == n) {
        cout << "Character card with that id not found" << endl;
        return;
    }

    cout << "Enter name : "; cin >> dat.name;
    cout << "Enter rarity (n*): "; cin >> dat.rarity;
    cout << "Enter date (yyyymmdd): "; cin >> dat.dateofget;
    cout << "enter base probability(double): "; cin >> dat.base_probability;
    cout << "enter current probavility(double): "; cin >> dat.current_probability;
    cout << "enter type: "; cin >> dat.type;
    cout << "enter speciality attribute: "; cin >> dat.speciality_attribute;
    cout << "Enter current garantee, max garantee, min garantee: "; cin >> dat.garanted[0]; cin >> dat.garanted[1]; cin >> dat.garanted[2];
    dat.id = id;
    a[i] = dat;

    from_mas_to_file(a, n, "f:\\School\\files\\file_input.txt");
}

void delete_character(characters* a, int& n)
{
    int id, i;
    cout << "Enter character id: "; cin >> id;
    for (i = 0; i < n; i++)
        if (a[i].id == id)
            break;
    if (i == n) {
        cout << "Character with that id not found" << endl;
        return;
    }

    for (int j = i; j < n - 1; j++)
        a[j] = a[j + 1];
    n--;
    from_mas_to_file(a, n, "f:\\School\\files\\file_input.txt");
}

void insert_character(characters* a, int& n)
{
    characters dat;
    int max_id = 0;
    for (int i = 0; i < n; i++)
        if (a[i].id > max_id)
            max_id = a[i].id;

    cout << "Enter name: "; cin >> dat.name;
    cout << "Enter rarity (n*): "; cin >> dat.rarity;
    cout << "Enter date (yyyymmdd): "; cin >> dat.dateofget;
    cout << "enter base probability(double): "; cin >> dat.base_probability;
    cout << "enter current probavility(double): "; cin >> dat.current_probability;
    cout << "enter type: "; cin >> dat.type;
    cout << "enter speciality attribute: "; cin >> dat.speciality_attribute;
    cout << "Enter current garantee, max garantee, min garantee: "; cin >> dat.garanted[0]; cin >> dat.garanted[1]; cin >> dat.garanted[2];
    dat.id = max_id + 1;
    a[n++] = dat;

    from_mas_to_file(a, n, "f:\\School\\files\\file_input.txt");
}

void order_by_name_vozr(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[j].name, a[min_idx].name) < 0)
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            characters temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }
}

void order_by_name_ubiv(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[j].name, a[max_idx].name) > 0)
            {
                max_idx = j;
            }
        }
        if (max_idx != i)
        {
            characters temp = a[i];
            a[i] = a[max_idx];
            a[max_idx] = temp;
        }
    }
}

void order_by_dateofget_vozr(characters* a, int n)
{
    int min_date, imin;
    characters temp;
    for (int k = 0; k < n; k++)
    {
        min_date = a[k].dateofget;
        imin = k;
        for (int i = k; i < n; i++)
            if (a[i].dateofget < min_date)
            {
                min_date = a[i].dateofget;
                imin = i;
            }
        temp = a[k];
        a[k] = a[imin];
        a[imin] = temp;
    }
}

void order_by_dateofget_ubiv(characters* a, int n)
{
    int max_date, imax;
    characters temp;
    for (int k = 0; k < n; k++)
    {
        max_date = a[k].dateofget;
        imax = k;
        for (int i = k; i < n; i++)
            if (a[i].dateofget > max_date)
            {
                max_date = a[i].dateofget;
                imax = i;
            }
        temp = a[k];
        a[k] = a[imax];
        a[imax] = temp;
    }
}

void max_dateofget(characters* a, int n)
{
    int max_date = a[0].dateofget;
    for (int i = 0; i < n; i++)
        if (a[i].dateofget > max_date)
            max_date = a[i].dateofget;
    for (int i = 0; i < n; i++)
        if (a[i].dateofget == max_date)
        {
            cout << " - " << a[i].id << " " << a[i].name << " " << a[i].rarity;
            cout << " " << a[i].dateofget << " " << a[i].base_probability << "%";
            cout << " " << a[i].current_probability << "% " << a[i].type;
            cout << " " << a[i].speciality_attribute << " " << a[i].garanted[0] << a[i].garanted[1] << a[i].garanted[2] << endl;
        }
}

void vivod_mas(characters* a, int n)
{
    characters dat;
    for (int i = 0; i < n; i++)
    {
        dat = a[i];
        cout << " - " << dat.id << " " << dat.name << " " << dat.rarity;
        cout << " " << dat.dateofget << " " << dat.base_probability << "%";
        cout << " " << dat.current_probability << "% " << dat.type;
        cout << " " << dat.speciality_attribute << " " << a[i].garanted[0] << a[i].garanted[1] << a[i].garanted[2] << endl;
    }
}

void from_mas_to_file(characters* a, int n, const char* filename)
{
    ofstream f_out;
    f_out.open(filename);
    characters dat;
    for (int i = 0; i < n; i++)
    {
        dat = a[i];
        f_out << dat.id << endl;
        f_out << dat.name << endl;
        f_out << dat.rarity << endl;
        f_out << dat.dateofget << endl;
        f_out << dat.base_probability << endl;
        f_out << dat.current_probability << endl;
        f_out << dat.type << endl;
        f_out << dat.speciality_attribute << endl;
        f_out << dat.garanted[0] << " " << dat.garanted[1] << " " << dat.garanted[2] << endl;
    }
    f_out.close();
}

void from_file_to_mas(characters* a, int& n, const char* filename)
{
    ifstream f;
    f.open(filename);
    characters dat;
    while (f.peek() != EOF)
    {
        f >> dat.id;
        f >> dat.name;
        f >> dat.rarity;
        f >> dat.dateofget;
        f >> dat.base_probability;
        f >> dat.current_probability;
        f >> dat.type;
        f >> dat.speciality_attribute;
        f >> dat.garanted[0]; f >> dat.garanted[1]; f >> dat.garanted[2];
        if (strcmp(dat.name, ""))
        {
            a[n] = dat;
            n++;
        }
    }
    f.close();
}
void order_by_min_garanted_5star(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool is_j_5star = strstr(a[j].rarity, "5*") != nullptr;
            bool is_j1_5star = strstr(a[j + 1].rarity, "5*") != nullptr;

            if (is_j_5star && is_j1_5star) {
                if (a[j].garanted[0] > a[j + 1].garanted[0]) {
                    swap(a[j], a[j + 1]);
                }
            }
            else if (!is_j_5star && is_j1_5star) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void order_by_max_garanted_5star(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool is_j_5star = strstr(a[j].rarity, "5*") != nullptr;
            bool is_j1_5star = strstr(a[j + 1].rarity, "5*") != nullptr;

            if (is_j_5star && is_j1_5star) {
                if (a[j].garanted[0] < a[j + 1].garanted[0]) {
                    swap(a[j], a[j + 1]);
                }
            }
            else if (!is_j_5star && is_j1_5star) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void order_by_base_probability(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].base_probability < a[min_idx].base_probability) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
}

void order_by_current_probability(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].current_probability > a[max_idx].current_probability) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(a[i], a[max_idx]);
        }
    }
}
void order_by_speciality(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[j].speciality_attribute, a[min_idx].speciality_attribute) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
}

void order_by_type(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[j].type, a[min_idx].type) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
}

void order_by_rarity(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int rarity_j = a[j].rarity[0] - '0';
            int rarity_j1 = a[j + 1].rarity[0] - '0';

            if (rarity_j < rarity_j1) {
                swap(a[j], a[j + 1]);
            }
        }
    }
