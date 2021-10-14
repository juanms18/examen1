/*
 * pedidos.c
 *
 *  Created on: 14 oct. 2021
 *      Author: Juan
 */


#include "pedidos.h"


void InicializarIdYEstadoPedidos (ePedido listaPedidos[] , int tam)
{
  for (int i = 0; i < tam; i++)
    {
      listaPedidos[i].idPedido = EMPTY;
      listaPedidos[i].isEmpty = EMPTY;
      listaPedidos[i].pp = EMPTY;


    }
}


int BuscarPrimerEspacioLibrePedidos(ePedido losPedidos[],  int tam)
{
  int i;
  int index;

  index = -1;
  for (i=0; i < tam; i++)
    {
      if (losPedidos[i].isEmpty == EMPTY)
	{
	  index = i;
		  break;
	}
    }
  return index;
}

ePedido IngresarUnPedido()
{
	ePedido elPedido;


	getInt(&elPedido.kilos, "Ingrese la cantidad de kilos que se recolectaran:\n", "ERROR!! Cantidad de kilos exedidos o dato ingresado erroneo!\n", 1, 90000000, 3);
	elPedido.isEmpty=FULL;
	elPedido.estado=EMPTY;

	return elPedido;
}

int MostrarListadoDePedidos (ePedido Pedidos[], int tam)
{
    int retorno = -1;
    printf ("ID Pedido\tID Cliente\tCantidad de kg.\t     Estado del pedido\n");

      for (int i = 0; i < tam; i++)
      {
      if (Pedidos[i].isEmpty == FULL)
      {
	      MostrarPedido(Pedidos[i]);
	     retorno = 0;
	  }
    }
    return retorno;
}

void MostrarPedido (ePedido unPedido)
{
	if(unPedido.estado==EMPTY)
	{
       printf ("   %-15d %-15d  %-20d PENDIENTE\n",  unPedido.idPedido , unPedido.idCliente , unPedido.kilos);

	}
	if(unPedido.estado==FULL)
	{
	  printf ("   %-15d %-15d  %-20d COMPLETADO\n",  unPedido.idPedido , unPedido.idCliente , unPedido.kilos);

	}

}

int igresarPedidos(ePedido elPedido[] , eCliente elCliente[] , int tamPedido ,  int tamCliente)
{
	int i;
	int j;
	int cliente;
	int index=BuscarPrimerEspacioLibrePedidos(elPedido, tamPedido);
	int retorno=0;

	MostrarListadoClientes (elCliente ,  tamCliente);

	getInt(&cliente, "Ingrese numero de id del cliente seleccionado:\n", "ERROR, cliente desconocido!!\n",1, CANTIDADDECLIENTES, 3);

	for (i = 0; i < tamCliente; i++)
	{
      if(elCliente[i].idCliente == cliente && elCliente[i].isEmpty == FULL)
      {
    	  elCliente[i].idPedido=FULL;
        for(j=0; j<tamPedido; j++)
        {
           if(index != -1  )
           {
        	   elPedido[index]=IngresarUnPedido();
        	   elPedido[index].idPedido = index+1;
        	   elPedido[index].idCliente = i+1;
        	   retorno=1;
        	   break;
           }
        }
      }
	}
  return retorno;
}

int ProcesarResiduos(ePedido elPedido[] , int tam)
{

	int pedidoSeleccionado;
	int i;
	int retorno=0;

	MostrarListadoDePedidos (elPedido, tam);

	getInt(&pedidoSeleccionado, "Ingrese numero de ID pedido:\n", "ERROR, ID pedido desconocido!!\n",1, CANTIDADDECLIENTES, 3);

	for(i=0; i<tam; i++)
	{
	if(elPedido[i].idPedido == pedidoSeleccionado && elPedido[i].isEmpty == FULL)
	{
		elPedido[i].estado = FULL;
		IngresarCantidadDeKg();
		retorno=1;
	}

	}
return retorno;
}

ePedido IngresarCantidadDeKg()
{
	ePedido unPedidoCantidad;

	getInt(&unPedidoCantidad.hdpe, "Ingrese la cantidad de POLIETILENO DE ALTA DENSIDAD pocesado:\n", "ERROR, dato ingresado erroneo!!\n",1, 50000000, 3);
	getInt(&unPedidoCantidad.ldpe, "Ingrese la cantidad de POLIETILENO DE BAJA DENSIDAD pocesado:\n", "ERROR, dato ingresado erroneo!!\n",1, 50000000, 3);
	getInt(&unPedidoCantidad.pp, "Ingrese la cantidad de POLIPROPILENO procesado:\n", "ERROR, dato ingresado erroneo!!\n",1, 50000000, 3);
	unPedidoCantidad.estado = FULL;
}

int MostrarListadoClientesConPedidos (ePedido elPedido[] , eCliente elCliente[] , int tamPedido ,  int tamCliente)
{
    int retorno = -1;
    int i;
	int j;

    printf ("Nombre\t\t\t\t\tCuit\t\tDireccion\t\t\tLocalidad\t\tID Cliente \t\t\ID Pedido \tEstado \n");
      for ( i = 0; i < tamCliente; i++)
      {
      if (elCliente[i].isEmpty == FULL && elCliente[i].idPedido == FULL )
      {
    	  MostrarClienteEstado(elCliente[i]);
	      for(j=0 ; j<tamPedido; j++)
	      {

           if(elCliente[i].idCliente==elPedido[j].idCliente && elPedido[j].estado==EMPTY)
           {

        	   MostrarPedidoEstado (elPedido[j]);

           }

	      }
	      retorno = 0;
	  }
    }
    return retorno;
}

void MostrarPedidoEstado (ePedido unPedido)
{
	if(unPedido.estado==EMPTY)
	{
       printf ("   \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %d \t\tPENDIENTE\n",  unPedido.idPedido );
	}

}

void MostrarClienteEstado (eCliente unCliente)
{
  printf ("%-39s %-15s %-31s %-24s  %d\n", unCliente.nombre, unCliente.cuit, unCliente.direccion,  unCliente.Localidad.localidad , unCliente.idCliente);

}


void MostrarPedidosPendientes(ePedido elPedido[] , eCliente elCliente[] , int tamPedido , int tamCliente)
{
	int i;
	int j;

	 printf ("ID Pedido\tEstado\t    Cantidad de Kg a Recolectar \tCuit del cliente\t\tDireccion del cliente\n");
	for (i = 0; i < tamPedido; i++)
	{
	  if(elPedido[i].isEmpty == FULL && elPedido[i].estado == EMPTY)
	  {
		  for(j=0; j<tamCliente ; j++)
		  {
			  if(elCliente[i].idCliente == elCliente[j].idCliente)
			  {
				  MostrarPedidoPendiente(elPedido[i]);
				  MostrarClientesConPedidosPendientes(elCliente[j]);
			  }
		  }
	  }

  }
}

void MostrarClientesConPedidosPendientes (eCliente unCliente)
{
  printf (" \t\t\t  %-30s  %s \n",  unCliente.cuit, unCliente.direccion);

}

void MostrarPedidoPendiente (ePedido unPedido)
{
	if(unPedido.estado==EMPTY)
	{
       printf ("%d\t\tPENDIENTE\t  %d", unPedido.idPedido , unPedido.kilos );
	}

}

void MostrarPedidosProcesados(ePedido elPedido[] , eCliente elCliente[] , int tamPedido , int tamCliente)
{
	int i;
	int j;

	 printf ("ID Pedido\tEstado\t  Cantidad de Kg HDPE \tCantidad de Kg LDPE\tCantidad de Kg PP\tCuit del cliente\t\tDireccion del cliente\n");
	for (i = 0; i < tamPedido; i++)
	{
	  if(elPedido[i].isEmpty == FULL && elPedido[i].estado == FULL)
	  {
		  for(j=0; j<tamCliente ; j++)
		  {
			  if(elCliente[i].idCliente == elCliente[j].idCliente)
			  {
				  MostrarUnPedidoProcesado(elPedido[i]);
				  MostrarUnClienteConPedidosProcesados(elCliente[j]);
			  }
		  }
	  }

  }
}

void MostrarUnPedidoProcesado (ePedido unPedido)
{
	if(unPedido.estado==FULL)
	{
       printf ("%d\t      COMLETADO\t      %d        \t\t%d  \t  \t\t%d", unPedido.idPedido , unPedido.kilos, unPedido.hdpe, unPedido.ldpe, unPedido.pp );
	}

}

void MostrarUnClienteConPedidosProcesados (eCliente unCliente)
{
  printf (" \t\t  %-30s  %s \n",  unCliente.cuit, unCliente.direccion);

}

int CantidadDePedidosPorLocalidad(ePedido elPedido[] , eCliente elCliente[] , int tamPedido , int tamCliente)
{
 int i;
 int j;
 char localidad[15];
 printf("Ingrese localidad deseada:\n");
 scanf("%s" , localidad);
 int contador=0;

 for(i=0 ; i<tamCliente ; i++)
 {
	 strupr(localidad);
	 strupr(elCliente[i].Localidad.localidad);
	 if(strcmp(elCliente[i].Localidad.localidad,localidad)==0)
	 {
			 for(j=0; j<tamPedido; j++)
		 {
			 if(elPedido[j].estado==EMPTY && elPedido[j].idCliente==elCliente[i].idCliente   )
			 {
				 contador = contador+1;
			 }
		 }
	 }
 }
 return contador;
}

int SumarPP(ePedido losPedidos[], int tam)
{
	int i;
	int acumuladorPP=0;

	for (i = 0; i < tam; i++)
	{
		if (losPedidos[i].isEmpty == FULL)
		{
          acumuladorPP = acumuladorPP+losPedidos[i].pp;

		}
	}
	return acumuladorPP;
}

float CantidadKilosPPPromedioPorCliente(eCliente losClientes[], ePedido losPedidos[] , int tamClientes , int tamPedidos)
{
  int retorno;
  int cantidadClientes;
  float promedio;
  int KgPP;

  cantidadClientes = SumarCantidadDeClientes(losClientes , tamClientes );
  KgPP = SumarPP( losPedidos, tamPedidos);

  promedio = (KgPP/cantidadClientes);


}

