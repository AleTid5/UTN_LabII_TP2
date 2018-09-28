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

void retry()
{
    menu();
    showErrorFooter();
    index();
}

void showHelp() {
    sys::cls();
    int length = 85;
    divider(length);
    divider(length, true);
    buildMenu("A Y U D A  D E L  M E N U", false, length / 4, "cyan", length);
    divider(length, true);
    divider(length);
    divider(length, true);
    buildMenu("1. Cree, edite o vea la lista de categorias de freelancers.", false, length, "cyan", length);
    buildMenu("2. Cree, edite o vea la lista de freelancers.", false, length, "cyan", length);
    buildMenu("3. Cargue las horas trabajdas de los freelancers (De forma masiva o individual).", false, length, "cyan", length);
    buildMenu("4. Vea las estadisticas de trabajo en el mes.", false, length, "cyan", length);
    divider(length, true);
    divider(length);
    cout << Text_Center << "Presione Enter para volver...";
    sys::getch();
}

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
