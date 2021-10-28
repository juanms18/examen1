/*
 ============================================================================
 Name        : Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "input.h"
#include "cliente.h"


int main(void)
{
	setbuf (stdout, NULL);


		int opcion;
		int leerOpcion;
	    int llamaFuncion;
	    float promedio;


		eCliente listaClientes[CANTIDADDECLIENTES] =
		{
				{1,"jose","30707857478","elizalde 506" ,"caba" ,1,FULL},
				{2,"juan","30707857478","corrientes 506" ,"caba" ,1,FULL},
				{3,"lucas","30707857478","pasco 1276" ,"CABA" ,1,FULL}//,
				//{4,"dsadjose","30707857478","elizdasdalde 506" ,"las" ,1,FULL}
		};


		ePedido losPedidos[CANTIDADDEPEDIDOS] =
		{
				{1,1,500555,EMPTY,1,150,200,100},
				{3,2,56565,EMPTY,1,120,100,34},
				{1,3,56565,FULL,1,3000,1500,569}

		};

		//InicializarIdYListaClientes ( listaClientes, CANTIDADDECLIENTES);
		//InicializarIdYListaClientes(losPedidos, CANTIDADDEPEDIDOS);


		do {

		printf("1.  Alta de cliente.\n");
		printf("2.  Modificar datos de cliente.\n");
		printf("3.  Baja de cliente.\n");
		printf("4.  Crear pedido de recoleccion.\n");
		printf("5.  Procesar residuos.\n");
		printf("6.  Imprimir clientes con pendidos pendientes de procesar.\n");
		printf("7.  Imprimir pedidos pendientes.\n");
		printf("8.  Imprimir pedidos procesados.\n");
		printf("9.  Pedidos pendientes en la localidad solicitada.\n");
		printf(	"10.Imprimir Cantidad de kilos de de polipropileno reciclado promedio por cliente.\n");
		printf("11. Salir\n");

		leerOpcion = getInt(&opcion, "Ingrese  una opcion del menu.\n",	"Cuidado!! --> La opcion ingresada no es valida!!\n", 1, 11, 3);
		if (leerOpcion == -1)
		{
			printf("¡¡¡¡Ingreso demasiados intentos erroneos!!!!");
			break;
		}

		switch (opcion)
		{
		case 1:
			llamaFuncion = CargarClientes(listaClientes, CANTIDADDECLIENTES);

			if (llamaFuncion == -1)
			{
				printf("ERROR!! El cliente no puede cargarse!!\nNo quedan mas lugares para cargar!!!\n\n\n");
				system("pause");
			}

			break;
		case 2:

			llamaFuncion = ModificarDatosCliente(listaClientes , CANTIDADDECLIENTES);
			if(llamaFuncion==1){
				printf("El cliente fue modificado con exito!\n");
			}
			if(llamaFuncion==0)
			{
				printf("El cliente no se pudo modificar o no existe!\n");

			}
            system("pause");
			break;


		case 3:

			llamaFuncion = DarDeBajaUnCliente(listaClientes,	CANTIDADDECLIENTES);

			if (llamaFuncion == 1) {
				printf("El cliente fue dado de baja con exito!\n");
			}
			if (llamaFuncion == 0) {
				printf("El cliente no se dio de baja o no existe!!\n");

			}
			system("pause");
			break;


		case 4:

			llamaFuncion = igresarPedidos(losPedidos , listaClientes ,CANTIDADDEPEDIDOS , CANTIDADDECLIENTES);
			if (llamaFuncion == 0)
			{
				printf("ERROR!! El pedido no puede cargarse!!\nEl id del cliente es incorrecto!!!\n\n\n");
				system("pause");


			}
			if(llamaFuncion == 1)
			{
				printf("El pedido fue cargado correctamente!!\n");
				system("pause");
			}
			break;

		case 5:
          llamaFuncion = ProcesarResiduos(losPedidos , CANTIDADDEPEDIDOS);
			if (llamaFuncion == 1)
			{
				printf("La carga fue exitosa!\n");
			}
			if (llamaFuncion == 0)
			{
				printf("ERROR!  No se pudieron guardar los datos!!\n");

			}
			system("pause");
			break;


		case 6:
			MostrarListadoClientesConPedidos (losPedidos, listaClientes, CANTIDADDEPEDIDOS, CANTIDADDECLIENTES);
			system("pause");
			break;


		case 7:
			 MostrarPedidosPendientes(losPedidos , listaClientes ,CANTIDADDEPEDIDOS, CANTIDADDECLIENTES);
			 system("pause");
			break;


		case 8:
			MostrarPedidosProcesados(losPedidos , listaClientes ,CANTIDADDEPEDIDOS, CANTIDADDECLIENTES);
			system("pause");
			break;


		case 9:

			llamaFuncion = CantidadDePedidosPorLocalidad(losPedidos , listaClientes ,CANTIDADDEPEDIDOS, CANTIDADDECLIENTES);
			 if(llamaFuncion==0)
			 {
				 printf("No hay pedidos pendientes para esa localidad!\n");
				 system("pause");
			 }
			 else
			 {
				 printf("La cantidad de pedidos pendientes para esa localidad es %d\n", llamaFuncion);
				 system("pause");
			 }

			break;
		case 10:
			/*promedio = CantidadKilosPPPromedioPorCliente(listaClientes, losPedidos, CANTIDADDECLIENTES , CANTIDADDEPEDIDOS);
			printf("El promedio de kilos reciclados de pp por cliente es %.2f kg por cliente.\n" ,promedio);
			system("pause");*/
			ClientesConMasPedidosPendientes(listaClientes , losPedidos, CANTIDADDECLIENTES , CANTIDADDEPEDIDOS);
			break;





		}

	} while (opcion != 11);
	return EXIT_SUCCESS;
}
