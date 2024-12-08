//
//  Bai5.1.cpp
//  Chuong5
//
//  Created by Kain on 8/12/2024.
//

/*
Quick sort: Chọn phần tử đầy dãy làm phần tử chốt
*/
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &A, int left, int right)
{
  int i = left + 1;
  int j = right;

  // int i = left;
  // int j = right + 1;
  int pivot = A[left];

  while (i <= j)
  {
    // Tìm phần tử từ trái qua phải >= pivot
    // i = i + 1;
    // j = j - 1;
    while (i <= right && A[i] < pivot)
      i = i + 1;
    // Tìm phần tử từ phải qua trái <= pivot
    while (j > left && A[j] > pivot)
      j = j - 1;
    // if (i >= j)
    //   break;

    // swap(A[i], A[j]);

    if (i < j)
    {
      swap(A[i], A[j]);
      i = i + 1;
      j = j - 1;
    }
  }

  swap(A[j], A[left]);

  return j;
}

void quickSort(vector<int> &A, int left, int right)
{
  if (left < right)
  {
    int pivot = partition(A, left, right);
    quickSort(A, left, pivot - 1);
    quickSort(A, pivot + 1, right);
  }
}

void printVector(const vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  vector<int> A = {38, 27, 43, 3, 9, 82, 10};

  cout << "Given vector is \n";
  printVector(A);

  quickSort(A, 0, A.size() - 1);

  cout << "\nSorted vector is \n";
  printVector(A);

  return 0;
}