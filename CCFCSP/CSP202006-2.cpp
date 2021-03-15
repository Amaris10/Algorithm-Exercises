#include<iostream>
#include<map>

using namespace std;
map<int, int> svector;

int main() {
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    int index, value, i;
    long long sum = 0;
    for (i = 1; i <= a; i++) {
        cin >> index >> value;
        svector[index] = value;
    }
    for (i = 1; i <= b; i++) {
        cin >> index >> value;
        if (svector[index] != 0) {
            sum += svector[index] * value;
        }
    }
    cout << sum << endl;
    return 0;
}