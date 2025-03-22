void main() {
  final String pokemon = 'Ditto';
  final int hp = 100;
  final bool isAlive = true;
  final List<String> abilities = ['impostor'];  // Forma de definir una lista de datos
  // ignore: unused_local_variable
  final abilities2 = <String>['sus'];           // Otra forma de definir una lista
  final sprites = ['ditto/front.png', 'ditto/back.png'];

  // dynamic == null
  // Tipo de dato dynamic, puede ser cualquier tipo de dato
  // ignore: unused_local_variable
  dynamic errorMsg = 'Hola';
  errorMsg = true;
  errorMsg = [1, 2, 3, 4, 5, 6, 7];
  errorMsg = null;


  print("""
    $pokemon
    $hp
    $isAlive
    $abilities
    $sprites
  """);
}