#include<stdio.h>
int a[1001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        if(i != 1){
            printf(" ");
        }
        printf("%d",(a[i] + a[i-1] + a[i+1]) / ((i == 1 || i == n) ? 2 : 3 ));
    }
    return 0;
}