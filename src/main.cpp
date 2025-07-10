#include <memory>
#include "main.h"
#include "game_of_life.h"
#include "raylib.h"

int main () {
  InitWindow(800, 450, "raylib [core] example - basic window");

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
  std::unique_ptr<GameOfLife> game = std::make_unique<GameOfLife>();
}
