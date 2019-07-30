#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;
#define ERROR -1;

bool isPalindrome(string str);
void selectSort(int arr[], int n);
void bubbleSort(int arr[], int n);
int partition(int arr[], int left, int right);  // 找基准数， 做划分
void quickSort(int arr[], int left, int right);
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);
int integerBinaryConvert(string binaryString);
float decimalBinaryConvert(string binaryString);
float binaryConvert(string binaryString);
bool isPrime(int n);
int binarySearch(int arr[], int x, int low, int high);

int main() {
    /*回文串*/
    string string1;
    getline(cin, string1);
    cout << isPalindrome(string1) << endl;
    /*选择排序，冒泡排序， 快速排序， 归并排序*/
    int n = 0;
    cin >> n;
    int test[n];
    for (int i = 0; i < n; i++) {
        cin >> test[i];
    }
    selectSort(test, n);
    bubbleSort(test, n);
    quickSort(test, 0, n - 1);
    mergeSort(test, 0, n - 1);
    cout << "The result of sort is: ";
    for (int i: test) {
        cout << i << " ";
    }
    cout << endl;

    /*进制转换*/
    string binaryString;
    cin >> binaryString;
    float result = binaryConvert(binaryString);
    cout << result;
    /*判断素数*/
    int testNum;
    cin >> testNum;
    cout << isPrime(testNum) << endl;
    /*二分查找*/
    cout << binarySearch(test, 5, 0, n - 1);
    return 0;
}

/**
 * 判断回文串
 * @param str
 * @return
 */
bool isPalindrome(string str) {
    for (int i = 0; i < str.length() / 2; i++)
        if (str.at(i) != str.at(str.length() - 1 - i))
            return false;
    return true;
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

/**
 * 快速排序， 调用了自己写的 partition 方法， 详细内容在下面
 * @param arr
 * @param left
 * @param right
 */
void quickSort(int arr[], int left, int right) {
    if (left > right)
        return;
    int j = partition(arr, left, right);
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

/**
 * 归并排序， 调用了自己写的 merge 方法， 详细内容在下面
 * @param arr
 * @param low
 * @param high
 */
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

/**
 * 素数判断
 * @param n
 * @return
 */
bool isPrime(int n){
    int temp = sqrt(n);
    if(n == 1)  return false;
    for(int i = 2; i <= temp; i++)
    {
        if(n % i == 0)    return false;
    }
    return true;
}

/**
 * 二进制转换，调用了自己写的integerBinaryConvert 和 decimalBinaryConvert 方法，详细内容在下面
 */
float binaryConvert(string binaryString) {
    string integerBinaryString;
    string decimalBinaryString;
    int n = binaryString.length();
    int pos = binaryString.find('.');
    if(pos == -1){
        integerBinaryString = binaryString;
        decimalBinaryString = "0";
    } else{
        for(int i = 0; i < n; i++){
            if(binaryString[i] == '.'){
                integerBinaryString = binaryString.substr(0, i);
                decimalBinaryString = binaryString.substr(i + 1, n);
            }
        }
    }
    return integerBinaryConvert(integerBinaryString) + decimalBinaryConvert(decimalBinaryString);
}

/**
 * 二分查找
 * @param arr
 * @param x
 * @param low
 * @param high
 * @return
 */
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



/**
 * 进制转换中的整数部分
 * @param integerBinaryString
 * @return
 */
int integerBinaryConvert(string integerBinaryString){
    int n = integerBinaryString.length();
    int weights = 1;
    int intResult = 0;
    while(n--) {
        intResult += (integerBinaryString[n]-'0') * weights;
        weights *= 2;
    }
    return intResult;
}

/**
 * 进制转换中的小数部分
 * @param decimalBinaryString
 * @return
 */
float decimalBinaryConvert(string decimalBinaryString){
    int n = decimalBinaryString.length();
    float weights = 0.5;
    float decResult = 0;
    for(int i = 0; i < n; i++){
        decResult += (decimalBinaryString[i] - '0') * weights;
        weights *= 0.5;
    }
    return decResult;
}

/**
 * 快速排序找基准数，做划分
 * @param arr
 * @param left
 * @param right
 * @return
 */
int partition(int arr[], int left, int right) {
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

/**
 * 归并排序的归并操作
 * @param arr
 * @param low
 * @param mid
 * @param high
 */
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
