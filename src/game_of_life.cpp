#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "game_of_life.h"

GameOfLife::GameOfLife() {
  struct winsize w;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
    perror("ioctl");
  }

  int width = w.ws_col - 2;
  int height = w.ws_row - 4;

  std::cout << "Terminal size: " << width << " cols x " << height << " rows\n";
  std::cout << "A new game has been created\n";

  std::vector<std::vector<GameOfLife::State>> 
  grid(height, std::vector<GameOfLife::State>(width, GameOfLife::State::Dead));

  CreateGlider(grid);

  GameIter(grid);
}

void GameOfLife::GameIter(std::vector<std::vector<State>>& grid) {
  while (true) {
    PrintBoard(grid);
    grid = NextGrid(grid);
    // Sleep for a short duration to visualize the game
    usleep(1000);
  }
}

void GameOfLife::PrintBoard(std::vector<std::vector<GameOfLife::State>>& grid) {
    std::cout << "\033[2J\033[H";  // Clear screen

    int width = grid[0].size();

    std::cout << '+';
    for (int i = 0; i < width; ++i) std::cout << '-';
    std::cout << "+\n";

    for (const auto& row : grid) {
        std::cout << '|';
        for (const auto& cell : row) {
            if (cell == GameOfLife::State::Alive)
                std::cout << "\033[32m█\033[0m";
            else
                std::cout << ' ';
        }
        std::cout << "|\n";
    }

    std::cout << '+';
    for (int i = 0; i < width; ++i) std::cout << '-';
    std::cout << "+\n";
}

std::vector<std::vector<GameOfLife::State>> 
GameOfLife::NextGrid(std::vector<std::vector<GameOfLife::State>>& grid) {

  std::vector<std::vector<GameOfLife::State>> new_grid(grid.size(), 
    std::vector<GameOfLife::State>(grid[0].size(), GameOfLife::State::Dead));

  // Rules of Life:
  // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
  // Any live cell with two or three live neighbours lives on to the next generation.
  // Any live cell with more than three live neighbours dies, as if by overpopulation.
  // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
  // https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

  // Iterate through all cells in grid, and set the ones in new_grid
  for (size_t current_row = 0; current_row < grid.size(); current_row++) {
    for (size_t current_column = 0; current_column < grid[0].size(); current_column++) {
      int alive_neighbors = CountAliveNeighbors(grid, current_row, current_column);
      
      if (grid[current_row][current_column] == GameOfLife::State::Alive) {
        if (alive_neighbors < 2 || alive_neighbors > 3) {
          new_grid[current_row][current_column] = GameOfLife::State::Dead;
        } else {
          new_grid[current_row][current_column] = GameOfLife::State::Alive;
        }

      } else {
        if (alive_neighbors == 3) {
          new_grid[current_row][current_column] = GameOfLife::State::Alive;
        }
      }
    }
  }

  return new_grid;
}

// This method counts the alive neighbors of a cell, wrapping on overflow and 
// underflow to the bottom or top respectively.
//
// I wonder if there is a more modern way of doing this?
int GameOfLife::CountAliveNeighbors(std::vector<std::vector<GameOfLife::State>>& grid, int current_row, int current_column) {
  int sum = 0;
  for (int row_offset = -1; row_offset < 2; row_offset++) {
    for (int col_offset = -1; col_offset < 2; col_offset++) {
      if (row_offset == 0 && col_offset == 0) {
        continue; // Skip the current cell
      }
      int row = (current_row + row_offset + grid.size()) % grid.size();
      int col = (current_column + col_offset + grid[0].size()) % grid[0].size();
      if (grid[row][col] == GameOfLife::State::Alive) sum+=1;
    }
  }
  return sum;
}

void GameOfLife::CreateGlider(std::vector<std::vector<GameOfLife::State>>& grid) {
  // This is a glider pattern, it will move diagonally across the grid.
  // Should implement some error checking
  grid[12][12] = GameOfLife::State::Alive;
  grid[13][13] = GameOfLife::State::Alive;
  grid[14][11] = GameOfLife::State::Alive;
  grid[14][12] = GameOfLife::State::Alive;
  grid[14][13] = GameOfLife::State::Alive;
}
