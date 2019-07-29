//
// Created by Desirelife on 2019/7/29.
//
#include <iostream>
using namespace std;
#define ERROR -1;

int binarySearch(int arr[], int x, int low, int high);

int main(){
    int test[5] = {0, 1, 2, 4, 5};
    cout << binarySearch(test, 5, 0, 4);
}

int binarySearch(int arr[], int x, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x < arr[mid])
            high = mid - 1;
        else if (x > arr[mid])
            low = mid + 1;
        else
            return mid;
    }
    return ERROR
}
