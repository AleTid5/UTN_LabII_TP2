////#############################################################################
// ARCHIVO : MainController.h
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
// Controlador de las funciones principales del sistema.
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef MAINCONTROLLER_H_INCLUDED
#define MAINCONTROLLER_H_INCLUDED

#include <algorithm>
#include <iostream>
#include "../Rules/MainRules.h"          // Reglas del main.
#include "../Interfaces/MainInterface.h" // Interface de
#include "../Interfaces/ConfigurationInterface.h" // Interface de
#include "../Interfaces/FreelancerInterface.h" // Interface de
#include "../Interfaces/ReportsInterface.h" // Interface de
#include "../Interfaces/SchedulerInterface.h" // Interface de

using namespace std;

namespace Main
{

//***************************************************************************
// DEFINICION DE LAS FUNCIONES
//===========================================================================
// FUNCION   : void welcome()
// ACCION    : Muestra en pantalla mensaje de bienvenida.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void welcome()
{
    cout << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                    °°" << endl;
    cout << Text_Center << "°°         °°°°°° °°°° °°   °° °°°°°      °°°°°°°°°                   °°" << endl;
    cout << Text_Center << "°°           °°    °°  °°° °°° °°        °° \\ | / °°                  °°" << endl;
    cout << Text_Center << "°°           °°    °°  °° ° °° °°°°°     °° _ ° _ °°  Powered by      °°" << endl;
    cout << Text_Center << "°°           °°    °°  °°   °° °°        °°   °   °°  Magic Software  °°" << endl;
    cout << Text_Center << "°°           °°   °°°° °°   °° °°°°°     °° / | \\ °°  S. A.           °°" << endl;
    cout << Text_Center << "°°                                        °°°°°°°°°                   °°" << endl;
    cout << Text_Center << "°°                                                                    °°" << endl;
    cout << Text_Center << "°°     °°°°° °°°°° °°  °° °°°°° °°°°°  °°  °° °°     °°°°° °°°°°°     °°" << endl;
    cout << Text_Center << "°°     °°    °°    °°  °° °°    °° °°° °°  °° °°     °°    °°  °°     °°" << endl;
    cout << Text_Center << "°°     °°°°° °°    °°°°°° °°°°° °°  °° °°  °° °°     °°°°° °°°°°°     °°" << endl;
    cout << Text_Center << "°°        °° °°    °°  °° °°    °° °°° °°  °° °°     °°    °° °°      °°" << endl;
    cout << Text_Center << "°°     °°°°° °°°°° °°  °° °°°°° °°°°°  °°°°°° °°°°°° °°°°° °°  °°     °°" << endl;
    cout << Text_Center << "°°                                                                    °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;

    sys::msleep(2);

    loading();
}

//---------------------------------------------------------------------------
// FUNCION   : void goodbye()
// ACCION    : Muestra en pantalla mensaje de despedida.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void goodbye()
{
    sys::cls();

    cout << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                    °°" << endl;
    cout << Text_Center << "°°         °°°°°° °°°° °°   °° °°°°°      °°°°°°°°°                   °°" << endl;
    cout << Text_Center << "°°           °°    °°  °°° °°° °°        °° \\ | / °°                  °°" << endl;
    cout << Text_Center << "°°           °°    °°  °° ° °° °°°°°     °° _ ° _ °°  Powered by      °°" << endl;
    cout << Text_Center << "°°           °°    °°  °°   °° °°        °°   °   °°  Magic Software  °°" << endl;
    cout << Text_Center << "°°           °°   °°°° °°   °° °°°°°     °° / | \\ °°  S. A.           °°" << endl;
    cout << Text_Center << "°°                                        °°°°°°°°°                   °°" << endl;
    cout << Text_Center << "°°                                                                    °°" << endl;
    cout << Text_Center << "°°     °°°°° °°°°° °°  °° °°°°° °°°°°  °°  °° °°     °°°°° °°°°°°     °°" << endl;
    cout << Text_Center << "°°     °°    °°    °°  °° °°    °° °°° °°  °° °°     °°    °°  °°     °°" << endl;
    cout << Text_Center << "°°     °°°°° °°    °°°°°° °°°°° °°  °° °°  °° °°     °°°°° °°°°°°     °°" << endl;
    cout << Text_Center << "°°        °° °°    °°  °° °°    °° °°° °°  °° °°     °°    °° °°      °°" << endl;
    cout << Text_Center << "°°     °°°°° °°°°° °°  °° °°°°° °°°°°  °°°°°° °°°°°° °°°°° °°  °°     °°" << endl;
    cout << Text_Center << "°°                                                                    °°" << endl;
    cout << Text_Center << "°°     G R A C I A S  P O R  U T I L I Z A R  E L  S I S T E M A !    °°" << endl;
    cout << Text_Center << "°°                                                                    °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;

    sys::msleep(2);
}

//---------------------------------------------------------------------------
// FUNCION   : void menu()
// ACCION    : Muestra en pantalla el menu principal.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void menu()
{
    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);
    const char* title = "M E N U   P R I N C I P A L";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle);
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. AML de Categorias.", false, sizeOfTitle, "green");
    buildMenu("2. AML de Freelancers.", false, sizeOfTitle, "blue");
    buildMenu("3. Cargar horas trabajadas.", false, sizeOfTitle, "magenta");
    buildMenu("4. Reportes.", false, sizeOfTitle, "yellow");
    buildMenu("5. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("6. Salir.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

//---------------------------------------------------------------------------
// FUNCION   : void retry()
// ACCION    : Si la entrada es incorrecta, vuelve a intentar.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void retry()
{
    menu();
    showErrorFooter();
    index();
}

//---------------------------------------------------------------------------
// FUNCION   : void showHelp()
// ACCION    : Muestra una pantalla de ayuda.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showHelp() {
    sys::cls();
    int length = 85;
    divider(length);
    divider(length, true);
    buildMenu("~ A Y U D A  D E L  M E N U  P R I N C I P A L ~", false, length / 2, "cyan", length);
    divider(length, true);
    divider(length);
    divider(length, true);
    buildMenu("Este es el Menu Principal del sistema:", false, length - 5, "cyan", length);
    divider(length, true);
    buildMenu("- Dentro del AML (Alta, Modificacion, Lista) de categorias podra crear, editar", false, length - 5, "cyan", length);
    buildMenu("  o ver categorias de freelancers.", false, length - 5, "cyan", length);
    divider(length, true);
    buildMenu("- Dentro del AML de freelancers podra crear, editar o ver freelancers. La", false, length - 5, "cyan", length);
    buildMenu("  busqueda de freelancer la puede realizar mediante el nombre y apellido o ", false, length - 5, "cyan", length);
    buildMenu("  simplemente puede ver TODOS los freelancers que se encuentren dados de alta. ", false, length - 5, "cyan", length);
    divider(length, true);
    buildMenu("- Dentro del modulo de carga de horas podra cargar las horas a un freelancer en", false, length - 5, "cyan", length);
    buildMenu("  particular o a todos juntos. Si la carga de horas se corta, el programa", false, length - 5, "cyan", length);
    buildMenu("  guarda hasta donde se haya cargado. La carga particular se realiza a traves", false, length - 5, "cyan", length);
    buildMenu("  del DNI del freelancer.", false, length - 5, "cyan", length);
    divider(length, true);
    buildMenu("- Dentro del modulo de reportes podra visualizar el total de sueldo a pagar el", false, length - 5, "cyan", length);
    buildMenu("  corriente mes, que empleados facturaron y cuanto les corresponde cobrar y la", false, length - 5, "cyan", length);
    buildMenu("  tabla de categorias de freelancer.", false, length - 5, "cyan", length);
    divider(length, true);
    divider(length);
    cout << Text_Center << "Presione Enter para volver...";
    sys::getch();
}

//---------------------------------------------------------------------------
// FUNCION   : void dispatch()
// ACCION    : Despacha la opcion ingresada por el usuario.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void dispatch()
{
    if (entry[0] == '1') {
        //loading(25, 50);
        Configuration::menu();
        Configuration::index();
    }

    if (entry[0] == '2') {
        //loading(25, 50);
        Freelancer::menu();
        Freelancer::index();
    }

    if (entry[0] == '3') {
        //loading(25, 50);
        Scheduler::menu();
        Scheduler::index();
    }

    if (entry[0] == '4') {
        Reports::menu();
        Reports::index();
    }

    if (entry[0] == '5') {
        showHelp();
        menu();
        index();
    }

    if (entry[0] == '6') {
        goodbye();
        return;
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void index()
// ACCION    : Obtiene y valida la opcion que desea ingresar.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void index()
{
    setCurrentDate();

    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(sixOptions))
    {
        retry();
    }

    dispatch();

    exit(0);
}
}

#endif // MAINCONTROLLER_H_INCLUDED
