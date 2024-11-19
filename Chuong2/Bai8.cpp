//
//  Bai8.cpp
//  Chuong2
//
//  Created by Kain on 19/11/2024.
//

#include <iostream>
using namespace std;

// Liệt kê các tập con m phần tử của tập N

int n, m, cnt, k;
int a[100], s[100];
void Ghinhan()
{
  int i;
  cnt++;
  cout << "Tap con thu " << cnt << ": ";
  for (i = 1; i <= m; i++)
    cout << a[i] << " ";
  cout << endl;
}

void MSet(int i)
{
  for (int j = a[i - 1] + 1; j <= n - m + i; j++)
  {
    a[i] = j;
    if (i == m)
      Ghinhan();
    else
      MSet(i + 1);
  }
}

int main(int argc, char const *argv[])
{
  /* code */

  cout << "Nhap n, m = ";
  cin >> n;
  cin >> m;
  a[0] = 0;
  cnt = 0;
  MSet(1);
  cout << "So tap con " << m << " phan tu cua tap " << n << " phan tu = " << cnt << endl;
  return 0;
}
