#pragma once
#include "raylib.h"
#include <vector>
#include <string>

class Animation {
public:
    Animation(const std::vector<std::string>& frameFiles, float frameTime);
    ~Animation();

    void Update();
    void Draw(int x, int y);
    void Reset();

private:
    std::vector<Texture2D> frames;
    int currentFrame;
    float frameTime;
    float timer;
};
