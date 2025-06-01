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
    cout << "„B„„q„u„‚„y„„„u „‚„u„w„y„} „‚„p„q„€„„„ „„‚„€„s„‚„p„}„}„:" << endl;
    cout << "0 - „B„„‡„€„t" << endl;
    cout << "1 - „B„„r„€„t „r„ƒ„u„‡ „„u„‚„ƒ„€„~„p„w„u„z" << endl;
    cout << "2 - „D„€„q„p„r„y„„„Ž „„u„‚„ƒ„€„~„p„w„p" << endl;
    cout << "3 - „T„t„p„|„y„„„Ž „„u„‚„ƒ„€„~„p„w„p" << endl;
    cout << "4 - „I„x„}„u„~„y„„„Ž „„u„‚„ƒ„€„~„p„w„p" << endl;
    cout << "5 - „P„u„‚„ƒ„€„~„p„w„y „ƒ „~„p„y„q„€„|„Ž„Š„u„z „t„p„„„€„z „„€„|„…„‰„u„~„y„‘" << endl;
    cout << "6 - „R„€„‚„„„y„‚„€„r„{„p „„€ „t„p„„„u („…„q„„r„p„~„y„u)" << endl;
    cout << "7 - „R„€„‚„„„y„‚„€„r„{„p „„€ „t„p„„„u („r„€„x„‚„p„ƒ„„„p„~„y„u)" << endl;
    cout << "8 - „R„€„‚„„„y„‚„€„r„{„p „„€ „y„}„u„~„y („…„q„„r„p„~„y„u)" << endl;
    cout << "9 - „R„€„‚„„„y„‚„€„r„{„p „„€ „y„}„u„~„y („r„€„x„‚„p„ƒ„„„p„~„y„u)" << endl;
    cout << "10 - „R„€„‚„„„y„‚„€„r„{„p „„€ „}„y„~„y„}„p„|„Ž„~„€„}„… „s„p„‚„p„~„„„… 5š" << endl;
    cout << "11 - „R„€„‚„„„y„‚„€„r„{„p „„€ „}„p„{„ƒ„y„}„p„|„Ž„~„€„}„… „s„p„‚„p„~„„„… 5š" << endl;
    cout << "12 - „R„€„‚„„„y„‚„€„r„{„p „„€ „q„p„x„€„r„€„z „r„u„‚„€„‘„„„~„€„ƒ„„„y" << endl;
    cout << "13 - „R„€„‚„„„y„‚„€„r„{„p „„€ „„„u„{„…„‹„u„z „r„u„‚„€„‘„„„~„€„ƒ„„„y" << endl;
    cout << "14 - „R„€„‚„„„y„‚„€„r„{„p „„€ „‚„u„t„{„€„ƒ„„„y" << endl;
    cout << "„B„p„Š „r„„q„€„‚: ";
    cin >> c;
    return c;
}

void update_character(characters* a, int n)
{
    characters dat;
    int id, i;
    cout << "„B„r„u„t„y„„„u id „„u„‚„ƒ„€„~„p„w„p: "; cin >> id;
    for (i = 0; i < n; i++)
        if (a[i].id == id)
            break;
    if (i == n) {
        cout << "„P„u„‚„ƒ„€„~„p„w „ƒ „„„p„{„y„} id „~„u „~„p„z„t„u„~!" << endl;
        return;
    }

    cout << "„N„p„x„r„p„~„y„u: "; cin >> dat.name;
    cout << "„Q„u„t„{„€„ƒ„„„Ž: "; cin >> dat.rarity;
    cout << "„D„p„„„p „„€„|„…„‰„u„~„y„‘: "; cin >> dat.dateofget;
    cout << "„A„p„x„€„r„p„‘ „r„u„‚„€„‘„„„~„€„ƒ„„„Ž: "; cin >> dat.base_probability;
    cout << "„S„u„{„…„‹„p„‘ „r„u„‚„€„‘„„„~„€„ƒ„„„Ž: "; cin >> dat.current_probability;
    cout << "„S„y„: "; cin >> dat.type;
    cout << "„R„„u„ˆ„y„p„|„Ž„~„„z „p„„„‚„y„q„…„„: "; cin >> dat.speciality_attribute;
    cout << "„C„p„‚„p„~„„: "; cin >> dat.garanted[0]; cin >> dat.garanted[1]; cin >> dat.garanted[2];
    dat.id = id;
    a[i] = dat;

    from_mas_to_file(a, n, "f:\\School\\files\\file_input.txt");
}

void delete_character(characters* a, int& n)
{
    int id, i;
    cout << "„B„r„u„t„y„„„u id „„u„‚„ƒ„€„~„p„w„p „t„|„‘ „…„t„p„|„u„~„y„‘: "; cin >> id;
    for (i = 0; i < n; i++)
        if (a[i].id == id)
            break;
    if (i == n) {
        cout << "„P„u„‚„ƒ„€„~„p„w „ƒ „„„p„{„y„} id „~„u „~„p„z„t„u„~!" << endl;
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

    cout << "„N„p„x„r„p„~„y„u: "; cin >> dat.name;
    cout << "„Q„u„t„{„€„ƒ„„„Ž: "; cin >> dat.rarity;
    cout << "„D„p„„„p „„€„|„…„‰„u„~„y„‘: "; cin >> dat.dateofget;
    cout << "„A„p„x„€„r„p„‘ „r„u„‚„€„‘„„„~„€„ƒ„„„Ž: "; cin >> dat.base_probability;
    cout << "„S„u„{„…„‹„p„‘ „r„u„‚„€„‘„„„~„€„ƒ„„„Ž: "; cin >> dat.current_probability;
    cout << "„S„y„: "; cin >> dat.type;
    cout << "„R„„u„ˆ„y„p„|„Ž„~„„z „p„„„‚„y„q„…„„: "; cin >> dat.speciality_attribute;
    cout << "„C„p„‚„p„~„„: "; cin >> dat.garanted[0]; cin >> dat.garanted[1]; cin >> dat.garanted[2];
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

void order_by_rarity(characters* a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int rarity_j = atoi(a[j].rarity);
            int rarity_j1 = atoi(a[j + 1].rarity);

            if (rarity_j < rarity_j1) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
// test
