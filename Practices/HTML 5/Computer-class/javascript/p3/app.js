/* Basic version of the script
count = parseInt(prompt("Input a number: "));

for (i = 1; i <= count; i++)
{
  alert("Number: " + i);
}
*/


// Function the counts from 1 to the input number and prints it
function count(count)
{

  //Chose if you want to use alert() or document.writeln(), the last one is not recomended but prints all in once
  opc = confirm("ACCEPT to use alerts and CANCEL to print on document");

  if(opc == true) //True uses alert()
  {
    for (i = 1; i <= count; i++)
    {
      alert("Number: " + i);
    }
  } else if (opc == false) //False uses document.writeln()
  {
    for (i = 1; i <= count; i++)
    {
      document.writeln("Number: " + i + "<br>");
    }
  }


}


//Initiates the function
count(prompt("Input number: "));
