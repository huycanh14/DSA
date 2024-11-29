//
//  Bai3.cpp
//  Chuong5
//
//  Created by Kain on 29/11/2024.
//

/*
Bubble sort
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int a[], int size)
{
  bool sorted = false;
  for (int i = 1; i <= size; i++)
  {
    if (sorted == false)
    {
      sorted = true;
      for (int j = 0; j <= size - i - 1; j++)
      {
        if (a[j] > a[j + 1])
        {
          swap(&a[j], &a[j + 1]);
          sorted = false;
        }
      }
    }
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
  bubbleSort(a, 5);

  cout << "Danh sach sau khi sap xep: " << endl;
  printArr(a, 5);
  return 0;
}
