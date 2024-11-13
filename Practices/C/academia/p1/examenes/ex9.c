#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inicializarMesas(int *hora1, int *min1, int *comensales1, int *menu1, bool *ocupada1,
		      int *hora2, int *min2, int *comensales2, int *menu2, bool *ocupada2,
		      int *hora3, int *min3, int *comensales3, int *menu3, bool *ocupada3) 
{
	*hora1 = *min1 = *hora2 = *min2 = *hora3 = *min3 = 0;	
	*comensales1 = *comensales2 = *comensales3 = 0;
	*menu1 = *menu2 = *menu3 = 0;
	*ocupada1 = *ocupada2 = *ocupada3 = false;
}

void mostrarMesas(int hora1, int min1, int comensales1, int menu1, bool ocupada1,
		  int hora2, int min2, int comensales2, int menu2, bool ocupada2,
	          int hora3, int min3, int comensales3, int menu3, bool ocupada3) 
{
	printf("\nEstado actual de las mesas:\n");
	printf("Mesa 1 - Hora %02d:%02d, ", hora1, min1);
	if (ocupada1)
		printf("Ocupada: Si, ");
	else
		printf("Ocupada: No, ");
	printf("Comensales: %d, Menus: %d\n", comensales1, menu1);

	printf("Mesa 2 - Hora %02d:%02d, ", hora2, min2);
	if (ocupada2)
		printf("Ocupada: Si, ");
	else
		printf("Ocupada: No, ");
	printf("Comensales: %d, Menus: %d\n", comensales2, menu2);

	printf("Mesa 3 - Hora %02d:%02d, ", hora3, min3);
	if (ocupada3)
		printf("Ocupada: Si, ");
	else
		printf("Ocupada: No, ");
	printf("Comensales: %d, Menus: %d\n", comensales3, menu3);	
}

void modificarMesa(int *hora, int *min, int *comensales, int *menu, bool *ocupada)
{
	printf("Ingrese la hora de la reserva (HH MM): ");
	scanf("%d %d", hora, min);
	printf("Ingrese el numero de comensales: ");
	scanf("%d", comensales);
	printf("Ingrese el menu (1-3): ");
	scanf("%d", menu);
	*ocupada = false; // Por defecto
	printf("Mesa modificada correctamente\n");
}

int ocuparDesocuparMesa(int comensales, int menu, bool *ocupada)
{
	if (!*ocupada) {
		*ocupada = true;
		printf("Mesa ocupada\n");
		return 0;
	} else {
		int precio;
		switch (menu) {
			case 1: precio = 255; break;
			case 2: precio = 175; break;
			case 3: precio = 195; break;
			default: precio = 0; break;
		}
		int total = precio * comensales;
		*ocupada = false;
		printf("Mesa desocupada. Cuenta: %d €\n", total);
		return total;
	}
}

void mostrarRecaudacion(int recaudacion) 
{
	printf("Recaudacion total hasta el momento: %d €\n", recaudacion);
}

int main(void)
{
	int hora1, min1, comensales1, menu1; // Mesa 1
    	int hora2, min2, comensales2, menu2; // Mesa 2
    	int hora3, min3, comensales3, menu3; // Mesa 3
    	bool ocupada1, ocupada2, ocupada3;
    	int recaudacion_total = 0;
    	int op, mesaSel;

	inicializarMesas(&hora1, &min1, &comensales1, &menu1, &ocupada1,
                     	&hora2, &min2, &comensales2, &menu2, &ocupada2,
                     	&hora3, &min3, &comensales3, &menu3, &ocupada3);

	do {
		printf("\n-----MENU-----\n");
		printf("1. Modificar mesa\n");
        	printf("2. Ocupar/Desocupar mesa\n");
        	printf("3. Recaudación\n");
        	printf("4. Salir del programa\n");
        	printf("Seleccione una opción: ");
        	scanf("%d", &op);

		
		switch (op) {
			case 1:
				printf("Ingrese el numero de mesa a modificar (1-3): ");
				scanf("%d", &mesaSel);
				if (mesaSel == 1)
                    			modificarMesa(&hora1, &min1, &comensales1, &menu1, &ocupada1);
                		if (mesaSel == 2)
                    			modificarMesa(&hora2, &min2, &comensales2, &menu2, &ocupada2);
                		if (mesaSel == 3)
                    			modificarMesa(&hora3, &min3, &comensales3, &menu3, &ocupada3);
                		else
                    			printf("Mesa no válida.\n");
					mostrarMesas(hora1, min1, comensales1, menu1, ocupada1,
                             			     hora2, min2, comensales2, menu2, ocupada2,
                             			     hora3, min3, comensales3, menu3, ocupada2);
                		break;
			case 2:
				printf("Ingrese el numero de mesa a modificar (1-3): ");
				scanf("%d", &mesaSel);
				if (mesaSel == 1)
                    			recaudacion_total += ocuparDesocuparMesa(comensales1, menu1, &ocupada1);
				if (mesaSel == 2)
                    			recaudacion_total += ocuparDesocuparMesa(comensales2, menu2, &ocupada2);
				if (mesaSel == 3)
                    			recaudacion_total += ocuparDesocuparMesa(comensales3, menu3, &ocupada3);
                		else
                    			printf("Mesa no válida.\n");
                			mostrarMesas(hora1, min1, comensales1, menu1, ocupada1,
                             			     hora2, min2, comensales2, menu2, ocupada2,
                             			     hora3, min3, comensales3, menu3, ocupada2);
                		break;
			case 3:
                		mostrarRecaudacion(recaudacion_total);
                		break;

            		case 4:
                		printf("Saliendo del programa.\n");
                		break;

            		default:
                		printf("Opción no válida.\n");

		}
	} while (op != 4);

	return 0;
}
