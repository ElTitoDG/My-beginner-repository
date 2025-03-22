void main() {

  final mySquare = Square(side: -10);
  //mySquare.side = -5;

  print('Area: ${mySquare.area}');

}

class Square {
  // la _ define una variable privada en la clase
  double _side; // side*side

  // Constructor de la clase, la asercion comprueba que se cumplan unas reglas predefinidas
  Square({required double side}) : assert(side>=0, 'side must be >= 0'), _side = side;

  
  double get area {
    return _side * _side;
  }

  // setter del valor side
  set side(double value){
    print('setting new value $value');
    if (value < 0) throw 'Value must be > 0';
    _side = value;
  }

  double calculateArea() {
    return _side * _side;
  }
}