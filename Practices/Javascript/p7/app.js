/*
 *  Crea una función que muestre un rango de años bisiestos yvque sean multiplos de diez
*/

//  Analiza valor de prompt() para convertirlo en entero
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

function showYear(startYear, endYear)
{
  for (i = startYear; i <= endYear; i++)
  {
    if(i%4==0 && i%10==0 && i%!100==0 || i%400==0)
    {
      document.writeln(i);
    }
  }
}
let Year1 = promptInt("Introduce el año de inicio: ");
let Year2 = promptInt("Introduce el años final: ");

showYear(Year1, Year2)
