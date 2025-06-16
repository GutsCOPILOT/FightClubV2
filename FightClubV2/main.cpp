#include "raylib.h"
#include "Animation.h"
#include "Character.h"
#include <vector>
#include <string>
#include <memory>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Joguin ai");
    SetTargetFPS(60);

    // Background animation
    std::vector<std::string> bgFiles;
    for (int i = 0; i < 27; ++i) {
        bgFiles.push_back("assets/background/" + std::to_string(i) + ".png");
    }
    Animation background(bgFiles, 0.1f);

    // Character
    Character player(100, 305); // Initialize player with position (100, 305)

    // Idle animation
    std::vector<std::string> idleFiles;
    for (int i = 0; i < 7; ++i) {
        idleFiles.push_back("assets/player/parado/" + std::to_string(i) + ".png");
    }
    Animation playerIdle(idleFiles, 0.12f);

    // Walk left animation
    std::vector<std::string> walkLeftFiles;
    for (int i = 0; i < 8; ++i) {
        walkLeftFiles.push_back("assets/player/A/" + std::to_string(i) + ".png");
    }
    Animation playerWalkLeft(walkLeftFiles, 0.10f);

    // Walk right animation (use your right-walk frames here)
    std::vector<std::string> walkRightFiles;
    for (int i = 0; i < 8; ++i) {
        walkRightFiles.push_back("assets/player/D/" + std::to_string(i) + ".png");
    }
    Animation playerWalkRight(walkRightFiles, 0.10f);

    // Jump animation
    std::vector<std::string> jumpFiles;
    for (int i = 0; i < 8; ++i) { // ajuste a quantidade conforme seus frames
        jumpFiles.push_back("assets/player/W/" + std::to_string(i) + ".png");
    }
    Animation playerJump(jumpFiles, 0.10f);

    // Crouch animation
    std::vector<std::string> crouchFiles;
    for (int i = 0; i < 8; ++i) { // ajuste conforme seus frames
        crouchFiles.push_back("assets/player/S/" + std::to_string(i) + ".png");
    }
    Animation playerCrouch(crouchFiles, 0.10f);

    // Set animations for the player
    player.SetIdleAnimation(std::make_shared<Animation>(playerIdle));
    player.SetWalkLeftAnimation(std::make_shared<Animation>(playerWalkLeft));
    player.SetWalkRightAnimation(std::make_shared<Animation>(playerWalkRight));
    player.SetJumpAnimation(std::make_shared<Animation>(playerJump));
    player.SetCrouchAnimation(std::make_shared<Animation>(playerCrouch));

    while (!WindowShouldClose()) {
        bool movingLeft = IsKeyDown(KEY_A);
        bool movingRight = IsKeyDown(KEY_D);
        bool jumping = IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE);
        bool crouching = IsKeyDown(KEY_S); // Novo

        background.Update();
        player.Update(movingLeft, movingRight, jumping, crouching);

        BeginDrawing();
        ClearBackground(BLACK);
        background.Draw(0, 0);
        player.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}