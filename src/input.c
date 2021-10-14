/*
 * input.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Juan
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "input.h"


int getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar[5];
	int validar;
	int numeroValidado;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
	do
	{
		printf("%s" ,mensaje);
		fflush(stdin);
		scanf("%s" ,&bufferChar);
		validar=validarNumeroEntero(bufferChar ,&numeroValidado);

		if(numeroValidado >= minimo && numeroValidado <= maximo && validar==1)
		{
		 *pResultado = numeroValidado;
          retorno = 0;
          break;
		}
		else
		{
			printf("%s\n", mensajeError);
			reintentos--;
		}
	}while(reintentos >= 0);
}
return retorno;
}


int validarNumeroEntero(char numero[] , int*numerovalido)
{
    int i;


    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {

            return 0;
        }
        if(isdigit(numero[i]))
        {
        *numerovalido=atoi(numero);
        return 1;
        }
    }

}

/*int getString(char *ingresado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=0;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario
    char auxiliar[maximo];
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tamaño de la cadena
    fgets(auxiliar,sizeof(auxiliar),stdin);
    //5.Al ultimo indice le asigno "\0"
    auxiliar[strlen(auxiliar)-1] = '\0';
    //6.si ingresado no es nulo,
    //el tamaño de auxiliar es mayor o igual al minimo y menor o igual al maximo
   // y validar letra devuelve 0 (no hay numeros)
    if(ingresado !=NULL && strlen(auxiliar)>=minimo && strlen(auxiliar)<=maximo && validarLetra(auxiliar)==0)
    {
    	//7.guardo la cadena del auxiliar en el puntero guardar
    	strncpy(ingresado, auxiliar, maximo);
    	//8.Devuelvo 1 porque no hubo errores
    	error=1;
    }else{
    	//9.repito en caso de error
    	while(intentos>0)
    	{
    		printf("%s", mensajeError);
    		fgets(auxiliar,sizeof(auxiliar),stdin);
    		auxiliar[strlen(auxiliar)-1] = '\0';
    		if(ingresado !=NULL && strlen(auxiliar)>=minimo && strlen(auxiliar)<=maximo && validarLetra(auxiliar)==0)
    		{
    			strncpy(ingresado, auxiliar, maximo);
    			error = 1;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}*/

int getString(char cadena[], char mensaje[], char mensajeError[] , int tam)
{
	char auxiliarString[1000];
	int retorno;
	retorno = 0;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 1;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);

		while (strlen(auxiliarString) > tam)
		{
			retorno=-1;
			printf("%s" , mensajeError);
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(cadena, auxiliarString);
		if (strlen(auxiliarString)<tam)
		{
			retorno=1;

		}
	}
	return retorno;
}
/*
float IngresarFlotante(char mensaje[])
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}
int IngresarEntero(char mensaje[])
{
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
*/
int validarLetra(char num[])
{
   int i=0;
   //repite hasta llegar al final de la cadena
   while(num[i] != '\0')
   {
       if (i == 0 && num[i] == '-')
       {
           i++;
           continue;
       }
       if(num[i] < '0' || num[i] > '9')
       {
          return 0;
       }
       i++;
   }
   return 1;
}

void IngresarCuit(char cuit[] , int reintentos)
{
	int bandera;
	int i;
	int largo;


	do{
      bandera=0;
	  printf("Ingrese cuit sin espacios ni guiones:\n");
	  scanf("%s" ,cuit);

	  largo = strlen(cuit);


	  if (largo!=11)
	  {
		  printf("La cantidad de digitos es incorrecta!\nRecuerde que el cuit contiene 11 digitos!! \n");
	  }
	  if(largo==11){

	  for(i=0; i<11; i++)
	  {
		  if(!(isdigit(cuit[i])))
		  {
			  bandera=-1;
		  }
	  }
	  if(bandera==-1)
	  {
		  printf("ERROR!! El cuit no puede contener letras!!\n");
	  }
	  if (bandera == 0)
	  {
	  printf("El Cuit se cargo correctamente! \n");
	  reintentos=0;
	  }
	  }
	}
	while(reintentos>0);

}

