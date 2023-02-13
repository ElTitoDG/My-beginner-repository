# Documentación código 

## Code_Arduino

Este código es para un sistema de radar que usa un servo motor y un sensor de distancia para medir la distancia de los objetos en su entorno.

La biblioteca Servo.h es importada para usar el servo motor. Se declaran dos constantes, trigPin y echoPin, que son los pines utilizados para el trigger y el echo del sensor de distancia. La variable duration se utiliza para almacenar el tiempo que tarda en viajar el pulso del trigger y retornar al echo. La variable distinCM se usa para almacenar la distancia en centímetros.

El objeto "radarServo" se define como un servo motor.

En la función setup(), se establecen los modos de los pines trigPin y echoPin. Se inicia la comunicación serial y se conecta el servo motor al pin 11.

En la función loop(), se realiza un primer bucle que gira el servo desde 0 hasta 180 grados con un retardo de 50ms entre cada giro. En cada posición, se realiza una medición de distancia utilizando el sensor de distancia. Se envían los datos a la computadora a través de la comunicación serial con el formato "grados * distancia #".

Luego, se realiza un segundo bucle que gira el servo desde 180 hasta 0 grados con un retardo de 25ms entre cada giro. En cada posición, se realiza una medición de distancia utilizando el sensor de distancia. Se envían los datos a la computadora a través de la comunicación serial con el formato "grados * distancia #".

Este código permite realizar un escaneo completo de 360 grados en el entorno del radar y medir la distancia de los objetos a cada ángulo.

## Code_Processing

Este código es una aplicación de Processing que muestra un radar en pantalla. La aplicación se comunica con un dispositivo externo a través de un puerto serial y recibe información sobre el ángulo y la distancia de un objeto detectado. La información recibida se usa para dibujar líneas en la pantalla que representan la ubicación del objeto detectado.

La aplicación comienza importando las siguientes bibliotecas:

- `processing.serial`: esta biblioteca se utiliza para establecer una conexión serial con un dispositivo externo.
- `processing.opengl`: esta biblioteca se utiliza para proporcionar un soporte de gráficos en 3D.
- `java.awt.event.KeyEvent`: esta biblioteca se utiliza para manejar eventos de teclado.
- `java.io.IOException`: esta biblioteca se utiliza para manejar excepciones de entrada/salida.

Después, se definen algunas variables:

- `port`: es un objeto de la clase `Serial` que se utiliza para establecer la conexión serial con el dispositivo externo.
- `serialAngle` y `serialDistance`: son cadenas que almacenan el ángulo y la distancia del objeto detectado, respectivamente.
- `serialData`: es una cadena que almacena la información completa recibida del dispositivo externo.
- `objectDistance`: es un número flotante que representa la distancia del objeto detectado.
- `radarAngle` y `radarDistance`: son enteros que representan el ángulo y la distancia del objeto detectado, respectivamente.
- `index`: es un entero que se utiliza para almacenar la posición de un carácter específico en la cadena serialData.

La función `setup()` se utiliza para establecer las propiedades iniciales de la aplicación. Primero, se establece el tamaño de la pantalla en 1280 x 720 pixels. Luego, se activa la suavización de gráficos y se imprimen los nombres de los puertos serial disponibles. Después, se establece la conexión serial con el dispositivo externo especificando el nombre del puerto y la velocidad de transmisión de datos. Finalmente, se configura el objeto `port` para leer los datos hasta que se encuentre el carácter `#`.

La función `draw()` se utiliza para dibujar los elementos en la pantalla. Primero, se dibuja un rectángulo de fondo negro y se establecen algunas propiedades de dibujo, como el grosor de línea.

## Code_Procesing_V2

Este código es un programa escrito en Processing, un lenguaje de programación y entorno de desarrollo integrado (IDE) que utiliza Java como lenguaje base. El código crea un radar basado en una transmisión serial desde un dispositivo externo.

El programa comienza importando las siguientes bibliotecas:

- `processing.serial`: para la comunicación serial con el dispositivo externo.
- `processing.opengl`: para gráficos en 3D.
- `java.awt.event.KeyEvent`: para eventos de teclado.
- `java.io.IOException`: para manejar excepciones en la entrada/salida de datos.

Luego se declaran algunas variables:

- `port`: para almacenar una instancia de la clase Serial.
- `serialAngle`, `serialDistance` y `serialData`: para almacenar los datos recibidos a través de la transmisión serial.
- `objectDistance`, `radarAngle` y `radarDistance`: para almacenar los valores de ángulo y distancia del objeto detectado por el radar.
- `index`: una variable de tipo entero que se utiliza para separar el ángulo y la distancia recibidos a través de la transmisión serial.

La función `setup()` se ejecuta una sola vez al iniciar el programa y es utilizada para configurar el entorno de visualización, la suavidad de los gráficos, y la conexión serial con el dispositivo externo.

La función `draw()` se ejecuta continuamente y es utilizada para dibujar los elementos en la pantalla. El código dibuja varios arcos y líneas para formar un radar, y también dibuja líneas que representan la detección de objetos.

La función `serialEvent()` es llamada cada vez que se recibe un nuevo paquete de datos a través de la transmisión serial. Esta función procesa los datos recibidos, separándolos en dos partes: ángulo y distancia. Estos valores son luego asignados a las variables `radarAngle` y `radarDistance`.

En resumen, este código crea una visualización de radar que muestra la detección de objetos en tiempo real, basado en datos recibidos a través de una conexión serial con un dispositivo externo.
