#include "../include/raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  const int screenWidth = 800;
  const int screenHeight = 400;

  InitWindow(screenWidth, screenHeight, "Test 3D in raylib");

  Camera3D camera = { 0 };
  camera.position = (Vector3){0.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubepos = {0.0f, 0.0f, 0.0f};
  Vector3 cubesize = {2.0f, 2.0f, 2.0f};
  Vector2 cubeScreenPos = {0.0f, 0.0f};

  SetCameraMode(camera, CAMERA_FREE);

  SetTargetFPS(60);

  /*Main Game Loop*/
  while(!WindowShouldClose())
  {

    char EnemyText[] = "Enemy 100/100";
    char cubeText[] = "Text is always in top of the cube";

    UpdateCamera(&camera);

    cubeScreenPos = GetWorldToScreen((Vector3){cubepos.x, cubepos.y + 2.5f, cubepos.z}, camera);

    BeginDrawing();
      ClearBackground(RAYWHITE);

      BeginMode3D(camera);
        DrawCubeV(cubepos, cubesize, RED);
        DrawCubeWiresV(cubepos, cubesize, MAROON);
        DrawGrid(10, 1.0f);
      EndMode3D();

      DrawText(EnemyText, (int)cubeScreenPos.x - MeasureText(EnemyText, 20)/2, (int)cubeScreenPos.y, 20, BLACK);
      DrawText(cubeText, (screenWidth - MeasureText(cubeText, 20))/2, 25, 20, GRAY);
      DrawFPS(10, 10);
    EndDrawing();
  }

  return 0;
}
