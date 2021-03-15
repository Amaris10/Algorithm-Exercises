#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//600154635
long  maxn = 0;
int prime[40001];
int size = 0;
void Initial(){
    maxn = sqrt(10) * 10000 + 1;
    int isprime[maxn];
    for(int i = 0 ;i < maxn ; i++){
        isprime[i] = 1;
    }
    isprime[0] = isprime[1] = 0;
    for(int i = 2 ; i < maxn ; i++){
        if(isprime[i] == 0) continue;
        prime[size ++] = i;
        for(int j = i * i ; j < maxn ; j = j + i){
            isprime[j] = 0;
        }
    }
}
int main(){
    Initial();
    int n;
    while(scanf("%d" ,&n) != EOF){
        int number;

        for(int i = 0 ; i < n ; i++){
            scanf("%d" , &number);
            int answer = 1 ;
            int factor = number;
            for(int j = 0 ; prime[j] * prime[j] <= factor; j ++ ){
                int k = 1;
                while(factor % prime[j] == 0 ){
                    k ++;
                    factor /= prime[j];
                }
                answer *= k;
            }
            if(factor != 1){
                answer *= 2;
            }
            printf("%d\n" , answer);
        }

    }

    return 0;
}
