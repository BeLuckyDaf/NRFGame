#pragma once

namespace NRFGame::interfaces {

class Drawable {
 public:
  virtual void SetPosition(int x, int y) = 0;
  virtual void Draw() = 0;
};

}  // namespace NRFGame