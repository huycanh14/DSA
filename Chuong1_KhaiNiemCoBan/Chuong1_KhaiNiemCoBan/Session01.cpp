//
//  main.cpp
//  Chuong1_KhaiNiemCoBan
//
//  Created by Kain on 31/10/2024.
//


#include <iostream>
int a[] = { -2, 11, -4, 13, -5, 2};
int n = 6;

/***
 Phuong phap duyet toan bo
**/
void DuyetToanBo(){
    int maxSum = INT_MIN;
    for(int i = 0; i <= n-1; i++){
        for(int j = i; j <= n-1; j++){
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += a[k];
            }
            if(sum > maxSum) maxSum = sum;
        }
    }
    std::cout << "Phuong phap duyet toan bo: Trong luong day con lon nhat = " << maxSum << std::endl;
}

/***
 Phuong phap duyet toan bo co cai tien
**/

void DuyetToanBo_CaiTien(){
    int maxSum = INT_MIN;
    for(int i = 0; i <= n-1; i++){
        int sum = 0;
        for(int j = i; j <= n-1; j++){
            sum += a[j];
            if(sum > maxSum) maxSum = sum;
        }
    }
    std::cout << "Phuong phap duyet toan bo co cai tien: Trong luong day con lon nhat = " << maxSum << std::endl;
}

/***
 Phuong phap de qui
**/

int maxLeft(int arr[], int low, int mid){
    int sum = 0, maxSum = INT_MIN;
    for(int i = mid; i >= low; i--){
        sum += arr[i];
        if(sum > maxSum) maxSum = sum;
    }
    return maxSum;
}

int maxRight(int arr[], int mid1, int heigh){
    int sum = 0, maxSum = INT_MIN;
    for(int i = mid1; i <= heigh; i++){
        sum += arr[i];
        if(sum > maxSum) maxSum = sum;
    }
    return maxSum;
}

int maxSub(int arr[], int low, int heigh){
    if(low == heigh) return a[low];
    int mid = (low + heigh)/2;
    int wL = maxSub(arr, low, mid);
    int wR = maxSub(arr, mid + 1, heigh);
    int wM = maxLeft(arr, low, mid) + maxRight(arr, mid + 1, heigh);
    return std::max(wL, std::max(wR, wM));
}

void DeQui(){
    int maxSum = maxSub(a, 0, n - 1);
    std::cout << "Phuong phap de qui: Trong luong day con lon nhat = " << maxSum << std::endl;
}

/***
 Phuong phap quy hoach dong
**/

void QuyHoachDong(){
    int ei = a[0];
    int si = a[0];
    for(int i = 1; i <= n-1; i++){
        ei = std::max(a[i], a[i]+ ei);
        si = std::max(si, ei);
    }
    std::cout << "Phuong phap qui hoach dong: Trong luong day con lon nhat = " << si << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    DuyetToanBo();
    DuyetToanBo_CaiTien();
    DeQui();
    QuyHoachDong();
    return 0;
}
