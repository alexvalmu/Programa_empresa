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
	int meses;
	char puesto[15];
	

}Templeados;




void inicializar_codigo_empleado(char empleado[])
{
	 	sprintf(empleado,"Empleado01");
}

void inicializar_codigo_Director(char director[])
{
	
 		sprintf(director,"Director01");
}

void inicializar_empleados(Templeados em[])
{
	sprintf(em[0].nombre_completo,"Tomás");
	sprintf(em[1].nombre_completo,"María");
 	sprintf(em[2].nombre_completo,"Carlos");
 	sprintf(em[3].nombre_completo,"Carolina");
 	sprintf(em[4].nombre_completo,"Alex");
 	sprintf(em[5].nombre_completo,"Rosana");
}

void inicializar_puestos(Templeados em[])
{
	sprintf(em[0].puesto,"Ingeniero");
	sprintf(em[1].puesto,"Ingeniera");
 	sprintf(em[2].puesto,"Ventas");
 	sprintf(em[3].puesto,"Ventas");
 	sprintf(em[4].puesto,"Logística");
 	sprintf(em[5].puesto,"Logística");


}

void inicizar_meses(Templeados em[])
{

	  em[0].meses= 12;
	  em[1].meses= 10;
	  em[2].meses= 6;
	  em[3].meses= 20;
	  em[4].meses= 3;
	  em[5].meses= 16;
	


}



int elegir_empleados()
{
	int e,rep=0;
	
	do{
		printf("Elige tu usuario de empleado:\n");
		printf("1. Tomás\n2. María\n3. Carlos\n4. Carolina\n5. Alex\n6. Rosana\n");
		scanf(" %i",&e);
	if(e>6||e<1){
		printf("Usuario incorrecto.\n");
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


void inicializar_pregunta_horarios(Templeados em[],int e)
{	
	
	printf("Introduce tu hora de entrada y tu hora de salida:\n");
	scanf("%i %i",&em[e].entrada,&em[e].salida);
	cleanbuffer();


}


int Sueldo_horas(Templeados em[],int e)
{	
		em[e].horas_totales = em[e].salida - em[e].entrada;

		em[e].sueldo = (10 * em[e].horas_totales *25 );

		printf("Has trabajado %i horas por día, por lo tanto a 10€ la hora tu sueldo es de %i euros mensuales\n", em[e].horas_totales, em[e].sueldo);

	
}

void inicializar_horarios(Templeados em[],int e)
{	
	int i;
	

		if(em[e].horas_totales >= 8){

		
		printf("\t   Lu\t   Ma\t   Mi\t   Ju\t   Vi\t   Sa\t   Do\n");
		for(i=0;i<=4;i++)
			{
				printf("Semana%i\t   %i-%i\t   %i-%i\t   %i-%i\t   %i-%i\t    %i-%i   //\t   //\t\n",i,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida);

			}
  	}
  	else{

  	printf("\t   Lu\t   Ma\t   Mi\t   Ju\t   Vi\t   Sa\t   Do\n");
			for(i=0;i<=4;i++)
			{
				printf("Semana%i\t   //\t   //\t   %i-%i\t   %i-%i\t    %i-%i   %i-%i\t   %i-%i\t\n",i,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida,em[e].entrada,em[e].salida);

			}

  	}
}





void inicializar_menu_empleados(Templeados em[],int e)
{	

	int opcion,i; 
	int calculo_aumento;

	
	
do{
	printf("Introduce la operación que quieres hacer: 1-Ver sueldo actual y horas trabajadas   2-Ver horario  3-Pedir aumento  4-Introducir quejas  5-Volver:\n");
	scanf("%i",&opcion);
	cleanbuffer();

	switch(opcion){

	case 1:
		 Sueldo_horas(em,e);
		 break;
	case 2:
		inicializar_horarios(em,e);
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

	}

}while(opcion != 5);
}








void inicializar_datos(Templeados em[])
{ 

for(int i=0;i<=5;i++)
		{

			
			printf("NOMBRE[%d] = %s\n",i,em[i].nombre_completo);

		}


		printf("\n");	
		for(int i=0;i<=5;i++)
		{

			
			printf("PUESTOS[%d] = %s\n",i,em[i].puesto);

		}


		printf("\n");	
		for(int i=0;i<=5;i++)
		{

			
			printf("HORAS TRABAJADAS[%d] = %d\n",i,em[i].horas_totales);

		}		


		printf("\n");	
		for(int i=0;i<=5;i++)
		{

			
			printf("SUELDO[%d] = %i€\n",i,em[i].sueldo);

		}


		printf("\n");	
		for(int i=0;i<=5;i++)
		{

			
			printf("MESES TRABAJADOS[%d] = %i\n",i,em[i].meses);

		}


		printf("\n");	
		for(int i=0;i<=5;i++)
		{

			
			printf("QUEJAS DE[%d] = %s\n",i,em[i].quejas);

		}

		printf("\n");	
		for(int i=0;i<=5;i++)
		{

			
			printf("HORARIO DE[%d] = %i-%i\n",i,em[i].entrada,em[i].salida);

		}

}





int main(){

  char inicio[20]; char codigo_empleado[20];char codigo_Director[20];

	char volver,reintentar;
	int emp;

	Templeados em[5];

	inicializar_empleados(em);
	inicializar_puestos(em);
	
	inicializar_codigo_Director(codigo_Director);
	inicializar_codigo_empleado(codigo_empleado);
	
	printf("%s\n",codigo_Director);
	printf("%s\n",codigo_empleado);

do{
	printf("INGRESE SU CODIGO: \n");
	scanf("%s",inicio);
  cleanbuffer();

	if(strcmp(inicio,codigo_empleado)==0)
	{
					
		do{
				//Sueldo_horas(em);
				inicizar_meses(em);
				emp=elegir_empleados();
				inicializar_pregunta_horarios(em,emp);
				Sueldo_horas(em,emp);
				inicializar_horarios(em,emp);
				inicializar_menu_empleados(em,emp);
				
				
				
				printf("Quieres entrar en otro usuario?[s/n]\n");
				scanf("%c",&volver);
			  cleanbuffer();

		}while(volver != 'n');

	}else if(strcmp(inicio,codigo_Director)==0)
	{

		inicializar_datos(em);

	}else
	{
		printf("Codigo Incorrecto\n");
	}	


	printf("Quieres hacerlo de nuevo? [s|n]");
	scanf("%c",&reintentar);

	
	
	
	
}while(reintentar!='n');	
return 0;
}