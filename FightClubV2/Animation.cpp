#include "Animation.h"

Animation::Animation(const std::vector<std::string>& frameFiles, float frameTime)
    : currentFrame(0), frameTime(frameTime), timer(0.0f)
{
    for (const auto& file : frameFiles) {
        frames.push_back(LoadTexture(file.c_str()));
    }
}

Animation::~Animation() {
    for (auto& tex : frames) {
        UnloadTexture(tex);
    }
}

void Animation::Update() {
    timer += GetFrameTime();
    if (timer >= frameTime) {
        timer = 0.0f;
        currentFrame = static_cast<int>((static_cast<size_t>(currentFrame) + 1) % frames.size());
    }
}

void Animation::Draw(int x, int y) {
    if (!frames.empty()) {
        DrawTexture(frames[currentFrame], x, y, WHITE);
    }
}

void Animation::Reset() {
    currentFrame = 0;
    timer = 0.0f;
}