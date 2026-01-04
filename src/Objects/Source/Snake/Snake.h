#pragma once

#include "IObject.h"
#include "SDL.h"

namespace Object {
class Snake: public IObject {
    public:
        Snake(SDL_Renderer& renderer, SDL_Point startPos, SDL_Point speed, uint32_t height, uint32_t width);
        void Render() final;
        void Update() final;

    private:
        SDL_Point mPos;
        SDL_Point mSpeed;
        const uint32_t mHeight;
        const uint32_t mWidth;

        SDL_Renderer& mRenderer;
};
} // namespace Object