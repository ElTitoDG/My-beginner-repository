import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:widgets_app/config/theme/app_theme.dart';

// Listado de colores inmutables
final colorListProvider = Provider((ref) => colorList);

final isDarkModeProvider = StateProvider((ref) => false);

// Un simple int
final selectedColorProvider = StateProvider((ref) => 0);

// Un objeto de tipo AppTheme
final themeNotifierProvider = StateNotifierProvider<ThemeNotifier, AppTheme>(
  (ref) => ThemeNotifier()
);

class ThemeNotifier extends StateNotifier<AppTheme> {
  // STATE = new AppTheme()
  ThemeNotifier() : super(AppTheme());

  void toggleDarkmode() {
    state = state.copyWith(isDarkMode: !state.isDarkMode);
  }

  void changeColorIndex(int colorIndex) {
    state = state.copyWith(selectedColor: colorIndex);
  }

}