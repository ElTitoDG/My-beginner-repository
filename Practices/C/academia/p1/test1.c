#include <stdio.h>

void leerUsuario(int *positivo, int *identicon){
	do{
		printf("Introdcue un numero positivo: ");
		scanf("%d", identicon);
	}while(*positivo <= 0);
	do{
		printf("Introduce el tamaño del identincon: ");
		scanf("%d", positivo);
	}while(*identicon <= 0);
}

int sumarDigitos(int n){
	int suma = 0;
	int digito;
	while(n > 0){
		digito = n % 10;
		suma = suma + digito;
		n = n / 10;
	}
	return suma;
}

void dibujaIdenticon(int n, int identicon){
	int i, j;
	int s, resto;
	
	s = sumarDigitos(identicon);
	for(i = 1; i <= n; i++){
		printf("[%d] ", i);
		if(i == 1 || i == n){
			printf("+");
			for(j = 1; j <= n - 2; j++){
				printf("-");
			}
			printf("+");
		}
		else{
			for(j = 1; j <= n; j++){
				if(j == 1 || j == n){
					printf("|");
				}
				else{
					if(i == 2 && j == 2){
						if(s % 2 == 0){
							printf("=");
						}
						else{
							printf("%%");
						}
					}
					else{
						resto = identicon % (i - 2 + j - 2 + 1);
						switch(resto){
							case 0:
								printf(".");
								break;
							case 1:
								printf("*");
								break;
							default:
								printf("o");
						}			
					}
				}
			}
		}
	
		printf("\n");
	}
}

int main(){
	int n, identicon;
	
	leerUsuario(&n, &identicon);
	dibujaIdenticon(n, identicon);
}

