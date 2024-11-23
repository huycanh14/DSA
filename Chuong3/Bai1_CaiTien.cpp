//
//  Bai1_CaiTien.cpp
//  Chuong3
//
//  Created by Kain on 23/11/2024.
//

/*
Cho danh sách các số nguyên được lưu trữ bởi danh sách liên kết đơn.
Nhập n từ bàn phìm: số lượng nút trong danh sách
a. Tạo danh sách lư trữ số nguyên
b. In các số nguyên trong danh sách ra màn hình (duyệt danh sách)
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

void showDataOfCurrentNode(int data)
{
  cout << data << " ---> ";
}

int main(int argc, char const *argv[])
{
  /* code */
  int n, t;
  cout << "Nhap so luong nut trong danh sach: ";
  cin >> n;

  if (n <= 0)
  {
    cout << "Khong co so luong nut";
    return 0;
  }

  Node *head, *newNode, *tail;

  for (int i = 0; i < n; i++)
  {
    cout << "Nhap gia tri thu " << i + 1 << " = ";
    cin >> t;
    newNode = new Node;
    newNode->data = t;

    if (i == 0)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }
  newNode->next = NULL;

  Node *cur;
  for (cur = head; cur != NULL; cur = cur->next)
  {
    showDataOfCurrentNode(cur->data);
  }

  return 0;
}
