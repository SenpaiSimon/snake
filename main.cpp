#include "SDL.h" 

#include "Snake.h"
#include "Renderer.h"
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

  Game::Renderer renderer(window);
  Object::Snake player(renderer.GetRenderer(), SDL_Point{10, 10}, SDL_Point{2, 2}, 40, 40);

  renderer.RegisterObject(&player);
  renderer.Start();

  SDL_Event event;
  
  while(renderer.IsRunning()) {
    // do we stop?
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        renderer.Stop();
      }

      if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        renderer.Stop();
      }
    }

    // lets render
    if(renderer.IsRunning()) {
      renderer.ProcessFrame();
    }

    // fps
    SDL_Delay(1000 / 60);
  }


  return 0;
}