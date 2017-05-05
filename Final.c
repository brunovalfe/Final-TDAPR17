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


	printf("\n-CreadorExamenes-\n");

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

	while((fgets(lineaArchivo,300,archivoReactivos)!=NULL)&&(contador_1<numeroPreguntas))
	{

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
void aplicadorExamenes(void)
{
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

	if(archivoAlumno=fopen("archivoAlumno.txt","wt")==NULL)
		printf("No existe e")

printf("\tIngresa el nombre del archivo examen.\n");


	printf("\n-AplicadorExamenes-\n");

	printf("\nIngrese el nombre del examen: ");
	scanf("%s", nombreExamen);
	getchar();

	strcat(nombreExamen,'\0');

	if((archivoExamen=fopen(nombreExamen,"rt"))==NULL)
	{
		printf("\tNo existe el archivo.\n"); 
		exit(1);
	}

	printf("\nIngrese su número de cuenta: ");
	scanf("%s",numeroCuenta);
	getchar();

	while(fgets(lineaAlumnos,300,bancoAlumnos)!=NULL)
	{
		sscanf(lineaAlumnos,"%[^,],%s",cuentaAlumno,nombreAlumno);
		if(strstr(lineaAlumnos,numeroCuenta)!=NULL)
		{
			printf("Usuario: %s \n",nombreAlumno);
			strcpy(lineaImprimir,nombreAlumno);
			strcat(lineaImprimir,numeroCuenta);
//IDENTIFICADOR DEL EXAMEN|CUENTA|CALIFICACIÓN|TIEMPO|RESPUESTAS|CORRECTAS(#)|PREGUNTAS(#)|TIEMPO TOTAL| MÁXIMO DE PUNTOS QUE SE PUEDE TENER
		}
	}

	while(fgets(lineaArchivo,300,archivoExamen)!=NULL)
	{
		sscanf(lineaArchivo,"%d%[^,],%[^,]|%[^,],%[^,],%[^,],%c|%d",&numeroPregunta,pregunta,incisoA,incisoB,incisoC,incisoD,&respuesta_correcta,&valor);
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
}
*/

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

