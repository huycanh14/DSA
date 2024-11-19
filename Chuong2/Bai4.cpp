//
//  Bai4.cpp
//  Chuong2
//
//  Created by Kain on 18/11/2024.
//

#include <iostream>
using namespace std;

int Palindrome(int start, int end, char str[])
{
  if (start >= end)
    return 1;
  else if (str[start] == str[end])
    return Palindrome(start + 1, end - 1, str);
  else
    return -1;
}

int main(int argc, char const *argv[])
{
  /* code */
  char str[] = "DEEDE";
  int start = 0;
  int end = 4;
  int result = Palindrome(start, end, str);
  if (result == 1)
  {
    cout << "Ke qua la Palindrome" << endl;
  }
  else
  {
    cout << "Ke qua khong la Palindrome" << endl;
  }

  return 0;
}
