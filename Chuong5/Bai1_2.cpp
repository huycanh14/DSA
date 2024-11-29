//
//  Bai1.3.cpp
//  Chuong5
//
//  Created by Kain on 29/11/2024.
//

/*
Insertion sort
Cách 2: Chuyển từng phần tử phía bên trái (Chuyển lần lượt)
*/

#include <iostream>
using namespace std;

void insertionSort(int a[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int temp = a[i];
    int pos = i;
    while (pos > 0 && a[pos - 1] > temp)
    {
      a[pos] = a[pos - 1];
      pos--;
    }
    a[pos] = temp;
  }
}

void printArr(int a[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
  int a[5] = {8, 4, 7, 2, 1};
  // int a[5] = {1, 2, 5, 7, 9};
  cout << "Danh sach truoc khi sap xep: " << endl;
  printArr(a, 5);
  insertionSort(a, 5);

  cout << "Danh sach sau khi sap xep: " << endl;
  printArr(a, 5);
  return 0;
}
