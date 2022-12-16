#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

/*- Una empresa quiere implementar un sistema de registro de empleados, con sus nombres, puestos y sus horas de entrada y salida. 
Realiza un programa que permita realizar varias opciones, como ingresar un nuevo empleado (sólo alguno con un puesto determinado), 
fichar una entrada o salida (uno mismo), ver el resumen de horarios por empleados. 
Todo ello se podría gestionar mediante un código de empleado, dependiendo de la acción a realizar.


NOMBRES DE LOS COMPONENTES DEL PORYECTO: Alex Valdelvira Muñoz, Tomas Woodward Marín, Carlos Hurtado Baeza. */


void cleanbuffer()
{
  while(getchar() !='\n'){;}
  
}



// este struct sirve para almacenar los datos relacionados con los empleados
typedef struct 
{	
	char nombre_completo[35];
	char quejas[140];
	int entrada;
	int salida;
	int horas_totales;
	int sueldo;
	int meses;
	char puesto[17];
	

}Templeados;



//Este módulo sirve para inicializar la contraseña para acceder al menú del empleado
void inicializar_codigo_empleado(char empleado[])
{
	 	sprintf(empleado,"Empleado01");
}


//Este módulo sirve para inicializar la contraseña para acceder al menú del director
void inicializar_codigo_Director(char director[])
{
	sprintf(director,"Director01");
}


//Este módulo sirve para inicializar los nombres de los trabajadores que hay en la empresa hasta la fecha
void inicializar_empleados(Templeados em[])
{
	sprintf(em[0].nombre_completo,AMARILLO_T "Tomás"RESET_COLOR);
	sprintf(em[1].nombre_completo,AMARILLO_T "María"RESET_COLOR);
 	sprintf(em[2].nombre_completo,AMARILLO_T "Carlos"RESET_COLOR);
 	sprintf(em[3].nombre_completo,AMARILLO_T "Carolina"RESET_COLOR);
 	sprintf(em[4].nombre_completo,AMARILLO_T "Alex"RESET_COLOR);
 	sprintf(em[5].nombre_completo,AMARILLO_T "Rosana"RESET_COLOR);
}


//Este módulo sirve para inicializar los puestos de los trabajadores que hay en la empresa hasta la fecha
void inicializar_puestos(Templeados em[])
{
	sprintf(em[0].puesto,"Ingeniero");
	sprintf(em[1].puesto,"Ingeniera");
 	sprintf(em[2].puesto,"Ventas");
 	sprintf(em[3].puesto,"Ventas");
 	sprintf(em[4].puesto,"Logística");
 	sprintf(em[5].puesto,"Logística");
}


//Este módulo sirve para inicializar los meses que llevan los trabajadores que hay en la empresa hasta la fecha
void inicizar_meses(Templeados em[])
{

	  em[0].meses= 12;
	  em[1].meses= 10;
	  em[2].meses= 6;
	  em[3].meses= 20;
	  em[4].meses= 3;
	  em[5].meses= 1;
	  em[6].meses= 1;
	  em[7].meses= 1;
	  em[8].meses= 1;
	
}

//Este módulo sirve para inicializar en 0 todos los valores de fichar las entradas y las salidas cuando no se han introducido datos
void inicializar_entradas_salidas(Templeados em[])
{
	int i;
	for (i=0;i<=8;i++)
	{
		em[i].entrada = 0;	
	}

	for (i=0;i<=8;i++)
	{
		em[i].salida = 0;	
	}
	
}

//Este módulo sirve para inicializar en 0 todos los valores de los sueldo cuando no se han introducido datos
void inicializar_sueldos(Templeados em[])
{
	int i;
	for (i=0;i<=8;i++)
	{
		em[i].sueldo = 0;

	}
	
}


//Este módulo sirve para inicializar en 0 todos los valores las horas totales trabajadas en un dia cuando no se han introducido datos
void inicializar_horas_totales(Templeados em[])
{
	int i;
	for(i=0;i<=8;i++)
	{

		em[i].horas_totales = 0;



	}
}


//Este módulo sirve para inicializar en -- todos los valores las quejas cuando no se han introducido datos
void inicializar_quejas(Templeados em[])
{
	int i;
	for(i=0;i<=8;i++)
	{
		sprintf(em[i].quejas,"--");

	}


}

//Este módulo sirve para inicializar en -- todos los valores de los nombres que se pueden añadir cuando no se han introducido datos
void inicializar_nombres_anadidos(Templeados em[])
{
	int i;
	for(i=6;i<=9;	i++)
	{
		sprintf(em[i].nombre_completo,AMARILLO_F "--" RESET_COLOR);
	}
}


//Este módulo sirve para recoger la opcion recogida por teclado y almacenarla en la variable e la cual le restará 1 para que esta pueda ser pasada a los demas módulos para referenciar que arrays quieres rellenar depende el usuario seleccionado
int elegir_empleados(Templeados em[])
{
	int e,rep=0;
	
	do{
		printf(AZUL_T"Elige tu usuario de empleado:\n"RESET_COLOR);
		printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\n7. %s\n8. %s\n9. %s\n",em[0].nombre_completo,em[1].nombre_completo,em[2].nombre_completo,em[3].nombre_completo,em[4].nombre_completo,em[5].nombre_completo,em[6].nombre_completo,em[7].nombre_completo,em[8].nombre_completo);
		scanf(" %i",&e);
		cleanbuffer();
	if(e>9||e<1){
		printf("Usuario incorrecto.\n\n");
		rep=1;
	}
	else{
		rep=0;
	}
	}while(rep==1);

	e-=1;
	return(e);
	printf("\n");
}



//Este módulo sirve para recoger los datos de fichar hora de entrada y salida de cada usuario
void pregunta_horarios(Templeados em[],int e)
{	
	
	printf("Introduce tu hora de entrada y tu hora de salida:\n");
	scanf("%i %i",&em[e].entrada,&em[e].salida);
	cleanbuffer();
	em[e].horas_totales = em[e].salida - em[e].entrada;
	
	if(em[e].horas_totales<0){
		em[e].horas_totales = fabs(em[e].horas_totales);

	} else{
		em[e].horas_totales = em[e].salida - em[e].entrada;
	}

}

//Este módulo sirve para calcular las horas trabajadas por dia y el sueldo de cada persona y almacenarlo estos datos en las arrays horas_totales y sueldo 
int Sueldo_horas(Templeados em[],int e)
{	
		em[e].horas_totales = em[e].salida - em[e].entrada;

	if(em[e].horas_totales<0){
		em[e].horas_totales = fabs(em[e].horas_totales);

	}else{
		em[e].horas_totales = em[e].salida - em[e].entrada;
	}
		em[e].sueldo = (10 * em[e].horas_totales *25 );

		printf("Has trabajado %i horas por día, por lo tanto a 10€ la hora tu sueldo es de %i euros mensuales\n", em[e].horas_totales, em[e].sueldo);

	
}


//Este módulo sirve para imprimir el formato de horarios dependiendo de la cantidad de horas trabajadas por dia usando los valores de cada trabajador de entrada y salida
void imprimir_horarios(Templeados em[],int e)
{	
	int i;
	

		if(em[e].horas_totales >= 8 || em[e].horas_totales==0){

		
		printf(VERDE_T"\t   Lu\t   Ma\t   Mi\t   Ju\t   Vi\t   Sa\t   Do\n" RESET_COLOR);
		for(i=0;i<=4;i++)
			{
				printf(ROJO_T"Semana%i\t"RESET_COLOR   "  %i-%i\t   %i-%i\t   %i-%i\t   %i-%i\t    %i-%i   //\t   //\t\n",i,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida);

			}
  	}
  	else{

  	printf("\t   Lu\t   Ma\t   Mi\t   Ju\t   Vi\t   Sa\t   Do\n");
			for(i=0;i<=4;i++)
			{
				printf("Semana%i\t   //\t   //\t   %i-%i   %i-%i    %i-%i   %i-%i   %i-%i\n",i,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida);

			}

  	}
}





//Este modulo sirve para llamar a los módulos que estan introducidos dentros del menú empleados
void menu_empleados(Templeados em[],int e)
{	

	int opcion,i; 
	int calculo_aumento;

	
	
	do{
		printf("Introduce la operación que quieres hacer:  " VERDE_T "  1-Ver sueldo actual y horas trabajadas  "  MAGENTA_T "2-Ver horario  " CYAN_T "3-Pedir aumento  " BLANCO_T  "4-Introducir quejas  " ROJO_T "5-Volver  " VERDE_T "6-Introducir tu horario:  \n"RESET_COLOR);
		scanf("%i",&opcion);
		cleanbuffer();

		switch(opcion){

		case 1:
			 Sueldo_horas(em,e);
			 break;
		case 2:
			 imprimir_horarios(em,e);
			 break;
		case 3: 
			calculo_aumento = em[e].sueldo * em[e].meses;
			if (calculo_aumento >= 36000){
				printf("ENHORABUENA, te mereces un aumento de sueldo, a partir de ahora cobrarás las horas a 13€ en vez de a 10€\n");
			}
			else{

				printf("Lo siento por el momento NO mereces un aumento de sueldo, sigue trabajando duro\n");
			} 
			 break;
		case 4: 
			printf("Introduce a continuación la queja que quieres introducir:\n");
			scanf("%[^\n]s",em[e].quejas);
			break;
		case 5: 
			break;
		case 6:
				pregunta_horarios(em,e);
			break;
		default:
			printf("Opción incorrecta");

		}

	}while(opcion != 5);
}



//Este módulo sirve para eliminar a los usuarios que ya estaban en la empresa desde hace meses
void eliminar_usuarios(Templeados em[])
{
	int elim;
	printf("Que usuario quieres eliminar?\n");
	printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\n",em[0].nombre_completo,em[1].nombre_completo,em[2].nombre_completo,em[3].nombre_completo,em[4].nombre_completo,em[5].nombre_completo);
	scanf("%i",&elim);
	cleanbuffer();
	switch(elim)
	{
	case 1:
		sprintf(em[0].nombre_completo,"--");
		sprintf(em[0].puesto,"--");
		sprintf(em[0].quejas,"--");
		em[0].horas_totales = 0;
		em[0].sueldo = 0;
		em[0].meses = 0;
		em[0].entrada = 0;
		em[0].salida = 0;
		break;

	case 2:
		sprintf(em[1].nombre_completo,"--");
		sprintf(em[1].puesto,"--");
		sprintf(em[1].quejas,"--");
		em[1].horas_totales = 0;
		em[1].sueldo = 0;
		em[1].meses = 0;
		em[1].entrada = 0;
		em[1].salida = 0;
		break;

	case 3:
		sprintf(em[2].nombre_completo,"--");
		sprintf(em[2].puesto,"--");
		sprintf(em[2].quejas,"--");
		em[2].horas_totales = 0;
		em[2].sueldo = 0;
		em[2].meses = 0;
		em[2].entrada = 0;
		em[2].salida = 0;
		break;

	case 4:
		sprintf(em[3].nombre_completo,"--");
		sprintf(em[3].puesto,"--");
		sprintf(em[3].quejas,"--");
		em[3].horas_totales = 0;
		em[3].sueldo = 0;
		em[3].meses = 0;
		em[3].entrada = 0;
		em[3].salida = 0;
		break;

	case 5:
		sprintf(em[4].nombre_completo,"--");
		sprintf(em[4].puesto,"--");
		sprintf(em[4].quejas,"--");
		em[4].horas_totales = 0;
		em[4].sueldo = 0;
		em[4].meses = 0;
		em[4].entrada = 0;
		em[4].salida = 0;
		break;	

	case 6:
		sprintf(em[5].nombre_completo,"--");
		sprintf(em[5].puesto,"--");
		sprintf(em[5].quejas,"--");
		em[5].horas_totales = 0;
		em[5].sueldo = 0;
		em[5].meses = 0;
		em[5].entrada = 0;
		em[5].salida = 0;
		break;
	default:
			printf("Opción incorrecta");
	}
}


//Este modulo sirve para agregar usuarios nuevos y rellenarlos en los espacios libres del array
void agregar_usuarios(Templeados em[])
{
	int agregar;
	printf(AZUL_T"Que usuario quieres agregar?\n"RESET_COLOR);
	printf(AMARILLO_T"1.Natalia \n2. Ana \n3. Jose \n"RESET_COLOR);
	scanf("%i",&agregar);
	cleanbuffer();
	switch(agregar)
	{
	case 1:
		sprintf(em[6].nombre_completo,AMARILLO_T"Natalia"RESET_COLOR);
		sprintf(em[6].puesto,"Administrativo");
		em[6].meses = 1;
		break;

	case 2:
		sprintf(em[7].nombre_completo,AMARILLO_T"Ana"RESET_COLOR);
		sprintf(em[7].puesto,"Administrativo"RESET_COLOR);
		em[7].meses = 1;
		break;

	case 3:
		sprintf(em[8].nombre_completo,AMARILLO_T"Jose"RESET_COLOR);
		sprintf(em[8].puesto,"Marketing");
		em[8].meses = 1;
	break;

	default:
		printf("Opción incorrecta");
}




}


//Este modulo sirve para que el director pueda imprimir el resumen de todos los datos de los empleados de u
void imprimir_datos(Templeados em[])
{ 
		printf("\n");	
		for(int i=0;i<=8;i++)
		{
			printf("PUESTOS [%s] = %s\n",em[i].nombre_completo,em[i].puesto);

		}


		printf("\n");	
		for(int i=0;i<=8;i++)
		{
			printf("HORAS TRABAJADAS[%s] = %d\n",em[i].nombre_completo,em[i].horas_totales);

		}		


		printf("\n");	
		for(int i=0;i<=8;i++)
		{
			printf("SUELDO[%s] = %i€\n",em[i].nombre_completo,em[i].sueldo);

		}


		printf("\n");	
		for(int i=0;i<=8;i++)
		{
			printf("MESES TRABAJADOS[%s] = %i\n",em[i].nombre_completo,em[i].meses);

		}


		printf("\n");	
		for(int i=0;i<=8;i++)
		{
			printf("QUEJAS DE[%s] = %s\n",em[i].nombre_completo,em[i].quejas);

		}

		printf("\n");	
		for(int i=0;i<=8;i++)
		{
			printf("HORARIO DE[%s] = %i-%i\n",em[i].nombre_completo,em[i].entrada,em[i].salida);
			printf("\n");
		}

}


void modulo_director (Templeados em[],int e) {

	int seleccionar_director;	
	char respuesta;

	do {	

		printf(AZUL_T"Estas son las funciones disponibles para tu cargo en la empresa:\n"RESET_COLOR);
		printf(AMARILLO_T" 1 - Contratar trabajadores\n 2 - Despedir trabajadores\n 3 - Ver datos de la empresa\n"RESET_COLOR);
		printf("¿Que funcion quieres desempeñar?: \n\n");	
		scanf("%i", &seleccionar_director);
		cleanbuffer();
		
		switch (seleccionar_director) {

			case 1: 
				printf(AZUL_T"A continuación podrás contratar a nuevos empleados\n"RESET_COLOR); 
				agregar_usuarios(em);
			break;                          

			case 2: 
				printf(AZUL_T"A continuación podrás despedir a tus empleados\n"RESET_COLOR); 
				eliminar_usuarios(em);
			break;

			case 3: 
				printf(AZUL_T"A continuación verás los datos de tus empresa\n"RESET_COLOR);
				imprimir_datos(em);
			break;

		default:
			printf("Opción incorrecta");
		

		}

		printf("¿Quieres cerrar sesion como jefe? s/n: "); 
		scanf("%c", &respuesta);
		cleanbuffer();

	} while (respuesta == 'n' || respuesta == 'N');

}




int main(){

  char inicio[20]; char codigo_empleado[20];char codigo_Director[20];

	char volver,reintentar;
	int emp;

	Templeados em[9];
printf("     /\\      | |         (_)     (_)   | |              | |                                                   					\n");
printf("    /  \\   __| |_ __ ___  _ _ __  _ ___| |_ _ __ __ _   | |_ _   _    ___ _ __ ___  _ __  _ __ ___  ___  __ _ 					\n");
printf("   / /\\ \\ / _` | '_ ` _ \\| | '_ \\| / __| __| '__/ _` |  | __| | | |  / _ \\ '_ ` _ \\| '_ \\| '__/ _ \\/ __|/ _` |	\n");
printf("  / ____ \\ (_| | | | | | | | | | | \\__ \\ |_| | | (_| |  | |_| |_| | |  __/ | | | | | |_) | | |  __/\\__ \\ (_| |		  \n");
printf(" /_/    \\_\\__,_|_| |_| |_|_|_| |_|_|___/\\__|_|  \\__,_|   \\__|\\__,_|  \\___|_| |_| |_| .__/|_|  \\___||___/\\__,_|	\n");
printf("                                                                                   | |                        					\n");
printf("                                                                                   |_|                        		      \n");

	inicializar_nombres_anadidos(em);
	inicializar_entradas_salidas(em);
	inicializar_sueldos(em);
	inicializar_horas_totales(em);
	inicializar_quejas(em);
	inicializar_empleados(em);
	inicializar_puestos(em);
	inicizar_meses(em);
	inicializar_codigo_Director(codigo_Director);
	inicializar_codigo_empleado(codigo_empleado);
	
	printf("%s\n",codigo_Director);
	printf("%s\n",codigo_empleado);

	do{

		printf(AZUL_T"INGRESE SU CODIGO: \n"RESET_COLOR );
		scanf("%s",inicio);
	  cleanbuffer();

		if(strcmp(inicio,codigo_empleado)==0)
		{
						
			do{
					emp=elegir_empleados(em);
					menu_empleados(em,emp);
					printf(AZUL_T"Quieres entrar en otro usuario?[s/n]\n"RESET_COLOR);
					scanf("%c",&volver);
				  cleanbuffer();

			}while(volver != 'n');

		}else if(strcmp(inicio,codigo_Director)==0)
		{
			modulo_director(em,emp);
			

		}else
		{
			printf(ROJO_T"Codigo Incorrecto\n"RESET_COLOR);
		}	


		printf("Quieres comenzar de nuevo? [s|n]");
		scanf("%c",&reintentar);

			
	}while(reintentar!='n');	
	return 0;
}
