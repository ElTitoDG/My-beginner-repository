void main() {
  print(greetEveryone()); 
  print('Suma: ${addTwoNum(10, 20)}');
  print('Suma: ${addTwoNumOp(10)}');
  print(greetPerson(name: 'Julian'));
}

// Funcion de flecha
String greetEveryone2() => 'Hello Everyone';

String greetEveryone() {
  return 'Hello EveryOne';
}
int addTwoNum(int a, int b) => a+b;
int addTwoNumOp(int a, [int b = 0]) {
  // b ??= 0; // Valor por defecto es 0
  // Donde b es opcional
  return a+b;
}

// Trata dos parametros opcionales, pero obliga a poner name
String greetPerson({required String name, String message = 'Hola'}) {
  return '$message, $name';
}