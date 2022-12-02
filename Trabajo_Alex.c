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
	int entrada;
	int salida;
	int horas_totales;
	int sueldo;

}Tinicializar;


int Sueldo_horas(Tinicializar *opc)
{

	opc->horas_totales = opc->salida - opc->entrada;

	opc->sueldo = (10 * opc->horas_totales *25 );

	printf("Has trabajado %i horas por lo tanto a 10€ la hora tu sueldo es de %i euros mensuales\n", opc->horas_totales, opc->sueldo);
}



int main(){

int opcion;

 Tinicializar in;


	printf("Introduce tu nombre:\n");
	scanf("%[^\n]s",in.nombre_completo);
	cleanbuffer();
	printf("Introduce tu hora de entrada y tu hora de salida:\n");
	scanf("%i%i",&in.entrada,&in.salida);
	cleanbuffer();



	printf("Introduce la operación que quieres hacer: 1-Ver sueldo actual y horas trabajadas   2-Ver horario  3-Pedir aumento  4-Introducir quejas  5-Salir:\n");
	scanf("%i",&opcion);
	cleanbuffer();

	switch(opcion){

	case 1:
		 Sueldo_horas(&in);

	 break;
	case 2: ; break;
	case 3: ; break;
	case 4: ;break;
	case 5: break;

}


		












	return 0;
	
}