#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main ();
void PrintMatrix (char **M, int r, int c);
int countAliveNeighbors(char **M, int x, int y);
#endif // MAIN_H
