/*
 *  Crea una función que calcule la potencia pidiendo al usuario tanto la base como el exponente sin usar Math.pow()
*/

//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

//Función que hace la potencia
function toPower(base, exponent) {
  let power = 1;
  let res = 1;
  for (i = 1; i <= exponent; i++) {
    power = power + res;
    for (i=1; i<=base; i++) {
      res = res + base;
    }
  }
  return power;
}

//Declarando variables para la función
let base = promptInt(" Input a base: ");
let exponent = promptInt(" Input a exponent:  ");

//Llamando a la función
let ress = toPower(base, exponent);

//Enseñando resultado
document.writeln("The result of the power is: ", ress);
