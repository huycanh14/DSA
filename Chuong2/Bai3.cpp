//
//  Bai3.cpp
//  Chuong2
//
//  Created by Kain on 08/11/2024.
//

#include <iostream>
using namespace std;
// HanoiTower
int cnt = 0;
void HanoiTower(int n, char a, char c, char b)
{
  if (n == 1)
  {
    cnt++;
    cout << cnt << ") Chuyen dia tu coc " << a << " sang coc " << c << endl;
  }
  else
  {
    HanoiTower(n - 1, a, b, c);
    HanoiTower(1, a, c, b);
    HanoiTower(n - 1, b, c, a);
  }
}

int main(int argc, char const *argv[])
{
  /* code */
  int n;
  cout << "Nhap so luong dia: n = ";
  cin >> n;
  HanoiTower(n, 'a', 'c', 'b');
  return 0;
}
