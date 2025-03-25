import 'package:flutter/material.dart';

class ChatScreen extends StatelessWidget {
  const ChatScreen({super.key});
  final String urlImage = 'https://media-mad1-1.cdn.whatsapp.net/v/t61.24694-24/473393407_1353759179394154_6746389256378579898_n.jpg?ccb=11-4&oh=01_Q5AaIfB9-u8o4HK__ryoqvHJXZSv1KynsvkBYXAwSh2x1ejL&oe=67EEA5C9&_nc_sid=5e03e0&_nc_cat=111';

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: Padding(
          padding: const EdgeInsets.all(3.0),
          child: CircleAvatar(
            backgroundImage: NetworkImage(urlImage),
          ),
        ),
        title: const Text('Peque'), 
        centerTitle: false,
      ),
      
    );
  }
}