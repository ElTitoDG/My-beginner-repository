/*
 *  Crea una función que muestre un menu
*/

//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}



let cond = 1000;

for (i = 1; i<=cond; i++)
{
  let opt = promptInt("Select option 1, 2 or 3: ");
  if( opt == 1 ) {
    document.writeln("hola");
  } else if( opt == 2 ) {
    document.writeln("Viva la vida");
  } else if( opt == 3 ) {
    document.writeln("Fin de programa")
    cond = 1; //break;
  } else {
    document.writeln("Error");
    break;
  }
}
