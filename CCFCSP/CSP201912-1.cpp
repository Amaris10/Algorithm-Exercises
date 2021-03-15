/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/4 22:48
 * @description:
 */
#include <iostream>
using namespace std;
#define  N 4
int have7(int n)
{
    while(n)
        if(n % 10 == 7) return 1;
        else n /= 10;
    return 0;
}

int main(void)
{
    int n,cnt[N] = {0, 0, 0, 0};
    scanf("%d", &n);
    for(int i = 1;i <= n ;i++){
        if(i%7==0||have7(i)) {
            cnt[(i - 1) % N]++;
        }
    }
    for(int i = 0; i < N; i++)
        printf("%d\n", cnt[i]);
    return 0;
}
