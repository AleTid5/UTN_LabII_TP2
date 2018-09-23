#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef char char1[1], char12[12], char25[25];
const char* threeOptions = "123";
const char* fourOptions = "1234";
unsigned int maxOptionLength = 1;
unsigned const int maxPagination = 5;
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

void setCurrentDate() { //Singleton de fecha del dia.
    if (currentDate[0] != '\0')
        return;

    tm tstruct;
    char12 buf;
    time_t now = time(0);
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    strcpy(currentDate, buf);
}

bool strFind(auto haystack, auto needle)
{
    int haystackLenght = strlen(haystack);
    int needleLenght = strlen(needle);

    if (needleLenght > haystackLenght)
        return false;

    for (int i = 0; i < haystackLenght; i++)
        if (toupper((int) haystack[i]) == toupper((int) needle[0]))
        {
            int aux = i, cont = 0;

            for(int j = 0; j < needleLenght; j++, aux++)
                if (toupper((int) haystack[aux]) == toupper((int) needle[j]))
                    cont++;

            if (cont == needleLenght)
                return true;
        }

    return false;
}

void divider(unsigned int i, bool headerDivider = false)
{
    cout << Text_Center;

    if (headerDivider) {
        cout << "같";
        for (i -= 4; i > 0; i--)
            cout << " ";
        cout << "같";
    } else {
        for (; i > 0; i--)
            cout << "�";
    }

    cout << endl;
}

const char* getColorCodeByColorName(const char* colorName) {
    if (! (bool) strcmp("black", colorName))    return "\033[1;30m";
    if (! (bool) strcmp("red", colorName))      return "\033[1;31m";
    if (! (bool) strcmp("green", colorName))    return "\033[1;32m";
    if (! (bool) strcmp("yellow", colorName))   return "\033[1;33m";
    if (! (bool) strcmp("blue", colorName))     return "\033[1;34m";
    if (! (bool) strcmp("magenta", colorName))  return "\033[1;35m";
    if (! (bool) strcmp("cyan", colorName))     return "\033[1;36m";

    return "\033[1;37m";
}

void buildMenu(const char* header, bool isTitle, int sizeOfTitle, const char* colorName = "white")
{
   int startWrite = (isTitle ? 31 : 33) - (sizeOfTitle / 2), endWrite = startWrite + strlen(header), position = 0;

   cout << Text_Center << "같";

   if (isTitle) cout << "같";

   cout << getColorCodeByColorName(colorName);

   for (int i = 0; i < (isTitle ? 62 : 66); i++) {
        if (i > startWrite && i <= endWrite) {
            cout << header[position];
            position++;
        } else {
            cout << " ";
        }
   }

   cout << "\033[0m같";

   if (isTitle) cout << "같";

   cout << endl;
}

#endif // CONFIG_H_INCLUDED
