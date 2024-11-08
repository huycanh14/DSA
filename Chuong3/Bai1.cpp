//
//  main.cpp
//  Chuong3
//
//  Created by Kain on 08/11/2024.
//

#include <iostream>
using namespace std;

// Xay dung cong thuc de quy: helperProd(list, k) = list[k] * list[k + 1] *...* list[list.size - 1]
int listSize;
int helperProd(int list[], int k){
    if(k == listSize - 1) return list[k];
    return list[k] * helperProd(list, k + 1);
}

int main(int argc, const char * argv[]) {
    int list[] = { 1, 3, 3, 4 };
    listSize = 4;
    int kq = helperProd(list, 0);
    cout << "Ket qua = " << kq << endl;
    return 0;
}
