import 'package:flutter/material.dart';
import 'package:yes_no_app/presentation/widgets/chat/her_message_bubble.dart';
import 'package:yes_no_app/presentation/widgets/chat/my_message_bubble.dart';
import 'package:yes_no_app/presentation/widgets/shared/message_field_box.dart';

class ChatScreen extends StatelessWidget {
  const ChatScreen({super.key});
  final String urlImage = 'https://media-mad1-1.cdn.whatsapp.net/v/t61.24694-24/473393407_1353759179394154_6746389256378579898_n.jpg?ccb=11-4&oh=01_Q5AaIfB9-u8o4HK__ryoqvHJXZSv1KynsvkBYXAwSh2x1ejL&oe=67EEA5C9&_nc_sid=5e03e0&_nc_cat=111';

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: Padding(
          padding: const EdgeInsets.all(4.0),
          child: CircleAvatar(
            backgroundImage: NetworkImage(urlImage),
          ),
        ),
        title: const Text('Peque ♥️'), 
        centerTitle: false,
      ),
      body: _ChatView(),
    );
  }
}

class _ChatView extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 10),
        child: Column(
          children: [
            Expanded(child: ListView.builder(itemCount: 100, itemBuilder: (context, index) {
              return (index % 2 == 0) ?
                const HerMessageBubble() : const MyMessageBubble();
            })),
            // Caja de texto de mensajes
            const MessageFieldBox(),
            //Expanded(child: Container(color: Colors.red,)), //Debug view
          ],
        ),
      ),
    );
  }
}