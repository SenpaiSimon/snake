#include "SDL.h" 

#include "Snake.h"
#include <vector>
#include <memory>

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
    "SnakeGame",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    1280,
    720,
    0
  );

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  std::vector<std::unique_ptr<Object::IObject>> objects;
  objects.push_back(std::make_unique<Object::Snake>(
    renderer, SDL_Point{10, 10}, SDL_Point{2, 2}, 40, 40)
  );

  for(int i = 0; i < 1000; i++) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    for(const auto& object : objects) {
      object->Update();
      object->Render();
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}