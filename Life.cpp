#include <iostream>

void PrintMatrix (char **M, int r, int c) {

  for (int i=0; i < r; i++) {
    for (int j=0; j < c; j++)
      std::cout << M[i][j] << ' ';
    std::cout << std::endl;
  }

}

int main (int argc, char *argv[]) {
  const int gameSize = 50;
  int rows = 25;
  int columns = 25;

  char **M = new char * [rows]; //Allocate the array of rows

  for (int i=0; i < rows; i++)
    M[i] = new char[columns]; //allocate the individual rows
  for (int i=0;i < rows; i++)
    for (int j=0; j < columns; j++)
      M[i][j] = 'x';

  PrintMatrix (M,rows,columns);

  for (int i=0; i < rows; i++)
    delete[] M[i]; //deallocating the row arrays
  delete[] M; //deallocating the array of pointers
  //All dynamic memory must be deallocated when
  //you're done with it.
  //Any memory created with new, must be destroyed
  //with delete.
  return 0;
}
