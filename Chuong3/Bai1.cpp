//
//  Bai1.cpp
//  Chuong3
//
//  Created by Kain on 22/11/2024.
//

/*
Cho danh sách các số nguyên được lưu trữ bởi danh sách liên kết đơn
a. Tạo danh sách lư trữ 3 số nguyên 1, 2, 3
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
  cout << "Data = " << data << endl;
}

int main(int argc, char const *argv[])
{
  /* code */
  Node *head, *second = NULL, *third = NULL;

  head = new Node;
  second = new Node;
  third = new Node;

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  Node *cur;
  for (cur = head; cur != NULL; cur = cur->next)
  {
    showDataOfCurrentNode(cur->data);
  }

  delete head;
  delete second;
  delete third;

  return 0;
}
