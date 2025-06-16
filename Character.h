class Character {
public:
    Character(int x, int y);

    void Update(bool moveLeft, bool moveRight, bool jump, bool crouch);
    void Draw();

    // M�todos para setar anima��es (j� existentes)
    void SetIdleAnimation(std::shared_ptr<Animation> anim);
    void SetWalkLeftAnimation(std::shared_ptr<Animation> anim);
    void SetWalkRightAnimation(std::shared_ptr<Animation> anim);
    void SetJumpAnimation(std::shared_ptr<Animation> anim);
    void SetCrouchAnimation(std::shared_ptr<Animation> anim);

private:
    int x, y;
    float velocityX, velocityY;
    bool onGround;
    bool isCrouching;
    float gravity;
    float jumpStrength;

    // Anima��es
    std::shared_ptr<Animation> idleAnim, walkLeftAnim, walkRightAnim, jumpAnim, crouchAnim;
    std::shared_ptr<Animation> currentAnim;
};