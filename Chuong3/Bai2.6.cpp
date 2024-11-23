//
//  Bai2.6.cpp
//  Chuong3
//
//  Created by Kain on 23/11/2024.
//

/*
Xoá tất cả các nút trong danh sách
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *deleteAll(Node *head)
{
  Node *del;
  del = head;
  while (del != NULL)
  {
    head = head->next;
    delete del;
    del = head;
  }
  return head;
}

int isEmpty(Node *head)
{
  return head == NULL ? 1 : 0;
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

  head = deleteAll(head);
  int result = isEmpty(head);
  if(result == 1){
    cout << "Da xoa danh sach thanh cong" << endl;
  } else{
    cout << "Xoa danh sach that bai" << endl;
  }

  return 0;
}
