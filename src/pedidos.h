/*
 * pedidos.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Juan
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "cliente.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>



#define CANTIDADDEPEDIDOS 5


typedef struct
{
  int idCliente;
  int idPedido;//PK
  int kilos;
  int estado;
  int isEmpty;
  int hdpe;
  int ldpe;
  int pp;

} ePedido;



/// @fn void InicializarIdYEstadoPedidos(ePedido[], int)
/// @brief inicializa el array idPedido idCliente isEmpty en 0
///  @param pedido array que recibe
/// @param tam largo del array
void InicializarIdYEstadoPedidos (ePedido listaPedidos [] , int tam);

/// @fn int BuscarPrimerEspacioLibre del array
/// @brief recorre el array de structura y busca el primero vacio empty
/// @param ePedido array a recorrer
/// @param tam largo del array
/// @return devuelve -1 si no hay lugares vacios y si encontro alguno devuelve el indice
int BuscarPrimerEspacioLibrePedidos(ePedido losPedidos[], int tam);

/// @fn ePedido IngresarUnPedido()
/// @brief pide los datos del pedido
/// @return retorno los datos recibidos
ePedido IngresarUnPedido();

/// @fn int MostrarListadoDePedidos(ePedido[], int)
/// @brief muestra una lista de pedidos
/// @param array de los pedidos que recibe
/// @param tam largo del array que recibe
/// @return retorna 0 si pudo mostrar -1 si no pudo
int MostrarListadoDePedidos (ePedido Pedidos[], int tam);


/// @fn void MostrarPedido(ePedido)
/// @brief muestra un pedido
/// @param unPedido pedido que recibe para mostrar
void MostrarPedido (ePedido unPedido);

/// @fn ePedido IngresarCantidadDeKg()
/// @brief
/// @return
ePedido IngresarCantidadDeKg();

/// @fn int ProcesarResiduos(ePedido[], int)
/// @brief
/// @param elPedido
/// @param tam
/// @return
int ProcesarResiduos(ePedido elPedido[] , int tam);

//int ImprimirClientes (eCliente listaClientes[], ePedido losPedidos[], int tamClientes , int tamPedidos);

//int MostrarListadoClientesConPedidos (ePedido elPedido[] , eCliente elCliente[] , int tamPedido ,  int tamCliente);

void MostrarPedidoPendiente (ePedido unPedido);

void MostrarUnPedidoProcesado (ePedido unPedido);

//

#endif  PEDIDOS_H_

