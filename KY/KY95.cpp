/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 16:27
 * @description:
 */
#include<iostream>
#include<cstring>
using namespace std;
int Solve(int N, int X, int Y, int  Z) {
    bool find = false;
    int sum = 0;
    for (int i = 9; i >= 1; i--) {
        for (int j = 9; j >= 0; j--) {
            sum = i * 10000 + X * 1000 + Y * 100 + Z * 10 + j;
            if (sum%N == 0) {
                find = true;
                cout << i << " " << j << " " << (sum / N) << endl;
                return 0;
            }
        }
    }
    if (!find) {
        cout << 0 << endl;
    }
    return 0;
}
int main() {
    int N, X, Y, Z;
    while (cin >> N >> X >> Y >> Z) {
        Solve(N, X, Y, Z);
    }
    return 0;
}

