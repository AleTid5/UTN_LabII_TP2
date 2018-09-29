////#############################################################################
// ARCHIVO : SchedulerController.h
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
// Controlador de las funciones de cargas de horas de los freelancers.
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef SCHEDULERCONTROLLER_H_INCLUDED
#define SCHEDULERCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h" // Reglas principales del sistema

namespace Scheduler
{

//***************************************************************************
// DEFINICION DE LAS FUNCIONES
//===========================================================================
// FUNCION   : void menu()
// ACCION    : Muestra en pantalla el menu principal de carga de horas.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void menu()
{
    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);
    const char* title = "C A R G A  D E  H O R A S";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "magenta");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Cargar horas a todos los freelancers.", false, sizeOfTitle, "magenta");
    buildMenu("2. Cargar horas a un freelancer.", false, sizeOfTitle, "magenta");
    buildMenu("3. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("4. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

//---------------------------------------------------------------------------
// FUNCION   : void showHelp()
// ACCION    : Muestra una pantalla de ayuda de carga de horas.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showHelp() {
    sys::cls();
    int length = 85;
    divider(length);
    divider(length, true);
    buildMenu("A Y U D A  D E  C A R G A  D E  H O R A S", false, length / 2, "cyan", length);
    divider(length, true);
    divider(length);
    divider(length, true);
    buildMenu("Aqui puede cargar horas masiva o individualmente.", false, length, "cyan", length);
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
// FUNCION   : void showFreelancer(Freelancer::freelancer _freelancer, bool allFreelancers = true)
// ACCION    : Muestra al freelancer que se le esta por cargar horas.
// PARAMETROS: - Freelancer::freelancer _freelancer: Freelancer a mostrar.
//             - bool allFreelancers: Determina si se modifican todos Freelancers o uno solo.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void showFreelancer(Freelancer::freelancer _freelancer, bool allFreelancers = true)
{
    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);

    if (allFreelancers) {
        const char* title = "C A R G A R  H O R A S  A  T O D O S";
        buildMenu(title, true, strlen(title), "magenta");
    } else {
        const char* title = "C A R G A R  H O R A S  A  E M P L E A D O";
        buildMenu(title, true, strlen(title), "magenta");
    }

    divider(70, true);
    divider(70);

    cout << endl;
    cout << Text_Center << "DNI del Freelancer: \033[1;35m" << _freelancer.dni << endl;
    cout << Text_Center << "\033[0mNombre del Freelancer: \033[1;35m" << _freelancer.name << endl;
    cout << Text_Center << "\033[0mApellido del Freelancer: \033[1;35m" << _freelancer.lastname << endl;
    cout << Text_Center << "\033[0mTipo de Freelancer: \033[1;35m" << _freelancer.type << endl;
    cout << Text_Center << "\033[0mHoras trabajadas: \033[1;35m";
}

//---------------------------------------------------------------------------
// FUNCION   : void setWorkedTime(Freelancer::freelancer &_freelancer)
// ACCION    : Establece las horas trabajadas.
// PARAMETROS: - Freelancer::freelancer &_freelancer: Freelancer a modificar.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void setWorkedTime(Freelancer::freelancer &_freelancer)
{
    cin >> _freelancer.workedTime;

    while (! cin.good() || _freelancer.workedTime < 0) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << Text_Center << "\033[1;31mIngrese un numero valido de horas: \033[0m";
        cin >> _freelancer.workedTime;
    }

    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    cout << "\033[0m";
}

//---------------------------------------------------------------------------
// FUNCION   : void setDNI(unsigned int &dni)
// ACCION    : Valida el ingreso numerico del DNI.
// PARAMETROS: - unsigned int &dni: DNI a buscar.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void setDNI(unsigned int &dni)
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
// FUNCION   : void successUpdate()
// ACCION    : Muestra un mensaje en pantalla de modificacion satisfactoria.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void successUpdate()
{
    cout << Text_Center << "\033[1;32mHoras cargadas exitosamente!\033[0m";
    cin.ignore();
}

//---------------------------------------------------------------------------
// FUNCION   : void modifyData(bool allUsers = true)
// ACCION    : Determina que opcion se va a utilizar para cargar horas.
// PARAMETROS: - bool allUsers: Determina si se modifican todos los freelancers o uno solo.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void modifyData(bool allUsers = true)
{
    file = fopen ("BIN/freelancer.b", "rb+");

    if (file == NULL) {
        cout << Text_Center << "\033[1;31mAun no se han cargado freelancers.\033[0m";
        sys::getch();
        fclose(file);
        menu();
        index();
    }

    Freelancer::freelancer _freelancer;
    fseek(file, 0, 2);
    unsigned long sizeOfFile = ftell(file);
    size_t sizeOfFreelancer = sizeof(_freelancer);
    fseek(file, 0, 0);

    if (allUsers) {
        for (unsigned int i = 0; i < (sizeOfFile / sizeOfFreelancer); i++) {
            fread(&_freelancer, sizeof(_freelancer), 1, file);
            showFreelancer(_freelancer);
            setWorkedTime(_freelancer);
            Freelancer::positionate(_freelancer, 2, i);
            fwrite(&_freelancer, sizeof(_freelancer), 1, file);
            Freelancer::positionate(_freelancer, 2, i + 1);
            successUpdate();
        }
    } else {
        unsigned int dni;
        bool founded = false;
        cout << Text_Center << "Ingrese el DNI a buscar: ";
        setDNI(dni);

        for (unsigned int i = 0; i < (sizeOfFile / sizeOfFreelancer) && ! founded; i++) {
            fread(&_freelancer, sizeof(_freelancer), 1, file);
            if (_freelancer.dni == dni) {
                showFreelancer(_freelancer, false);
                setWorkedTime(_freelancer);
                Freelancer::positionate(_freelancer, 2, i);
                fwrite(&_freelancer, sizeof(_freelancer), 1, file);
                founded = ! founded;
                successUpdate();
            }
        }

        if (! founded) {
            cout << Text_Center << "No se ha encontrado el DNI ingresado.";
            sys::getch();
        }
    }

    fclose(file);

    menu();
    index();
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
// FUNCION   : void dispatch()
// ACCION    : Despacha la opcion ingresada por el usuario.
// PARAMETROS: Ninguno.
// DEVUELVE  : Nada.
//---------------------------------------------------------------------------
void dispatch()
{
    if (entry[0] == '1')
        modifyData();

    if (entry[0] == '2')
        modifyData(false);

    if (entry[0] == '3') {
        showHelp();
        menu();
        index();
    }

    if (entry[0] == '4')
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

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(fourOptions)) {
        retry();
    }

    dispatch();
}
}

#endif // SCHEDULERCONTROLLER_H_INCLUDED
