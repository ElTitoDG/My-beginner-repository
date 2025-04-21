import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

class CounterScreen extends StatelessWidget {
  static const String name = 'counter-river';

  const CounterScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Counter Screen'),
      ),
      body:Center(
        child: Text('Valor: ', style: Theme.of(context).textTheme.titleLarge,),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {},
        child: Icon(Icons.add),
      ),
    );
  }
}