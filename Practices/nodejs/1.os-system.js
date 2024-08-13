const os = require('node:os');

console.log("Información del sistema operativo");
console.log("------------------------");

console.log("Nombre del sistema operativo: ", os.platform());
console.log("Version del sistema operativo: ", os.release());
console.log("Arquitectura: ", os.arch());
console.log("CPU: \n", os.cpus());
