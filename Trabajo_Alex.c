#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cleanbuffer()
{
  while(getchar() !='\n'){;}
  
}


typedef struct 
{	
	char nombre_completo[35];
	char quejas[140];
	int entrada;
	int salida;
	int horas_totales;
	int sueldo;
	char horarios[4][5];

}Templeados;


int Sueldo_horas(Templeados *opc)
{	
		opc->horas_totales = opc->salida - opc->entrada;

		opc->sueldo = (10 * opc->horas_totales *25 );

		printf("Has trabajado %i horas por lo tanto a 10€ la hora tu sueldo es de %i euros mensuales\n", opc->horas_totales, opc->sueldo);

	
}





int main(){

int opcion;

 Templeados em;


	printf("Introduce tu nombre:\n");
	scanf("%[^\n]s",em.nombre_completo);
	cleanbuffer();
	printf("Introduce tu hora de entrada y tu hora de salida:\n");
	scanf("%i%i",&em.entrada,&em.salida);
	cleanbuffer();
	
do{
	printf("Introduce la operación que quieres hacer: 1-Ver sueldo actual y horas trabajadas   2-Ver horario  3-Pedir aumento  4-Introducir quejas  5-Salir:\n");
	scanf("%i",&opcion);
	cleanbuffer();

	switch(opcion){

	case 1:
		 Sueldo_horas(&em);
		 break;
	case 2: 
		; break;
	case 3: 
		; break;
	case 4: 
		printf("Introduce a continuación la queja que quieres introducir:\n");
		scanf("%[^\n]s",em.quejas);
		break;
	case 5: 
		break;

	}

}while(opcion != 5);

	return 0;
	
}
