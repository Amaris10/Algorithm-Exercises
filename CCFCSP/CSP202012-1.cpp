/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/4 22:45
 * @description:
 */
#include<stdio.h>
int main(){
    int  n =0;
    int  w,score,sum=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&w,&score);
        sum += w*score;
    }
    if (sum>0){
        printf("%d", sum);
    }else{
        printf("0");
    }
    return 0;
}
