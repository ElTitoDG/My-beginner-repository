/*
 *  Crea una función que muestre un menu
*/

//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

// This function is bugged
function printDoc(element, string, extra)
{
  if (extra == undefined)
  {
    let p = document.createElement(element);
    p.textContent = string;
    document.body.appendChild(p);
  } else {
    let p = document.createElement(element);
    p.textContent = string + extra;
    document.body.appendChild(p);
  }
}

const days = [
  "Lunes",
  "Martes",
  "Miercoles",
  "Jueves",
  "Viernes",
  "Sabado",
  "Domingo"
];

let input = promptInt("Input days: ");

document.writeln("Days: ");
for (i = 0; i<input; i++) {
  printDoc("p", "", days[i]);
}
