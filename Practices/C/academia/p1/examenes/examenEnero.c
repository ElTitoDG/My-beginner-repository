#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 5
#define N 5
#define MAX_CADENAS 5
#define MAX_TAM 100

typedef int TMatrizE [M][N];
typedef int TMask[3][3];

typedef char TCadena[MAX_TAM + 1];
typedef TCadena TMatrizCad[MAX_CADENAS];

typedef char TResultado[MAX_CADENAS * (MAX_TAM + 1)];

typedef int TVectorE [50];
typedef int TContadores[10];

#define MAX_CONTADORES 'z' - 'a' + 1
typedef int TContadoresLetras[MAX_CONTADORES];
typedef char TLetras [100];

typedef int TMatrizC[6][3];

// Ejercicios recursividad
// ==========================================

// Devueleve la cantidad de digitos coincidentes
// En esta funcion tienen que tener los dos numeros la misma longitud
int igualesDigitos(int n1, int n2)
{
  int digitosIguales;
  if (n1 < 10 && n2 < 10)  {
    if (n1 == n2)
      digitosIguales = 1;
    else
      digitosIguales = 0;
  } else {
    if (n1 % 10 == n2 % 10)
      digitosIguales = 1 + igualesDigitos(n1/10, n2/10);
    else
      digitosIguales = igualesDigitos(n1/10, n2/10);
  }
  return digitosIguales;
}

// Aqui da igual la longuitud de los dos numeros
int igualesDigitos2(int n1, int n2)
{
  int digitosIguales;
  if (n1 < 10 || n2 < 10) {
    if (n1 % 10 == n2 % 10)
      digitosIguales = 1;
    else
      digitosIguales = 0;
  } else {
    if (n1 % 10 == n2 % 10)
      digitosIguales = 1 + igualesDigitos2(n1/10, n2/10);
    else
      digitosIguales = 0 + igualesDigitos2(n1/10, n2/10);
  }
  return digitosIguales;
}

// Devuelve cierto si ambos numeros tienen la misma logitud y para
// todo digito de num1 se cumple que es mayor que para num2
bool mayor(int num1, int num2)
{
  bool es;
  int digit1, digit2;

  if (num1 < 10 && num2 >= 10 || num1 >= 10 && num2 < 10)
    es = false;
  else {
    if (num1 < 10 && num2 < 10) {
      if (num1 >= num2)
	es = true;
      else
	es = false;
    } else {
      digit1 = num1 % 10;
      digit2 = num2 % 10;
      if (digit1 >= digit2)
	es = mayor(num1/10, num2/10);
      else
	es = false;
    }
  }
  return es;
}

int programin(int codNormal)
{
  int codSecreto, digit;

  if (codNormal < 10) { // Si es menor 10 == solo un digito
    if (codNormal == 0)
      codSecreto = 1; // Si es igual a cero se transforma en uno
    else {
      if (codNormal % 3 == 0)
	codSecreto = codNormal * 2; // Si es mult 3 se multiplica por 2
      else
	codSecreto = codNormal; // En el resto de casos es igual
    }
  } else { // Si tiene mas de un digito
    digit = codNormal % 10; // Extraemos el digito
    if (digit == 0)
      codSecreto = 1 * programin(codNormal/10); // Caso cero y se une el siguiente con llamada recursiva
    else {
      if (digit % 3 == 0)
	codSecreto = (digit * 2) * programin(codNormal/10); // Igual pero en su caso especifico
      else
	codSecreto = digit * programin(codNormal/10); // Igual 
    }
  }
  return codSecreto;
}

// ==========================================

// Matrices - Adyacentes, Ajedrez ETC...
// ==========================================

void fillRandom(TMatrizE m){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            m[i][j] = rand() % 10 + 1;
        }
    }
}

void printMatrix(TMatrizE m)
{
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%4d", m[i][j]);
    }
    printf("\n");
  }
}

// Hacer ejercicio de adyacentes
// Esta funcion imprime las posiciones adyacentes de una matriz
void adyacentes(TMatrizE m, int fila, int columna)
{
  for (int i = fila - 1; i <= fila + 1; i++) {
    for (int j  = columna - 1; j <= columna + 1; j++) {
      if (i >= 0 && i < M && j >= 0 && j < N)
	printf("%4d", m[i][j]);
    }
    printf("\n");
  }
}

// Con la misma idea se le aplica una mascara a cierta zona, es decir, sumamos algo en la zona de las adyacentes
void applyMask(TMatrizE m, TMask mask, int fil, int col)
{
  int p = 0, q;
  for (int i = fil - 1; i <= fil + 1; i++) {
    q = 0;
    for (int j = col - 1; j <= col + 1; j++) {
      if (i >= 0 && i < M && j >= 0 && j < N) {
	m[i][j] = mask[p][q] + m[i][j];
      }
      q++;
    }
    p++;
  }
}

void imprimirCaballo(char x, char y)
{
  if (y - 2 >= '1' && x - 1 >= 'a')
    printf("%c%c ", y - 2, x - 1);

  printf("%c%c ", y - 2, x + 1);
  
  printf("%c%c ", y - 1, x - 2);
  printf("%c%c ", y - 1, x + 2);

  printf("%c%c ", y + 1, x - 2);
  printf("%c%c ", y + 1, x + 2);

  printf("%c%c ", y + 2, x - 1);
  printf("%c%c ", y + 2, x + 1);
}

void imprimirCaballoAlter(char x, char y)
{
  printf("\n");
  printf("\n");

  for (char cy = y + 2; cy >= y - 2; cy--) {
    for (char cx = x - 2; cx <= x + 2; cx++) {
      printf("(%c%c) ", cy, cx);
    }
    printf("\n");
  }
  printf("\n");

  printf("Coordenadas del caballo: (%c%c)\n", x, y);
  for (int incy = 2; incy >= - 2; incy--) {
    for (int incx = -2; incx <= 2; incx++) {
      printf("(%2d %2d) ", incy, incx);
    }
    printf("\n");
  }

  printf("Despues de sumar\n");
  printf("\n");
  for (int incy = 2; incy >= - 2; incy--) {
    for (int incx = - 2; incx <= 2; incx++) {
      printf("(%c%c) ", y + incy, x + incx);
    }
    printf("\n");
  }

  printf("Despues de filtrar\n");
  for (int incy = 2; incy >= - 2; incy--) {
    for (int incx = - 2; incx <= 2; incx++) {
      if (abs(incx) != abs(incy) && incx != 0 && incy != 0)
	printf("%c%c ", y + incy, x + incx);
      else
        printf("   ");
    }
    printf("\n");
  }
}

// ==========================================

// Cadenas de Caracteres
// ==========================================

void hazFrase(TMatrizCad m, TResultado res)
{
  int j = 0, k = 0;
  for (int i = 0; i < MAX_CADENAS; i++) {
    j = 0;
    while (m[i][j] != '\0') {
      res[k] = m[i][j];
      k++;
      printf("%c", m[i][j]);
      j++;
    }

    if (i == MAX_CADENAS - 1)
      res[k] = '\0';
    else
      res[k] = ' ';

    k++;
    printf(" - ");
  }
}

void matrizFrase(TCadena cad, TMatrizC c)
{
  int i = 0, k = 0, inicio = 0;

  while (cad[i] != '\0') {
    // Buscamos el comienzp de la siguiente palabra
    while (cad[i] == ' ') {
      i++;
    }

    if (cad[i] != '\0') {
      c[k][0] = i;
      while (cad[i] != ' ' && cad[i] != '\0') {
	i++;
      }
      c[k][1] = i - 1;
      c[k][2] = c[k][1] - c[k][0] + 1;
      k++;
    }
  }
  for (int i = 0; i < 6; i++) {
    printf("%2d %2d %2d\n", c[i][0], c[i][1], c[i][2]);
  }
}

// ==========================================

// Ejercicios contadores
// ==========================================

// Cuanta las veces que aparece el caracter numero del 0 a al 9
void contarVeces(TVectorE v, TContadores res)
{
  int pos;
  for (int i = 0; i < 50; i++) {
    pos = v[i] - '0';
    res[pos]++;
  }
}

void contarVecesLetras(TLetras v, TContadoresLetras res)
{
  int pos, i;

  // Inicializar vector de resultados
  for (int i = 0; i < MAX_CONTADORES; i++) {
    res[i] = 0;
  }

  // Contador
  i = 0;
  while (v[i] != '\0') {
    pos = v[i] - 'a';
    res[pos]++;
    i++;
  }

  
}

void contarVecesLetras2(TLetras v)
{
  TContadoresLetras res;
  int pos, i;

  // Inicializar vector de resultados
  for (int i = 0; i < MAX_CONTADORES; i++) {
    res[i] = 0;
  }

  // Contador
  i = 0;
  while (v[i] != '\0') {
    if (v[i] >= 'a' && v[i] <= 'z') { // miro si es letra minuscula
      pos = v[i] - 'a';
      res[pos]++;
      i++;
    }
  }
  
  // Visualizador
  for(int i = 0; i < MAX_CONTADORES; i++) {
    if(res[i] != 0) {
      printf("%c esta %d veces\n", i + 'a', res[i]);
    }
  }
}

// ==========================================

// Ejercicios Dibujos
// ==========================================

void elDibujo(char car, int size)
{
  int espacios, asteriscos;

  espacios = size - 1;
  asteriscos = 1;
  for (int i = 1; i <= size; i++) {
    for (int k = 1; k <= 5; k++) {
      for (int j = 1; j <= espacios; j++) {
	printf(" ");
      }
      for (int j = 1; j <= asteriscos; j++) {
	if (j == 1 || j == asteriscos || i == size)
	  printf("%c", car);
	else
	  printf(" ");
      }
      for (int j = 1; j <= espacios; j++) {
	printf(" ");
      }
    }
    espacios--;
    asteriscos *= 2;
    printf("\n");
  }
}

// ==========================================

int main(void)
{
  TMatrizE test1;
  TMatrizC test2;

  TMatrizCad cadenasSin = {
    {'J', 'O', 'S', 'E', '\0'},
    {'E', 'S', '\0'},
    {'G', 'R', 'A', 'N', 'D', 'E', '\0'},
    {'Y', '\0'},
    {'P', 'O', 'D', 'E', 'R', 'O', 'S', 'O', '\0'}
  };


  printf("Ejercicios recursividad: \n");
  int iguales = igualesDigitos2(92345, 2645);
  printf("El numero de digitos iguales es: %d\n", iguales);

  bool esMayor = mayor(92312, 81001);
  if (esMayor) printf("Ambos numeros tienen la misma longitud y num1 es mayor que num2\n");

  printf("Prueba programin: \n");
  printf("Numero normal %d\n", 2345789);
  printf("Programin: (Numero secreto)%d\n", programin(2345789));
  printf("\n");


  
  printf("Ejercicios matrices: \n");
  fillRandom(test1);
  printf("Adyacentes: \n Matriz completa: \n");
  printMatrix(test1);
  printf("Celdas Adyacentes: \n");
  adyacentes(test1, 2, 2);

  printf("Imprimir caballo: \n");
  imprimirCaballo('e', '5');

  printf("Imprimir caballo alternativa: \n");
  imprimirCaballoAlter('e', '5');
  printf("\n");

  

  printf("Ejercicios cadenas: \n");
  TResultado res;

  hazFrase(cadenasSin, res);
  printf("[%s]\n\n", res);

  matrizFrase("Ana programa genial y Rudi tambien", test2);


  
  printf("Ejercicios contadores: \n");
  TContadoresLetras resLetras;

  contarVecesLetras("ADFDDAfdsadfa sfd assef dapoya   #", resLetras);
  for(int i = 0; i < MAX_CONTADORES; i++) {
    if(resLetras[i] != 0) {
      printf("%c esta %d veces\n", i + 'a', resLetras[i]);
    }
  }
  printf("\n");

  printf("Ejercicio dibujo: \n");
  elDibujo('*', 5);
  
  return 0;
}
