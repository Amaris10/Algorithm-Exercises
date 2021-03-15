#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

const int MAXM = 10000;

int nextTable[MAXM];
//创建next表
void GetNextTable(string pattern){
    int m = pattern.size();
    int j =0;
    nextTable[j] = -1;
    int i = nextTable[j];
    while (j < m){
        if(i == -1||pattern[j]==pattern[i]){
            i++;
            j++;
            nextTable[j]=i;
        }else{
            i =nextTable[i];
        }
    }
}
int KMP(string text,string pattern){
    GetNextTable(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;
    int number = 0;  //记录匹配次数
    while(i < n){
        if(j==-1||text[i]==pattern[j]){//当前字符匹配成功
            i++;
            j++;
        }else{ //当前字符匹配失败
            j=nextTable[j];
        }
        if(j==m){//模式串匹配成功
            number++;
            j=nextTable[j];
        }
    }
    return number;
}
int main(){
    string pattern, text;
    while(cin>>text>>pattern){
        printf("%d\n",KMP(text,pattern));
    }
    return 0;
}
