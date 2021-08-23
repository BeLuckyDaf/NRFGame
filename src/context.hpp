#pragma once

#include "SDL.h"
#include "common.hpp"

namespace NRFGame {

struct Context {
  SDL_Window* window;
  SDL_Renderer* renderer;

  void Init(const std::string& window_name, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (!renderer) {
      throw std::runtime_error(SDL_GetError());
    }
  }

  void Cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }
};

}  // namespace NRFGame