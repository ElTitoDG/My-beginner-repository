/*
 *  Crea una función que muestre un menu
*/

//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

// This function is bugged, only works if script tag is on body
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

for (i = 0; i<input; i++) {
  if (input > 7 || input < 1 || input == NaN) {
    alert("Error, input a number between 0 and 7");
    break;
  } else {
    printDoc("p", "", days[i]);
  }
}
