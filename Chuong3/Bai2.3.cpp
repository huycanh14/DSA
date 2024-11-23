//
//  Bai2.3.cpp
//  Chuong3
//
//  Created by Kain on 23/11/2024.
//

/*
Thêm vào ngay trước nút trỏ bởi con trỏ cur
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

void insertBefore(Node *head, Node *cur, int x)
{
  Node *newNode;
  newNode = new Node;
  newNode->data = x;
  newNode->next = NULL;
  if (head == NULL)
  {
    head = newNode;
  }
  else if (cur == head)
  {
    head = newNode;
    newNode->next = cur;
  }
  else
  {
    Node *prev;
    prev = head;
    while (prev->next != cur)
    {
      prev = prev->next;
    }
    prev->next = newNode;
    newNode->next = cur;
  }
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

  cout << "Nhap gia tri node moi = ";
  cin >> t;

  newNode = new Node;
  newNode->data = t;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    int temp;
    cout << "Nhap vi tri muon them node moi = ";
    cin >> temp;
    int i = 0;
    for (cur = head; cur != NULL; cur = cur->next)
    {
      if (i + 1 == t)
      {
        insertBefore(head, cur, temp);
        break;
      }
      i++;
    }
  }

  cur = head;

  cout << "Danh sach sau khi them nut moi vao danh sach:" << endl;

  while (cur != NULL)
  {
    showDataOfCurrentNode(cur->data);
    cur = cur->next;
  }

  return 0;
}
