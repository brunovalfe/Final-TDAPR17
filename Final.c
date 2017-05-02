/*
*    @File/archivo       Final.c 
*    @Brief/resumen      El objetivo del programa es formar 3 módulos que permitan la
*                        creación, aplicación y valoración de un examen.
*                        El máximo de preguntas admitidas en la base de datos será de 
*                        50. 
*                        
*    @Author/autor        Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*    @Date/fecha          14-05-17


	Cambio Prueba
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GENERADOR(void);
void APLICADOR(void);
void ERROR(int value);

int main(void)
{
	return 0;
}

/*
*	Generador
*	descripcion:	Esta funcion envia mensajes de error al usuario en caso de
*			ejecutar de manera incorrecta el programa.
*/
void ERROR(int value)
{
	system("clear");	
	if(value==1)
		printf("El archivo indicado no existe. Intentar con uno valido./n");

}

/*
*	Generador
*	descripcion:	En esta funcion se generan los examenes en base a un archivo tipo vcs
*			que funciona como banco de preguntas de un tema. En la funcion se lee
*			cada renglon del archivo, que separa por campos las preguntas, respuestas
*			correctas, respuestas posibles y puntaje por pregunta. La funcion elige 
*			una cantidad (indicada por el usuario) de preguntas del campo y las pega
*			un archivo, cuyo nombre es indicado por el usuario.
*/
void GENERADOR(void)
{
	char seed[30];
	FILE *fp;

	printf("Escribe el nombre del archivo del cual se van a extraer las preguntas.\n");
	scanf("%s",seed);
	getchar();
	if((fp=fopen(seed,"rt"))==NULL)
		ERROR(1);
}

