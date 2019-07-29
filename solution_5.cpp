#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int integerBinaryConvert(string binaryString);
float decimalBinaryConvert(string binaryString);
float binaryConvert(string binaryString);

int main(){
    string binaryString;
    cin >> binaryString;
    float result = binaryConvert(binaryString);
    cout << result;
}

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
