/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/4 23:01
 * @description:
 */
#include <stdio.h>
#include <limits.h>
int main(void)
{
    int n, m, a, drop, i, j;
    int sum = 0, maxCut = INT_MIN, id = 0;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) {
        scanf("%d", &a);
        sum += a;
        drop = 0;
        for(j = 0; j < m; j++) {
            scanf("%d", &a);
            sum += a;
            drop -= a;
        }
        if(drop > maxCut) {
            maxCut = drop;
            id = i;
        }
    }
    printf("%d %d %d\n", sum, id + 1, maxCut);
    return 0;
}

