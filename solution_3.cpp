//
// Created by Desirelife on 2019/7/29.
//
#include <iostream>

using namespace std;

int partition(int arr[], int left, int right);  // 找基准数， 做划分
void quickSort(int arr[], int left, int right);
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int main(){
    /*快速排序，归并排序*/
    int n = 0;
    cin >> n;
    int test[n];
    for (int i = 0; i < n; i++) {
        cin >> test[i];
    }
    quickSort(test, 0, n - 1);
    cout << "The result of quick sort is: ";
    for (int i: test) {
        cout << i << " ";
    }
    mergeSort(test, 0, n - 1);
    cout << "The result of merge sort is: ";
    for (int i: test) {
        cout << i << " ";
    }
}

void quickSort(int arr[], int left, int right) {
    if (left > right)
        return;
    int j = partition(arr, left, right);
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int left, int right) {  //找基准数 划分
    int i = left + 1;
    int j = right;
    int temp = arr[left];
    while (i <= j) {
        while (arr[i] < temp) {
            i++;
        }
        while (arr[j] > temp) {
            j--;
        }
        if (i < j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j], arr[left]);
    return j;
}

void merge(int arr[], int low, int mid, int high) {    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i = low, j = mid + 1, k = 0; //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp = new(nothrow) int[high - low + 1]; //temp数组暂存合并的有序序列
    if (!temp) {    //内存分配失败
        cout << "error";
        return;
    }
    while (i <= mid && j <= high) {
        if (arr[i] <=
            arr[j]) //较小的先存入temp中
            temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid)    //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = arr[i++];
    while (j <= high)   //同上
        temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++)//将排好序的存回arr中low到high这区间
        arr[i] = temp[k];
    delete[] temp;//删除指针，由于指向的是数组，必须用 delete[]
}