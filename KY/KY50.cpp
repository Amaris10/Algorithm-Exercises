/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 16:03
 * @description:
 */
#include <iostream>

using namespace std;

bool judge(int n){
    if(n % 7 == 0)
        return false;
    if(n % 10 == 7)
        return false;
    if(n / 10 == 7)
        return false;
    return true;
}

int main(){
    int n;
    while(cin >> n){
        int ret = 0;
        for(int i = 1; i <= n; i++){
            if(judge(i)){
                ret = ret + i * i;
            }
        }
        cout << ret << endl;
    }
    return 0;
}
