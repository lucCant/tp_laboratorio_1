#include "funcionesMatematicas.h"

/**
 * @brief Suma 2 variables a+b y devuelve el resultado
 * @param a La primera variable a sumar
 * @param b La segunda variable a sumar
 * @return Resultado de la suma.
 */
int sumar(int a, int b){
    return a + b;
}

/**
 * @brief Resta 2 variables a-b y devuelve el resultado
 * @param a La primera variable a restar
 * @param b La segunda variable a restar
 * @return Resultado de la resta.
 */
int restar(int a, int b){
    return a - b;
}

/**
 * @brief Multiplica 2 variables a*b y devuelve el resultado
 * @param a La primera variable a multiplicar
 * @param b La segunda variable a multiplicar
 * @return Resultado de la multiplicación.
 */
int multiplicar(int a, int b){
    return a * b;
}

/**
 * @brief Divide 2 variables a/b y devuelve el resultado
 * @param a La primera variable a dividir (dividendo)
 * @param b La segunda variable a dividir (divisor)
 * @return Resultado de la división.
 */
int dividir(int a, int b){
    return a / b;
}

/**
 * @brief Realiza la descomposicion factorial de una variable a y devuelve el resultado
 * @param factorial La variable que asegura la repetida multiplicación del valor decreciente de la variable "a" mientras ésta sea mayor a 1.
 * @param a         La variable a descomponer factorialmente.
 * @return Resultado de la descomposición factorial
 */
int factorial(int a){
    int factorial = 1;
    while(a>1){
        factorial = factorial * a;
        a--;
    }
    return factorial;
}


