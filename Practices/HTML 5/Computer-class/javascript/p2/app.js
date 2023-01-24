
function showGrade(grade)
{

  grade = parseInt(prompt("Last grade: "));

  if (grade <= 3)
  {
    alert("Very Bad");

  }
  if (grade > 3 && grade < 5)
  {
    alert("Bad");

  }
  if (grade >= 5 && grade < 6)
  {
    alert("Passed");

  }
  if (grade >= 6 && grade < 9)
  {
    alert("Remarkable");

  }
  if (grade >= 9)
  {
    alert("Outstanding");
  }

}

showGrade();
