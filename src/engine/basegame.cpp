#include "basegame.hpp"

#include "SDL.h"
#include "sprite.hpp"

using namespace NRFGame;
using namespace std::chrono_literals;

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

void BaseGame::SetTargetFramerate(uint64_t /* framerate */) {}

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
  Create();
  SDL_Event event;
  auto quit = false;
  auto target_delta = 13ms;
  auto last_update = SDL_GetPerformanceCounter();
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
    auto current_update = SDL_GetPerformanceCounter();
    Update((current_update - last_update) /
           (float)SDL_GetPerformanceFrequency() * 1000.0f);
    last_update = current_update;
    Render();
  }
  Destroy();
}
