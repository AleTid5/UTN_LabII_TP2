#ifndef MAINCONTROLLER_H_INCLUDED
#define MAINCONTROLLER_H_INCLUDED
#include <iostream>
#include "../CSYSTEM/csystem.h"    // Libreria para multiplataforma.
#include "../config.h"          // Configuraciones del sistema.

using namespace std;

namespace Main
{
    void loading(int percentage = 0)
    {
        if (percentage <= 100) {
            sys::cls();
            cout << endl << Text_Center << "\033[1;32m";
            for (int i = 0; i < percentage / 2; i++) {
                cout << "°";
            }
            cout << endl << Text_Center << "Iniciando el sistema.. " << percentage << "%";
            sys::msleep(1);
            loading(percentage + 20);
        }
    }

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
        cout << endl;
        cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << Text_Center << "°°                                                                    °°" << endl;
        cout << Text_Center << "°°                                                                    °°" << endl;
        cout << Text_Center << "°°                                                                    °°" << endl;
        cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    }

    void dispatch()
    {

    }
}

#endif // MAINCONTROLLER_H_INCLUDED
