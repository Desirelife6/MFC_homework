//
// Created by Desirelife on 2019/7/29.
//
#include <iostream>
using namespace std;

void selectSort(int arr[], int n);
void bubbleSort(int arr[], int n);

int main(){
    /*选择排序，冒泡排序*/
    int n = 0;
    cin >> n;
    int test[n];
    for (int i = 0; i < n; i++) {
        cin >> test[i];
    }
    selectSort(test, n);
    cout << "The result of select sort is: ";
    for (int i: test) {
        cout << i << " ";
    }
    bubbleSort(test, n);
    cout << "The result of bubble sort is: ";
    for (int i: test) {
        cout << i << " ";
    }
}

/**
 * 选择排序
 * @param a
 * @param n
 */
void selectSort(int arr[], int n) {
    int k;
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[k])
                k = j;
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

/**
 * 冒泡排序
 * @param arr
 * @param n
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
