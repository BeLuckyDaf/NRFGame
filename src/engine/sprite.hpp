#pragma once

#include <string>

#include "gameobject.hpp"

namespace NRFGame {

class Sprite : public GameObject {
 private:
  SDL_Texture* texture_;
  SDL_Rect rect_;

 public:
  Sprite(const Context& context, const std::string& path, int width,
         int height);

  virtual void SetPosition(int x, int y) override;
  virtual void Draw() override;

  void SetSize(int width, int height);

  SDL_Rect& GetRect() { return rect_; };
};

}  // namespace NRFGame