//
//  Bai7.cpp - De qui co nho
//  Chuong2
//
//  Created by Kain on 19/11/2024.
//

#include <iostream>
using namespace std;

// Liệt kê xâu nhị phân độ dài n

int a[100];
int n;

void GhiNhan()
{
  for (int i = 1; i <= n; i++)
    cout << a[i];
  cout << endl;
}

void Try(int k)
{ // Xac dinh bit thu k cua do dai n
  // S(k) = (0, 1) => bit luon bang 0 va 1
  for (int y = 0; y <= 1; y++)
  {
    a[k] = y;
    if (k == n)
    {
      // Ghi nhan loi giai
      GhiNhan();
    }
    else
    {
      Try(k + 1);
    }
  }
}

int main(int argc, char const *argv[])
{
  /* code */
  cout << "Nhap gia tri n = ";
  cin >> n;

  cout << "Tat ca cac xau nhi phan do dai " << n << endl;
  Try(1);
  return 0;
}
