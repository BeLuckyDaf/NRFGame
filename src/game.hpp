#pragma once

#include "basegame.hpp"

namespace NRFGame {

class Game : public BaseGame {
 private:
  int x, y;

 public:
  Game(const std::string& name, int width, int height)
      : BaseGame(name, width, height) {}

  virtual void Start() override;
  virtual void Logic() override;
  virtual void Exit() override;
};

}  // namespace NRFGame