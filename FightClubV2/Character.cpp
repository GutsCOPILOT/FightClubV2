#include "Character.h"
#include "raylib.h"

Character::Character(int x, int y)
    : posX(x), posY(y), speed(3), state(CharacterState::Idle), groundY(y) {}

void Character::SetIdleAnimation(std::shared_ptr<Animation> anim) {
    idleAnimation = anim;
}
void Character::SetWalkLeftAnimation(std::shared_ptr<Animation> anim) {
    walkLeftAnimation = anim;
}
void Character::SetWalkRightAnimation(std::shared_ptr<Animation> anim) {
    walkRightAnimation = anim;
}
void Character::SetJumpAnimation(std::shared_ptr<Animation> anim) {
    jumpAnimation = anim;
}
void Character::SetCrouchAnimation(std::shared_ptr<Animation> anim) {
    crouchAnimation = anim;
}

void Character::Update(bool moveLeft, bool moveRight, bool jump, bool crouch) {
    if (isJumping) {
        velocityY += gravity;
        posY += (int)velocityY;
        if (jumpAnimation) jumpAnimation->Update();

        if (posY >= groundY) {
            posY = groundY;
            isJumping = false;
            velocityY = 0;
            state = CharacterState::Idle;
        } else {
            state = CharacterState::Jumping;
        }
    } else if (jump) {
        Jump();
    } else if (crouch) {
        state = CharacterState::Crouching;
        if (crouchAnimation) crouchAnimation->Update();
    } else if (moveLeft) {
        state = CharacterState::MovingLeft;
        posX -= speed;
        if (walkLeftAnimation) walkLeftAnimation->Update();
    } else if (moveRight) {
        state = CharacterState::MovingRight;
        posX += speed;
        if (walkRightAnimation) walkRightAnimation->Update();
    } else {
        state = CharacterState::Idle;
        if (idleAnimation) idleAnimation->Update();
    }
}

void Character::Draw() {
    if (state == CharacterState::Crouching) {
        if (crouchAnimation) crouchAnimation->Draw(posX, posY);
    } else if (state == CharacterState::Jumping) {
        if (jumpAnimation) jumpAnimation->Draw(posX, posY);
    } else if (state == CharacterState::MovingLeft) {
        if (walkLeftAnimation) walkLeftAnimation->Draw(posX, posY);
    } else if (state == CharacterState::MovingRight) {
        if (walkRightAnimation) walkRightAnimation->Draw(posX, posY);
    } else {
        if (idleAnimation) idleAnimation->Draw(posX, posY);
    }
}

void Character::MoveLeft() {
    state = CharacterState::MovingLeft;
}
void Character::MoveRight() {
    state = CharacterState::MovingRight;
}
void Character::Jump() {
    if (!isJumping) {
        isJumping = true;
        velocityY = -10.0f; // força do pulo
        state = CharacterState::Jumping;
        if (jumpAnimation) jumpAnimation->Update();
    }
}
void Character::Stop() {
    state = CharacterState::Idle;
}