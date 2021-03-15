#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int *check(char a[],char b[]){
    int LA,LB;
    int i,j,k;
    int temp[100];
    i = j = 0;
    k = 1;
    LA = strlen(a);
    LB = strlen(b);
    while(i<LA){
        while(j<LB){
            if(a[i]==b[j]){++i;++j;}
            else{
                i = i-j+1;
                j = 0;
            }
        }
        if(j==LB){
            temp[k++] = i-LB;
            j = 0;
        }
    }
    temp[0] = k;
    return temp;
}

int main(){
    char a[100];
    char b[5];
    char c[5];
    int temp,LC,LA;
    int *d;
    d = new int [100];
    scanf("%s",a);
    scanf("%s",b);
    scanf("%s",c);
    LC = strlen(c);
    LA = strlen(a);
    d = check(a,b);
    for(int j=1;j<d[0];j++){
        temp = d[j];
        for(int i=0;i<LC;i++){
            a[temp++] = c[i];
        }
    }
    printf("%s",a);
    return 0;
}

