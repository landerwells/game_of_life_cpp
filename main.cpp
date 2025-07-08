// #include <cstdio>
#include <iostream>
#include <memory>
#include "main.h"
#include "game_of_life.h"

int main () {
  std::unique_ptr<GameOfLife> game = std::make_unique<GameOfLife>();
}

