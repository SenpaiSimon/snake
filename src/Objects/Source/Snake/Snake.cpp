#include "Snake.h"

#include <stdexcept>

namespace Object {
Snake::Snake(SDL_Renderer& renderer, SDL_Point startPos, SDL_Point speed, uint32_t height, uint32_t width) : mRenderer(renderer), mPos(startPos), mSpeed(speed), mHeight(height), mWidth(width) {}

void Snake::Render() {
    SDL_SetRenderDrawColor(&mRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect rect = {mPos.x, mPos.y, static_cast<int>(mWidth), static_cast<int>(mHeight)};
    SDL_RenderFillRect(&mRenderer, &rect);
}

void Snake::Update() {
    mPos.x += mSpeed.x;
    mPos.y += mSpeed.y;
}

} // namespace Object