//
//  Bai2.5.cpp
//  Chuong3
//
//  Created by Kain on 23/11/2024.
//

/*
Xóa nút trỏ bởi con trỏ "del" của danh sách có nút đầu tiên trỏ bởi con trỏ "head"
Hàm trả về địa chỉ của nút đầu tiên của danh sách sau khi xóa
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *deleteNode(Node *head, Node *del)
{
  if (head == del)
  {
    head = del->next;
  }
  else
  {
    Node *prev;
    prev = head;
    while (prev->next != del)
    {
      prev = prev->next;
    }
    prev->next = del->next;
  }
  delete del;
  return head;
}

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
  cout << endl;

  cout << "Nhap vi tri muon xoa = ";
  cin >> t;

  Node *del = head;
  for (int i = 0; i < n; i++)
  {
    if (i + 1 == t)
    {
      break;
    }
    del = del->next;
  }

  head = deleteNode(head, del);

  cur = head;

  cout << "Danh sach sau khi xoa nut khoi danh sach:" << endl;

  while (cur != NULL)
  {
    showDataOfCurrentNode(cur->data);
    cur = cur->next;
  }

  return 0;
}
