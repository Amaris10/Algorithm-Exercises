/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 9:42
 * @description:
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string x, y;
    while (cin >> x >> y) {
        int sum = 0;
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < x.size(); ++j) {
                sum += (x[i] - '0') * (y[i] - '0');
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
