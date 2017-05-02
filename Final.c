
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


