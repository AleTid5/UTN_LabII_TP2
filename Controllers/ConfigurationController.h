////#############################################################################
// ARCHIVO : ConfigurationController.h
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
// Controlador de las funciones de configuracion de categorias de los freelancers.
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef CONFIGURATIONCONTROLLER_H_INCLUDED
#define CONFIGURATIONCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h" // Reglas principales del sistema

namespace Configuration
{

//***************************************************************************
// DEFINICION DE LAS ESTRUCTURAS
//===========================================================================
// ESTRUCTURA : struct configutation
// ACCION     : Almacena la configuracion de categorias de freelancers.
// COMPONENTES:
//              - unsigned int id: ID autoincremental.
//              - char25 type: Tipo de categoria.
//              - unsigned int amount: Monto que percibe la categoria por hora.
//              - char12 registrationDate: Fecha de creacion de la categoria.
//              - char12 registrationDate: Fecha de modificacion de la categoria.
//---------------------------------------------------------------------------
struct configuration
{
    unsigned int id;
    char25 type;
    unsigned int amount;
    char12 registrationDate;
    char12 modificationDate = "Sin cambios";
} _configuration;

//***************************************************************************
// DEFINICION DE LAS VARIABLES GLOBALES DE CONFIGURACION
//===========================================================================
int paginatorFrom = 0, paginatorTo = maxPagination; //Paginacion desde/hasta.

//***************************************************************************
// DEFINICION DE LAS FUNCIONES
//===========================================================================
// FUNCION   : void menu()
// ACCION    : Muestra en pantalla el menu principal de configuracion.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
    buildMenu("4. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("5. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

//---------------------------------------------------------------------------
// FUNCION   : void modifyDataMenu()
// ACCION    : Muestra en pantalla el menu de modificacion de categoria.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
    buildMenu("3. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("4. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

//---------------------------------------------------------------------------
// FUNCION   : void showHelp(bool isModify)
// ACCION    : Muestra una pantalla de ayuda.
// PARAMETROS: bool isModify: Por defecto falso. Determina si es modificacion.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showHelp(bool isModify = false) {
    sys::cls();
    int length = 85;
    divider(length);
    divider(length, true);

    if (! isModify)
        buildMenu("A Y U D A  D E  C A T E G O R I A S", false, length / 2, "cyan", length);
    else
        buildMenu("A Y U D A  D E  M O D I F I C A C I O N", false, length / 2, "cyan", length);

    divider(length, true);
    divider(length);
    divider(length, true);
    if (! isModify)
        buildMenu("Aqui puede crear, editar o ver la lista de categorias.", false, length, "cyan", length);
    buildMenu("- La edicion la puede realizar el ID de categoria (si lo conoce) o por tipo.", false, length, "cyan", length);
    buildMenu("- El ID de categoria es un numero autoincremental, vea la tabla para conocerlo.", false, length, "cyan", length);
    if (! isModify)
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
    file = fopen ("Bin/configuration.b","rb");
    fseek(file, 0, 2);
    unsigned int sizeOfRegisters = ftell(file) / sizeof(_configuration);
    fclose(file);

    return (! (bool)(sizeOfRegisters % maxPagination) ? (sizeOfRegisters / maxPagination) : ((sizeOfRegisters / maxPagination) + 1));
}

//---------------------------------------------------------------------------
// FUNCION   : void showTable()
// ACCION    : Muestra en pantalla la tabla de configuraciones de freelancers.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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
// FUNCION   : void retryModify()
// ACCION    : Si la entrada es incorrecta al modificar, vuelve a intentar.
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
// FUNCION   : void setFreelancerType(char25 &type, unsigned int minLength = 3)
// ACCION    : Establece el tipo de Freelancer.
// PARAMETROS: - char25 &type: Tipo de categoria a establecer. Se modifica en memoria
//             - unsigned int minLength: Cantidad minima aceptada de caracteres. Por defecto 3.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void setFreelancerType(char25 &type, unsigned int minLength = 3)
{
    cin.ignore();
    char typeAux[1000];
    cin.getline(typeAux, 1000);

    while (! cin.good() || strlen(typeAux) > 25 || strlen(typeAux) < minLength)
    {
        cin.clear();
        cout << Text_Center << "\033[1;31mIngrese un tipo valido (" << minLength << " - 25 caracteres): \033[0m";
        cin.getline(typeAux, 1000);
    }

    strcpy(type, typeAux);
}

//---------------------------------------------------------------------------
// FUNCION   : void setFreelancerAmount(unsigned int &amount, bool money = true
// ACCION    : Establece el dinero que gana una categoria.
// PARAMETROS: - unsigned int &amount: Cantidad de dinero. Se modifica en memoria
//             - bool money: Determina si es dinero o un ID. Por defecto es dinero.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
// FUNCION   : void positionate(configuration structure, unsigned int position, unsigned int times = 0)
// ACCION    : Posicionamiento dentro de un archivo.
// PARAMETROS: - configuration structure: La estructura para posicionar.
//             - unsigned int position: Determina si se posiciona al final o en un punto en particular.
//             - unsigned int times: Si es pos. part. es la posicion dentro del archivo.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void positionate(configuration structure, unsigned int positionType, unsigned int times = 0)
{
    size_t structSize = sizeof(structure);

    if (positionType == 1) {
        fseek(file, 0, 2);
        long sizeOfFile = ftell(file);
        fseek(file, sizeOfFile - structSize, 0);
    }

    if (positionType == 2) {
        fseek(file, structSize * times, 0);
    }
}

//---------------------------------------------------------------------------
// FUNCION   : void addData()
// ACCION    : Agrega un registro al archivo de configuracion de categorias.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
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

    cout << Text_Center << "Desea cargar otra categoria? (S/N) ";
    validateEntryTF();

    if (entry[0] == 'S' || entry[0] == 's') {
        menu();
        addData();
    }

    menu();
    index();
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
    cout << Text_Center << "Se ha encontrado la siguiente categoria:" << endl;
    cout << Text_Center << "ID: " << _configuration.id << endl;
    cout << Text_Center << "Tipo de Freelancer: " << _configuration.type << endl;
    cout << Text_Center << "Monto que percibe: $" << _configuration.amount << endl;
    cout << Text_Center << "Fecha de creacion: " << _configuration.registrationDate << endl;
    cout << Text_Center << "Desea modificarlo? (S/N) ";
    validateEntryTF();
    cin.ignore(0, '\n');

    if (entry[0] == 'S' || entry[0] == 's') {
        cout << Text_Center << "Desea modificar el tipo de freelancer? (S/N) ";
        validateEntryTF();
        cin.ignore(0, '\n');

        if (entry[0] == 'S' || entry[0] == 's') {
            strcpy(_configuration.modificationDate, currentDate);
            cout << Text_Center << "Ingrese el tipo de freelancer: ";
            setFreelancerType(_configuration.type);
        }

        cout << Text_Center << "Desea modificar el monto que va a ganar? (S/N) ";
        validateEntryTF();
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

        cout << Text_Center << "\033[1;32mCategoria modificada exitosamente!\033[0m";
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

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(fourOptions)) {
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
                freelancerFounded = true;
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
        showHelp(true);
        modifyDataMenu();
        modifyData();
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

    if (entry[0] == '3')
        showTable();

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

#endif // CONFIGURATIONCONTROLLER_H_INCLUDED
