#include <iostream>
#include <cstdio>
using namespace std;
const int MAXM = 10000;
const int MAXN = 1000000;
int nextTable[MAXM];
int pattern[MAXM];
int text[MAXN];
//创建next表
void GetNextTable(int m){
    int j = 0;
    nextTable[j] = -1;
    int i = nextTable[j];
    while (j < m){
        if(i == -1 || pattern[j]==pattern[i]){  //公共前缀后缀增长
            i++;
            j++;
            nextTable[j]=i;
        }else{                                  //公共前缀后缀不匹配
            i = nextTable[i];
        }
    }
}
int KMP(int n, int m){
    GetNextTable(m);
    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if( j == -1 || text[i] == pattern[j]){     //当前字符匹配成功
            i++;
            j++;
        }else{
            j = nextTable[j];                 //当前字符匹配失败
        }
    }
    if(j == m){                 //模式串匹配成功
        return i-j+1;
    }else{                      //模式串匹配失败
        return -1;
    }
}
int main(){
    int caseNumber;
    scanf("%d",&caseNumber);
    while (caseNumber--) {
        int n, m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &text[i]);
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", &pattern[j]);
        }
        printf("%d\n", KMP(n, m));
    }
    return 0;
}