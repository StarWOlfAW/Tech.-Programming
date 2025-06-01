#include "Header.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    characters* a = new characters[1000];
    int n = 0;
    const char* filename = "f:\\School\\files\\file_input.txt";

    from_file_to_mas(a, n, filename);

    int c;
    while (true)
    {
        c = menu();
        switch (c)
        {
        case 1: vivod_mas(a, n); break;
        case 2: insert_character(a, n); break;
        case 3: delete_character(a, n); break;
        case 4: update_character(a, n); break;
        case 5: max_dateofget(a, n); break;
        case 6:
            order_by_dateofget_ubiv(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_date_ubiv.txt");
            cout << "Sort by descending date done " << endl;
            break;
        case 7:
            order_by_dateofget_vozr(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_date_vozr.txt");
            cout << "Sort by ascending date done" << endl;
            break;
        case 8:
            order_by_name_ubiv(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_name_ubiv.txt");
            cout << "Sort by name descending done" << endl;
            break;
        case 9:
            order_by_name_vozr(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_name_vozr.txt");
            cout << "Sort by name ascending done" << endl;
            break;
        case 10:
            order_by_min_garanted_5star(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_min_garanted.txt");
            cout << "Sort by minimum 5* garantee done" << endl;
            break;
        case 11:
            order_by_max_garanted_5star(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_max_garanted.txt");
            cout << "Sort by max faranted 5* done" << endl;
            break;
        case 12:
            order_by_base_probability(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_base_prob.txt");
            cout << "Sort by base probability done" << endl;
            break;
        case 13:
            order_by_current_probability(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_current_prob.txt");
            cout << "Sort by current probability done" << endl;
            break;
        case 14:
            order_by_rarity(a, n);
            from_mas_to_file(a, n, "f:\\School\\files\\file_output_rarity.txt");
            cout << "Sort by rarity done" << endl;
            break;
        case 15:
            order_by_speciality(a, n);
            from_mas_to_file(a, n, "d:\\file_output_speciality.txt");
            cout << "Sort by speciality done" << endl;
            break;
        case 16:
            order_by_type(a,n);
            from_mas_to_file(a, n, "d:\\file_output_type.txt");
            cout << "Sort by type done" << endl;
            break;
        case 0:
            delete[] a;
            return 0;
        default:
            cout << "Incorrect choice " << endl;
        }
        system("pause");
    }

    delete[] a;
    return 0;
}

