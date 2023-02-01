/*
 * Create a function that inputs two numbers and the times is going to use the fibonacci function
*/

// parse value of prompt() to int
function promptInt(string) {
  let input = prompt(string);
  return parseInt(input);
}

//totalAdd function
function totalAdd(count) {
  let ans = 0;
  for (i = 1; i <= count; i++) {
    var res = promptInt("Write a number: ");
    ans = ans + res;
  }
  return ans;
}

let input = promptInt("Number of iterations: ");

let print = totalAdd(input);

document.writeln(print);
