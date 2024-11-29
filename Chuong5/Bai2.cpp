//
//  Bai2.cpp
//  Chuong5
//
//  Created by Kain on 29/11/2024.
//

/*
Selection sort
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int a[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int temp, index_min = i;

    for (int j = i + 1; j < size; j++)
    {
      if (a[j] < a[index_min])
      {
        index_min = j;
      }
    }
    swap(&a[i], &a[index_min]);
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
  selectionSort(a, 5);

  cout << "Danh sach sau khi sap xep: " << endl;
  printArr(a, 5);
  return 0;
}
