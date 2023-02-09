/*
 *  Crea una función que permite al usuario ingresar una base y un exponente y realiza la potencia correspondiente usando unicamente este operador +.
*/

/*
 *  La función promptInt toma una cadena como argumento
 *  y muestra una ventana de diálogo en la que se pide al usuario que ingrese un valor.
 *  El valor ingresado se convierte a un número entero y se devuelve.
 */
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

/*
 *  Explicación función toPower
 *  Toma dos argumentos, la base y el exponente, y realiza la potencia unicamente usando el operador +.
 *  La función primero comprueba si el exponente es 0 y en ese caso devuelve 1. Luego, se inicializa
 *  una variable llamada "answer" con el valor de la base y una variable llamada "increment" con el valor de la base.
 *
 *  Luego, se realiza un bucle for que se ejecuta "exponent" veces. Dentro de este bucle for, hay otro bucle for que se ejecuta "base" veces.
 *  Cada vez que se ejecuta el bucle interior, la variable "answer" se actualiza sumándole "increment".
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


// Forma mas moderna
// Crea un elemento p y agrega el resultado dentro de él
let p = document.createElement("p");
p.textContent = "The final result: " + res;

// Agrega el elemento p al body
document.body.appendChild(p);
