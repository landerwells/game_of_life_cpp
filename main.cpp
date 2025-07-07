#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <unistd.h>
#include "main.h"
#include "game_of_life.h"

int main () {
  std::string row_string;
  std::string columns_string;

  std::cout << "Enter the number of rows you would like: ";
  std::getline(std::cin, row_string);

  std::cout << "Enter the number of columns you would like: ";
  std::getline(std::cin, columns_string);

  std::unique_ptr<GameOfLife> game = std::make_unique<GameOfLife>(
      std::stoi(row_string), std::stoi(columns_string));
}

