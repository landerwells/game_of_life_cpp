#include <iostream>
#include <unistd.h>
#include "main.h"

// How to get the terminal window size in cpp, and also how to do a lot of 
// escape code goodness?

const int gameSize = 50;
int rows = 25;
int columns = 25;

// Need to make multiple boards or else changing the bit inside each cell
// doesn't matter.

int main() {
  char **Current = new char * [rows]; //Allocate the array of rows
  char **Next = new char * [rows]; //Allocate the array of rows

  for (int i=0; i < rows; i++)
    Current[i] = new char[columns]; //allocate the individual rows
  for (int i=0;i < rows; i++)
    for (int j=0; j < columns; j++)
      Current[i][j] = 'x';

  Next = Current;

  // Make the starting shape here

  // Glider
  
  Current[12][12] = 'o';
  Current[13][13] = 'o';
  Current[14][11] = 'o';
  Current[14][12] = 'o';
  Current[14][13] = 'o';

  PrintMatrix (Current,rows,columns);

  while (1 == 1) {

    for (int i=0;i < rows; i++) {
      for (int j=0; j < columns; j++) {
        int aliveNeighbors = countAliveNeighbors(Current, i, j);
        if (Current[i][j] == 'x' && aliveNeighbors == 3) {
          Next[i][j] = 'o';
        }
        else if (aliveNeighbors == 2 || aliveNeighbors == 3) {
          continue;
        }
        else {
          Next[i][j] = 'x';
        }
      }
    }
    PrintMatrix (Current,rows,columns);
    
    Next = Current;
    for (int i=0; i < rows; i++)
      delete[] Current[i]; //deallocating the row arrays
    delete[] Current; //deallocating the array of pointers

    sleep(1);
  }

  //All dynamic memory must be deallocated when
  //you're done with it.
  //Any memory created with new, must be destroyed
  //with delete.
  return 0;
}

void PrintMatrix (char **Current, int r, int c) {

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
  for (int i=0; i < r; i++) {
    for (int j=0; j < c; j++)
      std::cout << Current[i][j] << ' ';
    std::cout << std::endl;
  }
}

int countAliveNeighbors(char **Current, int x, int y) {
  int sum = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      int col = (x + i + columns) % columns;
      int row = (y + j + rows) % rows;
      if (Current[col][row] != 'x') sum+=1;
    }
  }
  return sum;
}
