#include <stdlib.h>
#include <stdbool.h>

#define TAM1 50
#define TAM2 10
typedef char TVector [TAM1];
typedef int TContenedores[TAM2];

int contarTotalUnosRecur(int n)
{
    int c;
    if (n < 10) {
	if (n == 1)
	  c = 1;
	else
	  c = 0;
    } else {
      if (n % 10 == 1)
	c = 1 + contarTotalUnosRecur(n/10);
      else
	c = contarTotalUnosRecur(n/10);
    }
    return c;
}

long calcularDigitosContro(long n)
{
  int digitoControl = -1;
  int digito;
  int peso;
  if (n >= 10000000 && 99999999) {
    peso = 8;
    while (n > 0) {
      digito = n % 10;
      n = n / 10;
      digitoControl = digito * peso;
      peso--;
    }
  }  
  return digito;
}

int coincidentes(int n)
{
  int s;
  if (n < 10) {
    if (n == 3 || n == 5)
      s = n;
    else
      s = 0;
  } else {
    if (n % 10 == 3 || n % 10 == 5) 
      s = n % 10 + coincidentes(n/10);
    else
      s = coincidentes(n/10);
  }
  return s;
}

void contarDigitos(TVector v, TContenedores conts)
{
  int pos;
  // Inicializar contadores en el modulo
  for (int i = 0; i < TAM2; i++) {
    conts[i] = 0;
  }
  for (int i = 0; i < TAM1; i++) {
    pos = v[i] - '0';
    conts[pos]++;
  }
}


// Rellena el vector de chars numericos
void fillRandom(TVector v)
{
    for (int i = 0; i < TAM1; i++) {
	v[i] = rand() % 10 + '0';
    }
}

int programin(int n)
{
  int s, digito;
    if (n < 10) {
      if (n == 0)
	s = 1;
      else {
	if (n % 3 == 0)
	  s = n * 2;
	else
	  s = n;
      }
    } else {
      digito = n % 10;
      if (digito == 0)
	s = 1 * programin(n/10);
      else {
	if (digito % 3 == 0)
	  s = digito * 2 * programin(n/10);
	else
	  s = digito * programin(n/10);
      }
    }

    return s;
}

int buscarPosRecur(int n, int digi)
{
    int pos = -1;

    if (n < 10) {
	if (n == digi)
	    pos = 1;
	else
	    pos = -1;
    } else {
	if (n % 10 == digi)
	    pos = 1;
	else {
	    pos = buscarPosRecur(n / 10, digi);
	    if (pos != -1) {
		pos++;
	    }  
	}
    }
    return pos;
}

bool esMayorRecur(int n, int sd)
{
  
}

char getMayorRecur(char cadena[], int desde)
{
    char mayor;

    if (cadena[desde] == '\0') {
	mayor = '\0';
    } else {
	mayor = getMayorRecur(cadena, desde + 1);
	if (cadena[desde] > mayor) {
	    mayor = cadena[desde];
	}
    }

    return mayor;
}

int getMayorDigitoRecur(int n)
{
    int mayor;

    if (n < 10) {
	mayor = n;
    } else {
	mayor = getMayorDigitoRecur(n / 10);
	if (n % 10 > mayor) {
	    mayor = n % 10;
	}
    }
    
    return mayor;
}

int main()
{
       
  return 0;
}
