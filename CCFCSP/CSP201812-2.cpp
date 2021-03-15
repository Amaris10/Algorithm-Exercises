
#include <iostream>
using namespace std;
int main()
{
    int r, y, g, n;
    long long sum = 0, tmp;
    cin >> r >> y >> g >> n;
    while(n--){
        int k, t;
        cin >> k >> t;
        if(k != 0){//tmp是距时间段开始的时间。
            if(k == 1)
                tmp = sum + (r - t);
            else if(k == 2)
                tmp = sum + (r + g + y) - t;
            else if(k == 3)
                tmp = sum + (r + g) - t;

            tmp %= r + g + y;

            if(tmp >= r + g)
                t = r + g + y + r - tmp;
            else if(tmp <= r)
                t = r - tmp;
            else
                t = 0;
        }
        sum += t;
    }
    cout << sum << endl;
    return 0;
}
