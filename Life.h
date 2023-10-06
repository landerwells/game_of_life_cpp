#ifndef Life_h
#define Life_h

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main (int argc, char **argv);
void PrintMatrix (char **M, int r, int c);
int countAliveNeighbors(char **M, int x, int y);

#endif
