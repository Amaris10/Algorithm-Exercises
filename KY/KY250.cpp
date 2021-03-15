#include<iostream>
#include<cstring>
using namespace std;
const int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int fun(int year, int mon, int day) {
    if (mon == 12 && day == 31) {
        year++;
        mon = day = 1;
    }
    else {
        if (day < month[mon]) {
            day++;
        }
        else {
            mon++;
            day = 1;
        }
    }
    printf("%04d-%02d-%02d\n", year, mon, day);
    return 0;
}
int main() {
    int m, year, mon, day;
    while (cin >> m) {
        for (int i = 0; i < m; i++) {
            cin >> year >> mon >> day;
            fun(year, mon, day);
        }
    }
    return 0;
}