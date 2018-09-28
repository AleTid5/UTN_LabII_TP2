#ifndef REPORTSCONTROLLER_H_INCLUDED
#define REPORTSCONTROLLER_H_INCLUDED

#include "../Rules/MainRules.h"

namespace Reports
{

int paginatorFrom = 0, paginatorTo = maxPagination;

void menu()
{
    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);
    const char* title = "         M E N U  D E  R E P O R T E S          ";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "yellow");
    divider(70, true);
    divider(70);
    divider(70, true);
    buildMenu("1. Ver total de horas trabajadas y sueldos a pagar.", false, sizeOfTitle, "yellow");
    buildMenu("2. Ver empleados que facturaron agrupados por tipo.", false, sizeOfTitle, "yellow");
    buildMenu("3. Ver listado de valor precio/hora de cada categorias.", false, sizeOfTitle, "yellow");
    buildMenu("4. Ayuda.", false, sizeOfTitle, "cyan");
    buildMenu("5. Volver.", false, sizeOfTitle, "red");
    divider(70, true);
    divider(70);
}

void showHelp() {
    sys::cls();
    int length = 85;
    divider(length);
    divider(length, true);
    buildMenu("A Y U D A  D E  E S T A D I S T I C A S", false, length / 4, "cyan", length);
    divider(length, true);
    divider(length);
    divider(length, true);
    buildMenu("Aqui puede visualizar las estadisticas mas relevantes del mes.", false, length, "cyan", length);
    divider(length, true);
    divider(length);
    cout << Text_Center << "Presione Enter para volver...";
    sys::getch();
}

void backToMain()
{
    Main::menu();
    Main::index();
}

unsigned int countRegisters()
{
    file = fopen ("Bin/configuration.b","rb");
    fseek(file, 0, 2);
    unsigned int sizeOfRegisters = ftell(file) / sizeof(Configuration::_configuration);
    fclose(file);

    return sizeOfRegisters;
}

int getMaxPages()
{
    unsigned int sizeOfRegisters = countRegisters();
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
        fread(&Configuration::_configuration, sizeof(Configuration::_configuration), 1, file);
        for (int i = 0;! feof(file); i++) {
            if (i >= paginatorFrom && i < paginatorTo) {
                cout << Text_Center
                    << "° "   << setw(10) << left << Configuration::_configuration.id
                    << " ° "  << setw(25) << left << Configuration::_configuration.type
                    << " ° $" << setw(13) << left << Configuration::_configuration.amount
                    << " ° "  << setw(10) << left << Configuration::_configuration.registrationDate
                    << " ° "  << setw(12) << left << Configuration::_configuration.modificationDate
                    << " °"   << endl;
            }

            fread(&Configuration::_configuration, sizeof(Configuration::_configuration), 1, file);
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

void showPaymentWorkReport()
{
    unsigned int countOfRegisters = countRegisters();

    FILE* configFile = fopen("BIN/configuration.b", "rb");
    FILE* freelancerFile = fopen("BIN/freelancer.b", "rb");

    if (configFile == NULL || freelancerFile == NULL) {
        fclose(configFile);
        fclose(freelancerFile);
        cout << Text_Center << "\033[1;31mNo se pueden mostrar las estadisticas. Insuficiente informacion.\033[0m";
        sys::getch();
        Reports::menu();
        Reports::index();
    }

    struct WorkedMoney {
        char25 type;
        unsigned int workedTime = 0;
        unsigned int payment = 0;
    } _workedMoney[countOfRegisters];

    sys::cls();
    cout << endl;
    divider(70);
    divider(70, true);
    const char* title = "H O R A S  /  S U E L D O S";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "yellow");
    divider(70, true);
    divider(70);

    fseek(configFile, 0, 0);
    fseek(freelancerFile, 0, 0);

    for (unsigned int i = 0; i < countOfRegisters; i++) {
        fread(&Configuration::_configuration, sizeof(Configuration::_configuration), 1, configFile);
        strcpy(_workedMoney[i].type, Configuration::_configuration.type);
        fread(&Freelancer::_freelancer, sizeof(Freelancer::_freelancer), 1, freelancerFile);
        for (unsigned int j = 0;! feof(freelancerFile); j++) {
            if (! (bool) strcmp(Freelancer::_freelancer.type, Configuration::_configuration.type)) {
                _workedMoney[i].workedTime += Freelancer::_freelancer.workedTime;
                _workedMoney[i].payment += (Freelancer::_freelancer.workedTime * Configuration::_configuration.amount);
            }
            fread(&Freelancer::_freelancer, sizeof(Freelancer::_freelancer), 1, freelancerFile);
        }
        fseek(freelancerFile, 0, 0);
    }

    fclose(configFile);
    fclose(freelancerFile);

    unsigned int totalTime = 0, totalPayment = 0;

    cout << Text_Center
             << "°° "  << setw(25) << left << "TIPO"
             << " ° " << setw(16) << left << "HORAS TRABAJADAS"
             << " ° " << setw(17) << left << "SUELDO A PAGAR"
             << " °°"  << endl;

    for (unsigned int i = 0; i < countOfRegisters; i++) {
        cout << Text_Center
             << "°° "  << setw(25) << left << _workedMoney[i].type
             << " ° " << setw(16) << left << _workedMoney[i].workedTime
             << " ° $" << setw(16) << left << _workedMoney[i].payment
             << " °°"  << endl;
        totalTime += _workedMoney[i].workedTime;
        totalPayment += _workedMoney[i].payment;
    }

    cout << Text_Center
             << "°° \033[1;32m"  << setw(25) << left << "TOTAL"
             << " ° " << setw(16) << left << totalTime
             << " ° $" << setw(16) << left << totalPayment
             << "\033[0m °°"  << endl;

    divider(70);

    cout << endl;
    divider(70);
    divider(70, true);
    const char* title2 = "ESTADISTICA DE HORAS";
    int sizeOfTitle2 = strlen(title2);
    buildMenu(title2, true, sizeOfTitle2, "yellow");
    divider(70, true);
    divider(70);
    cout << endl;

    for (unsigned int i = 0; i < countOfRegisters; i++) {
        float percentage = 0;

        if (totalTime > 0)
            percentage = (float) _workedMoney[i].workedTime * 100 / (float) totalTime;

        cout << Text_Center << setw(20) << left << _workedMoney[i].type;

        cout << Text_Center << "\033[1;32m";
        for (int j = 0; j < (((int) percentage) / 3); j++) {
            cout << "°";
        }
        cout << "\033[0m " << percentage << "%" << endl;

    }

    cout << endl;

    cout << endl;
    divider(70);
    divider(70, true);
    const char* title3 = "ESTADISTICA DE SUELDOS";
    int sizeOfTitle3 = strlen(title3);
    buildMenu(title3, true, sizeOfTitle3, "yellow");
    divider(70, true);
    divider(70);
    cout << endl;

    for (unsigned int i = 0; i < countOfRegisters; i++) {
        float percentage = 0;

        if (totalPayment > 0)
            percentage = (float) _workedMoney[i].payment * 100 / (float) totalPayment;

        cout << Text_Center << setw(20) << left << _workedMoney[i].type;

        cout << Text_Center << "\033[1;32m";
        for (int j = 0; j < (((int) percentage) / 3); j++) {
            cout << "°";
        }
        cout << "\033[0m " << percentage << "%" << endl;

    }

    cout << endl;

    cout << Text_Center << "Presione Enter para volver al menu de reportes...";
    sys::getch();

    Reports::menu();
    Reports::index();
}

void showCategoriesReport()
{
    unsigned int countOfRegisters = countRegisters();

    FILE* configFile = fopen("BIN/configuration.b", "rb");
    FILE* freelancerFile = fopen("BIN/freelancer.b", "rb");

    if (configFile == NULL || freelancerFile == NULL) {
        fclose(configFile);
        fclose(freelancerFile);
        cout << Text_Center << "\033[1;31mNo se pueden mostrar las estadisticas. Insuficiente informacion.\033[0m";
        sys::getch();
        Reports::menu();
        Reports::index();
    }

    sys::cls();
    cout << endl;
    divider(105);
    divider(105, true);
    const char* title = "C A T E G O R I A S";
    int sizeOfTitle = strlen(title);
    buildMenu(title, true, sizeOfTitle, "yellow", 105);
    divider(105, true);

    fseek(configFile, 0, 0);
    fseek(freelancerFile, 0, 0);

    for (unsigned int i = 0; i < countOfRegisters; i++) {
        unsigned int totalTime = 0, totalPayment = 0;
        fread(&Configuration::_configuration, sizeof(Configuration::_configuration), 1, configFile);
        divider(105);
        buildMenu(Configuration::_configuration.type, false, sizeOfTitle, "yellow", 105);
        divider(105, true);
        cout << Text_Center
             << "°° "  << setw(10) << left << "DNI"
             << " ° " << setw(25) << left << "Nombre"
             << " ° " << setw(25) << left << "Apellido"
             << " ° " << setw(16) << left << "Horas trabajadas"
             << " ° $" << setw(10) << left << "Sueldo"
             << " °°"  << endl;
        fread(&Freelancer::_freelancer, sizeof(Freelancer::_freelancer), 1, freelancerFile);
        for (;! feof(freelancerFile);) {
            if (! (bool) strcmp(Freelancer::_freelancer.type, Configuration::_configuration.type)) {
                cout << Text_Center
                     << "°° "  << setw(10) << left << Freelancer::_freelancer.dni
                     << " ° " << setw(25) << left << Freelancer::_freelancer.name
                     << " ° " << setw(25) << left << Freelancer::_freelancer.lastname
                     << " ° " << setw(16) << left << Freelancer::_freelancer.workedTime
                     << " ° $" << setw(10) << left << (Freelancer::_freelancer.workedTime * Configuration::_configuration.amount)
                     << " °°"  << endl;
                totalTime += Freelancer::_freelancer.workedTime;
                totalPayment += (Freelancer::_freelancer.workedTime * Configuration::_configuration.amount);
            }
            fread(&Freelancer::_freelancer, sizeof(Freelancer::_freelancer), 1, freelancerFile);
        }
        cout << Text_Center
             << "°° \033[1;32m"  << setw(66) << right << "T O T A L E S"
             << " ° " << setw(16) << left << totalTime
             << " ° $" << setw(10) << left << totalPayment
             << "\033[0m °°"  << endl;
        divider(105, true);
        fseek(freelancerFile, 0, 0);
    }

    fclose(configFile);
    fclose(freelancerFile);

    divider(105);

    cout << Text_Center << "Presione Enter para volver al menu de reportes...";
    sys::getch();

    Reports::menu();
    Reports::index();
}

void dispatch()
{
    if (entry[0] == '1')
        showPaymentWorkReport();

    if (entry[0] == '2')
        showCategoriesReport();

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

void retry()
{
    menu();
    showErrorFooter();
    index();
}

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

#endif // REPORTSCONTROLLER_H_INCLUDED
