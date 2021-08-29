namespace NRFGame::interfaces {

class IUpdate {
 public:
  virtual void Create() = 0;
  virtual void Update(float delta) = 0;
  virtual void Destroy() = 0;
};

}  // namespace NRFGame