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

  Game::Renderer renderer(60, window);
  Object::Snake player(renderer.GetRenderer(), SDL_Point{10, 10}, SDL_Point{2, 2}, 40, 40);

  renderer.RegisterObject(&player);
  renderer.Start();

  while(renderer.IsRunning()) {
    renderer.ProcessFrame();
  }

  renderer.Stop();


  return 0;
}