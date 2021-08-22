#include "game.hpp"

#include "SDL.h"

using namespace NRFGame;

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