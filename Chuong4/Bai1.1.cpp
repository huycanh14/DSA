//
//  Bai1.1.cpp
//  Chuong4
//
//  Created by Kain on 28/11/2024.
//

/*
Tính giá trị ký pháp hậu tố sử dụng stack
*/

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluetionPostfix(string E)
{
  stack<int> S;
  int len = E.length();
  for (int i = 0; i < len; i++)
  {
    if (E[i] >= '0' && E[i] <= '9')
    {
      S.push(E[i] - '0');
    }
    else
    {
      // E[i] la phep toan
      int op1 = S.top();
      S.pop();
      int op2 = S.top();
      S.pop();

      switch (E[i])
      {
      case '+':
        S.push(op2 + op1);
        break;
      case '-':
        S.push(op2 - op1);
        break;
      case '*':
        S.push(op2 * op1);
        break;
      case '/':
        S.push(op2 / op1);
        break;
      case '^':
        S.push(pow(op2, op1));
        break;
      default:
        break;
      }
    }
  }

  return S.top();
}

int main(int argc, char const *argv[])
{
  string E = "636+5*9/-";
  cout << "Ket qua = " << evaluetionPostfix(E);
  return 0;
}
