import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

class SnackbarScreen extends StatelessWidget {
  static const name = 'snackbar_screen';

  const SnackbarScreen({super.key});

  void showCustomSnackbar(BuildContext context) {
    ScaffoldMessenger.of(context).clearSnackBars();
    final snackbar = SnackBar(
      content: Text('Hola Mundo'),
      action: SnackBarAction(label: 'Ok!', onPressed: (){}),
      duration: const Duration(seconds: 2),
    );

    ScaffoldMessenger.of(context).showSnackBar(snackbar);
  }

  void openDialog(BuildContext context) {
    showDialog(context: context, barrierDismissible: false, builder: (context) => AlertDialog(
      title: Text('Estas seguro?'),
      content: Text('Test content'),
      actions: [
        TextButton(onPressed: () => context.pop(), child: Text('Cancelar')),
        FilledButton(onPressed: () => context.pop(), child: Text('Aceptar'))
      ],
    ));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Snackbar y Diálagos'),
      ),
      
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            FilledButton.tonal(
              onPressed: (){
                showAboutDialog(
                  context: context,
                  barrierDismissible: false,
                  children: [
                    Text('App Info')
                  ]
                );
              }, 
              child: Text('Licencias usadas')
            ),

            SizedBox(height: 10),
            
            FilledButton.tonal(
              onPressed: () => openDialog(context), 
              child: Text('Mostrar diálogos')
            ),
          ],
        ),
      ),

      floatingActionButton: FloatingActionButton.extended(
        label: Text('Mostrar Snackbar'),
        icon: Icon(Icons.remove_red_eye_outlined),
        onPressed: () => showCustomSnackbar(context)
      ),
    );
  }
}