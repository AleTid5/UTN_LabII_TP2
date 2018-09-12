#ifndef MAINRULES_H_INCLUDED
#define MAINRULES_H_INCLUDED
#include <string>      // Librería String
#include "../config.h" // Configuraciones del sistema.

namespace MainRule
{
    bool validEntry(unsigned int maxLength)
    {
        return maxLength >= strlen(entry);
    }

    bool validEntry(const char* acceptedLetters)
    {
        unsigned int i = 0;
        for (; acceptedLetters[i] != entry[0] && acceptedLetters[i] != '\0'; i++);
        return i != strlen(acceptedLetters);
    }
}

#endif // MAINRULES_H_INCLUDED
