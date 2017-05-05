/*
*	@File/archivo 		generadorExamenes.c 
*	@Brief/resumen 		El objetivo del programa es formar 3 módulos que permitan la
*						creación, aplicación y valoración de un examen.
*						El máximo de preguntas admitidas en la base de datos será de 
*						50. 
*						
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	@Date/fecha			01-01-01
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void creadorExamenes(void);
void aplicadorExamenes(void);
void calificadorExamenes(void);

int main(void)
{
	char opcion;	

	system("clear");
	do{
		printf("\n\tBienvenido.\n");
		printf("\tQue deseas, aplicar o hacer un examen?\n");
		printf("\tPresiona una opcion para continuar.\n");
		printf("\t\t1- Crear un examen\n");
		printf("\t\t2- Aplicar un examen.\n");
		printf("\t\ts- Salir del programa.\n");
		printf("\t\tOpcion: ");	
	        scanf("%c", & opcion);
		getchar();
		switch(opcion)
		{
			case '1': creadorExamenes();
				break;
			case '2':aplicadorExamenes();
        			calificadorExamenes();		
				break;
			case 's':break;
			default: system("clear");
				printf("Opcion no valida.\n");	
		}
	}while(opcion!='s'&&opcion!='S');
}


/*
*	@Brief/resumen		La función permite generar un examen basado en las 
*						características que le dé el usuario.
*						Es importante mencionar que cada pregunta e inciso llevará un 
*						formato especial para su lectura en el siguiente 
*						segmento.
*
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	
*	@Return 				void
*/
void creadorExamenes(void){

	FILE *archivoReactivos;
	FILE *archivoExamen;

	char nombreArchivo[30];
	char nombreExamen[40]={"Examen_"};
	char lineaArchivo[300];

	int i;
	int numeroPreguntas;
	int contador_1=0;


	printf("\n-creadorExamenes-\n");

	printf("\nNombre del archivo de reactivos que desea subir: ");
	fgets(nombreArchivo,30,stdin);

	for(i=0;i<=30;i++){

		if(nombreArchivo[i]=='\n') nombreArchivo[i]='\0';
	}

	archivoReactivos=fopen(nombreArchivo,"rt");
	if(archivoReactivos==NULL){printf("no existe el archivo\n"); exit(1);}

	do{
		system("clear");
		printf("Número de preguntas que desea colocar en el examen: ");
		scanf("%d",&numeroPreguntas);
		getchar();
	}
	while(numeroPreguntas<5);

	strcat(nombreExamen,nombreArchivo);

	archivoExamen=fopen(nombreExamen,"wt");

	while((fgets(lineaArchivo,300,archivoReactivos)!=NULL)&&(contador_1<numeroPreguntas)){

		fprintf(archivoExamen,"%d|",contador_1+1);
		fputs(lineaArchivo,archivoExamen);

		contador_1++;
	}

	if(contador_1<5) exit(1);

	printf("\nFue creado el examen (%s) con (%d) preguntas\n",nombreExamen,numeroPreguntas);

	fclose(archivoReactivos);
	fclose(archivoExamen);
}

/*
*	@Brief/resumen		La función permite hacer una recopilación de todas las 			
*						preguntas y las muestra en pantalla.
*						Al principio, se pedirán los datos completos del alumno, nombre 
*						y número de cuenta.
*						Los datos del alumno al concluir el test se verán guardados en 
*						un archivo, en él estarán guardadas las respuestas del alumno. 
*				
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	
*	@Return 				void
*/
void aplicadorExamenes(void){

	FILE *bancoAlumnos;
	FILE *archivoExamen;
	FILE *archivoAlumno;

	char lineaAlumnos[300];
	char numeroCuenta[20];

	char nombreAlumno[100];
	char cuentaAlumno[20];

	char nombreExamen[30];

	char lineaArchivo[300];
	char pregunta[200];	
	char incisoA[100], incisoB[100],  incisoC[100],  incisoD[100];
	char respuesta_correcta, respuesta;
	int valor;
	int numeroPregunta;

	int contador_1=0;
	int resultado=0;
	int i;

	char lineaImprimir[100];

	printf("\tIngresa el nombre del archivo examen.\n");
	bancoAlumnos=fopen("bancoAlumnos.txt","rt");
	if(bancoAlumnos==NULL){printf("no existe el archivo\n"); exit(1);}

	archivoAlumno=fopen("archivoAlumno.txt","wt");


	printf("\n-aplicadorExamenes-\n");

	printf("\nIngrese el nombre del examen: ");
	fgets(nombreExamen,30,stdin);

	for(i=0;i<=30;i++) if(nombreExamen[i]=='\n') nombreExamen[i]='\0';

	puts(nombreExamen);

	archivoExamen=fopen(nombreExamen,"rt");
	if(archivoExamen==NULL){printf("no existe el archivo\n"); exit(1);}

	printf("\nIngrese su número de cuenta: ");
	scanf("%s",numeroCuenta);
	getchar();

	while(fgets(lineaAlumnos,300,bancoAlumnos)!=NULL){

		sscanf(lineaAlumnos,"%[^|]|%s",cuentaAlumno,nombreAlumno);

		if(strstr(lineaAlumnos,numeroCuenta)!=NULL){

			printf("Usuario: %s \n",nombreAlumno);

			strcpy(lineaImprimir,nombreAlumno);
			strcat(lineaImprimir,numeroCuenta);
//IDENTIFICADOR DEL EXAMEN|CUENTA|CALIFICACIÓN|TIEMPO|RESPUESTAS|CORRECTAS(#)|PREGUNTAS(#)|TIEMPO TOTAL| MÁXIMO DE PUNTOS QUE SE PUEDE TENER
		}
	}


	while(fgets(lineaArchivo,300,archivoExamen)!=NULL){

			sscanf(lineaArchivo,"%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%d",&numeroPregunta,pregunta,incisoA,incisoB,incisoC,incisoD,&respuesta_correcta,&valor);

			contador_1++;
	}

		//for(i=0;i<=100;i++) if(lineaImprimir[i]=='\n') lineaImprimir[i]='\t';

		//fprintf(archivoAlumno,"%d ",(resultado*10)/contador_1);
		//fputs(lineaImprimir,archivoAlumno);//IDENTIFICADOR DEL EXAMEN|CUENTA|CALIFICACIÓN|TIEMPO|RESPUESTAS|CORRECTAS(#)|PREGUNTAS(#)|TIEMPO TOTAL| MÁXIMO DE PUNTOS QUE SE PUEDE TENER


	fclose(bancoAlumnos);
	fclose(archivoExamen);
	fclose(archivoAlumno);
}

/*
*	@Brief/resumen		La función permite recibir la información del aplicador de 
*						exámenes, y evalúa las respuestas correctas del alumno y envía 
*						la calificación a un archivo en el cual se tendrá la base de 
*						datos genera.
*			
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	
*	@Return 				void
*/
void calificadorExamenes(void){

	FILE *archivoAlumno;

	char lineaAlumno[50];
	char datosAlumno[30];
	int calificacion;

	archivoAlumno=fopen("archivoAlumno.txt","rt");
	if(archivoAlumno==NULL){printf("no existe el archivo\n"); exit(1);}


	fgets(lineaAlumno,50,archivoAlumno);

	sscanf(lineaAlumno,"%d %s",&calificacion,datosAlumno);

	printf("\n-calificadorExamenes-\n");

	printf("La calificación de %s es de %d \n\n",datosAlumno,calificacion);

	fclose(archivoAlumno);
}

void funcionRand(){

#include<stdio.h>

int main(){
 
    int arreglo[10];
    int aux = 0;
	int i; 

    srand(time(0));
 
    for(i = 0; i < 10; i++){
        aux = rand() % 10 + 1;
 
        int aux2 = 0;
 
        while(aux2 < i){
 
            if(aux != arreglo[aux2])
                aux2++;
 
            else{
                    aux =rand() % 10 + 1;
                    aux2 = 0;
 
                }
        }
 
        arreglo[i] = aux;
 
     printf("%d ",arreglo[i]);
    }
 
    return 0;
}
}



