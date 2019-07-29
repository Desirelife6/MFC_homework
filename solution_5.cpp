//
// Created by Desirelife on 2019/7/29.
//
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n);

int main(){
    int n;
    cin >> n;
    cout << isPrime(n) << endl;
}

bool isPrime(int n){
    int temp = sqrt(n);
    if(n == 1)  return false;
    for(int i = 2; i <= temp; i++)
    {
        if(n % i == 0)    return false;
    }
    return true;
}
