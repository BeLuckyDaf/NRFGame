#include "game.hpp"

#include "SDL.h"
#include "sprite.hpp"

using namespace NRFGame;

Game::Game(const std::string& name, int width, int height) {
  context_.Init(name, width, height);
}

void Game::SetWindowSize(int width, int height) {
  SDL_SetWindowSize(context_.window, width, height);
}

void Game::Render() {
  SDL_SetRenderDrawColor(context_.renderer, 100, 100, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(context_.renderer);

  for (auto& name_object : objects_) {
    name_object.second->Draw();
  }

  SDL_RenderPresent(context_.renderer);
}

void Game::MoveObject(const std::string& name, int x, int y) {
  auto it = objects_.find(name);
  if (it != objects_.end()) {
    it->second->SetPosition(x, y);
  }
}

void Game::Start() {
  AddObject("object", Sprite(context_, "planet.png", 160, 160));
}

void Game::Loop() {
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
    auto obj = GetObject<Sprite>("object");
    if (obj) {
      auto rect = obj->GetRect();
      MoveObject("object", x - rect.w / 2, y - rect.h / 2);
    }
    Render();
  }
}

void Game::Exit() {
  context_.Cleanup();
  SDL_Quit();
}