#include "Header.h"
#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
void input(char* str)
{
    gets_s(str, 80);
    //gets_s(s,sizeof(s));
    //fgets(s,sizeof(s),stdin);
}
void output(char* str)
{
    cout << str << endl;
}
void AbirValg(char* input) {
    int length = strlen(input);
    char* temp = new char[length + 1];
    int tempIndex = 0;

    char* wordStart = input;
    char* wordEnd = input;

    while (*wordEnd) {
        if (*wordEnd == ' ') {
            for (char* p = wordEnd - 1; p >= wordStart; p--) {
                temp[tempIndex++] = *p;
            }
            temp[tempIndex++] = ' ';
            wordStart = wordEnd + 1;
        }
        wordEnd++;
    }
    for (char* p = wordEnd - 1; p >= wordStart; p--) {
        temp[tempIndex++] = *p;
    }
    temp[tempIndex] = '\0';
    for (int i = 0; i <= tempIndex; i++) {
        input[i] = temp[i];
    }

    delete[] temp;
}