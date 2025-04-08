#include "Header.h"
#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
void words(char* str)
{
    char new_str[80];
    char last_str[80];
    int k, i;
    i = strlen(str) - 1;
    while ((str[i] == ' ') && (i >= 0)) i--;
    while ((str[i] != ' ') && (i >= 0)) i--;
    i++;
    k = 0;
    while ((str[i] != ' ') && (i < strlen(str)))
    {
        last_str[k] = str[i];
        k++; i++;
    }
    last_str[k] = '\0';
    //vivod(last_str);

    i = 0;
    while (i < strlen(str))
    {
        while ((str[i] == ' ') && (i < strlen(str)))
            i++;
        k = 0;
        while ((str[i] != ' ') && (i < strlen(str)))
        {
            new_str[k] = str[i];
            k++; i++;
        }
        new_str[k] = '\0';
        if ((strcmp(last_str, new_str)) && (notsame(new_str)))
            output(new_str);
    }
}
void input(char* str)
{
    gets_s(str,80);
    //gets_s(s,sizeof(s));
    //fgets(s,sizeof(s),stdin);
}
void output(char* str)
{
    cout << str << endl;
}
bool notsame(char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        for (int k = i + 1; k <= strlen(str); k++)
        {
            if (str[i] == str[k])
            {
                return 0;
            }
        }
    }
    return 1;
}