/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/4 22:29
 * @description:
 */
#include <stdio.h>
struct Node {
    int x;
    int y;
    char kind;
}node[1000];
int Check(int n,int x0,int x1,int x2) {
    char kind_first = 'a', kind_second = 'b';
    int i;
    for (i = 0; i < n; ++i) {
        int result=x0 + node[i].x * x1 + node[i].y * x2;
        if (result== 0)
            return 0;
        if (result > 0) {
            kind_first = node[i].kind;
        }
        else if (result < 0) {
            kind_second = node[i].kind;
        }
        if (kind_first == kind_second)
            return 0;
    }
    return 1;
}
int main()
{
    int n, m;
    int x0, x1, x2;
    scanf("%d %d",&n,&m);
    int i;
    for ( i= 0; i < n; ++i)
    {
        scanf("%d %d %c", &node[i].x, &node[i].y ,&node[i].kind);
    }
    int ans[20];
    for ( i = 0; i < m; ++i) {
        scanf("%d %d %d", &x0, &x1 ,&x2);
        ans[i]=Check(n,x0,x1,x2);
    }
    for(i =0 ;i<m;i++){
        if (ans[i]) {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}

