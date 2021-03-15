/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 10:00
 * @description:
 */
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
vector<int> v1, v2;
vector<int>::iterator it;

int main() {
    int sum, temp;
    for (int i = 2; i <= 60; ++i) {//求因子
        sum = 0;
        for (int j = 1; j <= i / 2; ++j) {
            if (i % j == 0) {
                temp = j;
                sum += j;
            }
        }
        if (sum == i) {
            v1.push_back(i);
        }
        if (sum > i)
            v2.push_back(i);
    }
    cout << "E:";
    for (it = v1.begin(); it != v1.end(); it++) {
        cout << " " << *it;//末尾不加空格！！！不然格式会一直错误
    }
    cout << endl;
    cout << "G:";
    for (it = v2.begin(); it != v2.end(); it++) {
        cout << " " << *it;//末尾不加空格！！！不然格式会一直错误
    }
    return 0;
}
