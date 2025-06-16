Character::Character(int x, int y)
    : x(x), y(y), velocityX(0), velocityY(0), onGround(true), isCrouching(false), gravity(0.5f), jumpStrength(-10.0f)
{}

void Character::Update(bool moveLeft, bool moveRight, bool jump, bool crouch) {
    // Movimento horizontal (no ar ou no chão)
    velocityX = 0;
    if (moveLeft) velocityX = -4;
    if (moveRight) velocityX = 4;

    // Pulo (só se estava no chão)
    if (jump && onGround) {
        velocityY = jumpStrength;
        onGround = false;
    }

    // Aplicar gravidade
    velocityY += gravity;

    // Atualizar posição
    x += static_cast<int>(velocityX);
    y += static_cast<int>(velocityY);

    // Simular chão (ajuste conforme seu cenário)
    if (y >= 305) {
        y = 305;
        velocityY = 0;
        onGround = true;
    } else {
        onGround = false;
    }

    // Agachar pode ser feito no ar ou no chão
    isCrouching = crouch;

    // Troca de animação conforme estado
    if (!onGround) {
        currentAnim = isCrouching ? crouchAnim : jumpAnim;
    } else if (isCrouching) {
        currentAnim = crouchAnim;
    } else if (velocityX != 0) {
        currentAnim = (velocityX < 0) ? walkLeftAnim : walkRightAnim;
    } else {
        currentAnim = idleAnim;
    }

    if (currentAnim) currentAnim->Update();
}

void Character::Draw() {
    if (currentAnim) currentAnim->Draw(x, y);
}