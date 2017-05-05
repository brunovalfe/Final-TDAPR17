include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento //Definicion de un struct que contiene un char y un puntero.
{
    char pregunta[200];
    char incisoA[50];
    char incisoB[50];
    char incisoC[50];
    char incisoD[50];
    int puntos;
    struct elemento *punt;
};
typedef struct elemento Preguntas;

int Busca_Alumno(char nombre[50],char apellido[25],int cuenta);
int Leer();
int main()
{
    FILE *sal,*Examenin;
    char Linea[250];
    char s[2]= ",";
    char *token;
    char nombre[50],apellido[50];
    int cuenta,x;

        sal =fopen("Examen.txt","w");
			/*
            printf("Copia: %s\n",nuevo->pregunta);
            fprintf(sal ," %s\n",nuevo->pregunta );
            printf("Copia: %s\n",nuevo->incisoA);
            fprintf(sal ," %s\n",nuevo->incisoA );
            printf("Copia: %s\n",nuevo->incisoB);
            fprintf(sal ," %s\n",nuevo->incisoB );
            printf("Copia: %s\n",nuevo->incisoC);
            fprintf(sal ," %s\n",nuevo->incisoC );
            printf("Copia: %s\n",nuevo->incisoD);
            fprintf(sal ," %s\n",nuevo->incisoD );
            printf("Copia: %d\n",nuevo->puntos);
            fprintf(sal ," %d\n",nuevo->puntos );
 			*/
   		fclose(sal);
   
    
    printf("ingresa nombre,apellido y numero de cuenta\n");
    scanf("%s %s %d",nombre,apellido,&cuenta);
    printf("Nombre: %s\nApellido: %s\nCuenta: %d\n",nombre,apellido,cuenta);
    Busca_Alumno(nombre,apellido,cuenta);
    
    return 0;
}


int Leer()
{
	char pregunta[200];
    char incisoA[50];
    char incisoB[50];
    char incisoC[50];
    char incisoD[50];
    int puntos,npreg;
	FILE *in;
	

	printf("Cuantas preguntas quieres? \n");
	scanf("%d",&npreg);
	
	Preguntas *lista=malloc(npreg);
	
	in = fopen("Banco.csv", "r");

	

 	fclose(in);
	
}

int Busca_Alumno(char nombre[50] ,char apellido[50] ,int cuenta)
{
    FILE *Base;
    int x=1;
    char s[2]= ",";
    char *token;
    char Line[250];
    char Datos[225];
    
	Base = fopen("Alumnos.txt","r");
    if (Base==NULL)
	{
		printf("El archivo no existe.\n");
		exit(1);
    }
    while(fgets(Line,sizeof(Line),Base) !=NULL)
    {
        token = strtok(Line, s);
        
        while( token != NULL)
            
        {
            printf("\n" );
            x=strcmp(nombre,token);
            
            if(x==0)
            {
                 printf("El alumno esta en la lista\n");
                
                return x;
            }            
             token = strtok(NULL, s);     
        }
        printf("El Alumno no esta en la lista\n");
        return x;
    }
    
     fclose(Base);
     return x;
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
		//fputs(lineaImprimir,archivoAlumno);//IDENTIFICADOR DEL EXAMEN|CUENTA|CALIFICACIÓN|TIEMPO|RESPUESTAS|CORRECTAS(#)|PREGUNTAS(#)|TIEMPO TOTAL| MÁXIMO DE PUNTO/*
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

/*________________________________________________________________________*/
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

int archivoLineas(char nombreArchivo[30]);
int lineasAleatorias(int numeroAleatorio,int contador,char nombreExamen_1[30]);
int lineasAleatorias2(char nombreExamen_1[30]);
void creadorExamenes(void);
void aplicadorExamenes(void);
void calificadorExamenes(void);

int main(void){

	creadorExamenes();
	aplicadorExamenes();
	calificadorExamenes(); 

}

/*
*	@Brief/resumen		La función permite generar un archivo para leer las líneas.
*
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	
*	@Return 				contador_1: es el contador de líneas por archivo.
*/
int archivoLineas(char nombreArchivo[30]){

	FILE *archivoLineas;
	int contador_1=0;
	char lineaArchivo[300];

	archivoLineas=fopen(nombreArchivo,"rt");
	if(archivoLineas==NULL){

		printf("El archivo %s no existe\n",nombreArchivo);
		exit(1);
	}

	while(fgets(lineaArchivo,300,archivoLineas)!=NULL) contador_1++;

	fclose(archivoLineas);

	return contador_1;

}

/*
*	@Brief/resumen		La función permite leer del parámetro números aleatorios
*						abrir un archivo e imprimirlos aleatoriamente.
*
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	
*	@Return 				valor: valor por pregunt.
*/
int lineasAleatorias(int numeroAleatorio,int contador,char nombreExamen_1[30]){

	FILE *archivo_1;


	int idPregunta;
	char lineaArchivo[500];
	char pregunta[200];	
	char incisoA[100], incisoB[100],  incisoC[100],  incisoD[100];
	char respuesta_correcta, respuesta;
	int valor;

	archivo_1=fopen(nombreExamen_1,"rt");
	if(archivo_1==NULL){

		printf("El archivo (%s) no existe.\n\n",nombreExamen_1);
		exit(1);
	}

	while(fgets(lineaArchivo,500,archivo_1)!=NULL){

			sscanf(lineaArchivo,"%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%d",&idPregunta,pregunta,incisoA,incisoB,incisoC,incisoD,&respuesta_correcta,&valor);

			
			if(numeroAleatorio==idPregunta){
 
				printf("\n\nPregunta (%d):%s\n a)%s\n b)%s\n c)%s\n d)%s \n",numeroAleatorio,pregunta,incisoA,incisoB,incisoC,incisoD,valor);

				printf("->");
				scanf(" %c",&respuesta);

				system("clear");
			}
	}

	fclose(archivo_1);

	if(respuesta==respuesta_correcta)return valor;
	else return 0; 

}

/*
*	@Brief/resumen		La función permite leer del parámetro números aleatorios
*						abrir un archivo e imprimirlos aleatoriamente.
*
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	
*	@Return 				valor: valor por pregunt.
*/
int lineasAleatorias2(char nombreExamen_1[30]){

	FILE *archivo_1;


	int idPregunta;
	char lineaArchivo[500];
	char pregunta[200];	
	char incisoA[100], incisoB[100],  incisoC[100],  incisoD[100];
	char respuesta_correcta, respuesta;
	int valor;

	archivo_1=fopen(nombreExamen_1,"rt");
	if(archivo_1==NULL){

		printf("El archivo (%s) no existe.\n\n",nombreExamen_1);
		exit(1);
	}

	while(fgets(lineaArchivo,500,archivo_1)!=NULL){

			sscanf(lineaArchivo,"%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%d",&idPregunta,pregunta,incisoA,incisoB,incisoC,incisoD,&respuesta_correcta,&valor);

	}

	fclose(archivo_1);

	 return valor; 

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

	FILE *archivo_0;
	FILE *archivo_1;

	int i1;
	int contador_1=0;
	int numeroPreguntas,numeroLineas;
	char nombreArchivo_0[30];
	char nuevoExamen[30]={"Exm_"};
	char lineaArchivo[300];
	

	printf("\n[creadorExamenes]\n");

	printf("\nNombre del archivo a subir: ");
	fgets(nombreArchivo_0,30,stdin);

	for(i1=0;i1<=30;i1++) if(nombreArchivo_0[i1]=='\n') nombreArchivo_0[i1]='\0';

	archivo_0=fopen(nombreArchivo_0,"rt");
	if(archivo_0==NULL){

		printf("El archivo (%s) no existe.\n\n",nombreArchivo_0);
		exit(1);
	}

	numeroLineas=archivoLineas(nombreArchivo_0);

	if(numeroLineas<5) printf("El archivo poseé menos de 5 preguntas.");

	do{
		system("clear");
		printf("\nNúmero de preguntas que desea colocar en el examen: ");
		scanf("%d",&numeroPreguntas);
		getchar();
	}
	while((numeroPreguntas<5)||(numeroLineas<numeroPreguntas));

	strcat(nuevoExamen,nombreArchivo_0);
	archivo_1=fopen(nuevoExamen,"wt");

	i1=0;

	while((fgets(lineaArchivo,300,archivo_0)!=NULL)&&(i1<numeroPreguntas)){

		fprintf(archivo_1,"%d|",contador_1+1);
		fputs(lineaArchivo,archivo_1);
		i1++;
		contador_1++;
	}

	printf("\nSe creó el archivo (%s) con (%d) preguntas\n\n",nuevoExamen,numeroPreguntas);

	fclose(archivo_0);
	fclose(archivo_1);

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

	FILE *archivo_0;
	FILE *archivo_2;

	int i1;
	int contador_1=0,contador_2=0,contador_3=0;
	int idPregunta;
	char nombreExamen_1[30];
	char numeroCuenta[10];
	char lineaAlumnos[100];
	char cuentaAlumno[10],nombreAlumno[30];
	char placaAlumno[500];//IDENTIFICADOR DEL EXAMEN|CUENTA|CALIFICACIÓN|TIEMPO|RESPUESTAS|CORRECTAS(#)|PREGUNTAS(#)|TIEMPO TOTAL| MÁXIMO DE PUNTOS QUE SE PUEDE TENER

	int valor,valor2, valorTotal=0, valorNeto=0;
	int numeroLineas;
	int numeroAleatorio;

    int aux = 0;
	int i;

 	srand(time(0));

	printf("\n[aplicadorExamenes]\n");

	/**/archivo_0=fopen("bancoAlumnos.txt","rt");
	if(archivo_0==NULL){

		printf("El archivo (bancoAlumnos.txt) no existe.\n\n");
		exit(1);
	}

	/**/archivo_2=fopen("informeAlumno.txt","wt");

	printf("\nIngrese el nombre del examen: ");
	fgets(nombreExamen_1,30,stdin);
	for(i1=0;i1<=30;i1++) if(nombreExamen_1[i1]=='\n') nombreExamen_1[i1]='\0';
	puts(nombreExamen_1);

	printf("\nIngrese su número de cuenta: ");
	scanf("%s",numeroCuenta);
	getchar();

	while(fgets(lineaAlumnos,100,archivo_0)!=NULL){

		sscanf(lineaAlumnos,"%[^|]|%s",cuentaAlumno,nombreAlumno);

		if(strstr(lineaAlumnos,numeroCuenta)!=NULL){

			printf("Usuario: (%s) \n",nombreAlumno);

		}
	}

	for(i1=0;i1<=100;i1++) if(placaAlumno[i1]=='\n') placaAlumno[i1]='\t';/**/

	numeroLineas=archivoLineas(nombreExamen_1);

	int arreglo[numeroLineas];

	 for(i = 0; i < numeroLineas; i++){
		    aux = rand() % numeroLineas + 1;
	 
		    int aux2 = 0;
	 
		    while(aux2 < i){
	 
		        if(aux != arreglo[aux2])
		            aux2++;
	 
		        else{
		                aux =rand() % numeroLineas + 1;
		                aux2 = 0;
	 
		            }
		    }
	 
		    arreglo[i] = aux;

  			//printf("%d ",arreglo[i]);
		}

	while(contador_2<numeroLineas){

		numeroAleatorio=arreglo[contador_2];

		valor=lineasAleatorias(numeroAleatorio,contador_3,nombreExamen_1);
		valor2=lineasAleatorias2(nombreExamen_1);

		valorTotal=valorTotal+valor;
		valorNeto=valorNeto+valor2;

		contador_2++;
		contador_3++;
	}


	sprintf(placaAlumno,"%s|%s|%d|TIEMPO|%d|%d|TIEMPO MAX|MAXPT",nombreExamen_1,numeroCuenta,(valorNeto*10)/numeroLineas,numeroLineas,valorNeto);

	fputs(placaAlumno,archivo_2);

	printf("\n\n");

	fclose(archivo_0);
	fclose(archivo_2);

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

	FILE *archivo;

	char lineaArchivo[300];
	char nombreExamen_1[100],numeroCuenta[10];
	char extra1[10],extra2[10],extra3[10];
	int numeroLineas1,numeroLineas2,valorNeto;


	archivo=fopen("informeAlumno.txt","rt");

	fgets(lineaArchivo,300,archivo);

	sscanf(lineaArchivo,"%[^|]|%[^|]|%d|%[^|]|%d|%d|%[^|]|%[^|]",nombreExamen_1,numeroCuenta,&numeroLineas1,extra1,&numeroLineas2,&valorNeto,extra2,extra3);

	printf("\nLa calificación de (%s) es de (%d)\n\n",numeroCuenta,numeroLineas1);

	fclose(archivo);
}
