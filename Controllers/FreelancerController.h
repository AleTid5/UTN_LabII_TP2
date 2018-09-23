#ifndef FREELANCERCONTROLLER_H_INCLUDED
#define FREELANCERCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h"
#include "ConfigurationController.h"

namespace Freelancer
{
struct freelancer
{
    unsigned int dni;
    char25 name;
    char25 lastname;
    char25 type;
    char12 registrationDate;
    char12 modificationDate;
} _freelancer;

/****************************************
* Prototipos del Configurador de Cobro. *
****************************************/
void index();
void modifyData();

void menu()
{
    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);
    const char* title = "C O N F I G U R A C I O N  D E  F R E E L A N C E R";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "blue");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Agregar freelancer.", false, sizeOfTitle, "blue");
    buildMenu("2. Modificar freelancer.", false, sizeOfTitle, "blue");
    buildMenu("3. Buscar freelancers.", false, sizeOfTitle, "blue");
    buildMenu("4. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

void modifyDataMenu()
{
    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);
    const char* title = "M O D I F I C A R  F R E E L A N C E R";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "blue");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Buscar freelancer por DNI.", false, sizeOfTitle, "blue");
    buildMenu("2. Buscar freelancer por Nombre.", false, sizeOfTitle, "blue");
    buildMenu("3. Buscar freelancer por Apellido.", false, sizeOfTitle, "blue");
    buildMenu("4. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

void backToMain()
{
    Main::menu();
    Main::index();
}

void findFreelancer()
{
    sys::cls();

    file = fopen ("Bin/freelancer.b","rb");

    cout << endl << endl;
    divider(87);

    if (file == NULL) {
        cout << Text_Center << "° " << setw(55) << right << "No hay datos cargados aun " << setw(30) << right << "°" << endl;
    } else {
        cout << Text_Center
                 << "° "  << setw(10) << left << "ID"
                 << " ° " << setw(25) << left << "TIPO"
                 << " ° " << setw(13) << left << "VALOR POR HORA"
                 << " ° " << setw(10) << left << "FECHA ALTA"
                 << " ° " << setw(12) << left << "MODIFICACION"
                 << " °"  << endl;
        divider(87);

        fseek (file, 0, 0);
        fread(&_freelancer, sizeof(_freelancer), 1, file);
        for (; ! feof(file);) {
            cout << Text_Center
                 << "° "   << setw(10) << left << _freelancer.dni
                 << " ° "  << setw(25) << left << _freelancer.type
                 << " ° "  << setw(10) << left << _freelancer.registrationDate
                 << " ° "  << setw(12) << left << _freelancer.modificationDate
                 << " °"   << endl;
            fread(&_freelancer, sizeof(_freelancer), 1, file);
        }
    }

    divider(87);
    cout << endl;
    cout << Text_Center << "Presione Enter para volver..";

    fclose(file);
    sys::getch();
    menu();
    index();
}

void retry()
{
    menu();
    showErrorFooter();
    index();
}

void retryModify()
{
    modifyDataMenu();
    showErrorFooter();
    modifyData();
}

void addData()
{
    unsigned int id = 1;

    file = fopen ("Bin/freelancer.b","rb");

    if (file != NULL) {
        positionate(_freelancer, 1);
        fread(&_freelancer, sizeof(_freelancer), 1, file);
        id = _freelancer.dni + 1;
    }

    fclose(file);

    char25 type;
    int amount;
    cin.ignore();
    cout << Text_Center << "Ingrese el tipo de freelancer: ";
    cin >> type;

    while (! cin.good()) {
        cin.clear();
        cin.ignore(9, '\n');
        cout << Text_Center << "\033[1;31mIngrese un tipo valido (Maximo 25 caracteres): \033[0m";
        cin >> type;
    }

    cout << Text_Center << "Ingrese el monto que va a ganar por hora: ";
    cin >> amount;
    cin.ignore();

    while (! cin.good()) {
        cin.clear();
        cin.ignore(9, '\n');
        cout << Text_Center << "\033[1;31mIngrese un monto valido: \033[0m";
        cin >> amount;
    }

    _freelancer.dni = id;
    strcpy(_freelancer.type, type);
    strcpy(_freelancer.registrationDate, currentDate);
    strcpy(_freelancer.modificationDate, "Sin cambios");

    file = fopen ("Bin/freelancer.b","ab+");
    fwrite(&_freelancer, sizeof(_freelancer), 1, file);
    fclose (file);

    cout << Text_Center << "Desea cargar otro registro? (S/N) ";
    cin >> entry;

    if (entry[0] == 'S' || entry[0] == 's') {
        menu();
        addData();
    }

    menu();
    index();
}

void changeDataWithCount(unsigned int times)
{
    modifyDataMenu();
    cout << Text_Center << "Se ha encontrado el siguiente registro:" << endl;
    cout << Text_Center << "ID: " << _freelancer.dni << endl;
    cout << Text_Center << "Tipo de Freelancer: " << _freelancer.type << endl;
    cout << Text_Center << "Fecha de creacion: " << _freelancer.registrationDate << endl;
    cout << Text_Center << "Desea modificarlo? (S/N) ";
    cin >> entry;
    cin.ignore();

    if (entry[0] == 'S' || entry[0] == 's') {

        cout << Text_Center << "Desea modificar el tipo de freelancer? (S/N) ";
        cin >> entry;
        cin.ignore();

        if (entry[0] == 'S' || entry[0] == 's') {
            char25 type;
            cout << Text_Center << "Ingrese el tipo de freelancer: ";
            cin >> type;

            while (! cin.good()) {
                cin.clear();
                cin.ignore(9, '\n');
                cout << Text_Center << "\033[1;31mIngrese un tipo valido (Maximo 25 caracteres): \033[0m";
                cin >> type;
            }

             strcpy(_freelancer.type, type);
             strcpy(_freelancer.modificationDate, currentDate);
        }

        cout << Text_Center << "Desea modificar el monto que va a ganar? (S/N) ";
        cin >> entry;
        cin.ignore();

        if (entry[0] == 'S' || entry[0] == 's') {
            int amount;
            cout << Text_Center << "Ingrese el monto que va a ganar por hora: ";
            cin >> amount;
            cin.ignore();

            while (! cin.good()) {
                cin.clear();
                cin.ignore(9, '\n');
                cout << Text_Center << "\033[1;31mIngrese un monto valido: \033[0m";
                cin >> amount;
            }

            strcpy(_freelancer.modificationDate, currentDate);
        }

        file = fopen ("Bin/freelancer.b","r+");
        positionate(_freelancer, 2, times - 1);
        fwrite(&_freelancer, sizeof(_freelancer), 1, file);
        fclose (file);
    }
}

void modifyData()
{
    file = fopen ("Bin/freelancer.b","rb");

    if (file == NULL) {
        fclose(file);
        cout << Text_Center << "\033[1;31mNo hay datos cargados aun.\033[0m";
        sys::getch();
        backToMain();
    }

    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(threeOptions)) {
        fclose(file);
        retryModify();
    }

    if (entry[0] == '1') {
        unsigned int id;

        cout << Text_Center << "Ingrese el ID del Freelancer: ";
        cin >> id;
        cin.ignore();

        while (! cin.good()) {
            cin.clear();
            cin.ignore(9, '\n');
            cout << Text_Center << "\033[1;31mIngrese un ID valido: \033[0m";
            cin >> id;
        }

        fseek (file, 0, 0);
        bool existsFreelancer = false;
        for (unsigned int i = 1; ! feof(file) && ! existsFreelancer; i++) {
            fread(&_freelancer, sizeof(_freelancer), 1, file);
            if (_freelancer.dni == id) {
                fclose(file);
                changeDataWithCount(i);
                existsFreelancer = true;
            }
        }

        if (! existsFreelancer) {
            cout << Text_Center << "\033[1;31mNo se ha encontrado el ID seleccionado.\033[0m";
            sys::getch();
        }

        fclose(file);
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '2') {
        char25 type;

        cout << Text_Center << "Ingrese el Tipo del Freelancer: ";
        cin >> type;
        cin.ignore();

        while (! cin.good()) {
            cin.clear();
            cin.ignore(9, '\n');
            cout << Text_Center << "\033[1;31mIngrese un Tipo valido: \033[0m";
            cin >> type;
        }

        fseek (file, 0, 0);
        bool existsFreelancer = false;
        for (unsigned int i = 1; ! feof(file) && ! existsFreelancer; i++) {
            fread(&_freelancer, sizeof(_freelancer), 1, file);
            if (strFind(_freelancer.type, type)) {
                fclose(file);
                changeDataWithCount(i);
                existsFreelancer = true;
            }
        }

        if (! existsFreelancer) {
            cout << Text_Center << "\033[1;31mNo se ha encontrado el Tipo seleccionado.\033[0m";
            sys::getch();
        }

        fclose(file);
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '3') {
        //loading(25, 50);
        menu();
        index();
    }

}

void dispatch()
{
    if (entry[0] == '1')
        addData();

    if (entry[0] == '2') {
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '3')
        findFreelancer();

    if (entry[0] == '4')
        backToMain();
}

void index()
{
    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(fourOptions)) {
        retry();
    }

    dispatch();
}
}

#endif // FREELANCERCONTROLLER_H_INCLUDED
