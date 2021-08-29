#pragma once

namespace NRFGame::interfaces {

class Updatable {
 public:
  virtual void Create() = 0;
  virtual void Update(float delta) = 0;
  virtual void Destroy() = 0;
};

}  // namespace NRFGame