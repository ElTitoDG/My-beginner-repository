import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:widgets_app/presentation/providers/counter_providers.dart';
import 'package:widgets_app/presentation/providers/theme_provider.dart';

class CounterScreen extends ConsumerWidget {
  static const String name = 'counter-river';

  const CounterScreen({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final int clickCounter = ref.watch(counterProvider);
    final bool isDarkMode = ref.watch(isDarkModeProvider);

    return Scaffold(
      appBar: AppBar(
        title: const Text('Counter Screen'),
        actions: [
          IconButton(
            onPressed: (){
              ref.read(isDarkModeProvider.notifier)
                .update((state) => !isDarkMode);
            }, 
            icon: Icon(isDarkMode ? Icons.dark_mode_outlined : Icons.light_mode_outlined)
          )
        ],
      ),
      body:Center(
        child: Text('Valor: $clickCounter', style: Theme.of(context).textTheme.titleLarge,),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          ref.read(counterProvider.notifier).state++;
          // ref.read(counterProvider.notifier).update((state) => state+1);
        },
        child: Icon(Icons.add),
      ),
    );
  }
}