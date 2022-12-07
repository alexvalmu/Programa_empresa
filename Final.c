#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{	
	char nombre_completo[35];
	int entrada;
	int salida;
	int horas_totales;
	int sueldo;
	char codigo_empleado[10]

}Templeados;

typedef struct 
{	
	char nombre_completo[35];
	char quejas[140];
	int entrada;
	int salida;
	int horas_totales;
	int sueldo;
	char horarios[4][5];

}TDirector;

void cleanbuffer()
{
  while(getchar() !='\n'){;}
  
}

int Sueldo_horas(Ttrabajador *opc)
{

	opc->horas_totales = opc->salida - opc->entrada;

	opc->sueldo = (10 * opc->horas_totales *25 );

	printf("Has trabajado %i horas por lo tanto a 10€ la hora tu sueldo es de %i euros mensuales\n", opc->horas_totales, opc->sueldo);
}

int main(){

	char inicio[10];
 	int opcion;

	Ttrabajador em;
	TDirector director;

	printf("INGRESE SU CODIGO DE EMPLEADO");
	scanf("%c",&inicio);
	
	if(strcmp(inicio,em->codigo_empleado)==0){
		
		do{
	
			printf("Introduce tu nombre:\n");
			scanf("%[^\n]s",em.nombre_completo);
			cleanbuffer();
			printf("Introduce tu hora de entrada y tu hora de salida:\n");
			scanf("%i%i",&em.entrada,&em.salida);
			cleanbuffer();

			printf("Introduce la operación que quieres hacer: 1-Ver sueldo actual y horas trabajadas   2-Ver horario  3-Pedir aumento  4-Introducir quejas  5-Salir:\n");
			scanf("%i",&opcion);
			cleanbuffer();
				
				switch(opcion){

					case 1:
		 				Sueldo_horas(&em);
		 			break;
					
					case 2: 
					break;
					
					case 3: 
					break;
					
					case 4: 
						printf("Introduce a continuación la queja que quieres introducir:\n");
						scanf("%[^\n]s",em.quejas);
					break;
					case 5: 
					break;

				}

		}while(inicio!=5);

	}else if(strcmp(inicio,director->codigo_director)==0){
		
		do{


		}while(inicio!=4);
	
	}
}