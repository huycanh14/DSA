//
//  Bai3.1.cpp
//  Chuong3
//
//  Created by Kain on 27/11/2024.
//

/*
Parenthese Matching
*/

#include <iostream>
#include <stack>
using namespace std;

bool isPair(char open, char close)
{
  if (open == '(' && close == ')')
    return true;
  if (open == '[' && close == ']')
    return true;
  if (open == '{' && close == '}')
    return true;
  return false;
}

bool parenMatch(const char *X, int n)
{
  stack<char> S;
  for (int i = 0; i < n; i++)
  {
    if (X[i] == '(' || X[i] == '[' || X[i] == '{')
    {
      S.push(X[i]);
    }
    else if (X[i] == ')' || X[i] == ']' || X[i] == '}')
    {
      if (S.empty())
        return false;

      char temp = S.top();
      S.pop();
      if (isPair(temp, X[i]) == false)
        return false;
      // Lam the nao de kiem tra temp va X[i] co di cap voi nhau hay khong
    }
  }
  return true;
}

int main(int argc, char const *argv[])
{
  bool result = parenMatch("([{}])", 6);
  if(result)
    cout << "Hop le" << endl;
  else
    cout << "Khong hop le" << endl;
  return 0;
}

