//
//  Bai2.cpp
//  Chuong3
//
//  Created by Kain on 08/11/2024.
//

#include <iostream>
using namespace std;

// Xay dung ham de qui tong  S1 = a0, Sn = S(n-1) + a(n-1)
int n;
int SumArray(int list[], int k){
    if(k == n - 1) return list[k];
    return list[k] * SumArray(list, k + 1);
}

int main(int argc, const char * argv[]) {
    int list[] = { 1, 2, 3, 4, 5, 6 };
    n = 6;
    int kq = SumArray(list, 0);
    cout << "Ket qua  = " << kq << endl;
    return 0;
}

