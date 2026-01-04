#pragma once

#include "IObject.h"
#include "SDL.h"
#include <vector>

namespace Game {
class Renderer {
    public:
        Renderer(size_t fps, SDL_Window* window);
        ~Renderer() = default;

        void RegisterObject(Object::IObject* object);
        void Start();
        void Stop();
        void ProcessFrame();
        bool IsRunning() const { return mRunning; }

        SDL_Renderer& GetRenderer() { return *mRenderer; }

    private:
        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;

        size_t mFps;
        bool mRunning;
        std::vector<Object::IObject*> mObjects;
};
} // namespace Game