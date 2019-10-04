#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees (Employee list[], int len){
    for (int i = 0 ; i < len ; i++){
        list[i].isEmpty = 1;
    }

    return 0;
}

int menu(){
    int option;

    fflush(stdin);
    system("cls");
    printf("**** MENU DE OPCIONES ****\n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n");

    printf("Ingresar una opcion: ");
    scanf("%d", &option);

    return option;
}

void registerEmployee(Employee list[], int len, int id){
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int control;

    system("cls");
    printf ("**** ALTA EMPLEADOS ****\n\n");
    printf ("Ingrese nombre: ");
        fflush(stdin);
        gets( name );
    printf ("Ingrese apellido: ");
        fflush(stdin);
        gets( lastName );
    printf ("Ingrese salario: ");
        scanf ("%f", &salary);
    printf ("Ingrese sector: ");
        scanf ("%d", &sector);

    control = addEmployee(list, len, id, name, lastName, salary, sector);

    if (control == 0){
        printf ("\nSe ha dado de alta.\n\n");
    }else {
        printf ("\nHa ocurrido un error.\n\n");
    }

    system("pause");
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector){
    int control = -1;
    for (int i = 0 ; i < len ; i ++){
        if (list[i].isEmpty == 1){
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;
            control = 0;
            break;
        }
    }

    return control;
}

int findEmployeeById (Employee list[], int len, int id){
    for (int i=0 ; i < len ; i++){
        if (list[i].isEmpty == 0 && list[i].id == id){
            return i;
            break;
        }
    }
    return -1;
}

int removeEmployee (Employee list[], int len, int id){
   char option;
   int index = 0;

   findEmployeeById(list, len, id);

   if (findEmployeeById(list, len, id) == -1){
       return 1;
   }else {
        printf ("\nDesea dar de baja al empleado? (s/n): ");
        fflush(stdin);
        scanf("%c", &option);
        if (option == 's'){
            list[index].isEmpty = 1;
            return 0;
        }
    }

   return -1;
}

int sortEmployees(Employee list[], int len, int order){
    Employee auxEmployee;
    int control = -1;
    if (order == 1 ){
        for(int i = 0; i < len-1 ; i++){
            for(int j = i+1; j <len; j++){
                if(list[i].sector > list[j].sector && list[i].isEmpty == 0 && list[j].isEmpty == 0){
                    auxEmployee= list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    control =0;
                }else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)>0){
                    auxEmployee= list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    control = 0;
                }
            }
        }
        printf ("\nEmpleados ordenados por apellido y sector de manera ascendente: \n");
        printEmployees(list, len);
   }else{
        for(int i= 0; i < len-1 ; i++ ){
            for(int j= i+1; j <len; j++){
                if(list[i].sector < list[j].sector && list[i].isEmpty == 0 && list[j].isEmpty == 0){
                    auxEmployee= list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    control = 0;
                }else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)<0){
                    auxEmployee= list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    control = 0;
                }
            }
        }
        printf ("\nEmpleados ordenados por apellido y sector de manera descendente: \n");
        printEmployees(list, len);
   }

   return control;
}

int printEmployees (Employee list[], int len){
    int allOk = -1;
    printf ("\n Id             Nombre        Apellido          Salario       Sector   \n");
    for (int i = 0 ; i < len ; i ++){
        if (list[i].isEmpty == 0){
            printf (" %3d      %10s      %10s       %10.2f        %2d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            allOk = 0;
        }
    }
    printf("\n");

    return allOk;
}

void modifyEmployee (Employee list[], int len){
    int flag = 0;
    int id;
    int index = 0;
    int option;
    int control = 0;

    for (int i= 0 ; i < len ; i++){
        if (list[i].isEmpty == 0){
            flag = 1;
        }
    }

    if (flag == 0){
        printf ("\nNo hay empleados.\n\n");
    }else {
        system("cls");
        printf ("**** MODIFICAR EMPLEADO ****\n\n");
        printf ("Ingrese id: ");
        scanf("%d", &id);
        findEmployeeById(list, len, id);

        if (findEmployeeById(list, len, id) == -1){
            printf ("\nNo hay empleado con esa id.\n\n");
        }else {
            printf ("\n1. Modificar el nombre [%s].\n", list[index].name);
            printf ("2. Modificar el apellido [%s].\n", list[index].lastName);
            printf ("3. Modificar el salario [%.2f].\n", list[index].salary);
            printf ("4. Modificar el sector [%d]\n", list[index].sector);
            printf ("5. Regresar.\n");
            printf ("\nIngrese opcion: ");
            scanf ("%d", &option);

            switch (option){
                case 1:
                    printf ("\nIngrese nuevo nombre: ");
                    fflush(stdin);
                    gets(list[index].name);
                    control = 1;
                    break;
                case 2:
                    printf ("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(list[index].lastName);
                    control = 1;
                    break;
                case 3:
                    printf ("Ingrese nuevo salario: ");
                    scanf ("%f", &list[index].salary);
                    control = 1;
                    break;
                case 4:
                    printf ("Ingrese nuevo sector: ");
                    scanf("%d", &list[index].sector);
                    control = 1;
                    break;
                case 5:
                    break;
                default:
                    printf ("Opcion incorrecta. Por favor, ingrese una opcion valida.");
                    system("pause");
                    break;
        }

        if (control == 0) {
            printf ("\nNo se han modificado los datos del empleado.\n");
        } else {
            printf("\nSe han modificado los datos del empleado.\n");
        }
        }
    }
}

void annulEmployee(Employee list[], int len){
    int id;
    int flag = 0;

    for (int i = 0 ; i < len ; i++){
        if (list[i].isEmpty == 0){
            flag = 1;
            break;
        }
    }

    if (flag == 0){
        printf ("\nNo hay empleados.\n\n");
        system("pause");
    }else {
        system("cls");
        printf ("**** BAJA EMPLEADO ****\n\n");
        printf ("Ingrese id: ");
        scanf ("%d", &id);

        removeEmployee(list, len, id);

        if(removeEmployee(list, len, id) == 1){
            printf ("\nNo hay ningun empleado con esa id. Por favor, ingrese una id valida.\n\n");
            system ("pause");
        }else if (removeEmployee(list, len, id) == 0){
            printf ("\nSe ha dado de baja al empleado.\n");
            system("pause");
        }else {
            printf ("\nNo se ha dado de baja al empleado.\n");
            system("pause");
        }
    }
}

void inform(Employee list[], int len){
    int option;
    int orden;
    int flag = 0;

    for (int i = 0 ; i < len ; i++){
        if (list[i].isEmpty == 0){
        flag = 1;
        }
    }

    if (flag == 0){
        printf ("\nNo hay empleados.\n\n");
    }else {
    system ("cls");
    printf ("**** INFORMES ****\n");
    printf ("\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf ("2. Mostrar total de salarios y promedio.\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &option);

    switch (option){
        case 1:
            system ("cls");
            printf ("**** INFORMES ****\n\n");
            printf ("1. Ordenar de manera ascendente.\n");
            printf ("2. Ordenar de manera descendente.\n");
            printf ("\nOpcion: ");
            scanf ("%d", &orden);
            sortEmployees(list, len, orden);
            break;

        case 2:
            computeSalaries(list, len);
            break;

        default:
            printf ("Opcion incorrecta!\n");
            break;
    }
    }
}

void computeSalaries(Employee list[], int len){

    float total = 0;
    float salaries = 0;
    float averageSalary =0;
    int aboveAverageEmployees = 0;

    for (int i=0; i<len; i++){
        salaries++;
        if (list[i].isEmpty == 0){
            total += list[i].salary;
        }

        averageSalary = (float) total/salaries;
        if (list[i].salary > averageSalary){
            aboveAverageEmployees++;
        }
    }

    system("cls");
    printf ("**** INFORMES ****\n");
    printf("\nTotal de salarios: %.2f\n", total);
    printf ("Promedio de salarios: %.2f\n", averageSalary);

    if (aboveAverageEmployees == 0){
        printf("No hay empleados que superen el promedio salarial.\n\n");
    }else{
        printf ("El numero de empleados que superan el promedio salarial: %d\n\n", aboveAverageEmployees);
    }
}


