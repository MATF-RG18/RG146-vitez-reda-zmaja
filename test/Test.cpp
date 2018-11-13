#include "../include/core/Engine.h"

int main(int argc, char **argv) {

  using namespace core;

  Engine *engine = new Engine();

  engine->start(&argc, argv);

  return 0;
}
