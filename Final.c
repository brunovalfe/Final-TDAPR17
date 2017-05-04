#include <stdio.h>
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
		//fputs(lineaImprimir,archivoAlumno);//IDENTIFICADOR DEL EXAMEN|CUENTA|CALIFICACIÓN|TIEMPO|RESPUESTAS|CORRECTAS(#)|PREGUNTAS(#)|TIEMPO TOTAL| MÁXIMO DE PUNTOS QUE SE PUEDE TENER


	fclose(bancoAlumnos);
	fclose(archivoExamen);
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



//new test
//mensaje para benja
