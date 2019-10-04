#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define LEN 1000

int main(){
    Employee employees[LEN];
    initEmployees(employees, LEN);
    char out = 'n';
    int id = 0000;
    do{
        switch (menu()){
            case 1:
                id++;
                registerEmployee(employees, LEN, id);
                break;
            case 2:
                modifyEmployee(employees, LEN);
                system("pause");
                break;
            case 3:
                annulEmployee(employees, LEN);
                break;
            case 4:
                inform(employees, LEN);
                system("pause");
                break;
            case 5:
                out = 's';
                break;
            default:
                printf ("Opcion incorrecta. Por favor, ingrese una opcion valida.\n");
                system("pause");
                break;

        }
    }while (out == 'n');

    return 0;
}

