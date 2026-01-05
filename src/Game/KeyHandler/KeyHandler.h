#pragma once

#include "SDL.h"
#include <unordered_map>
#include <functional>

namespace Game {
struct KeyReg {
    SDL_Keycode key;
    Uint32 downOrUp; // SDL_KEYDOWN or SDL_KEYUP
    std::function<void()> callback;
};

class KeyHandler {
    public:
        KeyHandler() = default;
        ~KeyHandler() = default;

        void RegisterKey(SDL_Keycode key, Uint32 downOrUp, std::function<void()> callback);

        void Handle(SDL_Event &event);
    private:
        std::unordered_map<SDL_Keycode, KeyReg> keys;
};
} // namespace Game