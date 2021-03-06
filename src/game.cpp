#include "game.hpp"

#include <sprite.hpp>

using namespace NRFGame;

void Game::Create() {
  AddObject("object", Sprite(context_, "examples/planet.png", 160, 160));
  x = y = 0;
}

void Game::Update(float delta) {
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
  std::cout << fmt::format("Mouse Position: {}, {}\n", m_x, m_y);
}

void Game::Destroy() {}
