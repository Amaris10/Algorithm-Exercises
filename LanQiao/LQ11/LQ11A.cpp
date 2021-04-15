/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-01 21:19
 * @description:门牌制作
 */

#include<iostream>
using namespace std;
int main(){
    int count = 0;
    for (int i = 1; i <= 2020; i++) {
        int k = i;
        do {
            if(k%10==2){
                count++;
            }
            k = k/10;
        } while (k!=0);
    }
    cout<<count;
    return 0;
}
