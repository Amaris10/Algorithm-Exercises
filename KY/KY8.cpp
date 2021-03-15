/**
 * @author: Qiuyue Zhang
 * @date: 2021/1/30 22:04
 * @description:
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using  namespace std;

struct Student{
    int number;
    int score;
};

const int MAXN = 100;

Student arr[MAXN];

//按照学号升序和成绩升序的比较函数
bool Compare(Student x, Student y){
    if(x.score == y.score){
        return x.number < y.number;
    } else {
        return x.score < y.score;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &arr[i].number, &arr[i].score);
    }
    sort(arr,arr+n,Compare);
    for(int i = 0; i < n; ++i){
        printf("%d %d\n", arr[i].number, arr[i].score);
    }
    return 0;
}