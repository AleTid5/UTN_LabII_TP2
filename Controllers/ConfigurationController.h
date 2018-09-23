#ifndef CONFIGURATIONCONTROLLER_H_INCLUDED
#define CONFIGURATIONCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h"

namespace Configuration
{

struct configuration
{
    unsigned int id;
    char25 type;
    unsigned int amount;
    char12 registrationDate;
    char12 modificationDate = "Sin cambios";
} _configuration;

int paginatorFrom = 0, paginatorTo = maxPagination;

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
    const char* title = "C O N F I G U R A C I O N  D E  C A T E G O R I A S";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "green");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Agregar categoria de Freelancer.", false, sizeOfTitle, "green");
    buildMenu("2. Modificar categoria de Freelancer.", false, sizeOfTitle, "green");
    buildMenu("3. Ver tabla de categorias de Freelancers.", false, sizeOfTitle, "green");
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
    const char* title = "M O D I F I C A R  C A T E G O R I A";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "green");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Modificar categoria por ID.", false, sizeOfTitle, "green");
    buildMenu("2. Modificar categoria por tipo.", false, sizeOfTitle, "green");
    buildMenu("3. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

void backToMain()
{
    Main::menu();
    Main::index();
}

int getMaxPages()
{
    file = fopen ("Bin/configuration.b","rb");
    fseek(file, 0, 2);
    unsigned int sizeOfRegisters = ftell(file) / sizeof(_configuration);
    fclose(file);

    return (! (bool)(sizeOfRegisters % maxPagination) ? (sizeOfRegisters / maxPagination) : ((sizeOfRegisters / maxPagination) + 1));
}

void showTable()
{
    sys::cls();

    file = fopen ("Bin/configuration.b","rb");

    cout << endl << endl;
    divider(87);

    if (file == NULL) {
        fclose(file);
        cout << Text_Center << "° " << setw(55) << right << "No hay datos cargados aun " << setw(30) << right << "°" << endl;
        divider(87);

        sys::getch();

        menu();
        index();
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
        fread(&_configuration, sizeof(_configuration), 1, file);
        for (int i = 0;! feof(file); i++) {
            if (i >= paginatorFrom && i < paginatorTo) {
                cout << Text_Center
                    << "° "   << setw(10) << left << _configuration.id
                    << " ° "  << setw(25) << left << _configuration.type
                    << " ° $" << setw(13) << left << _configuration.amount
                    << " ° "  << setw(10) << left << _configuration.registrationDate
                    << " ° "  << setw(12) << left << _configuration.modificationDate
                    << " °"   << endl;
            }

            fread(&_configuration, sizeof(_configuration), 1, file);
        }
    }

    fclose(file);

    unsigned int pages = getMaxPages();
    divider(87);
    divider(87, true);

    cout << Text_Center <<  "°° Pagina ";

    for (unsigned int i = 0; i < pages; i++) {
        if ((paginatorFrom + maxPagination) / maxPagination == i + 1) cout << "\033[1;32m";
        cout << "| " << i + 1 << " ";
        if ((paginatorFrom + maxPagination) / maxPagination == i + 1) cout << "\033[0m";
    }

    cout << setw(77 - (pages * 4) - (pages >= 10 ? pages - 9 : 0)) << right << "°°" << endl;

    divider(87, true);
    divider(87);

    cout << Text_Center << "Seleccione la pagina que desea ver o ingrese 0 para volver: ";
    unsigned int page;

    cin >> page;

    while (! cin.good() || page > pages) {
        cin.clear();
        cin.ignore(9, '\n');
        cout << Text_Center << "\033[1;31mIngrese una pagina valida: \033[0m";
        cin >> page;
    }

    if (page != 0) {
        paginatorFrom = (page * maxPagination) - maxPagination;
        paginatorTo = paginatorFrom + maxPagination;
        showTable();
    } else {
        menu();
        index();
    }
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

void setFreelancerType(char25 &type, unsigned int minLength = 3)
{
    cin.ignore();
    cin.getline(type, 25);

    while (! cin.good() || strlen(type) > 25 || strlen(type) < minLength) {
        cin.clear();
        cout << Text_Center << "\033[1;31mIngrese un tipo valido (" << minLength + 1 << " - 25 caracteres): \033[0m";
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cin.getline(type, 25);
    }
}

void setFreelancerAmount(unsigned int &amount, bool money = true)
{
    cin >> amount;

    while (! cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << Text_Center << "\033[1;31mIngrese un " << (money ? "monto" : "ID") << " valido: \033[0m";
        cin >> amount;
    }

    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void addData()
{
    _configuration.id = 1;

    file = fopen ("Bin/configuration.b","rb");

    if (file != NULL) {
        positionate(_configuration, 1);
        fread(&_configuration, sizeof(_configuration), 1, file);
        _configuration.id++;
    }

    fclose(file);

    cout << Text_Center << "Ingrese el tipo de freelancer: ";
    setFreelancerType(_configuration.type);

    cout << Text_Center << "Ingrese el monto que va a ganar por hora: ";
    setFreelancerAmount(_configuration.amount);

    strcpy(_configuration.registrationDate, currentDate);

    file = fopen ("Bin/configuration.b","ab+");
    fwrite(&_configuration, sizeof(_configuration), 1, file);
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

void modifyDataByPosition(unsigned int times)
{
    modifyDataMenu();
    cout << Text_Center << "Se ha encontrado el siguiente registro:" << endl;
    cout << Text_Center << "ID: " << _configuration.id << endl;
    cout << Text_Center << "Tipo de Freelancer: " << _configuration.type << endl;
    cout << Text_Center << "Monto que percibe: $" << _configuration.amount << endl;
    cout << Text_Center << "Fecha de creacion: " << _configuration.registrationDate << endl;
    cout << Text_Center << "Desea modificarlo? (S/N) ";
    cin >> entry;
    cin.ignore(0, '\n');

    if (entry[0] == 'S' || entry[0] == 's') {
        cout << Text_Center << "Desea modificar el tipo de freelancer? (S/N) ";
        cin >> entry;
        cin.ignore(0, '\n');

        if (entry[0] == 'S' || entry[0] == 's') {
            strcpy(_configuration.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el tipo de freelancer: ";
            setFreelancerType(_configuration.type);
        }

        cout << Text_Center << "Desea modificar el monto que va a ganar? (S/N) ";
        cin >> entry;
        cin.ignore(0, '\n');

        if (entry[0] == 'S' || entry[0] == 's') {
            strcpy(_configuration.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el monto que va a ganar por hora: ";
            setFreelancerAmount(_configuration.amount);
        }

        file = fopen ("Bin/configuration.b","rb+");
        positionate(_configuration, 2, times - 1);
        fwrite(&_configuration, sizeof(_configuration), 1, file);
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
        menu();
        index();
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
        setFreelancerAmount(id, false);

        fseek (file, 0, 0);
        bool freelancerFounded = false;
        for (unsigned int i = 1;! feof(file) && ! freelancerFounded; i++) {
            fread(&_configuration, sizeof(_configuration), 1, file);
            if (_configuration.id == id) {
                fclose(file);
                modifyDataByPosition(i);
                freelancerFounded = 1;
            }
        }

        if (! freelancerFounded) {
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
        setFreelancerType(type, 0);

        fseek (file, 0, 0);
        bool freelancerFounded = false;
        for (unsigned int i = 1; ! feof(file) && ! freelancerFounded; i++) {
            fread(&_configuration, sizeof(_configuration), 1, file);
            if (strFind(_configuration.type, type)) {
                fclose(file);
                modifyDataByPosition(i);
                freelancerFounded = true;
            }
        }

        if (! freelancerFounded) {
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
        showTable();

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

#endif // CONFIGURATIONCONTROLLER_H_INCLUDED
