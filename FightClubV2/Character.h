#pragma once
#include "Animation.h"
#include <vector>
#include <string>
#include <memory>

enum class CharacterState {
    Idle,
    MovingLeft,
    MovingRight,
    Jumping,
    Crouching // Novo estado
};

class Character {
public:
    Character(int x, int y);

    void SetIdleAnimation(std::shared_ptr<Animation> anim);
    void SetWalkLeftAnimation(std::shared_ptr<Animation> anim);
    void SetWalkRightAnimation(std::shared_ptr<Animation> anim);
    void SetJumpAnimation(std::shared_ptr<Animation> anim);
    void SetCrouchAnimation(std::shared_ptr<Animation> anim); // Novo método

    void Update(bool moveLeft, bool moveRight, bool jump, bool crouch); // Adicione o parâmetro crouch
    void Draw();

    void MoveLeft();
    void MoveRight();
    void Jump();
    void Stop();

    int GetX() const { return posX; }
    int GetY() const { return posY; }

    int posX, posY;
    int speed;
    CharacterState state;

private:
    std::shared_ptr<Animation> idleAnimation;
    std::shared_ptr<Animation> walkLeftAnimation;
    std::shared_ptr<Animation> walkRightAnimation;
    std::shared_ptr<Animation> jumpAnimation;
    std::shared_ptr<Animation> crouchAnimation; // Novo membro

    // Controle de pulo
    bool isJumping = false;
    float velocityY = 0.0f;
    float gravity = 0.5f;
    int groundY;
};
