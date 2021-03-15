#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,ArraySize;
    scanf("%d%d",&num,&ArraySize);
    int a[ArraySize][ArraySize];
    int col,row;
    col = row = 0;
    for(int i=0;i<ArraySize;i++)
    {
        col = i;
        for(row=0;row<i;row++)
            a[row][col] = num++;
        for(;col>=0;col--)
            a[row][col] = num++;
    }
    for(int i=0;i<ArraySize;i++){
        for(int j=0;j<ArraySize;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    return 0;
}