#pragma once

#include "context.hpp"
#include "interfaces/drawable.hpp"
#include "interfaces/updatable.hpp"

namespace NRFGame {

class GameObject : public interfaces::Drawable, public interfaces::Updatable {
 protected:
  Context context_;

 public:
  GameObject(const Context& context) : context_(context) {}

  virtual void Create() override {}
  virtual void Update(float delta) override {}
  virtual void Destroy() override {}
};

}  // namespace NRFGame