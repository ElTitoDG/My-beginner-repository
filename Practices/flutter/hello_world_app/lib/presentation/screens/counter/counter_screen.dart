import 'package:flutter/material.dart';

class CounterScreen extends StatefulWidget {

  const CounterScreen({super.key});

  @override
  State<CounterScreen> createState() => _CounterScreenState();
}

class _CounterScreenState extends State<CounterScreen> {
  int clickCounter = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Counter Screen'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text('$clickCounter', style: TextStyle(fontSize: 160, fontWeight: FontWeight.w100),),
            // Con operadores ternarios evaluamos en la propia string para determinar si mostramos o no la 's'
            Text('Click${clickCounter == 1 ? '' : 's'}', style: TextStyle(fontSize: 25),),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          setState(() { // Vuelve a renderizar el widget cada vez que se actualiza el estado
            clickCounter++; // Cuando se pulsa el boton la variable clickCounter incrementa en 1
          });
        },
        child: const Icon(Icons.plus_one),
      ),
    );
  }
}