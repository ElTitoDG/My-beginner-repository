/*
 *  Crea una función que calcule la multiplicación sin usar el operardor *
*/

//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

// Función de multiplicación
function mult(number, mult) {
  let res = 0;

  for (i=1; i<=mult; i++) {
    res = res + number;
  }

  return res;
}

// Establecemos los parametros
let number = promptInt("Enter the multiplied: ");
let multi = promptInt("Enter the multiplier: ");

//Guardamos el resultado en una variable
let final = mult(number, multi);

//Imprimimos el resultado
document.writeln("The result is: ", final);
