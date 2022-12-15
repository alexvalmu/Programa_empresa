#include <stdio.h>

void modulo_director () {


	printf("Bienvenido Eduard Gomez Aguilar - Jefe de empresa\n");

	int numero_funcion;	
	char respuesta;

	do {	

		printf("Estas son las funciones disponibles para tu cargo en la empresa:\n");
		printf(" 1 - Ver datos de empresa\n 2 - Contratar trabajadores\n 3 - Despedir trabajadores\n");
		printf("¿Que funcion quieres desempeñar?: \n");
		scanf("%i", &numero_funcion);
		cleanbuffer();

		switch (numero_funcion) {

			case 1: printf("A continuación verás los datos de tus empresa\n"); 
			break;

			case 2: printf("A continuación podrás contratar a nuevos empleados\n"); 
					modulo_contratar();
			break;

			case 3: printf("A continuación podrás despedir a tus empleados\n");
					modulo_despedir();
			break;
		}

		printf("¿Quieres cerrar sesion como jefe? s/n: "); 
		scanf("%c", &respuesta);
		cleanbuffer();

	} while (respuesta == 'n' || respuesta == 'N');

}