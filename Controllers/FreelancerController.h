////#############################################################################
// ARCHIVO : FreelancerController.h
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
// Controlador de las funciones de alta, modificaciones y lista de freelancers.
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef FREELANCERCONTROLLER_H_INCLUDED
#define FREELANCERCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h" // Reglas principales del sistema

namespace Freelancer
{

//***************************************************************************
// DEFINICION DE LAS ESTRUCTURAS
//===========================================================================
// ESTRUCTURA : struct freelancer
// ACCION     : Almacena la informacion de un freelancer.
// COMPONENTES:
//              - unsigned int dni: DNI del freelancer (unico).
//              - char25 name: Nombre del freelancer.
//              - char25 lastname: Apellido del freelancer.
//              - char25 type: Tipo de categoria al que pertenece.
//              - unsigned int workedTime: Horas trabajadas por el freelancer.
//              - char12 registrationDate: Fecha de creacion del freelancer.
//              - char12 registrationDate: Fecha de modificacion del freelancer.
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

//***************************************************************************
// DEFINICION DE LAS VARIABLES GLOBALES DE FREELANCER
//===========================================================================
int paginatorFrom = 0, paginatorTo = maxPagination; //Paginacion desde/hasta.

//***************************************************************************
// DEFINICION DE LAS FUNCIONES
//===========================================================================
// FUNCION   : void menu()
// ACCION    : Muestra en pantalla el menu principal de Freelancer.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
    buildMenu("4. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("5. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

//---------------------------------------------------------------------------
// FUNCION   : void modifyDataMenu()
// ACCION    : Muestra en pantalla el menu de modificacion de freelancer.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
    buildMenu("4. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("5. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

//---------------------------------------------------------------------------
// FUNCION   : void searchFreelancersMenu()
// ACCION    : Muestra en pantalla el menu de busqueda de freelancers.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void searchFreelancersMenu()
{
    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);
    const char* title = "B U S C A D O R  D E  F R E E L A N C E R S";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "blue");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Ver todos los freelancers.", false, sizeOfTitle, "blue");
    buildMenu("2. Buscar freelancer por nombre o apellido.", false, sizeOfTitle, "blue");
    buildMenu("3. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("4. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
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
    buildMenu("A Y U D A  D E  F R E E L A N C E R S", false, length / 2, "cyan", length);
    divider(length, true);
    divider(length);
    divider(length, true);
    buildMenu("Aqui puede crear, editar o ver la lista de freelancers.", false, length, "cyan", length);
    buildMenu("- La edicion la puede realizar DNI, nombre o apellido.", false, length, "cyan", length);
    buildMenu("- Si no conoce el DNI, puede buscarlo en la tabla.", false, length, "cyan", length);
    buildMenu("- La busqueda la puede realizar por nombre o apellido, o ver todos.", false, length, "cyan", length);
    divider(length, true);
    divider(length);
    cout << Text_Center << "Presione Enter para volver...";
    sys::getch();
}

//---------------------------------------------------------------------------
// FUNCION   : void showHelp()
// ACCION    : Muestra una pantalla de ayuda de modificacion.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showModifyHelp() {
    sys::cls();
    int length = 85;
    divider(length);
    divider(length, true);
    buildMenu("A Y U D A  D E  M O D I F I C A C I O N", false, length / 2, "cyan", length);
    divider(length, true);
    divider(length);
    divider(length, true);
    buildMenu("Aqui puede editar la lista de freelancers.", false, length, "cyan", length);
    buildMenu("- La edicion la puede realizar DNI, nombre o apellido.", false, length, "cyan", length);
    buildMenu("- Si no conoce el DNI, puede buscarlo en la tabla.", false, length, "cyan", length);
    divider(length, true);
    divider(length);
    cout << Text_Center << "Presione Enter para volver...";
    sys::getch();
}

//---------------------------------------------------------------------------
// FUNCION   : void showHelp()
// ACCION    : Muestra una pantalla de ayuda de busqueda.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showSearchHelp() {
    sys::cls();
    int length = 85;
    divider(length);
    divider(length, true);
    buildMenu("A Y U D A  D E  B U S Q U E D A", false, length / 2, "cyan", length);
    divider(length, true);
    divider(length);
    divider(length, true);
    buildMenu("Aqui puede ver la lista de freelancers.", false, length, "cyan", length);
    buildMenu("- La busqueda la puede realizar por nombre o apellido, o ver todos.", false, length, "cyan", length);
    buildMenu("- Si la consulta devuelve mas de 5 registros, se paginara la consulta.", false, length, "cyan", length);
    divider(length, true);
    divider(length);
    cout << Text_Center << "Presione Enter para volver...";
    sys::getch();
}

//---------------------------------------------------------------------------
// FUNCION   : void backToMain()
// ACCION    : Vuelve al menu principal.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void backToMain()
{
    Main::menu();
    Main::index();
}

//---------------------------------------------------------------------------
// FUNCION   : int getMaxPages()
// ACCION    : Devuelve la cantidad maximas de paginas que tiene el archivo.
// PARAMETROS: Ninguno.
// DEVUELVE  : Cantidad maxima de paginas.
//---------------------------------------------------------------------------
int getMaxPages()
{
    file = fopen ("Bin/freelancer.b","rb");
    fseek(file, 0, 2);
    unsigned int sizeOfRegisters = ftell(file) / sizeof(_freelancer);
    fclose(file);

    return (! (bool)(sizeOfRegisters % maxPagination) ? (sizeOfRegisters / maxPagination) : ((sizeOfRegisters / maxPagination) + 1));
}

//---------------------------------------------------------------------------
// FUNCION   : int getMaxPagesByFilter(char25 filter)
// ACCION    : Devuelve la cantidad maximas de paginas que tiene el archivo para el filtro ingresado.
// PARAMETROS: char25 filter: Filtro aplicado en la busqueda.
// DEVUELVE  : Cantidad maxima de paginas para el filtro.
//---------------------------------------------------------------------------
int getMaxPagesByFilter(char25 filter)
{
    file = fopen ("Bin/freelancer.b","rb");
    fseek(file, 0, 0);
    unsigned int sizeOfRegisters = 0;
    for (;! feof(file);) {
        fread(&_freelancer, sizeof(_freelancer), 1, file);
        if (strFind(_freelancer.name, filter) || strFind(_freelancer.lastname, filter))
            sizeOfRegisters++;
    }
    fclose(file);

    return (! (bool)(sizeOfRegisters % maxPagination) ? (sizeOfRegisters / maxPagination) : ((sizeOfRegisters / maxPagination) + 1));
}

//---------------------------------------------------------------------------
// FUNCION   : void showTable()
// ACCION    : Muestra en pantalla la tabla de freelancers.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
        searchFreelancersMenu();
        searchFreelancers();
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void showTableByFilter(char25 filter)
// ACCION    : Muestra en pantalla la tabla de freelancers para el filtro ingresado.
// PARAMETROS: char25 filter: Filtro aplicado en la busqueda.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showTableByFilter(char25 filter)
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
            if (strFind(_freelancer.name, filter) || strFind(_freelancer.lastname, filter)) {
                if (i >= paginatorFrom && i < paginatorTo)
                    cout << Text_Center
                        << "° "   << setw(10) << left << _freelancer.dni
                        << " ° "  << setw(25) << left << _freelancer.name
                        << " ° "  << setw(25) << left << _freelancer.lastname
                        << " ° "  << setw(16) << left << _freelancer.workedTime
                        << " ° "  << setw(25) << left << _freelancer.type
                        << " ° "  << setw(10) << left << _freelancer.registrationDate
                        << " ° "  << setw(12) << left << _freelancer.modificationDate
                        << " °"   << endl;

            } else {
                i--;
            }

            fread(&_freelancer, sizeof(_freelancer), 1, file);
        }
    }

    fclose(file);

    unsigned int pages = getMaxPagesByFilter(filter);
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
        showTableByFilter(filter);
    } else {
        searchFreelancersMenu();
        searchFreelancers();
    }
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
// FUNCION   : void retry()
// ACCION    : Si la entrada de la modificacion es incorrecta, vuelve a intentar.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void retryModify()
{
    modifyDataMenu();
    showErrorFooter();
    modifyData();
}

//---------------------------------------------------------------------------
// FUNCION   : void retry()
// ACCION    : Si la entrada de la busqueda es incorrecta, vuelve a intentar.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void retrySearch()
{
    searchFreelancersMenu();
    showErrorFooter();
    searchFreelancers();
}

//---------------------------------------------------------------------------
// FUNCION   : void setFreelancerName(char25 &nameReal, unsigned int minLength = 3)
// ACCION    : Establece el tipo de Freelancer.
// PARAMETROS: - char25 &nameReal: Nombre a establecer. Se modifica en memoria
//             - unsigned int minLength: Cantidad minima aceptada de caracteres. Por defecto 3.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void setFreelancerName(char25 &nameReal, unsigned int minLength = 3)
{
    char name[1000];
    cin.getline(name, 1000);

    while (! cin.good() || strlen(name) > 25 || strlen(name) < minLength) {
        cin.clear();
        cout << Text_Center << "\033[1;31mIngrese un nombre/apellido valido (" << minLength + 1 << " - 25 caracteres): \033[0m";
        cin.getline(name, 1000);
    }

    strcpy(nameReal, name);
}

//---------------------------------------------------------------------------
// FUNCION   : bool typeExists(char type[1000])
// ACCION    : Verifica que el tipo de freelancer exista.
// PARAMETROS: - char type[1000]: Tipo de Freelancer a verificar.
// DEVUELVE  : Si el tipo existe o no.
//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
// FUNCION   : void setFreelancerType(char25 &typeReal, unsigned int minLength = 3)
// ACCION    : Establece el tipo de Freelancer.
// PARAMETROS: - char25 &type: Tipo de categoria a establecer. Se modifica en memoria
//             - unsigned int minLength: Cantidad minima aceptada de caracteres. Por defecto 3.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
// FUNCION   : bool freelancerExists()
// ACCION    : Verifica que el freelancer no exista aun.
// PARAMETROS: Ninguno.
// DEVUELVE  : Si el freelancer existe o no.
//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
// FUNCION   : void setFreelancerDNI(unsigned int &dni)
// ACCION    : Establece el DNI del Freelancer.
// PARAMETROS: - unsigned int &dni: DNI a establecer. Se modifica en memoria
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void setFreelancerDNI(unsigned int &dni)
{
    cin >> dni;

    while (! cin.good() || freelancerExists()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << Text_Center << "\033[1;31mEl DNI ingresado no es valido o ya existe. Ingreselo nuevamente: \033[0m";
        cin >> dni;
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void setFreelancerName(char25 &nameReal, unsigned int minLength = 3)
// ACCION    : Valida el ingreso de un DNI numerico.
// PARAMETROS: - unsigned int &dni: DNI a verificar. Se modifica en memoria
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
// FUNCION   : void addData()
// ACCION    : Agrega un registro al archivo de freelancers.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
    validateEntryTF();

    if (entry[0] == 'S' || entry[0] == 's') {
        menu();
        addData();
    }

    menu();
    index();
}

//---------------------------------------------------------------------------
// FUNCION   : void positionate(freelancer structure, unsigned int position, unsigned int times = 0)
// ACCION    : Posicionamiento dentro de un archivo.
// PARAMETROS: - freelancer structure: La estructura para posicionar.
//             - unsigned int position: Determina si se posiciona al final o en un punto en particular.
//             - unsigned int times: Si es pos. part. es la posicion dentro del archivo.
// DEVUELVE  : Nada.
void positionate(freelancer structure, unsigned int position, unsigned int times = 0)
{
    size_t structSize = sizeof(structure);

    if (position == 1) {
        fseek(file, 0, 2);
        long sizeOfFile = ftell(file);
        fseek(file, sizeOfFile - structSize, 0);
    }

    if (position == 2) {
        fseek(file, structSize * times, 0);
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void modifyDataByPosition(unsigned int times)
// ACCION    : Modifica una posicion en particular del archivo.
// PARAMETROS: - unsigned int times: Veces que cicló el contador.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
    validateEntryTF();
    cin.ignore(0, '\n');

    if (entry[0] == 'S' || entry[0] == 's') {
        cout << Text_Center << "Desea modificar el nombre del freelancer? (S/N) ";
        validateEntryTF();

        if (entry[0] == 'S' || entry[0] == 's') {
            cin.ignore();
            strcpy(_freelancer.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el nombre del freelancer: ";
            setFreelancerName(_freelancer.name);
        }

        cout << Text_Center << "Desea modificar el apellido del freelancer? (S/N) ";
        validateEntryTF();
        cin.ignore(0, '\n');

        if (entry[0] == 'S' || entry[0] == 's') {
            cin.ignore();
            strcpy(_freelancer.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el apellido del freelancer: ";
            setFreelancerName(_freelancer.lastname);
        }

        cout << Text_Center << "Desea modificar el tipo de freelancer? (S/N) ";
        validateEntryTF();
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

//---------------------------------------------------------------------------
// FUNCION   : void modifyData()
// ACCION    : Determina que opcion se va a utilizar para modificar.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(fiveOptions)) {
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
        showModifyHelp();
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '5') {
        //loading(25, 50);
        menu();
        index();
    }

}

//---------------------------------------------------------------------------
// FUNCION   : void setFilter(char25 &filter)
// ACCION    : Establece el filtro de busqueda.
// PARAMETROS: - char25 &filter: Filtro a establecer. Se modifica en memoria.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void setFilter(char25 &filter)
{
    char filterAux[1000];
    cin.ignore(0, '\n');
    cin.getline(filterAux, 1000);

    while (! cin.good() || strlen(filterAux) > 25 || strlen(filterAux) == 0) {
        cin.clear();
        cout << Text_Center << "\033[1;31mIngrese un nombre/apellido valido (1 - 25 caracteres): \033[0m";
        cin.getline(filterAux, 1000);
    }

    strcpy(filter, filterAux);
}

//---------------------------------------------------------------------------
// FUNCION   : void searchFreelancers()
// ACCION    : Busca freelancers.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void searchFreelancers()
{
    file = fopen ("Bin/freelancer.b","rb");

    if (file == NULL) {
        fclose(file);
        cout << Text_Center << "\033[1;31mNo hay datos cargados aun.\033[0m";
        sys::getch();
        menu();
        index();
    }

    fclose(file);

    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(fourOptions)) {
        fclose(file);
        retrySearch();
    }

    if (entry[0] == '1') {
        paginatorFrom = 0;
        paginatorTo = maxPagination;
        showTable();
    }

    if (entry[0] == '2') {
        paginatorFrom = 0;
        paginatorTo = maxPagination;
        char25 filter;
        cout << Text_Center << "Ingrese el filtro a buscar: ";
        cin.ignore();
        setFilter(filter);
        showTableByFilter(filter);
    }

    if (entry[0] == '3') {
        showSearchHelp();
        searchFreelancersMenu();
        searchFreelancers();
    }

    if (entry[0] == '4') {
        //loading(25, 50);
        menu();
        index();
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void dispatch()
// ACCION    : Despacha la opcion ingresada por el usuario.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void dispatch()
{
    if (entry[0] == '1')
        addData();

    if (entry[0] == '2') {
        modifyDataMenu();
        modifyData();
    }

    if (entry[0] == '3') {
        searchFreelancersMenu();
        searchFreelancers();
    }

    if (entry[0] == '4') {
        showHelp();
        menu();
        index();
    }

    if (entry[0] == '5')
        backToMain();
}

//---------------------------------------------------------------------------
// FUNCION   : void index()
// ACCION    : Obtiene y valida la opcion que desea ingresar.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void index()
{
    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(fiveOptions)) {
        retry();
    }

    dispatch();
}
}

#endif // FREELANCERCONTROLLER_H_INCLUDED
