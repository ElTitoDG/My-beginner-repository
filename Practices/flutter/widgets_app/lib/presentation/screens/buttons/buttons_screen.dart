import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

class ButtonsScreen extends StatelessWidget {
  static const String name = 'buttons_screen';

  const ButtonsScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Buttons Screen')),
      body: _ButtonsView(),
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.arrow_back_ios_new_rounded),
        onPressed: () {
          context.pop();
        },
      ),
    );
  }
}

class _ButtonsView extends StatelessWidget {
  const _ButtonsView();

  @override
  Widget build(BuildContext context) {
    final colors = Theme.of(context).colorScheme;

    return SizedBox(
      width: double.infinity,
      child: Padding(
        padding: EdgeInsets.symmetric(horizontal: 10, vertical: 20),
        child: Wrap(
          spacing: 10,
          crossAxisAlignment: WrapCrossAlignment.center,
          alignment: WrapAlignment.center,
          children: [
            ElevatedButton(onPressed: () {}, child: Text('Elevated')),
            const ElevatedButton(onPressed: null, child: Text('Elevated Disable')),
            ElevatedButton.icon(
              onPressed: () {},
              label: Text('Elevated Icon'),
              icon: Icon(Icons.access_alarm_rounded),
            ),

            FilledButton(onPressed: () {}, child: Text('Filled')),
            FilledButton.icon(
              onPressed: () {},
              label: Text('Filled Icon'),
              icon: Icon(Icons.accessibility_new),
            ),

            OutlinedButton(onPressed: () {}, child: Text('Outline')),
            OutlinedButton.icon(
              onPressed: () {},
              label: Text('Outline Icon'),
              icon: Icon(Icons.terminal),
            ),

            TextButton(onPressed: () {}, child: Text('Text')),
            TextButton.icon(
              onPressed: () {},
              label: Text('Text Icon'),
              icon: Icon(Icons.account_box_outlined),
            ),

            CustomButton(textColor: Colors.white),

            IconButton(
              onPressed: () {},
              icon: Icon(Icons.app_registration_outlined),
            ),
            IconButton(
              onPressed: () {},
              icon: Icon(Icons.app_registration_rounded),
              style: ButtonStyle(
                backgroundColor: WidgetStatePropertyAll(colors.primary),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

class CustomButton extends StatelessWidget {
  final Color textColor;
  const CustomButton({super.key, this.textColor = Colors.black});

  @override
  Widget build(BuildContext context) {
    final colors = Theme.of(context).colorScheme;

    return ClipRRect(
      borderRadius: BorderRadius.circular(20),

      child: Material(
        color: colors.primary,

        child: InkWell(
          onTap:() {},

          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
            
            child: Text('Custom Button', style: TextStyle(color: textColor),),
          ),
        ),
      ),
    );
  }
}