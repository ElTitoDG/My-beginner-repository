/*
 *  Crea una función que permite al usuario ingresar una base y un exponente y realiza la potencia correspondiente usando unicamente este operador +.
*/

/*
 *  La función promptInt toma una cadena como argumento
 *  y muestra una ventana de diálogo en la que se pide al usuario que ingrese un valor.
 *  El valor ingresado se convierte a un número entero y se devuelve.
 */
function promptInt(string)
{
  let input = prompt(string);
  return parseInt(input);
}

//Forma mas moderna que usar document.writeln

/*
 *  Función que crea un nuevo elemento HTML en el cuerpo del documento y le agrega contenido de texto.
 *  La función toma tres argumentos:
 *
 *  1. element: especifica el tipo de elemento HTML que se va a crear, por ejemplo, "p" para un párrafo o "h1" para un encabezado.
 *  2. string: es el contenido de texto principal que se asignará al nuevo elemento.
 *  3. extra: es un argumento opcional que contiene una cadena adicional de texto que se agregará al contenido de texto principal.
 *
 *  Si extra es null, no se agregará ninguna cadena adicional. La función crea un nuevo elemento HTML
 *  con document.createElement(element) y le asigna el contenido de texto con p.textContent = string + extra
 *  (o solo p.textContent = string si extra es null). Finalmente, agrega el elemento al documento con document.body.appendChild(p).
 */
function printDoc(element, string, extra)
{
  if (extra !== null)
  {
    let p = document.createElement(element);
    p.textContent = string + extra;
    document.body.appendChild(p);
  } else {
    let p = document.createElement(element);
    p.textContent = string;
    document.body.appendChild(p);
  }
}

/*
 *  Explicación función toPower
 *  Toma dos argumentos, la base y el exponente, y realiza la potencia unicamente usando el operador +.
 *  La función primero comprueba si el exponente es 0 y en ese caso devuelve 1. Luego, se inicializa
 *  una variable llamada "answer" con el valor de la base y una variable llamada "increment" con el valor de la base.
 *
 *  Luego, se realiza un bucle for que se ejecuta "exponent" veces. Dentro de este bucle for, hay otro bucle for
 *  que se ejecuta "base" veces. Cada vez que se ejecuta el bucle interior, la variable "answer" se actualiza sumándole "increment".
 *
 *  Después de completar el bucle interior, la variable "increment" se actualiza con el valor actual de "answer".
 *
 *  Finalmente, la función devuelve el valor de "answer" como el resultado de la potencia.
*/
function toPower(base , exponent)
{
  if (exponent == 0) return 1;

  let answer = base;
  let increment = base;

  for (i = 1; i < exponent; i++)
  {
    for (j = 1; j < base; j++)
    {
      answer = answer + increment;
      console.log("First loop: ", answer);
    }
    increment = answer;
    console.log("Second Loop: ", increment)
    }

    return answer;
}

let base = promptInt("Input base: ");
let exponent = promptInt("Input exponent: ");

let res = toPower(base, exponent);
/* Forma común en clase
  document.writeln("The final result: ", res);
*/

printDoc("p", "The final result: ", res);
