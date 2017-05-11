/*
*	@File/archivo 		generadorExamenes.c 
*	@Brief/resumen 		El objetivo del programa es formar 3 módulos que permitan la
*						creación, aplicación y valoración de un examen.
*						El máximo de preguntas admitidas en la base de datos será de 
*						50. 						
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	@Date/fecha		10-5-17
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>

char CSORT(int num);
void RVALUE(int numlin, int rv[]);
void RVALANS(int numlin, int rv[]);

void creadorExamenes(void);
void aplicadorExamenes(void);
void calificadorExamenes(void);
int archivoLineas(char nombreArchivo[30]);
int lineasAleatorias(int numeroAleatorio,int contador,char nombreExamen_1[30]);
int lineasAleatorias2(char nombreExamen_1[30]);

struct ainfo{
	char l;
	char ans[35];
};

typedef struct bracket{
	int qnum;	
	char q[75];
	struct ainfo cans;
	struct ainfo b;
	struct ainfo c;
	struct ainfo d;
	int pts;
}quinfo;

int main(void)
{
	char opcion;	

	do{
		system("clear");
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
				break;
			case 's':break;
			default: system("clear");
				printf("Opcion no valida.\n");
		}
	}while(opcion!='s' && opcion!='S');
}


/*
*	@Brief/resumen		La función permite generar un examen basado en las 
*				características que le dé el usuario.
*				Es importante mencionar que cada pregunta e inciso llevará un 
*				formato especial para su lectura en el siguiente 
*				segmento.
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna	
*	@Return 		void
*/
void creadorExamenes(void){

	FILE *fp_in;
	FILE *fp_out;

	int cont;
	int numeroPreguntas,numeroLineas;
	char filename[30];
	char nuevoExamen[30];
	char lineaArchivo[300];

	printf("\n[Creador de Examenes]\n\n");
	printf("\tNombre del archivo a subir: ");
	scanf("%s", filename);
	getchar();
	strcat(filename,"\0");

	if((fp_in=fopen(filename,"rt"))==NULL)
	{
		printf("El archivo '%s' no existe.\n\n",filename);
		exit(1);
	}

	numeroLineas=archivoLineas(filename);
	do{
		system("clear");
		printf("\n[Creador de Examenes]\n\n");
		printf("\tEl archivo cuenta con %d preguntas.\n", numeroLineas);
		printf("\tNúmero de preguntas que desea colocar en el examen (menor o igual a %d): ", numeroLineas);
		scanf("%d",&numeroPreguntas);
		getchar();
		if(numeroPreguntas>numeroLineas)
		{
			printf("\n\tEl numero ingresado no es valido. Presiona enter para ingresar un numero valido.");
			getchar();
		}
	}while(numeroPreguntas>numeroLineas && numeroPreguntas>0);

	printf("\tIngresa el nombre del examen: ");
	scanf("%s", nuevoExamen);
	getchar();
	strcat(nuevoExamen,"\0");
	fp_out=fopen(nuevoExamen,"wt");

	for(cont=0;cont<numeroPreguntas;cont++)
	{
		fgets(lineaArchivo,300,fp_in);
		fprintf(fp_out,"%d,",cont+1);
		fputs(lineaArchivo,fp_out);
	}

	system("clear");
	printf("\nSe creó el archivo '%s' con '%d' preguntas\n\n",nuevoExamen,numeroPreguntas);
	fclose(fp_in);
	fclose(fp_out);
}

/*
*	@Brief/resumen		La función permite hacer una recopilación de todas las 			
*				preguntas y las muestra en pantalla.
*				Al principio, se pedirán los datos completos del alumno, nombre 
*				y número de cuenta.
*				Los datos del alumno al concluir el test se verán guardados en 
*				un archivo, en él estarán guardadas las respuestas del alumno. 
*				
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	
*	@Return 		void
*/
void aplicadorExamenes(void)
{
	int rvalans[4];	
	int cont, cont2, score=0, totscore=0, key=0;;
	char r;
	
	FILE *fpin, *fp_out, *sbank;

	int idPregunta;
	char nombreExamen_1[30];
	char numeroCuenta[10];
	char lineaAlumnos[100], buff[150];
	char cuentaAlumno[10],nombreAlumno[30];
//IDENTIFICADOR DEL EXAMEN|CUENTA|CALIFICACIÓN|TIEMPO|RESPUESTAS|CORRECTAS(#)|PREGUNTAS(#)|TIEMPO TOTAL| MÁXIMO DE PUNTOS QUE SE PUEDE TENER

	int valorNeto=0;
	int numeroLineas;

	double segundos = 0, milis=0;
	struct timeval final, inicio;

 	srand(time(0));
	printf("\n\t[Aplicador de Examenes]\n");
	if((sbank=fopen("bancoAlumnos.csv","rt"))==NULL)
	{
		printf("\tEl banco de alumnos no se encontro.\n\tAgregar un banco de alumnos para continuar.\n\n");
		exit(1);
	}

	printf("\n\tIMPORTANTE: si el alumno ya ha realizado el examen los resultados no seran validos.\n");
	printf("\tIngrese su número de cuenta: ");
	scanf("%s",numeroCuenta);
	getchar();

	while((fgets(lineaAlumnos,100,sbank))!=NULL)
//	while(fscanf(sbank,"%[^,],%[^,],\n",cuentaAlumno,nombreAlumno)>=0)//Forma alternativa de lectura de campos del archivo. Si recibe los campos pero no entra en la condicion 'if((strcmp...)
	{

/**/		sscanf(lineaAlumnos,"%[^,],%[^,],",cuentaAlumno,nombreAlumno);
		if((strcmp(numeroCuenta,cuentaAlumno))==0)
		{

			for(cont=0;cont<30;cont++) 
				if(nombreAlumno[cont]=='\n') 
					nombreAlumno[cont]='\0';	
			printf("\tUsuario: %s\n",nombreAlumno);
			key=1;
			break;
		}
	}
	if(key==0)
	{
		printf("\tEl usuario ingresado no existe.\n");
		exit(1);
	}

	
	printf("\tIngrese el nombre del examen: ");
	scanf("%s", nombreExamen_1);
	getchar();
	strcat(nombreExamen_1,"\0");

	if((fpin=fopen(nombreExamen_1,"rt"))==NULL)
	{
		printf("\tEl examen '%s' no se encontro.\n\n\tIntentar con un examen existente para continuar.\n\n", nombreExamen_1);
		exit(1);
	}

	numeroLineas=archivoLineas(nombreExamen_1);
	quinfo qlist[numeroLineas];//quinfo *qlist=malloc(numeroLineas);
	for(cont=0;cont<numeroLineas;cont++)
	{
		fscanf(fpin,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%d", &qlist[cont].qnum, qlist[cont].q, qlist[cont].cans.ans, qlist[cont].b.ans, qlist[cont].c.ans, qlist[cont].d.ans, &qlist[cont].pts);

//printf("%d, %s, %s, %s, %s, %s, %d\n",qlist[cont].qnum, qlist[cont].q, qlist[cont].cans.ans,qlist[cont].b.ans,qlist[cont].c.ans,qlist[cont].d.ans,qlist[cont].pts);
	}
	//rvalue= malloc(numeroLineas*sizeof(int));
	int rvalue[numeroLineas];
	RVALUE(numeroLineas, rvalue);

	system("clear");
	printf("\tEXAMEN:\n");

	gettimeofday(&inicio, NULL);

	for(cont=0;cont<numeroLineas;cont++)
	{
//printf("%d\n",cont);
		RVALANS(4, rvalans);
		printf("\nPregunta %d:\t\tValor:%d\n",cont+1,qlist[rvalue[cont]].pts);
		printf("%s\n",qlist[rvalue[cont]].q);
		for(cont2=0;cont2<4;cont2++)
		{
			if(rvalans[cont2]==1){
				qlist[rvalue[cont]].cans.l=CSORT(cont2);
				printf("%c) %s\n", qlist[rvalue[cont]].cans.l,qlist[rvalue[cont]].cans.ans);	
			}
			if(rvalans[cont2]==2){
				qlist[rvalue[cont]].b.l=CSORT(cont2);
				printf("%c) %s\n", qlist[rvalue[cont]].b.l,qlist[rvalue[cont]].b.ans);	
			}
			if(rvalans[cont2]==3){
				qlist[rvalue[cont]].c.l=CSORT(cont2);
				printf("%c) %s\n", qlist[rvalue[cont]].c.l,qlist[rvalue[cont]].c.ans);	
			}
			if(rvalans[cont2]==4){
				qlist[rvalue[cont]].d.l=CSORT(cont2);
				printf("%c) %s\n", qlist[rvalue[cont]].d.l,qlist[rvalue[cont]].d.ans);	
			}

		}
		printf("Ingresa el inciso de la respuesta correcta: ");
		scanf("%c", &r);
		getchar();
		if(r == qlist[rvalue[cont]].cans.l)
			score+= qlist[rvalue[cont]].pts;
		totscore+= qlist[rvalue[cont]].pts;
	}
	
	gettimeofday(&final, NULL);
	segundos = (double)(final.tv_usec - inicio.tv_usec) / 1000000 + (double)(final.tv_sec - inicio.tv_sec);
	printf("\n\nTotal: %d\ttotalpuntos: %d\ntiempo: %f segundos\n", score, totscore,segundos);


	if((fp_out=fopen("informeAlumno.txt","rt"))!=NULL)
	{
		while(fgets(lineaAlumnos,100,fpin)!=NULL)
		{
			sscanf(lineaAlumnos,"%[^,],%[^\n],\n",cuentaAlumno, buff);		
			if((strcmp(cuentaAlumno,numeroCuenta))==0)
			{	
				printf("El examen no es valido, ya hay un resultado previo.\n");
				exit(1);
			}
		}
		fclose(fp_out);
	}
	fp_out=fopen("informeAlumno.txt","a");
	
	fprintf(fp_out,"%s,%s,%s,%d,%d,%d,%f,\n",cuentaAlumno,nombreAlumno, nombreExamen_1, (score/totscore*10),totscore, score, segundos); 
	printf("\n\n");
	
	fclose(fpin);
	fclose(fp_out);
}


char CSORT(int cont2)
{
	if(cont2==0)
		return 'A';
	if(cont2==1)
		return 'B';
	if(cont2==2)
		return 'C';
	if(cont2==3)
		return 'D';
}

void RVALUE(int numlin, int rvalue[])//Igual que la funcion RVALANS; pero cambia las direcciones de rvalue[].
{
	int cont,x,aux=0;
	int key;
	srand((unsigned)time(NULL));

	for(cont=0;cont<numlin;cont++)
	{
		key=0;		
		do
		{
			x=rand()%numlin;
			for(aux=0;aux<=cont;aux++)
			{
				if(aux==cont)
				key=1;				
				if(rvalue[aux]==x)
					break;
				
			}
		}while(key==0);
		rvalue[cont]=x;
		//printf("%d  ",rvalue[cont]);	
	}
	return;
}

void RVALANS(int numlin, int rvalans[])//Igual que la funvion RVALUE: pero cambia los valores de RVALANS
{
	int cont=0,x=0,aux=0;
	int key=0;
	srand((unsigned)time(NULL));

	for(cont=0;cont<numlin;cont++)
	{
		key=0;		
		do
		{
			x=rand()%numlin+1;
			for(aux=0;aux<=cont;aux++)
			{
				if(aux==cont)
				key=1;				
				if(rvalans[aux]==x)
					break;
				
			}
		}while(key==0);
		rvalans[cont]=x;
		//printf("%d ",rvalans[cont]);	
	}
	return;
}
	

































/*
*	@Brief/resumen		La función permite recibir la información del aplicador de 
*						exámenes, y evalúa las respuestas correctas del alumno y envía 
*						la calificación a un archivo en el cual se tendrá la base de 
*						datos genera.			
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	@Return 				void
*/

/*
*	@Brief/resumen		La función permite generar un archivo para leer las líneas.
*	@Author/autor		Bruno Valerio Fernández, Abdín Alejandro Alcazar Terán, Benjamín Menchaca Reyna
*	@Return 		contador_1: es el contador de líneas por archivo.
*/
int archivoLineas(char *nombreArchivo)
{

	FILE *Bancopreg;
	int contador_1=0;
	char lineaArchivo[200];

	Bancopreg=fopen(nombreArchivo,"rt");
	while((fgets(lineaArchivo,200,Bancopreg))!=NULL)
	{
		contador_1++;	
	}

	if(contador_1<5)
	{
		printf("\n\tEs recomendable tener un minimo de 5 preguntas escritas en el banco de preguntas.\n\tAgregar mas preguntas o utilizar otro archivo para continuar.\n");
		exit(1);
	}
	fclose(Bancopreg);
	return contador_1;
}


