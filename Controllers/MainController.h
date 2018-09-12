#ifndef MAINCONTROLLER_H_INCLUDED
#define MAINCONTROLLER_H_INCLUDED
#include <algorithm>
#include <iostream>
#include "../CSYSTEM/csystem.h"          // Libreria para multiplataforma.
#include "../config.h"                   // Configuraciones del sistema.
#include "../Rules/MainRules.h"          // Reglas del main.

using namespace std;

namespace Main
{
/***********************
* Prototipos del Main. *
***********************/
void index();
void menu();
#include "ConfigurationController.h"    // Controlador de configuracion de freelancers.
#include "FreelancerController.h"       // Controlador de freelancers.
#include "SchedulerController.h"        // Controlador de tiempo de trrabajo.

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

void menu()
{
    sys::cls();
    cout << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°                 M E N U   P R I N C I P A L                  °°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°                 1. Configuracion de precio/hora.                 °°" << endl;
    cout << Text_Center << "°°                 2. ABM de freelancers.                           °°" << endl;
    cout << Text_Center << "°°                 3. Carga de horas a los freelancers.             °°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
}

void retry()
{
    menu();
    showErrorFooter();
    index();
}

void dispatch()
{
    if (entry[0] == '1') {
        //loading(25, 50);
        Configuration::menu();
        Configuration::index();
    }
    if (entry[0] == '2')
        cout << "asdw";

    if (entry[0] == '3')
        cout << "asd1";
}

void index()
{
    setCurrentDate();

    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! MainRule::validEntry(maxOptionLength) || ! MainRule::validEntry(mainOptions))
    {
        retry();
    }

    dispatch();

    exit(0);
}
}

#endif // MAINCONTROLLER_H_INCLUDED
