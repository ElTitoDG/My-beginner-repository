/*
 * Crea una función que pida la cantidad de repeticiones y según ese número
*/

//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

// Función de suma
function totalAdd(count) {
  let ans = 0;
  for (i = 1; i <= count; i++) {
    var res = promptInt("Write a number: ");
    ans = ans + res;
  }
  return ans;
}

// Declarando parametros de la función
let input = promptInt("Number of iterations: ");

//Iniciando función
let print = totalAdd(input);

// Imprimir el resultado
document.writeln("The final result is: ", print);
