#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////////////////////////
// propuesto 1
// que hace esta funcion?
// haz la traza como esta en el main.
void imp(int n, int x){
    if(n == 0){
        printf("\n");
    }
    else{
        if(n % x == 0){
            imp(n - x, x);
            printf("%d ", n);
        }
        else{
            imp(n - 1, x);
        }
    }
}
// imp(23, 5) => imp(22, 5) => imp(21, 5)
// => imp(20, 5) => imp(15, 5) => imp(10, 5) => imp(5, 5) => imp(0, 5)
//        20             15            10              5          \n

int main_imp(){
    imp(23, 5); // \n 5 10 15 20
    return 0;
}

//////////////////////////////////////////////////////////////////
// propuesto 2.
// realiza una funcion recursiva que imprima n veces el caracter c
void impNCR(int n, char c){
    if(n > 0){
        printf("%c", c);
        impNCR(n-1, c);
    }
    return;
}
// impNCR(n = 3)        => impNCR(n = 2)        => impNCR(n = 1)        => impNCR(n = 0)
//   printf("*")            printf("*")             printf("*")         -return
//   impNCR(2)              impNCR(1)<-               impNCR(0)<----------|
//                                     |___________   return
int main_impNCR(){
    impNCR(3, '*'); // imprimirimira: ***
    return 0;
}

//////////////////////////////////////////////////////////////////
// propuesto 3
// haz la traza para factorial(4)
/*
    factorial(n = 4) => 24
        f = 4 * factorial(3)
        -----
        f = 4 * 6
        return 24
    factorial(n = 3) => 6
        f = 3 * factorial(2)
        f = 3 * 2
        return 6
    factorial(n = 2) => 2
        f = 2 * factorial(1)
        -----
        f = 2 * 1
        f = 2
        return 2
    factorial(n = 1) => 1
        f = 1 * factorial(0)
        -----
        f = 1 * 1 = 1
        return 1

    factorial(n = 0) => 1
        f = 1
        return 1

*/
int factorial(int n){
    int f;
    if(n == 0){
        f = 1;
    }
    else{
        f = n * factorial(n-1);
    }
    return f;
}

//////////////////////////////////////////////////////////////////
// propuesto 4
// IMplementa la funcion recursiva que devuelve la suma de los valores
// que hay entre a y b (a siempre sera menor que b en la primera llamada)
int sumarRango(int a, int b){
    int sr = 0;
    if(a == b){
        sr = a;
    }
    else{
        sr = a + sumarRango(a + 1, b);
    }
    return sr;
}

int main_sumarRango(){
    int sr;
    sr = sumarRango(2, 5); // devuelve el valor 14
    printf("%d\n",sr);
    return 0;
}

////////////////////////////////////////////////////////////////
/// propuesto 5
///
/// devuelve la cantidad de digitos dle numero multiplos de x.
int cdmxn(int n, int x){
    int c = 0;

    if(n < 10){
        if(n % x == 0){
            c = 1;
        }
        else{
            c = 0;
        }
    }
    else{
        if(n % 10 % x == 0){
            c = 1 + cdmxn(n/10, x);
        }
        else{
            c = cdmxn(n/10, x);
        }
    }
    return c;
}
//        x xx
// cdmxn(19263, 3) => 3 (3 digitos multiplos de 3)


int main_cdmxn(){
    printf("%d\n", cdmxn(19263, 3));;
    return 0;
}

// funcio que devuelve cierto si los digitos del numero
// estan ordenados de mayor a menor
bool ordenadoDesc(int n){
    bool ord;
    if(n < 10){ // solo tiene un digito
        ord = true;
    }
    else{
        int digito1, digito2;
        digito1 = n % 10;
        digito2 = n / 10 % 10;
        if(digito2 >= digito1){
            ord = ordenadoDesc(n/10);
        }
        else{
            ord = false;
        }
    }
    return ord;
}
/*
    ordenadoDesc(n = 321)
        digito1 = 1
        digito2 = 2
        ord = ordenadoDesc(32)
        ------
        ord = true
        return true

    ordenadoDesc(n = 32)
        digito1 = 2
        digito2 = 3
        ord = ordenadoDesc(3)
        ----
        ord = true
        return true


    ordenadoDesc(n = 3) => true
        ord = true
        return true

--------------------------------------------

    ordenadoDesc(n = 9265)
        digito1 = 5
        digito2 = 6
        ord = ordenadoDesc(926)
        ---
        ord = false
        return false

    ordenadoDesc(n = 926)
        digito1 = 6
        digito2 = 2
        ord = false
        return false

*/

/*
    funcion recursiva que comprueba si los digitos dle numero son iguales 2 a 2.
*/
bool iguales2to2(int n){
    bool son;
    if(n < 10){
        son = true;
    }
    else{
        int digito1, digito2;
        digito1 = n % 10;
        digito2 = n / 10 % 10;
        if(digito1 == digito2){
            son = iguales2to2(n / 100);
        }
        else{
            son = false;
        }
    }
    return son;
}

/*
Devuelve la cantidad de veces que d esta en el numero n.
*/
int contarVeces(int n, int d){
    int veces;

    if(n < 10){
        if(n == d){
            veces = 1;
        }
        else{
            veces = 0;
        }
    }
    else{
        if(n % 10 == d){
            veces = 1 + contarVeces(n/10, d);
        }
        else{
            veces = contarVeces(n/10, d);
        }
    }
    return veces;
}

// a + a + a + ... + a
// b veces
// a x b
int f(int a, int b){
    int x;
    if(b == 0){
        x = 0;
    }
    else{
        x = a + f(a, b - 1);
    }
    return x;
}

// cuenta la cantidad de veces que le puedes
// quitar a a el valor de b
/*
d(7, 3) = 1 + d(4, 3) = 1 + 1 = 2
d(4, 3) = 1 + d(1, 3) = 1 + 0 = 1
d(1, 3) = 0
*/

int d(int a, int b){
    int c = 0;
    if(a >= b){
        c = 1 + d(a-b, b);
    }
    return c;
}

// PROPUESTO 1.
// - Devuelve la primera posicion del digito d en el numero n,
// las posiciones se numeran desde 1 empezando desde la derecha.
// - Devuelve -1 si el d no esta en el numero.
int buscarPos(int n, int d){

}

// PROPUESTO 2
// devuelve cierto si la suma de los digitos del numero es mayor que sd.
bool mayor(int n, int sd){

}

// PROPUESTO 3. Multimedia tendence
// realiza una funcion recursiva que devuelva el numero n que se
// le pasa como parametro invertido (no vale imprimirlo)



// devuelve la suma de los valores del vector que estan entre ini y fin.
int sumarEntre(int v[], int ini, int fin){
    int s;
    if(ini > fin){
        s = 0;
    }
    else{
        s = v[ini] + sumarEntre(v, ini + 1, fin);
    }
    return s;
}

// cad = "hola", ini = 0, fin = 3
//  => cad = "aloh"
// invierte la subcadena que hay entre las posiciones inicio y fin
void invertir(char cad[], int ini, int fin){
    char aux;
    if(ini < fin){
        aux = cad[ini];
        cad[ini] = cad[fin];
        cad[fin] = aux;
        invertir(cad, ini+1, fin-1);
    }
    return;
}

// devuelve cierto si el subvector que hay entre ini y fin esta ordenado de menor a mayor.
bool ordenado(int v[], int ini, int fin){
    bool esta;
    if(ini >= fin){
        esta = true;
    }
    else{
        // PROPUESTO 2.... POR HACER
    }
    return esta;
}

// devuelve el numero de veces que el caracter car esta en la cadena desde desde hasta el final de la cadena.

//        01234567
// veces("ABARCARDA", 3, 'A');

// veces(cad =, desde = 3, car = 'A'
//      cad[3] == car
//      v = veces(cad, 4, car)


// veces(cad, desde = 4, car = 'A')
//      cad[4] == car
//

int veces(char cad[], int desde, char car){
    int v = 0;

    if(cad[desde] == '\0'){
        v = 0;
    }
    else{
        if(cad[desde] == car){
            v = 1 + veces(cad, desde + 1, car);
        }
        else{
            v = veces(cad, desde + 1, car);
        }
    }
    return v;
}

// convierte a entero desde la posicion pasada como parametro hasta 0
//        01234
// toInt("34123", desde = 3)
//      devuelve el int 3412
int toInt(char cad[], int desde){

}


// PROPUESTO!!!
// devuelve cierto si las cadenas cad1 y cad2 son iguales desde la posicion pasada como parametro.
bool iguales(char cad1[], char cad2[], int desde){

}


// PROPUESTO
// devuelve el mayor caracter de la cadena existente desde
// la posicion desde hasta el fin de la cadena.
char getMayor(char cadena[], int desde){

}


int cociente(int a, int b){
    int c;
    if(a < b){
        c = 0;
    }
    else{
        c = 1 + cociente(a - b, b);
    }
    return c;
}

int main(){
    //                       4321
    printf("%d\n", buscarPos(72745, 7)); // 3
    printf("%d\n", buscarPos(2313, 9)); // -1

    printf("%d\n", d(7, 3));    //
    printf("%d\n", d(16, 4));   //

    printf("%d\n", f(7, 3)); // ¿¿¿ 7 + 7 + 7 = 3 x 7 = 21
    printf("%d\n", f(9, 2)); // ?? 9 + 9 = 2 x 9 = 18

    printf("%d\n", contarVeces(1233, 7)); // 0
    printf("%d\n", contarVeces(1211, 1)); // 3

    printf("%d\n", iguales2to2(112233)); // true
    printf("%d\n", iguales2to2(12233)); // true
    printf("%d\n", iguales2to2(115677)); // false

    printf("%d\n", ordenadoDesc(98872));
    return 0;
}
