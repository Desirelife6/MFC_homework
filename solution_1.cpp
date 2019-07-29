//
// Created by Desirelife on 2019/7/29.
//
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    /*回文串*/
    string string1;
    getline(cin, string1);
    cout << isPalindrome(string1) << endl;
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
