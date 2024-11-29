//
//  Bai4.2.cpp
//  Chuong5
//
//  Created by Kain on 29/11/2024.
//

/*
Merge sort:
Cách 2:
dùng 1 mảng phụ tempA có kích thước bằng mảng A Đồng thời duyệt qua lần lượt từng phần tử của 2 dãy con A[p..q] và A[q+1...r] bằng cách dùng biến first1
và first2: so sánh từng cặp 2 phần tử tương ứng của 2 dãy con, chọn phần tử nhỏ hơn để chép vào mảng phụ tempA.
Kết thúc vòng lặp, tất cả các phần tử của 2 dãy con đã được duyệt qua;
khi đó mảng tempA chứa tất cả các phần tử của 2 dãy con, nhưng các phần tử đã được sắp xếp.
Copy mảng tempA chèn vào mảng A
*/

#include <iostream>
#include <vector>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
// Hàm gộp hai mảng con A[p..q] và A[q+1..r] vào một mảng phụ tempA
void merge(vector<int> &A, vector<int> &tempA, int p, int q, int r)
{
  int first1 = p;     // Chỉ số bắt đầu dãy con A[p..q]
  int first2 = q + 1; // Chỉ số bắt đầu dãy con A[q+1..r]
  int k = p;          // Chỉ số bắt đầu cho việc sao chép vào tempA

  // Duyệt qua cả hai dãy con và chép phần tử nhỏ hơn vào tempA
  while (first1 <= q && first2 <= r)
  {
    if (A[first1] <= A[first2])
    {
      tempA[k++] = A[first1++];
    }
    else
    {
      tempA[k++] = A[first2++];
    }
  }

  // Nếu dãy con đầu tiên còn phần tử, sao chép vào tempA
  while (first1 <= q)
  {
    tempA[k++] = A[first1++];
  }

  // Nếu dãy con thứ hai còn phần tử, sao chép vào tempA
  while (first2 <= r)
  {
    tempA[k++] = A[first2++];
  }

  // Sao chép lại các phần tử đã được gộp từ tempA vào A
  for (int i = p; i <= r; ++i)
  {
    A[i] = tempA[i];
  }
}

/// Hàm thực hiện thuật toán MergeSort
void mergeSort(vector<int> &A, vector<int> &tempA, int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;           // Tính chỉ số giữa mảng
    mergeSort(A, tempA, p, q);     // Sắp xếp dãy con trái
    mergeSort(A, tempA, q + 1, r); // Sắp xếp dãy con phải
    merge(A, tempA, p, q, r);      // Gộp hai dãy con đã sắp xếp
  }
}
// Function to print a vector
void printVector(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver code
int main(int argc, char **argv)
{
  vector<int> A = {38, 27, 43, 3, 9, 82, 10};
  vector<int> tempA(A.size()); // Mảng phụ có cùng kích thước với A

  cout << "Given vector is \n";
  printVector(A);

  // Gọi thuật toán MergeSort
  mergeSort(A, tempA, 0, A.size() - 1);

  cout << "\nSorted vector is \n";
  printVector(A);
  return 0;
}