#include<stdio.h>
#define MAX_N 1000005
int a[1000005]={0};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        int b,c;
        scanf("%d%d",&b,&c);
        a[b]++;
        a[c]--;
    }
    int ans =0,cnt =0;
    for(int i=0;i<=MAX_N;i++)
    {
        cnt += a[i];
        ans += (cnt==2);
    }
    printf("%d",ans);
    return 0;
}


