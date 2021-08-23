#include "basegame.hpp"

#include "SDL.h"
#include "sprite.hpp"

using namespace NRFGame;

BaseGame::BaseGame(const std::string& name, int width, int height) {
  context_.Init(name, width, height);
}

BaseGame::~BaseGame() {
  context_.Cleanup();
  SDL_Quit();
}

void BaseGame::SetWindowSize(int width, int height) {
  SDL_SetWindowSize(context_.window, width, height);
}

void BaseGame::Render() {
  SDL_SetRenderDrawColor(context_.renderer, 100, 100, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(context_.renderer);

  for (auto& name_object : objects_) {
    name_object.second->Draw();
  }

  SDL_RenderPresent(context_.renderer);
}

void BaseGame::MoveObject(const std::string& name, int x, int y) {
  auto it = objects_.find(name);
  if (it != objects_.end()) {
    it->second->SetPosition(x, y);
  }
}

void BaseGame::Run() {
  Start();
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
    Logic();
    Render();
  }
  Exit();
}
