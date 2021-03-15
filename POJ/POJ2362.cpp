/**
 * 本题剪枝如下：
 * (1)如果总长不能被4整除，则一定不可以构成正方形
 * (2)如果某根木棍的长度大于边长side，那么必定无法构成正方形
 * (3)如果当前木棍无法构成边，之后可以跳过相同的木棍(需要排序)
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 25;//棍子的个数是4到20
int side;//边长
int m;//木棍数量
int sticks[MAXN];//木棍长度
bool visit[MAXN];

bool DFS(int sum,int number,int position){//sum是当前拼凑的木棍长度，number是当前已经拼凑成的边长数目，position是当前木棍的编号
    if(number==3){//如果总长能够整除4，且已经拼凑出3条边，那么剩下的木棍一定可以构成最后一条边。
        return true;
    }
    int sample=0;//剪枝(3)
    for (int i = position; i < m; ++i) {
        if (visit[i]||sum+sticks[i]>side||sticks[i]==sample){
            continue;//木棍被标记过、超过了边长、木棍之前被放弃过
        }
        visit[i]=true;//标记该木棍
        if(sum+sticks[i]==side){//恰好形成边
            if(DFS(0,number+1,0)){
                return true;
            }else{
                sample=sticks[i];//记录木棍失败长度
            }
        }else{//没有形成边继续拼凑
            if(DFS(sum+sticks[i],number,i+1)){
                return true;
            }else{
                sample=sticks[i];//记录木棍失败长度
            }
        }
        visit[i] = false;
    }
    return false;
}
bool Compare(int x,int y){
    return x>y;
}

int main(){
    int n;
    scanf("%d",&n);//第一行中有一个正整数n，代表数据有n组。
    while(n--){
        int length = 0;//总长
        scanf("%d",&m);//木棍数目
        for (int i = 0; i < m; ++i) {
            scanf("%d",&sticks[i]);//木棍长度
            length += sticks[i];
        }
        memset(visit,false,sizeof(visit));
        if(length%4!=0){//剪枝(1)
            printf("no\n");
            continue;
        }
        side = length / 4;//边长
        sort(sticks,sticks+m,Compare);//从大到小排序
        if(sticks[0]>side){//剪枝(2)
            printf("no\n");
            continue;
        }
        if(DFS(0,0,0)){//初始状态，第一根木棍开始
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}
