//
//  Bai2.4.cpp
//  Chuong3
//
//  Created by Kain on 23/11/2024.
//

/*
Thêm vào cuối danh sách
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *insertToLast(Node *head, int x)
{
  Node *newNode, *last;
  newNode = new Node;
  newNode->data = x;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    last = head;
    while (last->next != NULL)
    {
      last = last->next;
    }
    last->next = newNode;
  }
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

  head = insertToLast(head, 10);

  cur = head;

  cout << "\nDanh sach sau khi them nut moi vao cuoi danh sach:" << endl;

  while (cur != NULL)
  {
    showDataOfCurrentNode(cur->data);
    cur = cur->next;
  }

  return 0;
}
