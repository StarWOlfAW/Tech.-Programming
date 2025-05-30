#ifndef Source
#define Source
struct characters
{
    int id;
    char name[60];
    char rarity[60];
    int dateofget;
    double base_probability;
    double current_probability;
    char type[60];
    char speciality_attribute[60];
    int garanted[3];
};

void from_file_to_mas(characters* a, int& n, const char* filename);
void from_mas_to_file(characters* a, int n, const char* filename);
void vivod_mas(characters* a, int n);
void max_dateofget(characters* a, int n);
void order_by_dateofget_ubiv(characters* a, int n);
void order_by_dateofget_vozr(characters* a, int n);
void order_by_name_ubiv(characters* a, int n);
void order_by_name_vozr(characters* a, int n);
void insert_character(characters* a, int& n);
void delete_character(characters* a, int& n);
void update_character(characters* a, int n);
void order_by_min_garanted_5star(characters* a, int n);
void order_by_max_garanted_5star(characters* a, int n);
void order_by_base_probability(characters* a, int n);
void order_by_current_probability(characters* a, int n);
void order_by_rarity(characters* a, int n);
int menu();
#endif
