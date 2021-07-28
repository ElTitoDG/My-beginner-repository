#include  "raylib.h"

int main(void) {

	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "Test Window");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		BeginDrawing(); 
		
		ClearBackground(RAYWHITE);
		
			DrawText("Testeando la creacion de una ventana", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;



}
