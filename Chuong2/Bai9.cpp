//
//  Bai9.cpp
//  Chuong2
//
//  Created by Kain on 19/11/2024.
//

#include <iostream>
using namespace std;

// Liệt kê hoán vị
int a[100];
int n;

void GhiNhan()
{
  for (int i = 1; i <= n; i++)
    cout << a[i];
  cout << endl;
}

bool Check(int j, int k)
{
  // true: gia tri j da duoc gan cho a[k] ==> j != a[1], a[2],..., a[k-1]
  for (int i = 1; i <= k - 1; i++)
  {
    if (j == a[i])
    {
      return false;
    }
  }
  return true;
}

void Try(int k)
{
  // Sk = {1, 2,..., n} \ {a[1], a[2],...,a[k-1]}
  for (int j = 1; j <= n; j ++){
    if(Check(j, k)){
      a[k] = j;
      if(k == n)
        GhiNhan();
      else
        Try(k + 1);
    }
  }
}

int main(int argc, char const *argv[])
{
  /* code */
  cout << "Nhap gia tri n = ";
  cin >> n;
  Try(1);
  return 0;
}