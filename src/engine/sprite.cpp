#include "sprite.hpp"

#include "SDL_image.h"

using namespace NRFGame;

Sprite::Sprite(const Context& context, const std::string& path, int width,
               int height)
    : GameObject(context) {
  texture_ = IMG_LoadTexture(context_.renderer, path.c_str());
  if (!texture_) {
    throw std::runtime_error("Could not load texture");
  }
  SetSize(width, height);
}

void Sprite::SetPosition(int x, int y) {
  rect_.x = x;
  rect_.y = y;
}

void Sprite::Draw() {
  auto result = SDL_RenderCopy(context_.renderer, texture_, NULL, &rect_);
  if (result != 0) {
    throw std::runtime_error(SDL_GetError());
  }
}

void Sprite::SetSize(int width, int height) {
  rect_.w = width;
  rect_.h = height;
}
