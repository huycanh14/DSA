//
//  Bai2.6.cpp
//  Chuong3
//
//  Created by Kain on 23/11/2024.
//

/*
1. Tìm những nút có giá trị bằng x
2. Thêm vào trong danh sách nút có giá trị bằng x sao cho sau khi thêm vẫn được sắp xếp theo thứ tự giảm dần
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

Node *insertBefore(Node *head, int x)
{
  Node *current = head, *newNode = new Node;
  newNode->data = x;
  newNode->next = NULL;
  if (head == NULL || head->data <= x)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    while (current->next != NULL && current->next->data > x)
    {
      current = current->next;
    }

    // Chèn nút mới vào sau phần tử current
    newNode->next = current->next;
    current->next = newNode;
  }

  return head;
}

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

Node *sortLinkedList(Node *head)
{
  Node *temp = NULL;
  while (head != NULL)
  {
    temp = insertBefore(temp, head->data);
    cout << "data = " << head->data << endl;
    head = head->next;
  }
  deleteAll(head);
  return temp;
}

void findAddress(Node *head, int x)
{
  int cnt = 0;
  Node *temp = head;
  // temp = head;
  while (temp != NULL)
  {
    if (temp->data == x)
    {
      cnt++;
      cout << "Gia tri " << x << " xuat hien lan thu " << cnt << " tai dia chi: " << temp << endl;
    }
    temp = temp->next;
  }

  if (cnt == 0)
  {
    cout << "Khong xuat hien gia tri can tim trong danh sach" << endl;
  }
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

  cout << "Gia tri can tim = ";
  cin >> t;
  // Bai 1
  findAddress(head, t);

  // Bai 2
  cout << "-------------------------" << endl;
  head = sortLinkedList(head);
  cout << "Danh sach sau khi sap xep" << endl;

  cur = head;
  while (cur != NULL)
  {
    showDataOfCurrentNode(cur->data);
    cur = cur->next;
  }
  cout << endl;

  cout << "Nhap gia tri can them vao danh sach = ";
  cin >> t;

  head = insertBefore(head, t);
  cout << "Danh sach sau khi them" << endl;

  cur = head;
  while (cur != NULL)
  {
    showDataOfCurrentNode(cur->data);
    cur = cur->next;
  }
  cout << endl;

  return 0;
}
