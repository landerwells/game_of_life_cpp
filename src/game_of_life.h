#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <iostream>
#include <vector>

class GameOfLife {
public:
  GameOfLife();

  enum class State {
    Alive,
    Dead,
  };
private:
  void GameIter(std::vector<std::vector<GameOfLife::State>>& grid);
  void PrintBoard(std::vector<std::vector<GameOfLife::State>>& grid);
  std::vector<std::vector<GameOfLife::State>> 
  NextGrid(std::vector<std::vector<GameOfLife::State>>& grid);
  int CountAliveNeighbors(std::vector<std::vector<GameOfLife::State>>& grid, int current_row, int current_column);

  // Could create methods to create difference effects in the game.
  void CreateGlider(std::vector<std::vector<GameOfLife::State>>& grid);
};

#endif // GAME_OF_LIFE_H
