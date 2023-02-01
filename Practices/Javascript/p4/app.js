/*
 * Create a function that inputs two numbers and the times is going to use the fibonacci function
*/

//Fibonaccio function
function fibonacci(num1, num2, count) {

  let res;

  document.writeln("First number: ", num1, "<br>");
  document.writeln("Second number: ", num2,"<br>");

  for (i = 1; i <= count; i++) {
    res = num1 + num2;
    document.writeln("Iteration ", i, ": ", res + "<br>");
    num1 = num2;
    num2 = res;
  }
}

// parse value of prompt() to int
export function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

// Initiates the function
fibonacci(
  /* num1 param */promptInt("Introduce un numero: "),
  /* num2 param */promptInt("Introduce otro numero: "),
  /* count param*/promptInt("Introduce el numero final: ")
);
