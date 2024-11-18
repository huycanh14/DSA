//
//  Bai5.cpp
//  Chuong3
//
//  Created by Kain on 18/11/2024.
//

#include <iostream>
using namespace std;

int CountPaths(int i, int j, int D, int C)
{
  if (i == D || j == C)
    return 1;
  return CountPaths(i + 1, j, D, C) + CountPaths(i, j + 1, D, C);
}

int main(int argc, char const *argv[])
{
  /* code */

  cout << CountPaths(2, 3, 4, 4);
  return 0;
}
