#pragma once

#include <basegame.hpp>
#include <chrono>

namespace NRFGame {

class Game : public BaseGame {
 private:
  int x, y;

 public:
  Game(const std::string& name, int width, int height)
      : BaseGame(name, width, height) {}

  virtual void Create() override;
  virtual void Update(float delta) override;
  virtual void Destroy() override;
};

}  // namespace NRFGame