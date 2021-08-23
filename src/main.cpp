#include "SDL.h"
#include "game.hpp"
#include "sprite.hpp"

int main(int argc, char* argv[]) {
  NRFGame::Game game("SDL Game", 640, 480);

  game.Run();

  return 0;
}
