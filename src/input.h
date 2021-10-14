/*
 * input.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Juan
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @fn int getInt(int*, char*, char*, char, char, int)
/// @brief recibe un numero entero y valida
/// @param pResultado devuelve el numero recibido
/// @param mensaje mensaje solicitando la carga del numero
/// @param mensajeError mensaje informando que el dato ingresado no es un numero o esta fuera de rrango
/// @param minimo rango minimo
/// @param maximo rango maximo
/// @param reintentos cantidad de reintentos
/// @return retorna -1 si no pudo cargar el dato y 0 si lo cargo correctamente.
int getInt(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/// @fn int validarNumeroEntero(char[], int*)
/// @brief valida que el char ingresado sea un numero y lo devuelve como int
/// @param numero char ingresado
/// @param numerovalido int devuelto al puntero indicado
/// @return retorna 0 si era un caracter y 1 si devolvio correctamente el entero
int validarNumeroEntero(char numero[] , int*numerovalido);

/// @fn void IngresarCuit(char[], int)
/// @brief valida si el char ingresado es un numero de 11 digitos cuit o cuil
/// @param cuit que recibe
/// @param reintentos cantida de reintentos para ingresar
void IngresarCuit(char cuit[], int reintentos);

/// @fn int validarLetra(char[])
/// @brief valida que los datos ingresados no sean solo numeros
/// @param num
/// @return
int validarLetra(char num[]);


//int getString(char *ingresado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);

/// @fn int getString(char[], char[], char[], int)
/// @brief carga un strig
/// @param cadena strig que recibe
/// @param mensaje mensaje solicitando la carga
/// @param mensajeError informa cuando se desborda la cadena
/// @param tam largo del string
/// @return 1 si se cargo bien -1 si se desbordo la cadena
int getString(char cadena[], char mensaje[], char mensajeError[] , int tam);

//float IngresarFlotante(char mensaje[]);

//int IngresarEntero(char mensaje[]);

#endif  INPUT_H_
