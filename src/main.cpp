#include "SDL.h"
#include "game.hpp"
#include "sprite.hpp"

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  NRFGame::Game game;
  auto& context = game.GetContext();
  context.Init("SDL Game", 640, 480);

  game.AddObject("object", NRFGame::Sprite(context, "planet.png", 160, 160));

  SDL_Event event;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
    int x, y;
    SDL_GetMouseState(&x, &y);
    auto obj = game.GetObject<NRFGame::Sprite>("object");
    if (obj) {
      auto rect = obj->GetRect();
      game.MoveObject("object", x - rect.w / 2, y - rect.h / 2);
    }
    game.Render();
  }

  SDL_DestroyWindow(context.window);
  SDL_Quit();

  return 0;
}
