/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-01 21:56
 * @description:蛇形填数
 */
#include <iostream>
using namespace std;
int arr[50][50];
int main(){
    int id=1;//要填的数
    for(int i=1;i<=40;i++){
        for(int j=1;j<=i;j++)  //斜着填
        {
            if(i&1){   //奇数
                arr[i-j+1][j]=id;
                id++;
            }
            else{
                arr[j][i-j+1]=id;
                id++;
            }
        }
    }
    cout<<arr[20][20]<<endl;
    return 0;
}