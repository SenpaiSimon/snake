#include "SDL.h" 

#include "Snake.h"
#include "Renderer.h"
#include "KeyHandler.h"
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
  Game::KeyHandler keyHandler;
  const auto snakeSpeed = 5;
  Object::Snake player(renderer.GetRenderer(), SDL_Point{10, 10}, SDL_Point{snakeSpeed, 0}, 40, 40);

  renderer.RegisterObject(&player);
  renderer.Start();

  // register keys
  keyHandler.RegisterKey(SDLK_ESCAPE, SDL_KEYDOWN, std::bind(&Game::Renderer::Stop, &renderer));

  keyHandler.RegisterKey(SDLK_UP, SDL_KEYDOWN,    std::bind(&Object::Snake::SetVel, &player, SDL_Point{  0, -snakeSpeed}));
  keyHandler.RegisterKey(SDLK_DOWN, SDL_KEYDOWN,  std::bind(&Object::Snake::SetVel, &player, SDL_Point{  0,  snakeSpeed}));
  keyHandler.RegisterKey(SDLK_RIGHT, SDL_KEYDOWN, std::bind(&Object::Snake::SetVel, &player, SDL_Point{ snakeSpeed,   0}));
  keyHandler.RegisterKey(SDLK_LEFT, SDL_KEYDOWN,  std::bind(&Object::Snake::SetVel, &player, SDL_Point{-snakeSpeed,   0}));



  SDL_Event event;
  
  while(renderer.IsRunning()) {
    // do we stop?
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        renderer.Stop();
      }

      keyHandler.Handle(event);
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