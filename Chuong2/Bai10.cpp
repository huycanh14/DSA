//
//  Bai10.cpp
//  Chuong2
//
//  Created by Kain on 19/11/2024.
//

#include <iostream>
using namespace std;

// Liệt kê hoán vị
int a[100];
int n, dem = 0;

void GhiNhan()
{
  dem++;
  for (int i = 1; i <= n; i++)
    cout << "Xep quan thu " << i << " o o (" << i << ", " << a[i] << ")" << endl;
}

bool Check(int j, int k)
{
  // True neu quan hau thu k co the dat duoc o o (k, j)
  // ma khong trung cot va duong cheo voi (k-1) quan hau dang co o tren ban co:
  // (1, a[1]), (2, a[2]),..., (k-1, a[k-1])

  for (int i = 1; i <= k - 1; i++)
  {
    if (j == a[i] || fabs(j - a[i]) == k - i)
    {
      return false;
    }
  }
  return true;
}

void Try(int k)
{
  /*
    Xac dinh toa do cot cua quan hau thu k dang nam o dong k
    n cot: 1, 2,...,n
    cot[j]: j != a[1], a[2],..., a[k-1]: khong cung cot
            j - a[i] != k - i voi moi i = 1, 2,..., k: khong cung duong cheo
   */
  for (int j = 1; j <= n; j++)
  {
    if (Check(j, k)) // True neu quan hau thu k co the dat duoc o o (k, j)
    {
      a[k] = j;
      if (k == n)
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
  if(dem == 0){
    cout << "Khong ton tai cach xem nao thoa man dieu kien cua de bai tren ban co co kich thuoc " << n << "x" << n << endl;
  }
  return 0;
}