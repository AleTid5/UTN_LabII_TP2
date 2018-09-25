#ifndef FREELANCERCONTROLLER_H_INCLUDED
#define FREELANCERCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h"

namespace Freelancer
{

struct freelancer
{
    unsigned int dni;
    char25 name;
    char25 lastname;
    char25 type;
    unsigned int workedTime = 0;
    char12 registrationDate;
    char12 modificationDate = "Sin cambios";
} _freelancer;

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
    const char* title = "C O N F I G U R A C I O N  D E  F R E E L A N C E R";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "blue");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Agregar freelancer.", false, sizeOfTitle, "blue");
    buildMenu("2. Modificar freelancer.", false, sizeOfTitle, "blue");
    buildMenu("3. Ver tabla de freelancers.", false, sizeOfTitle, "blue");
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
    buildMenu("1. Modificar Freelancer por DNI.", false, sizeOfTitle, "blue");
    buildMenu("2. Modificar Freelancer por Nombre.", false, sizeOfTitle, "blue");
    buildMenu("3. Modificar Freelancer por Apellido.", false, sizeOfTitle, "blue");
    buildMenu("4. Volver.", false, sizeOfTitle, "red");
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
    file = fopen ("Bin/freelancer.b","rb");
    fseek(file, 0, 2);
    unsigned int sizeOfRegisters = ftell(file) / sizeof(_freelancer);
    fclose(file);

    return (! (bool)(sizeOfRegisters % maxPagination) ? (sizeOfRegisters / maxPagination) : ((sizeOfRegisters / maxPagination) + 1));
}

void showTable()
{
    sys::cls();

    file = fopen ("Bin/freelancer.b","rb");

    cout << endl << endl;
    divider(145);

    if (file == NULL) {
        fclose(file);
        cout << Text_Center << "° " << setw(85) << right << "No hay datos cargados aun " << setw(58) << right << "°" << endl;
        divider(145);

        sys::getch();

        menu();
        index();
    } else {
        cout << Text_Center
             << "° "  << setw(10) << left << "DNI"
             << " ° " << setw(25) << left << "Nombre"
             << " ° " << setw(25) << left << "Apellido"
             << " ° " << setw(16) << left << "Horas trabajadas"
             << " ° " << setw(25) << left << "Tipo"
             << " ° " << setw(10) << left << "FECHA ALTA"
             << " ° " << setw(12) << left << "MODIFICACION"
             << " °"  << endl;
        divider(145);

        fseek (file, 0, 0);
        fread(&_freelancer, sizeof(_freelancer), 1, file);
        for (int i = 0;! feof(file); i++) {
            if (i >= paginatorFrom && i < paginatorTo) {
                cout << Text_Center
                    << "° "   << setw(10) << left << _freelancer.dni
                    << " ° "  << setw(25) << left << _freelancer.name
                    << " ° "  << setw(25) << left << _freelancer.lastname
                    << " ° "  << setw(16) << left << _freelancer.workedTime
                    << " ° "  << setw(25) << left << _freelancer.type
                    << " ° "  << setw(10) << left << _freelancer.registrationDate
                    << " ° "  << setw(12) << left << _freelancer.modificationDate
                    << " °"   << endl;
            }

            fread(&_freelancer, sizeof(_freelancer), 1, file);
        }
    }

    fclose(file);

    unsigned int pages = getMaxPages();
    divider(145);
    divider(145, true);

    cout << Text_Center <<  "°° Pagina ";

    for (unsigned int i = 0; i < pages; i++) {
        if ((paginatorFrom + maxPagination) / maxPagination == i + 1) cout << "\033[1;32m";
        cout << "| " << i + 1 << " ";
        if ((paginatorFrom + maxPagination) / maxPagination == i + 1) cout << "\033[0m";
    }

    cout << setw(135 - (pages * 4) - (pages >= 10 ? pages - 9 : 0)) << right << "°°" << endl;

    divider(145, true);
    divider(145);

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

void setFreelancerName(char25 &nameReal, unsigned int minLength = 3)
{
    char name[1000];
    cin.getline(name, 1000);

    while (! cin.good() || strlen(name) > 25 || strlen(name) < minLength) {
        cin.clear();
        cout << Text_Center << "\033[1;31mIngrese un nombre/apellido valido (" << minLength + 1 << " - 25 caracteres): \033[0m";
        //cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cin.getline(name, 1000);
    }

    strcpy(nameReal, name);
}

bool typeExists(char type[1000])
{
    FILE* configFile = fopen ("Bin/configuration.b","rb");
    Configuration::configuration _configAux;

    bool typeFounded = false;

    if (configFile == NULL) {
        fclose(configFile);
        return typeFounded;
    }

    fseek (configFile, 0, 0);
    for (; ! feof(configFile) && ! typeFounded;) {
        fread(&_configAux, sizeof(_configAux), 1, configFile);
        if (! (bool) strcmp(_configAux.type,type))
            typeFounded = ! typeFounded;
    }

    fclose(configFile);

    return typeFounded;
}

void setFreelancerType(char25 &typeReal, unsigned int minLength = 3)
{
    char type[1000];
    cin.getline(type, 1000);

    while (! typeExists(type)) {
        cin.clear();
        cout << Text_Center << "\033[1;31mIngrese un tipo valido (" << minLength + 1 << " - 25 caracteres): \033[0m";
        cin.getline(type, 1000);
    }

    strcpy(typeReal, type);
}

bool freelancerExists()
{
    file = fopen ("Bin/freelancer.b","rb");
    freelancer _fAux;

    bool freelancerFounded = false;

    if (file == NULL) {
        fclose(file);
        return freelancerFounded;
    }

    fseek (file, 0, 0);
    for (; ! feof(file) && ! freelancerFounded;) {
        fread(&_fAux, sizeof(_fAux), 1, file);
        if (_fAux.dni == _freelancer.dni)
            freelancerFounded = ! freelancerFounded;
    }

    fclose(file);

    return freelancerFounded;
}

void setFreelancerDNI(unsigned int &dni)
{
    cin >> dni;

    while (! cin.good() || freelancerExists()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << Text_Center << "\033[1;31mEl DNI ingresado no es valido o ya existe. Ingreselo nuevamente: \033[0m";
        cin >> dni;
    }

    //cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void validateDNI(unsigned int &dni)
{
    cin >> dni;

    while (! cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << Text_Center << "\033[1;31mIngrese un DNI valido: \033[0m";
        cin >> dni;
    }

    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void addData()
{
    cout << Text_Center << "Ingrese el DNI del freelancer: ";
    setFreelancerDNI(_freelancer.dni);

    cout << Text_Center << "Ingrese el nombre del freelancer: ";
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    setFreelancerName(_freelancer.name);

    cout << Text_Center << "Ingrese el apellido del freelancer: ";
    setFreelancerName(_freelancer.lastname);

    cout << Text_Center << "Ingrese el tipo de freelancer: ";
    setFreelancerType(_freelancer.type);

    strcpy(_freelancer.registrationDate, currentDate);

    file = fopen ("Bin/freelancer.b","ab+");
    fwrite(&_freelancer, sizeof(_freelancer), 1, file);
    fclose (file);

    cout << Text_Center << "Desea cargar otro freelancer? (S/N) ";
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
    cout << Text_Center << "Se ha encontrado el siguiente freelancer:" << endl;
    cout << Text_Center << "ID: " << _freelancer.dni << endl;
    cout << Text_Center << "Nombre del Freelancer: " << _freelancer.name << endl;
    cout << Text_Center << "Apellido del Freelancer: " << _freelancer.lastname << endl;
    cout << Text_Center << "Tipo de Freelancer: " << _freelancer.type << endl;
    cout << Text_Center << "Fecha de creacion: " << _freelancer.registrationDate << endl;
    cout << Text_Center << "Desea modificarlo? (S/N) ";
    cin >> entry;
    cin.ignore(0, '\n');

    if (entry[0] == 'S' || entry[0] == 's') {
        cout << Text_Center << "Desea modificar el nombre del freelancer? (S/N) ";
        cin >> entry;

        if (entry[0] == 'S' || entry[0] == 's') {
            cin.ignore();
            strcpy(_freelancer.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el nombre del freelancer: ";
            setFreelancerName(_freelancer.name);
        }

        cout << Text_Center << "Desea modificar el apellido del freelancer? (S/N) ";
        cin >> entry;
        cin.ignore(0, '\n');

        if (entry[0] == 'S' || entry[0] == 's') {
            cin.ignore();
            strcpy(_freelancer.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el apellido del freelancer: ";
            setFreelancerName(_freelancer.lastname);
        }

        cout << Text_Center << "Desea modificar el tipo de freelancer? (S/N) ";
        cin >> entry;
        cin.ignore(0, '\n');

        if (entry[0] == 'S' || entry[0] == 's') {
            cin.ignore();
            strcpy(_freelancer.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el tipo de freelancer: ";
            setFreelancerType(_freelancer.type);
        }

        file = fopen ("Bin/freelancer.b","rb+");
        positionate(_freelancer, 2, times - 1);
        fwrite(&_freelancer, sizeof(_freelancer), 1, file);
        fclose (file);

        cout << Text_Center << "\033[1;32mUsuario modificado exitosamente!\033[0m";
        sys::getch();
    }
}

void modifyData()
{
    file = fopen ("Bin/freelancer.b","rb");

    if (file == NULL) {
        fclose(file);
        cout << Text_Center << "\033[1;31mNo hay datos cargados aun.\033[0m";
        sys::getch();
        menu();
        index();
    }

    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(fourOptions)) {
        fclose(file);
        retryModify();
    }

    if (entry[0] == '1') {
        unsigned int dni;

        cout << Text_Center << "Ingrese el DNI del Freelancer: ";
        validateDNI(dni);

        fseek (file, 0, 0);
        bool freelancerFounded = false;
        for (unsigned int i = 1;! feof(file) && ! freelancerFounded; i++) {
            fread(&_freelancer, sizeof(_freelancer), 1, file);
            if (_freelancer.dni == dni) {
                fclose(file);
                modifyDataByPosition(i);
                freelancerFounded = true;
            }
        }

        if (! freelancerFounded) {
            cout << Text_Center << "\033[1;31mNo se ha encontrado el DNI ingresado.\033[0m";
            sys::getch();
        }

        fclose(file);
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '2') {
        char25 name;

        cout << Text_Center << "Ingrese el Nombre del Freelancer: ";
        cin.ignore();
        setFreelancerName(name, 0);

        fseek (file, 0, 0);
        bool freelancerFounded = false;
        for (unsigned int i = 1; ! feof(file) && ! freelancerFounded; i++) {
            fread(&_freelancer, sizeof(_freelancer), 1, file);
            if (strFind(_freelancer.name, name)) {
                fclose(file);
                modifyDataByPosition(i);
                freelancerFounded = true;
            }
        }

        if (! freelancerFounded) {
            cout << Text_Center << "\033[1;31mNo se ha encontrado el nombre ingresado.\033[0m";
            sys::getch();
        }

        fclose(file);
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '3') {
        cin.ignore();
        char25 lastname;

        cout << Text_Center << "Ingrese el Apellido del Freelancer: ";
        setFreelancerName(lastname, 0);

        fseek (file, 0, 0);
        bool freelancerFounded = false;
        for (unsigned int i = 1; ! feof(file) && ! freelancerFounded; i++) {
            fread(&_freelancer, sizeof(_freelancer), 1, file);
            if (strFind(_freelancer.lastname, lastname)) {
                fclose(file);
                modifyDataByPosition(i);
                freelancerFounded = true;
            }
        }

        if (! freelancerFounded) {
            cout << Text_Center << "\033[1;31mNo se ha encontrado el Apellido ingresado.\033[0m";
            sys::getch();
        }

        fclose(file);
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '4') {
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

#endif // FREELANCERCONTROLLER_H_INCLUDED
