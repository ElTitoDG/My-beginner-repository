/*
 * Create a function that make the power using user input for base and exponent variables without using the Math.pow() function
*/

// parse value of prompt() to int
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

//Function that makes the power
function toPower(base, exponent) {
  let power = 1;
  for (i = 1; i <= exponent; i++) {
    power = power * base;
  }
  return power;
}

//Declaring variables for the function
let base = promptInt(" Input a base: ");
let exponent = promptInt(" Input a exponent:  ");

//Calling the function
let res = toPower(base, exponent);

//Printing the function
document.writeln("The result of the power is: ", res);
