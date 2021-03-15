/* CCF201903-1 小中大 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5;
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int mina = a[0], maxa = a[n - 1];
    if(mina > maxa) swap(mina, maxa);
    if(n % 2 == 1) {
        printf("%d %d %d", maxa, a[n / 2], mina);
    } else {
        if((a[n / 2 - 1] + a[n / 2]) % 2 == 1)
            printf("%d %.1lf %d", maxa, (double)((a[n / 2 - 1] + a[n / 2]) / 2.0), mina);
        else
            printf("%d %d %d", maxa, (a[n / 2 - 1] + a[n / 2]) / 2, mina);
    }

    return 0;
}
