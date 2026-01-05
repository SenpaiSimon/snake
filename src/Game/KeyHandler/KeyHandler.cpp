#include "KeyHandler.h"
#include <iostream>

namespace Game {
void KeyHandler::RegisterKey(SDL_Keycode key, Uint32 downOrUp, std::function<void()> callback) {
    keys[key] = {key, downOrUp, callback};
}

void KeyHandler::Handle(SDL_Event &event) {
    if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        if(keys.find(event.key.keysym.sym) != keys.end()) {
            if(keys[event.key.keysym.sym].downOrUp == event.type) {
                keys[event.key.keysym.sym].callback();
            }
        }
    }
}
};