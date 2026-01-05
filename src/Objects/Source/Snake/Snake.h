#pragma once

#include "IObject.h"
#include "SDL.h"

namespace Object {
class Snake: public IObject {
    public:
        Snake(SDL_Renderer& renderer, SDL_Point startPos, SDL_Point speed, uint32_t height, uint32_t width);
        void Render() final;
        void Update() final;

        void SetVel(SDL_Point vel) { mSpeed = vel; };
        void SetPos(SDL_Point pos) { mPos = pos; };

        SDL_Point GetVel() { return mSpeed; };
        SDL_Point GetPos() { return mPos; };

    private:
        SDL_Point mPos;
        SDL_Point mSpeed;
        const uint32_t mHeight;
        const uint32_t mWidth;

        SDL_Renderer& mRenderer;
};
} // namespace Object