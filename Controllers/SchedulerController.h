#ifndef SCHEDULERCONTROLLER_H_INCLUDED
#define SCHEDULERCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h"

namespace Scheduler
{

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
    buildMenu("3. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

void backToMain()
{
    Main::menu();
    Main::index();
}

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

void successUpdate()
{
    cout << Text_Center << "\033[1;32mHoras cargadas exitosamente!\033[0m";
    cin.ignore();
}

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
            positionate(_freelancer, 2, i);
            fwrite(&_freelancer, sizeof(_freelancer), 1, file);
            positionate(_freelancer, 2, i + 1);
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
                positionate(_freelancer, 2, i);
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

void retry()
{
    menu();
    showErrorFooter();
    index();
}

void dispatch()
{
    if (entry[0] == '1')
        modifyData();

    if (entry[0] == '2')
        modifyData(false);

    if (entry[0] == '3')
        backToMain();
}

void index()
{
    cout << Text_Center << "Seleccione una opcion para operar: ";
    cin >> entry;

    if (! Rule::validEntry(maxOptionLength) || ! Rule::validEntry(threeOptions)) {
        retry();
    }

    dispatch();
}
}

#endif // SCHEDULERCONTROLLER_H_INCLUDED
