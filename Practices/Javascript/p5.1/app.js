/*
 *  Crea una función que calcule la potencia pidiendo al usuario tanto la base como el exponente sin usar Math.pow()
*/
//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

  /*Solo funciona si a > 0 y b > 0 */
//Función para hacer potencia
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

document.writeln("The final result: ", res);
