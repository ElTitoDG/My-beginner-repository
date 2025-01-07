#include <stdio.h>
/*
Ejercicio 1.
Usando la estructura del rectangulo
    typedef struct{
        float base, altura;
    }TRectangulo;

Implementa un main, que llamando a funciones:
    a) Lea los datos de 3 rectangulos
    b) Imprima los datos de los 3 rectangulos
    c) Muestre los datos del rectanculo (base,altura) cuyo
    perimetro sea mayor. Para calcular el perimetro define
    una funcion.
    d) Prueba a meter los 3 rectangulos dentro de un vector
    y a repetir el programa

Ejercicio 2.
typedef struct{
    int horas, minutos;
}THora;

Implementa un main, que llamando a funciones:
    a) Lea los datos de 2 horas, modifica la funcion leer
    para que valida las horas (formato 24 horas), la funcion vuelve
    a pedir los datos si no son correctos.
    b) Imprima los datos las 2 horas
    c) Muestre por pantalla cual es la hora mas tardia (con o sin funciones,
    da igual)

*/

/*
    Ejercicio 3.
    // Usnado la estructura de abajo, crea un vector de 5
    // productos, y rellenalo con los siguientes datos (usando codigo).
    Aquí tienes cinco productos ficticios con sus nombres, precios de venta al público (PVP) y precios de compra:
Aquí tienes los productos con una fecha de alta añadida:
    1. **Producto**: Ratón Óptico LuxPro 200
       - **PVP**: 25,99 €
       - **Precio de compra**: 15,50 €
       - **Fecha de alta**: 2024-11-01

    2. **Producto**: Auriculares Inalámbricos SonicBreeze X3
       - **PVP**: 59,99 €
       - **Precio de compra**: 32,00 €
       - **Fecha de alta**: 2024-11-05

    3. **Producto**: Mochila Deportiva TrailMaster
       - **PVP**: 45,00 €
       - **Precio de compra**: 28,50 €
       - **Fecha de alta**: 2024-11-10

    4. **Producto**: Juego de Vasos Cristalino Luxe 6 Unidades
       - **PVP**: 19,99 €
       - **Precio de compra**: 12,00 €
       - **Fecha de alta**: 2024-11-15

    5. **Producto**: Cafetera Compacta BrewGo 800
       - **PVP**: 85,00 €
       - **Precio de compra**: 55,00 €
       - **Fecha de alta**: 2024-11-20
*/

typedef struct {
    int dia, mes, anyo;
} TFecha;

typedef struct {
    char   nombre[100];
    float  pvp;
    TFecha compra;
} TProducto;

int main_producto()
{
    TProducto productos[5] = {{}, {}, {}, {}, {}};
    return 0;
}

typedef struct {
    char  nombre[60];
    float saldo;
    char  pais[100];
} TCliente;

// imprime el nombre en una linea y en la siguiente el saldo.
void imprimirCliente(TCliente cliente)
{
    printf("Nombre: %s\n", cliente.nombre);
    printf("Saldo: %.2f\n", cliente.saldo);
    printf("Pais: %s\n", cliente.pais);
}

void leerCliente(TCliente* cliente)
{
    printf("Introduce el nombre del cliente: ");
    scanf(" %[^\n]", cliente->nombre); // con los vectores de caracteres NO se PONE el &
    printf("Introduce el saldo del cliente: ");
    scanf("%f", &cliente->saldo);
    printf("Intorduce le pais del cliente: ");
    scanf(" %[^\n]", cliente->pais);
}

void imprimirListaClientes(TCliente vcs[])
{
    printf("LISTA DE CLIENTES ALMACENADA    \n");
    printf("===============================\n");
    for (int i = 0; i < 3; i++) {
        imprimirCliente(vcs[i]);
    }
    printf("===============================\n");
}

int main()
{
    // inicializo dos clientes y muestro los valores por pantalla.
    TCliente c1 = {"jose", 1000, "spain"}, c2 = {"pepe", 2000, "italy"};
    imprimirCliente(c1); // copio en cliente los valores de c1
    imprimirCliente(c2); // copio en cliente los valores de c2

    // el usuario introduce los datos de cos clientes y muestro los datos introducidos.
    printf("Datos del cliente numero 1\n");
    //    leerCliente(&c1);
    printf("Datos del cliente numero 2\n");
    //    leerCliente(&c2);
    printf("Los clientes introducidos son:\n");
    imprimirCliente(c1);
    imprimirCliente(c2);

    TCliente clientes[5]; // aqui me caben hasta 5 clientes.
    // clientes[0].nombre   clientes[1].nombre      ...     clientes[4].nombre
    // clientes[0].saldo    clientes[1].saldo       ...     clientes[4].saldo
    // clientes[0].pais     clientes[1].pais        ...     clientes[4].pais

    //                                 TIPO
    // clientes             =>      TCliente []
    // clientes[0]          =>      TCliente
    // clientes[0].saldo    =>      float
    // clientes[0].pais     =>      char []

    TCliente cls[3] = {
        {"juan", 200, "egipto"},         // cls[0]
        {"jose manuel", 1000, "murcia"}, // cls[1]
        {"juan ramon", 2000, "rumania"}  // cls[2]
    };

    printf("imprimiendo a lo bruto...\n");
    printf("%s %f %s\n", cls[0].nombre, cls[0].saldo, cls[0].pais);
    printf("%s %f %s\n", cls[1].nombre, cls[1].saldo, cls[1].pais);
    printf("%s %f %s\n", cls[2].nombre, cls[2].saldo, cls[2].pais);

    printf("imprimendo llamando a la funcion...\n");
    imprimirCliente(cls[0]);
    imprimirCliente(cls[1]);
    imprimirCliente(cls[2]);

    printf("Imprimiendo como hay que hacerlo...\n");
    for (int i = 0; i < 3; i++) {
        imprimirCliente(cls[i]);
    }

    // leerCliente(&cls[0]); // le paso la direccion del cliente que ocupa la posicion 0 en el vector.
    printf("mete los datos de todos los clientes..\n");
    for (int i = 0; i < 3; i++) {
        printf("Introduce los datos para el cliente %d\n", i);
        leerCliente(&cls[i]);
    }

    printf("Los datos de los clientes que has introducido son ...\n");
    imprimirListaClientes(cls);

    return 0;
}

typedef struct {
    float base, altura;
} TRectangulo;

void imprimir(TRectangulo r)
{
    printf("base: %.2f, altura: %.2f\n", r.base, r.altura);
}

// aqui le pasamos los valores de un rectangulo que copio en r.
int calcularArea(TRectangulo r)
{
    int area;
    area = r.base * r.altura;
    return area;
}

// le pasamos la direccion de memoria de un rectangulo, el que vamoss a modificar
// dentro de la funcion.
void leerArea(TRectangulo* pr)
{
    printf("Introduce la base: ");
    scanf("%f", &pr->base); // pr-> PORQUE QUIERO ACCEDER AL CAMPO DE LA ESTRUCTURA CUYA DIR. ESTA EN PR!!

    // ALERT!! pr no es una estructura, es la direccion de una estructura
    // para acceder a un campo de esa direccion no se usa el .
    // scanf("%f", &pr.base);

    printf("Introduce la altura: ");
    scanf("%f", &pr->altura);
}

int main_rectangulo_funciones()
{
    // podemos inicializar las variables asi :)
    TRectangulo rect1 = {2.5, 3}, rect2 = {3, 12};
    float       area;

    imprimir(rect1); // r = rect1 (cuando hago la llamada copio los valores de rect1 en r)
    area = calcularArea(rect1);
    printf("El area es %f\n", area);
    imprimir(rect2); // r = rect2 (cuando hago la llamada copio los valores de rect2 en r)
    area = calcularArea(rect2);
    printf("El area es %f\n", area);

    // Ahora leo dos rectangulos y los imprimo
    printf("introduce los datos para el rectangulo 1:\n");
    leerArea(&rect1);
    printf("introduce los datos para el rectangulo 2:\n");
    leerArea(&rect2);
    printf("has metido los siguientes valores\n");
    imprimir(rect1); // r = rect1 (cuando hago la llamada copio los valores de rect1 en r)
    imprimir(rect2); // r = rect2 (cuando hago la llamada copio los valores de rect2 en r)
    // El area total como se calcularioa?
    area = calcularArea(rect1) + calcularArea(rect2);
    printf("La suma de las areas de los dos rectangulos es: %.2f\n", area);

    return 0;
}

int main_sin_funciones()
{
    TRectangulo rect1, rect2;
    float       area;
    printf("Introduce los datos para el rectangulo 1:\n");
    printf("Introduce la base: ");
    scanf("%f", &rect1.base);

    printf("Introduce la altura: ");
    scanf("%f", &rect1.altura);

    printf("base: %.2f, altura: %.2f\n", rect1.base, rect1.altura);
    area = rect1.base * rect1.altura;
    printf("Area del rectangulo: %.2f\n", area);

    printf("Introduce los datos para el rectangulo 2:\n");
    printf("Introduce la base: ");
    scanf("%f", &rect2.base);

    printf("Introduce la altura: ");
    scanf("%f", &rect2.altura);

    printf("base: %.2f, altura: %.2f\n", rect2.base, rect2.altura);
    area = rect2.base * rect2.altura;
    printf("Area del rectangulo: %.2f\n", area);

    return 0;
}

// Esto son tipos de datos, no ocupan memoria,
// lo que ocupa memoria, será las variables que defina
// de estos tipos.
typedef struct {
    int horas, minutos;
} THora;

int main_hora()
{
    THora h1, h2;

    h1.horas   = 12;
    h1.minutos = 23;

    h2.horas   = 23;
    h2.minutos = 59;

    printf("\n");
    printf("%02d:%02d\n", h1.horas, h1.minutos);
    printf("%02d:%02d\n", h2.horas, h2.minutos);
    printf("\n");

    printf("Introduce la hora 1 (horas y minutos separados por espacios): ");
    scanf("%d %d", &h1.horas, &h1.minutos);

    printf("Introduce la hora 2 (horas y minutos separados por espacios): ");
    scanf("%d %d", &h2.horas, &h2.minutos);

    printf("\n");
    printf("HORAS INTRODUCIDAS POR EL USUARIO\n");
    printf("%02d:%02d\n", h1.horas, h1.minutos);
    printf("%02d:%02d\n", h2.horas, h2.minutos);
    printf("\n");

    return 0;
}
