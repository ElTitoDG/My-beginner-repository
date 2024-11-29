#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool esMayuscula(char c) { return c >= 'A' && c <= 'Z'; }

bool esMinuscula(char c) { return c >= 'a' && c <= 'z'; }
bool esDigito(char c) { return c >= '0' && c <= '9'; }

// toMins('A') => 'a'
char toMins(char c)
{
	char res;
	if(c >= 'A' && c <= 'Z') // si es mayuscula lo paso a minuscula.
		res = c + 'a' - 'A';
	else
		res = c;
	return res;
}

char toMays(char c)
{
	char res;
	if(c >= 'a' && c <= 'z') // si es mayuscula lo paso a minuscula.
		res = c + 'A' - 'a';
	else
		res = c;
	return res;
}
// da igual mays o mins
bool esLetra(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }

// da igual mins o mays
bool esVocal(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; }

bool esVocalCool(char c){
	char x = toMins(c);
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

bool esCM(char c) { return c >= 'B' && c <= 'Z' && c != 'E' && c != 'I' && c != 'O' && c != 'U'; }

//         01234567
// true si DDDD LLL, las LLL no pueden haber vocales nazis.
bool esMatricula(char matricula[])
{
	bool es = false;
	int tam, i;
	
	tam = strlen(matricula);
	if(tam == 8) {
		if(matricula[4] == ' ') {
			es = true;
			i = 0;
			while(i < 4 && es == true) {
				if(esDigito(matricula[i]) == false)
					es = false;
				else
					i++;
			}
			if(es == true) {
				i = 5;
				while(i < 8 && es == true) {
					if(esCM(matricula[i]) == false)
						es = false;
					else
						i++;
				}
			}
		}
	}
	return es;
}

// copia el contenido de c1 a c2.
void copiar(char dst[], char org[]){
	int i;
	i = 0;
	while(org[i] != '\0'){
		dst[i] = org[i];
		i++;
	}
	dst[i] = '\0';
}

void copiarVo(char dst[], char org[])
{
	int i;
	i = 0;
	while (org[i] != '\0') {
		if (esVocalCool(org[i]))
			dst[i] = org[i];
		i++;
	}
	dst[i] = '\0';
}

//copia las vocales de c1 a c2.
void copiarVocales(char c1[], char c2[]){

}

// --------
// Ejercicio 1.
// devuelve el numero de digitos que tiene al cadena.
int contarDigitos(char cadena[]){

}
// Ejercicio 2.
// devuelve el numero de mayusculas y minusculas que tiene la cadena.
void contarMm(char cadena[], int *cmays, int *cmins){

}
// Ejercicio 3.
// DDDDDDDD-L
// 8 digitos y una letra
//	comprueba que la letra es valida, busca en internet como se calcula la letra en
// funcion del numero (no se lo preguntes a chatgpt que te lo va a progamar)
bool esNIF(char nif[]){

}

// Ejercicio 4.
// invierte la cadena que le pasas como parametro
// cadena = "ahola" => despues de la funcion => cadena = "aloha"
void invertir(char cadena[]){

}






int main(){
	printf("a: %d\n", 'a');
	printf("A: %d\n", 'A');

	printf("diferencia: %d\n", 'A' - 'a');

	char frase1[] = "Hola";
	char frase2[15];
	char frase3[15];
	copiar(frase2, frase1);
	copiarVo(frase3, frase1);

	printf("Frase copiada: %s\n", frase2);
	printf("Frase copiada: %s\n", frase3);

	return 0;
}
