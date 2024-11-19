//
//  Bai6.cpp - De qui co nho
//  Chuong2
//
//  Created by Kain on 18/11/2024.
//

#include <iostream>
using namespace std;

unsigned long long int D[100][100]; // D[n][k] = C(n, k)

unsigned int C(int n, int k)
{
  if (k == 0 || k == n)
    return 1;
  return C(n - 1, k - 1) + C(n - 1, k);
}

unsigned int C_CoNho(int n, int k)
{
  if (k == 0 || k == n)
    return 1;

  if (D[n][k] != -1)
    return D[n][k];

  D[n][k] = C_CoNho(n - 1, k - 1) + C_CoNho(n - 1, k);
  return D[n][k];
}

int main(int argc, char const *argv[])
{
  /* code */
  int n = 30, k = 20;

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      D[i][j] = -1;
    }
  }

  unsigned long long int KQ1 = C_CoNho(n, k);
  cout << "Co nho: KQ = " << KQ1 << endl;

  unsigned long long int KQ2 = C(n, k);
  cout << "Khong nho: KQ = " << KQ2 << endl;

  return 0;
}
