#include <stdio.h>
#include <stdlib.h>
#include <conio.h>                  // Añado para poder declarar la función getche()
#include "funcionesMatematicas.h"

int main()
{
    int     primerOperando;
    int     segundoOperando;
    char    operacion;
    char    volver = 'n';

    printf("Ingresar 1er operando: ");      // Se solicita el ingreso de un número.
    scanf("%d", &primerOperando);           /* Indico el tipo de variable con máscara %d (para que tome al argumento como int) y
                                             * utilizo el operador de dirección (&) para que lo almacene en la dirección de memoria
                                             * de la variable "primerOperando".*/

    printf("\nIngresar 2do operando: ");    // Se solicita el ingreso de un segundo número.
    scanf("%d", &segundoOperando);          /* Indico el tipo de variable con máscara %d (para que tome al argumento como int) y
                                             * utilizo el operador de dirección (&) para que lo almacene en la dirección de memoria
                                             * de la variable "segundoOperando".
                                             */
    do{
        printf("\nMenu de operaciones: \n");
        printf("a) Calcular la suma (%d+%d): \n", primerOperando, segundoOperando);
        printf("b) Calcular la resta (%d-%d): \n", primerOperando, segundoOperando);
        printf("c) Calcular la division (%d/%d): \n", primerOperando, segundoOperando);
        printf("d) Calcular la multiplicacion (%d*%d): \n", primerOperando, segundoOperando);
        printf("e) Calcular el factorial (%d! y %d!): \n", primerOperando, segundoOperando);
        printf("f) Realizar todas las operaciones.\n");

        operacion = getche();   /* Utilizo la función getche() para que el programa lea un solo carácter ingresado directamente desde
                                 * el teclado y se lo asigne a la variable "operacion".*/
        switch(operacion){      /* Utilizo switch para que, en base al valor de la variable "operacion", se ejecucuten diferentes partes
                                 * del código.*/

            case 'a': /* Cuando el carácter asignado a la variable "operacion" sea 'a', se utilizará la función sumar() con los
                       * valores almacenados en las variables "primerOperando" y "segundoOperando" como parámetros de la función.*/

                printf("\n\nEl resultado de %d+%d es: %d\n", primerOperando, segundoOperando, sumar(primerOperando, segundoOperando));
                volver = 'n';
                break;

            case 'b': /* Cuando el carácter asignado a la variable "operacion" sea 'b', se utilizará la función restar().*/

                printf("\n\nEl resultado de %d-%d es: %d\n", primerOperando, segundoOperando, restar(primerOperando, segundoOperando));
                volver = 'n';
                break;

            case 'c': /* Cuando el carácter asigncado a la variable "operacion" sea 'c', se utilizará la función dividir().*/

                if(segundoOperando == 0){
                    printf("\n\nNo es posible dividir entre cero\n"); /* Si el valor almacenado en la variable "segundoOperando" es igual a
                                                                       * 0, entonces se advierte que no es posible realizar la operación de
                                                                       * división con un divisor igual a 0.
                                                                       */
                } else {
                    printf("\n\nEl resultado de %d/%d es: %d\n", primerOperando, segundoOperando, dividir(primerOperando, segundoOperando));
                }
                volver = 'n';
                break;

            case 'd': /* Cuando el carácter asignado a la variable "operacion" sea 'd', se utilizará la función multiplicar().*/

                printf("\n\nEl resultado de %d*%d es: %d\n", primerOperando, segundoOperando, multiplicar(primerOperando, segundoOperando));
                volver = 'n';
                break;

            case 'e': /* Cuando el carácter asignado a la variable "operacion" sea 'e', se utilizará la función factorial().
                       * Sin embargo, si el valor almacenado en la variable "primerOperando" o "segundoOperando" es igual a un numero entero
                       * negativo, se advierte que no es posible realizar la descomposición factorial de numeros negativos.*/

                if(primerOperando < 0 && segundoOperando >= 0){
                    printf("\n\nEl factorial de %d es: No es posible hacer la descomposicion factorial de numeros negativos. Y el factorial de %d es: %d\n", primerOperando, segundoOperando, factorial(segundoOperando));
                } else if (primerOperando >=0 && segundoOperando < 0){
                    printf("\n\nEl factorial de %d es: %d. Y el factorial de %d es: No es posible hacer la descomposicion factorial de numeros negativos.\n", primerOperando, factorial(primerOperando), segundoOperando);
                } else {
                printf("\n\nEl factorial de %d es: %d. Y el factorial de %d es: %d\n", primerOperando, factorial(primerOperando), segundoOperando, factorial(segundoOperando));
                }   // En el caso de que el operando ingresado sea >= 20, se le deberá aplicar un rango de valores mayor (long long) al int. En tal caso, en vez de %d, debería ser %lli desde el scanf en línea 14 o 19.
                volver = 'n';
                break;

            case 'f': /* Una última opción para que se elija si se desea realizar una operación individual o que se muestren todos los resultados.
                       * De este modo, cuando el carácter asignado a la variable "operacion" sea 'f', se utilizarán todas las funciones anteriores.*/

                printf("\n\nEl resultado de %d+%d es: %d\n", primerOperando, segundoOperando, sumar(primerOperando, segundoOperando));
                printf("El resultado de %d-%d es: %d\n", primerOperando, segundoOperando, restar(primerOperando, segundoOperando));
                if(segundoOperando == 0){
                    printf("No es posible dividir por cero\n");
                } else {
                    printf("El resultado de %d/%d es: %d\n", primerOperando, segundoOperando, dividir(primerOperando, segundoOperando));
                }
                printf("El resultado de %d*%d es: %d\n", primerOperando, segundoOperando, multiplicar(primerOperando, segundoOperando));
                if(primerOperando < 0 && segundoOperando >= 0){
                    printf("El factorial de %d es: No es posible hacer la descomposicion factorial de numeros negativos. Y el factorial de %d es: %d\n", primerOperando, segundoOperando, factorial(segundoOperando));
                } else if (primerOperando >=0 && segundoOperando < 0){
                    printf("El factorial de %d es: %d. Y el factorial de %d es: No es posible hacer la descomposicion factorial de numeros negativos.\n", primerOperando, factorial(primerOperando), segundoOperando);
                }else{
                printf("El factorial de %d es: %d. Y el factorial de %d es: %d\n", primerOperando, factorial(primerOperando), segundoOperando, factorial(segundoOperando));
                }
                volver = 'n';
                break;

            default: /* En caso de que el carácter ingresado no se encuentre dentro de los instruidos, se ejecutará el bucle a partir de un uso
                      * booleano de la variable volver (ver: línea 109 y 113). Se repetirá la operación, volviendo al menu principal para que se ingrese
                      * una opción valida.*/

                printf("\n\nError. Por favor, ingrese una opcion valida.\n");
                volver = 's';
                break;
        }

    }while(volver!='n');

    return 0;
}

/**
 * @author Luciano Cantero, 1A, 41062563, canterofacultad@gmail.com
 */

