/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 23:33
 * @description:
 */
#include <iostream>
#include <cstdio>

using  namespace std;

const int MAXN = 10001;

bool arr[MAXN];

int main(){
    int l, m;
    while (scanf("%d%d", &l, &m) != EOF){
        for (int i = 0; i <= l; ++i) {
            arr[i] = true;
        }
        int number = l + 1;
        while (m--){
            int left, right;
            scanf("%d%d", &left, &right);
            for (int i = left; i <= right ; ++i) {
                if(arr[i]){
                    arr[i] = false;
                    number -- ;
                }
            }
        }
        printf("%d\n",number);
    }
}
