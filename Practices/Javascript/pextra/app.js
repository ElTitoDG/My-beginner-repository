/*
  Create a function that takes a string and parse it, the prints only the selected character
*/

// Function the counts from 1 to the input number and prints it
function selectedChar(string, char)
{

  for (i = 0; i <= string.length-1; i++) {
    if (string[i] == char) {
      document.writeln(string[i] + "<br>")
    }

  }

}

//Initiates the function
selectedChar(prompt("Input a string: "), prompt("Selected character: "));
