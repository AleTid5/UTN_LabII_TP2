////#############################################################################
// ARCHIVO : MainRules.h
// AUTOR : Tidele Alejandro - Acosta Guido
// FECHA DE CREACION : 03/09/2018.
// ULTIMA ACTUALIZACION: 28/09/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 10.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// Reglas del sistema.
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef MAINRULES_H_INCLUDED
#define MAINRULES_H_INCLUDED

#include <string>      // Librería String
#include "../config.h" // Configuraciones del sistema.

namespace Rule
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
