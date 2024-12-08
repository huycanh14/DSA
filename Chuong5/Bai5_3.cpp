//
//  Bai5.3.cpp
//  Chuong5
//
//  Created by Kain on 8/12/2024.
//

/*
Quick sort: Chọn phần tử giữa dãy làm phần tử chốt
*/
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &A, int left, int right)
{
  int pivot = A[(left + right) / 2];
  while (left < right)
  {
    while (A[left] < pivot)
      left++;
    while (A[right] > pivot)
      right--;
    if (left < right)
    {
      swap(A[left], A[right]);
    }
  }
  return right;
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