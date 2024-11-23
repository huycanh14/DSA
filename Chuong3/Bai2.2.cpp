//
//  Bai2.2.cpp
//  Chuong3
//
//  Created by Kain on 23/11/2024.
//

/*
Thêm vào ngay sau nút trỏ bởi con trỏ cur
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *insertNode(Node *cur, int x)
{
  Node *newNode;
  newNode = new Node;
  newNode->data = x;
  newNode->next = cur->next;
  cur->next = newNode;
  return newNode;
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
      if(i + 1 == t){
        cur = insertNode(cur, temp);
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
