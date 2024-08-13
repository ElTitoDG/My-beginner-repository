const fs = require('node:fs');

console.log("Leyendo el primer archivo");
fs.readFile('./test.txt', 'utf-8', (err, text) => {
  console.log(text);
});


console.log("Leyendo el segundo archivo");
fs.readFile('./test2.txt', 'utf-8', (err, text) => {
  console.log(text);
});
