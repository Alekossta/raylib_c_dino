#include <raylib.h>
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 400

const float jumpDuration = 0.1f;
const float playerStartingY = SCREEN_HEIGHT - 64;
const float gravity = 4500.f;
const float playerJumpForce = 1250.f;

bool bIsJumping = false;
float jumpTimer = 0.0f;

float playerY = playerStartingY;
float playerVelocityY = 0;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib C Dino");

    // load dino texture
    Texture2D dinoTexture = LoadTexture("assets/Dino.png");

    while(!WindowShouldClose())
    {
        bool playerInGround = playerY >= playerStartingY;
        // input
        if(IsKeyPressed(KEY_SPACE) && playerInGround)
        {
            bIsJumping = true;
            jumpTimer = jumpDuration;
            playerVelocityY = -playerJumpForce;
        }

        // update
        if(jumpTimer > 0)
        {
            jumpTimer -= GetFrameTime();
            if(jumpTimer <= 0)
            {
                bIsJumping = false;
            }
        }

        // apply gravity 
        if(!playerInGround)
        {
            playerVelocityY += GetFrameTime() * gravity;
        }
        else if (!bIsJumping)
        {
            playerVelocityY = 0;
            playerY = playerStartingY;
        }

        playerY += GetFrameTime() * playerVelocityY;

        // render
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(dinoTexture, (Vector2){25, playerY}, 0.f, 2.f, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}