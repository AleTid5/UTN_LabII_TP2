#ifndef CONFIGURATIONCONTROLLER_H_INCLUDED
#define CONFIGURATIONCONTROLLER_H_INCLUDED
#include "../Rules/MainRules.h"

namespace Configuration
{

struct configuration
{
    unsigned int id;
    char25 type;
    int amount;
    char12 registrationDate;
    char12 modificationDate;
} config;

/****************************************
* Prototipos del Configurador de Cobro. *
****************************************/
void index();
void modifyData();

void menu()
{
    sys::cls();
    cout << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°           C O N F I G U R A C I O N  D E  C O B R O          °°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°             1. Agregar cobro de los Freelancers.                 °°" << endl;
    cout << Text_Center << "°°             2. Modificar cobro de los Freelancers.               °°" << endl;
    cout << Text_Center << "°°             3. Ver tabla de cobro de los Freelancers.            °°" << endl;
    cout << Text_Center << "°°             4. Volver.                                           °°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
}

void modifyDataMenu()
{
    sys::cls();
    cout << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°             M O D I F I C A R  F R E E L A N C E R           °°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°              1. Modificar por ID de Freelancer.                  °°" << endl;
    cout << Text_Center << "°°              2. Modificar tipo de Freelancer.                    °°" << endl;
    cout << Text_Center << "°°              3. Volver.                                          °°" << endl;
    cout << Text_Center << "°°                                                                  °°" << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
}

void backToMain()
{
    Main::menu();
    Main::index();
}

void showTable()
{
    sys::cls();

    file = fopen ("Bin/configuration.b","rb");

    cout << endl << endl;
    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;

    if (file == NULL) {
        cout << Text_Center << "°                                No hay datos cargados aun                              °" << endl;
    } else {
        cout << Text_Center << "°     ID     °           TIPO            ° MONTO POR HORA °  FECHA ALTA  ° MODIFICACION °"        << endl;
        cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;

        fseek (file, 0, 0);
        fread(&config, sizeof(config), 1, file);
        for (; ! feof(file);) {
            cout << Text_Center
                 << "° "   << setw(10) << left << config.id
                 << " ° "  << setw(25) << left << config.type
                 << " ° $" << setw(13) << left << config.amount
                 << " ° "  << setw(12) << left << config.registrationDate
                 << " ° "  << setw(12) << left << config.modificationDate
                 << " °"   << endl;
            fread(&config, sizeof(config), 1, file);
        }
    }

    cout << Text_Center << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
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

    file = fopen ("Bin/configuration.b","rb");

    if (file != NULL) {
        positionate(config, 1);
        fread(&config, sizeof(config), 1, file);
        id = config.id + 1;
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

    config.id = id;
    strcpy(config.type, type);
    config.amount = amount;
    strcpy(config.registrationDate, currentDate);
    strcpy(config.modificationDate, "Sin cambios");

    file = fopen ("Bin/configuration.b","ab+");
    fwrite(&config, sizeof(config), 1, file);
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
    cout << Text_Center << "ID: " << config.id << endl;
    cout << Text_Center << "Tipo de Freelancer: " << config.type << endl;
    cout << Text_Center << "Monto que percibe: " << config.amount << endl;
    cout << Text_Center << "Fecha de creacion: " << config.registrationDate << endl;
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

             strcpy(config.type, type);
             strcpy(config.modificationDate, currentDate);
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

            config.amount = amount;
            strcpy(config.modificationDate, currentDate);
        }

        file = fopen ("Bin/configuration.b","r+");
        positionate(config, 2, times - 1);
        fwrite(&config, sizeof(config), 1, file);
        fclose (file);
    }
}

void modifyData()
{
    file = fopen ("Bin/configuration.b","rb");

    if (file == NULL) {
        fclose(file);
        cout << Text_Center << "\033[1;31mNo hay datos cargados aun.\033[0m";
        sys::getch();
        backToMain();
    }

    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! MainRule::validEntry(maxOptionLength) || ! MainRule::validEntry(mainOptions)) {
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
            fread(&config, sizeof(config), 1, file);
            if (config.id == id) {
                fclose(file);
                changeDataWithCount(i);
                existsFreelancer = true;
            }
        }

        if (! existsFreelancer) {
            cout << Text_Center << "\033[1;31mNo se ha encontrado el ID seleccionado.\033[0m";
            sys::getch();
        }

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
            fread(&config, sizeof(config), 1, file);
            if (strFind(config.type, type) >= 0) {
                fclose(file);
                changeDataWithCount(i);
                existsFreelancer = true;
            }
        }

        if (! existsFreelancer) {
            cout << Text_Center << "\033[1;31mNo se ha encontrado el Tipo seleccionado.\033[0m";
            sys::getch();
        }

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
        showTable();

    if (entry[0] == '4')
        backToMain();
}

void index()
{
    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! MainRule::validEntry(maxOptionLength) || ! MainRule::validEntry(configOptions)) {
        retry();
    }

    dispatch();
}
}

#endif // CONFIGURATIONCONTROLLER_H_INCLUDED
