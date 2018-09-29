////#############################################################################
// ARCHIVO : config.h
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
// Configuraciones generales del sistema.
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
                    // objetos cin, cout y endl.
#include <string>   // Libreria de manejo de cadenas.
using namespace std;

//***************************************************************************
// DEFINICION DE LAS VARIABLES GLOBALES DE CONFIGURACION
//===========================================================================
typedef char char1[1], char12[12], char25[25]; // Tipos de cadenas reutilizables.
const char* threeOptions = "123"; // Opciones validas
const char* fourOptions = "1234"; // Opciones validas
const char* fiveOptions = "12345"; // Opciones validas
const char* sixOptions = "123456"; // Opciones validas
unsigned int maxOptionLength = 1;  // Tamaño maximo de opciones validas
unsigned const int maxPagination = 5;  // Tamaño maximo de paginacion
char1 entry; // Entrada de opcioens
char12 currentDate = {0}; // Fecha actual
unsigned const char Text_Center[4] = "\t\t"; // Centrado de texto
FILE * file; // Puntero a archivo

//***************************************************************************
// DEFINICION DE LAS FUNCIONES
//===========================================================================
// FUNCION   : void loading(int percentage = 0, unsigned int speed = 20)
// ACCION    : Muestra en pantalla un cargador.
// PARAMETROS: - int percentage: Porcentaje inicial.
//             - unsigned int speed: Velocidad de carga (Simil MB).
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void loading(int percentage = 0, unsigned int speed = 20)
{
    if (percentage <= 100)
    {
        sys::cls();
        cout << endl << Text_Center << "\033[1;32m";
        for (int i = 0; i < percentage / 2; i++)
            cout << "°";
        cout << endl << Text_Center << "Cargando.. " << percentage << "%";
        sys::msleep(1);
        loading(percentage + speed);
        cout << "\033[0m";
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void showErrorFooter()
// ACCION    : Muestra en pantalla un cartel de error.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showErrorFooter()
{
    cout << "\033[1;31m";
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                El valor ingresado es incorrecto                  °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << "\033[0m";
}

//---------------------------------------------------------------------------
// FUNCION   : void setCurrentDate()
// ACCION    : Carga la fecha de hoy. Si ya existe, no la vuelve a cargar.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void setCurrentDate() { // Singleton de fecha del dia.
    if (currentDate[0] != '\0')
        return;

    tm tstruct;
    char12 buf;
    time_t now = time(0);
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    strcpy(currentDate, buf);
}

//---------------------------------------------------------------------------
// FUNCION   : bool strFind(char25 haystack, char25 needle)
// ACCION    : Verifica si encuentra la aguja en el pajar.
// PARAMETROS: - char25 haystack: El monton donde debe buscar.
//             - char25 needle: El valor a buscar en el monton.
// DEVUELVE  : Verdadero si lo encuentra, falso si no.
//---------------------------------------------------------------------------
bool strFind(char25 haystack, char25 needle)
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

//---------------------------------------------------------------------------
// FUNCION   : void divider(unsigned int i, bool headerDivider = false)
// ACCION    : Divisor de cabecera de menu.
// PARAMETROS: - unsigned int i: Longitud del divisor.
//             - bool headerDivider: Determina si muestra linea vacia o caracteres.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void divider(unsigned int i, bool headerDivider = false)
{
    cout << Text_Center;

    if (headerDivider) {
        cout << "°°";
        for (i -= 4; i > 0; i--)
            cout << " ";
        cout << "°°";
    } else {
        for (; i > 0; i--)
            cout << "°";
    }

    cout << endl;
}

//---------------------------------------------------------------------------
// FUNCION   : const char* getColorCodeByColorName(const char* colorName)
// ACCION    : Devuelve el codigo de color en base al nombre.
// PARAMETROS: - const char* colorName: Nombre del color.
// DEVUELVE  : Codigo del color.
//---------------------------------------------------------------------------
const char* getColorCodeByColorName(const char* colorName)
{
    if (! (bool) strcmp("black", colorName))    return "\033[1;30m";
    if (! (bool) strcmp("red", colorName))      return "\033[1;31m";
    if (! (bool) strcmp("green", colorName))    return "\033[1;32m";
    if (! (bool) strcmp("yellow", colorName))   return "\033[1;33m";
    if (! (bool) strcmp("blue", colorName))     return "\033[1;34m";
    if (! (bool) strcmp("magenta", colorName))  return "\033[1;35m";
    if (! (bool) strcmp("cyan", colorName))     return "\033[1;36m";

    return "\033[1;37m";
}

//---------------------------------------------------------------------------
// FUNCION   : void buildMenu(const char* header, bool isTitle, int sizeOfTitle, const char* colorName = "white", int length = 70)
// ACCION    : Construye las opcines y los titulos de la cabecera.
// PARAMETROS: - const char* header: Texto que se quiere ingresar.
//             - bool isTitle: Determina si es titulo u opcion.
//             - int sizeOfTitle: Tamaño del titulo (Utilizado para las opciones).
//             - const char* colorName: Nombre del color.
//             - int length: Tamaño del encuadro.
// DEVUELVE  : Codigo del color.
//---------------------------------------------------------------------------
void buildMenu(const char* header, bool isTitle, int sizeOfTitle, const char* colorName = "white", int length = 70)
{
   int startWrite = (isTitle ? ((length/2) - 4) : ((length/2) - 2)) - (sizeOfTitle / 2), endWrite = startWrite + strlen(header), position = 0;

   cout << Text_Center << "°°";

   if (isTitle) cout << "°°";

   cout << getColorCodeByColorName(colorName);

   for (int i = 0; i < (isTitle ? (length - 8) : (length - 4)); i++) {
        if (i > startWrite && i <= endWrite) {
            cout << header[position];
            position++;
        } else {
            cout << " ";
        }
   }

   cout << "\033[0m°°";

   if (isTitle) cout << "°°";

   cout << endl;
}

//***************************************************************************
// DEFINICION DE LAS FUNCIONES
//===========================================================================
// FUNCION   : validateEntryTF()
// ACCION    : Valida el ingreso de opcion Si y No.
// PARAMETROS: void
// DEVUELVE  : nada
//---------------------------------------------------------------------------

void validateEntryTF()
{
    cin >> entry;

    while (entry[0] != 'N' && entry[0] != 'n' && entry[0] != 'S' && entry[0] != 's') {
        cout << Text_Center << "\033[1;31mIngrese una opcion valida: \033[0m";
        cin >> entry;
    }
}

#endif // CONFIG_H_INCLUDED
