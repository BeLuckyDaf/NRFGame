#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "gameobject.hpp"
#include "interfaces/update.hpp"

namespace NRFGame {

class BaseGame : public interfaces::IUpdate {
 protected:
  Context context_;
  std::unordered_map<std::string, std::shared_ptr<GameObject>> objects_;
  std::chrono::milliseconds target_framerate_;

  void Render();
  void SetWindowSize(int width, int height);
  void SetTargetFramerate(uint64_t framerate);
  void MoveObject(const std::string& name, int x, int y);

  template <typename ObjectType>
  void AddObject(const std::string& name, ObjectType&& object) {
    auto it = objects_.find(name);
    if (it != objects_.end()) {
      // TODO: log replacing object
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

  virtual void Create() override {}
  virtual void Update(float delta) override {}
  virtual void Destroy() override {}

 public:
  BaseGame(const std::string& name, int width, int height);
  ~BaseGame();

  void Run();
};

}  // namespace NRFGame