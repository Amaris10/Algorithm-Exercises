/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-02 8:50
 * @description:成绩分析
 */
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",n);
    int score[100]={0};
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",score[i]);
        sum +=score[i];
    }
    int max = score[0];
    int min = score[0];
    for (int i = 0; i < n; ++i) {
        if (score[i]>max){
            max = score[i];
        }
        if (score[i] < min){
            min = score[i];
        }
    }
    printf("%d\n%d\n%.2f",max,min,sum/n);
}

