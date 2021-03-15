/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 9:37
 * @description:
 */
#include <iostream>
#include <string>
using namespace std;

string add(const string a, const string b){
    string res;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int extra = 0;
    while (i >= 0 && j >= 0){
        res = to_string((a[i] - '0' + b[j] - '0' + extra) % 10) + res;
        extra = (a[i] - '0' + b[j] - '0' + extra) / 10;
        i--;
        j--;
    }
    while (i >= 0){
        res = to_string((a[i] - '0' + extra) % 10) + res;
        extra = (a[i] - '0' + extra) / 10;
        i--;
    }
    while (j >= 0){
        res = to_string((b[j] - '0' + extra) % 10) + res;
        extra = (b[j] - '0' + extra) / 10;
        j--;
    }
    if (extra != 0)
        res = to_string(extra) + res;
    return res;
}

string _mul(const string a, const char b){
    string res;
    int extra = 0;
    int i = a.size() - 1;
    while (i >= 0){
        res = to_string(((a[i] - '0') * (b - '0') + extra) % 10) + res;
        extra = ((a[i] - '0') * (b - '0') + extra) / 10;
        i--;
    }
    if (extra != 0)
        res = to_string(extra) + res;
    return res;
}

string multiply(const string a, const string b){
    string res;
    for (int i = b.size() - 1; i >= 0; i--){
        string temp = _mul(a, b[i]);
        for (int j = 0; j < (int)b.length() - 1 - i; j++)
            temp = temp + "0";
        res = add(res, temp);
    }
    return res;
}

string factorial(int n){
    string res = "1";
    for (int i = 2; i <= n;i++){
        res = multiply(res, to_string(i));
    }
    return res;
}

int main(){
    int n;
    while (cin >> n){
        string res = factorial(n);
        cout << res << endl;
    }
    return 0;
}

