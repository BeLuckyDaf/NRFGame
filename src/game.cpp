#include "game.hpp"

#include "SDL.h"
#include "sprite.hpp"

using namespace NRFGame;

void Game::Start() {
  AddObject("object", Sprite(context_, "planet.png", 160, 160));
  x = y = 0;
}

void Game::Logic() {
  int m_x, m_y;
  SDL_GetMouseState(&m_x, &m_y);
  auto obj = GetObject<Sprite>("object");
  if (obj) {
    auto rect = obj->GetRect();
    int target_x = m_x - rect.w / 2;
    int target_y = m_y - rect.h / 2;
    x += target_x > x ? 1 : -1;
    y += target_y > y ? 1 : -1;
    MoveObject("object", x, y);
  }
}

void Game::Exit() {}
