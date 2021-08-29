#include "game.hpp"

int main(int argc, char* argv[]) {
  NRFGame::Game game("SDL Game", 640, 480);

  game.Run();

  return 0;
}
