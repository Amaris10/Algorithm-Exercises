/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 16:11
 * @description:
 */
#include <iostream>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i = 0;i <= 100; ++i){
            for(int j = 0;j <= 100-i; ++j){
                int k=100-i-j;
                if(15*i+9*j+1*k<=3*n)
                    printf("x=%d,y=%d,z=%d\n",i,j,k);
            }
        }
    }
}
