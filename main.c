#include <raylib.h>
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 400

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib C Dino");

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}