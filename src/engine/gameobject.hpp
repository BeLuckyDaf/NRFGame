#pragma once

#include "SDL.h"
#include "context.hpp"

namespace NRFGame {

class GameObject {
 protected:
  Context context_;

 public:
  virtual void SetPosition(int x, int y) = 0;
  virtual void Draw() = 0;
};

}  // namespace NRFGame