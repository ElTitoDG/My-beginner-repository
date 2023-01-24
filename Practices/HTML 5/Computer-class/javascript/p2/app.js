
function showGrade(grade)
{

  grade = parseInt(prompt("Last grade: "));

  if (grade <= 3)
  {
    alert("Very Bad");

  }
  else if (grade > 3 && grade < 5)
  {
    alert("Bad");

  }
  else if (grade >= 5 && grade < 6)
  {
    alert("Passed");

  }
  else if (grade >= 6 && grade < 9)
  {
    alert("Remarkable");

  }
  else if (grade >= 9)
  {
    alert("Outstanding");
  }

}

showGrade();
