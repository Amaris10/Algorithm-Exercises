/* CCF201912-1 ±¨Êý */

#include <stdio.h>
#define N 4
int have7(int n)
{
    while(n)
        if(n % 10 == 7) return 1;
        else n /= 10;
    return 0;
}

int main(void)
{
    int n,i, cnt[N] = {0, 0, 0, 0}; 
    scanf("%d", &n);
	for(i=1;n>0;i++){
		if(i%7==0||have7(i)){
			cnt[(i-1)%N]++;	
		}else{
			n--;
		} 
	}
    for(i = 0; i < N; i++)
        printf("%d\n", cnt[i]); 
    return 0;
}

