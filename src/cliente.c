/*
 * cliente.c
 *
 *  Created on: 9 oct. 2021
 *      Author: Juan
 */


#include "cliente.h"


eCliente IngresarUnCliente()
{
	eCliente cliente;
	getString(cliente.nombre, "Ingrese el nombre del cliente:\n" , "Nombre demasiado largo.Vuelva a intentar:\n", 50);
	IngresarCuit(cliente.cuit , 3);
	getString(cliente.direccion, "Ingrese direccion del cliente:\n" , "Direccion demasiado larga.Vuelva a intentar:\n \n", 50);
	getString(cliente.localidad, "Ingrese la localidad:\n" , "Localidad demasiado larga.Vuelva a intentar:\n", 50);
	cliente.isEmpty=FULL;

	return cliente;
}

int CargarClientes (eCliente listaCliente[], int tam  )
{

  int index = BuscarPrimerEspacioLibre (listaCliente, CANTIDADDECLIENTES);

  if (index != -1)
    {
   listaCliente[index] = IngresarUnCliente();
   listaCliente[index].idCliente= index+1;
   printf("Cliente cargado con exito!! Numero de ID asignado: %d\n", listaCliente[index].idCliente );
   system("pause");
    }

  return index;
  }



void InicializarIdYListaClientes (eCliente listaClientes[], int tam)
{
  for (int i = 0; i < tam; i++)
    {
      listaClientes[i].isEmpty = EMPTY;
      listaClientes[i].idCliente = EMPTY;
    }
}

int BuscarPrimerEspacioLibre (eCliente listaClientes[], int tam)
{
  int i;
  int index;

  index = -1;
  for (i = 0; i < tam; i++)
    {
	 if (listaClientes[i].isEmpty == EMPTY)
	{
	  index = i;
	  break;
	}
    }
  return index;
}

int MostrarListadoClientes (eCliente listaClientes[], int tam)
{
    int retorno = -1;
    printf ("Nombre\t\t\t\t\tCuit\t\tDireccion\t\t\tLocalidad\t\tID\n\n");
      for (int i = 0; i < tam; i++){
      if (listaClientes[i].isEmpty == FULL){
	      MostrarCliente(listaClientes[i]);
	      retorno = 0;
	  }
    }
    return retorno;
}

void MostrarCliente (eCliente unCliente)
{
  printf ("%-39s %-15s %-31s %-24s %-1d\n", unCliente.nombre, unCliente.cuit, unCliente.direccion,  unCliente.localidad , unCliente.idCliente);

}


int ModificarDatosCliente(eCliente listaClientes[] , int tam)
{
	int i;
	int clienteAModificar;
	int retorno;
	int clienteValido;

	retorno=0;

	clienteValido=getInt(&clienteAModificar,"Ingrese ID del cliente que desea modificar:\n", "ERROR!!! El cliente es incorrecto o no existe!", 1, 100, 3);

	 for (i = 0; i < tam; i++)
	    {
		 if(listaClientes[i].isEmpty == FULL && listaClientes[i].idCliente == clienteAModificar && clienteValido == 0)
		 {
			 getString(listaClientes[i].direccion, "Ingrese la nueva direecion:\n" , "Direccion erronea.Vuelva a intentar:\n", 50);
			 getString(listaClientes[i].localidad, "Ingrese la nueva localidad:\n" , "Localidad incorrecta. Vuelva a intentar:\n", 50);
			 retorno = 1;
			 break;
		 }
	    }
	 return retorno;
}

int DarDeBajaUnCliente (eCliente listaClientes[] , int tam)
{
	int i;
	int clienteADarDeBaja;
	int retorno;
	int clienteValido;
    int confirmacion;
	retorno=0;

	clienteValido=getInt(&clienteADarDeBaja,"Ingrese ID del cliente que desea dar de baja:\n", "ERROR!!! El cliente es incorrecto o no existe!", 1, 100, 3);
	getInt(&confirmacion,"Desea confirmar la baja?\n Presione 1 para confirmar o 2 para cancelar:\n", "ERROR!!! El cliente es incorrecto o no existe!", 1, 100, 3);
	if (confirmacion == 1)
	{
		for (i = 0; i < tam; i++)
		{

			if (listaClientes[i].isEmpty == FULL && listaClientes[i].idCliente == clienteADarDeBaja	&& clienteValido == 0)
			{
				listaClientes[i].isEmpty = EMPTY;
				retorno = 1;
				break;
			}
		}
	}
	if(confirmacion==2)
	{
	return retorno;
	}
}

int SumarCantidadDeClientes(eCliente losClientes[] , int tam)

{
 int i;
 int contadorClientes=0;

 for(i=0; i<tam; i++)
 {
	 if(losClientes[i].isEmpty==FULL)
	 {
		 contadorClientes=contadorClientes+1;
	 }
 }

 return contadorClientes;
}

