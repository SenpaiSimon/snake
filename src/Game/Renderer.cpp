#include "Renderer.h"
#include <iostream>

namespace Game {
Renderer::Renderer(size_t fps, SDL_Window* window) : mFps(fps), mWindow(window) {
    mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);
}

void Renderer::RegisterObject(Object::IObject* object) {
    mObjects.push_back(object);
}

void Renderer::Start() {
    mRunning = true;
}

void Renderer::Stop() {
    mRunning = false;
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Renderer::ProcessFrame() {
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            mRunning = false;
        }
    }

    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);
    
    for(const auto object : mObjects) {
        object->Update();
        object->Render();
    }

    SDL_RenderPresent(mRenderer);
    SDL_Delay(1000 / mFps);
}
};