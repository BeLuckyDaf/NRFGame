#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "gameobject.hpp"

namespace NRFGame {

class Game {
 private:
  Context context_;
  std::unordered_map<std::string, std::shared_ptr<GameObject>> objects_;

  void Render();

 public:
  Game(const std::string& name, int width, int height);

  void Start();
  void Loop();
  void Exit();

  void SetWindowSize(int width, int height);

  void MoveObject(const std::string& name, int x, int y);

  template <typename ObjectType>
  void AddObject(const std::string& name, ObjectType&& object) {
    auto it = objects_.find(name);
    if (it != objects_.end()) {
      // log replacing object
    }
    objects_[name] = std::make_shared<ObjectType>(std::move(object));
  }

  template <typename ObjectType>
  std::shared_ptr<ObjectType> GetObject(const std::string& name) {
    auto it = objects_.find(name);
    if (it != objects_.end()) {
      return std::dynamic_pointer_cast<ObjectType>(it->second);
    }
    return nullptr;
  }

  Context& GetContext() { return context_; }
};

}  // namespace NRFGame