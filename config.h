#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef char char1[1], char12[12], char25[25];
const char* mainOptions = "123";
const char* configOptions = "1234";
unsigned int maxOptionLength = 1;
char1 entry;
char12 currentDate = {0};
unsigned const char Text_Center[4] = "\t\t";
FILE * file;

void loading(int percentage = 0, unsigned int speed = 20)
{
    if (percentage <= 100)
    {
        sys::cls();
        cout << endl << Text_Center << "\033[1;32m";
        for (int i = 0; i < percentage / 2; i++)
            cout << "�";
        cout << endl << Text_Center << "Cargando.. " << percentage << "%";
        sys::msleep(1);
        loading(percentage + speed);
        cout << "\033[0m";
    }
}

void showErrorFooter()
{
    cout << "\033[1;31m";
    cout << Text_Center << "같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같" << endl;
    cout << Text_Center << "같                El valor ingresado es incorrecto                  같" << endl;
    cout << Text_Center << "같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같" << endl;
    cout << "\033[0m";
}

void positionate(auto structure, unsigned int position, unsigned int times = 0)
{
    size_t structSize = sizeof(structure);

    if (position == 1) {
        fseek(file, 0, 2);
        long sizeOfFile = ftell(file);
        fseek(file, sizeOfFile - structSize, 0);
    }

    if (position == 2) {
        fseek(file, structSize * times, 0);
    }
}

void setCurrentDate() {
    if (currentDate[0] != '\0')
        return;

    tm tstruct;
    char12 buf;
    time_t now = time(0);
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    strcpy(currentDate, buf);
}

int strFind(auto haystack, auto needle)
{
    int haystackLenght = strlen(haystack);
    int needleLenght = strlen(needle);

    if (needleLenght > haystackLenght)
        return -1;

    int position = -1;

    for (int i = 0; i < haystackLenght; i++)
        if (haystack[i] == needle[0])
        {
            position = i;
            int aux = i, cont = 0;

            for(int j = 0; j < needleLenght; j++, aux++)
                if (haystack[aux] == needle[j])
                    cont++;

            if (cont == needleLenght)
                return position;

            position = -1;
        }

    return position;
}


#endif // CONFIG_H_INCLUDED
