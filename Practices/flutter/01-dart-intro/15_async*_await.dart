void main() {
  emitNumbers().listen((value) {
    print('Stream value: $value');
  });
}


Stream<int> emitNumbers() async* {
  final valuesToEmit  = [1,2,3,4,5,6];

  for (int i in valuesToEmit) {
    await Future.delayed(Duration(seconds: 1));
    yield i; // Prestar valor
  }
}