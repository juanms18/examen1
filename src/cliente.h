/*
 * cliente.h
 *
 *  Created on: 9 oct. 2021
 *      Author: Juan
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "input.h"
#include "pedidos.h"


#define FULL 1
#define EMPTY 0
#define CANTIDADDECLIENTES 4
#define CANTIDADDEPEDIDOS 5
typedef struct
{
  int idCliente; //PK
  char nombre[50];
  char cuit[12];
  char direccion[50];
  char localidad[50];
  int idPedido;//FK
  int isEmpty;

} eCliente;

/// @fn int CargarClientes(eCliente[], int)
/// @brief funcion para cargar datos a una estructura
/// @param listaClientes estructura recubida
/// @param tam cantidad de lugares en la structura
/// @return retorna el indice donde se cargaron los datos
int CargarClientes (eCliente listaClientes[], int tam  );

/// @fn void InicializarListaClientes(eCliente[], int)
/// @brief iniciliza en empty todo el array de estructura empty e id
/// @param listaClientes estructura que recibe
/// @param tam
void InicializarIdYListaClientes (eCliente listaClientes[], int tam);

/// @fn int BuscarPrimerEspacioLibre(eCliente[], int)
/// @brief recorre el array de structura listaCliente y busca el rimero vacio
/// @param listaClientes array a recorrer
/// @param tam largo del array
/// @return devuelve -1 si no hay lugares vacios y si encontro alguno devuelve la indice
int BuscarPrimerEspacioLibre (eCliente listaClientes[], int tam);

/// @fn eCliente IngresarUnCliente()
/// @brief cargar los datos de un cliente
/// @return los datos del cliente cargado
eCliente IngresarUnCliente();

/// @fn int MostrarListadoClientes(eCliente[], int)
/// @brief muestra el listado de los clientes cargados
/// @param listaClientes array de estructura que recibe
/// @param tam largo del array
/// @return -1 si no mostro nada y 0 si pudo mostrar
int MostrarListadoClientes (eCliente listaClientes[], int tam);

/// @fn void MostrarCliente(eCliente)
/// @brief lista los datos cargados de un cliente
/// @param unCliente array de structura que recibe para mostrar
void MostrarCliente (eCliente unCliente);


/// @fn int ModificarDatosCliente(eCliente[], int)
/// @brief pide un id y luego solicita nuevos campos de domicilio y localidad para modificar
/// @param listaClientes array que recibe
/// @param tam largo del array
/// @return retorna 1 si pudo modificar y 0 si no pudo
int ModificarDatosCliente(eCliente listaClientes[] , int tam);

/// @fn int DarDeBajaUnCliente(eCliente[], int)
/// @brief pide un id para dar de baja
/// @param listaClientes array que recibe
/// @param tam largo del array
/// @return retorna 1 si pudo dar de baja y 0 si no pudo
int DarDeBajaUnCliente (eCliente listaClientes[] , int tam);


void MostrarClientesConPedidosPendientes (eCliente unCliente);

void MostrarUnClienteConPedidosProcesados (eCliente unCliente);

//int SumarCantidadDeClientes(eCliente losClientes[] , int tam);

#endif /* CLIENTE_H_ */
