/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 9:33
 * @description:
 */
#include<iostream>

using namespace std;

int root(int x, int y, int k) {
    if (y == 1) {
        if (x < k)
            return x;
        else {
            while (x >= k) {
                int sum = 0;
                while (x > 0) {
                    sum += x % k;
                    x /= k;
                }
                x = sum;
            }
            return x;
        }
    } else {
        int r = root(x, y / 2, k);
        r *= r;
        if (y % 2 == 1) {
            r *= root(x, 1, k);
        }
        return root(r, 1, k);
    }
}

int main() {
    int x, y, k;
    while (cin >> x >> y >> k)
        cout << root(x, y, k) << endl;
    return 0;
}
