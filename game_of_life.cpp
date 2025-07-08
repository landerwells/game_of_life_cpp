#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "game_of_life.h"

GameOfLife::GameOfLife() {
  struct winsize w;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
    perror("ioctl");
  }

  int width = w.ws_col;
  int height = w.ws_row;

  std::cout << "Terminal size: " << width << " cols x " << height << " rows\n";
  std::cout << "A new game has been created\n";

  std::vector<std::vector<GameOfLife::State>> 
  grid(height, std::vector<GameOfLife::State>(width, GameOfLife::State::Dead));

  GameOfLife::GameIter(grid);
}

void GameOfLife::GameIter(std::vector<std::vector<State>>& grid) {
  while (true) {
    // print the board
    GameOfLife::PrintBoard(grid);

    // update the board
    grid = GameOfLife::NextGrid(grid);
  }
}

void PrintBoard(std::vector<std::vector<GameOfLife::State>>& grid) {
  // Will need to extract this information from the grid or pass it in.
  if (grid[0][0] == GameOfLife::State::Dead) {
    std::cout << "The first cell is dead\n";
  }
}

std::vector<std::vector<GameOfLife::State>> 
  NextGrid(std::vector<std::vector<GameOfLife::State>>& grid) {
  // This is where the majority of the logic needs to be implemented,
  // Technically I could make this run fast using 
  return grid;
}

// int main() {
//   char **Current = new char * [rows];
//   char **Next = new char * [rows];
//
//   for (int i=0; i < rows; i++)
//     Current[i] = new char[columns]; //allocate the individual rows
//   for (int i=0;i < rows; i++)
//     for (int j=0; j < columns; j++)
//       Current[i][j] = 'x';
//
//   Next = Current;
//
//   // Make the starting shape here
//
//   // Glider
//
//   Current[12][12] = 'o';
//   Current[13][13] = 'o';
//   Current[14][11] = 'o';
//   Current[14][12] = 'o';
//   Current[14][13] = 'o';
//
//   PrintMatrix (Current,rows,columns);
//
//   while (1 == 1) {
//
//     for (int i=0;i < rows; i++) {
//       for (int j=0; j < columns; j++) {
//         int aliveNeighbors = countAliveNeighbors(Current, i, j);
//         if (Current[i][j] == 'x' && aliveNeighbors == 3) {
//           Next[i][j] = 'o';
//         }
//         else if (aliveNeighbors == 2 || aliveNeighbors == 3) {
//           continue;
//         }
//         else {
//           Next[i][j] = 'x';
//         }
//       }
//     }
//     PrintMatrix (Current,rows,columns);
//
//     Next = Current;
//     for (int i=0; i < rows; i++)
//       delete[] Current[i]; //deallocating the row arrays
//     delete[] Current; //deallocating the array of pointers
//
//     sleep(1);
//   }
// }

// Need to make multiple boards or else changing the bit inside each cell
// doesn't matter.

// int countAliveNeighbors(char **Current, int x, int y) {
//   int sum = 0;
//   for (int i = -1; i < 2; i++) {
//     for (int j = -1; j < 2; j++) {
//       int col = (x + i + columns) % columns;
//       int row = (y + j + rows) % rows;
//       if (Current[col][row] != 'x') sum+=1;
//     }
//   }
//   return sum;
// }
