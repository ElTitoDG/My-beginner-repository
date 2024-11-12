#include <stdio.h>
#include <stdbool.h>



// devolvera cierto si son positivos y distintos entre si.
bool sonCorrectos(int a, int b, int c){
	if (a > 0 && b > 0 && c > 0)
		if (a != b || b != c && c != a)
			return true;
	return false;
}

// pide 3 valores mayores que 0 y distintos entre si.
// Introduce 3 valores: 3 3 4
// Error. Introduce 3 valroes: 
void pedir3(int *a, int *b, int *c)
{
	do
	{
		printf("Introduce tres numeros positivos y distintos: ");
		scanf("%d %d %d", a, b, c);
	} while (!sonCorrectos(*a, *b, *c));
}
int min2(int a, int b){

}

int min3(int a, int b, int c){

}
int max2(int a, int b){

}
int max3(int a, int b, int c){

}

void obtenerMayorMenor(int a, int b, int c, int *min, int *max){


}
int main(){
    int a, b, c, menor, mayor;

    pedir3(&a, &b, &c);
    obtenerMayorMenor(a, b, c, &menor, &mayor);
    printf("Menor: %f\nMayor: %f\n", menor, mayor);
    return 0;
}
