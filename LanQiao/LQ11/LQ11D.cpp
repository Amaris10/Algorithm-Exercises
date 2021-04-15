/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-15 9:40
 * @description: 七段码
 */
#include<bits/stdc++.h>
using namespace std;
const int N=10;
int use[N],ans,e[N][N],fa[N];
void init(){
    /*
        连边建图，e[i][j]==1表示i和j相邻
        a b c d e f g
        1 2 3 4 5 6 7
    */
    e[1][2]=e[1][6]=1;
    e[2][1]=e[2][7]=e[2][3]=1;
    e[3][2]=e[3][4]=e[3][7]=1;
    e[4][3]=e[4][5]=1;
    e[5][4]=e[5][6]=e[5][7]=1;
    e[6][1]=e[6][5]=e[6][7]=1;
}
int find(int u){if(fa[u]==u)return u;fa[u]=find(fa[u]);return fa[u];}//并查集
void dfs(int d){
    if(d>7){
        /* 并查集判是否在同一集合 */
        for(int i=1;i<=7;i++)fa[i]=i;//初始化父亲集合
        for(int i=1;i<=7;i++)//遍历所有边集
            for(int j=1;j<=7;j++)
                if(e[i][j]&&use[i]&&use[j]){
                    int fx=find(i),fy=find(j);
                    if(fx!=fy)fa[fx]=fy;//如果不在同一集合,合并
                }
        int k=0;
        for(int i=1;i<=7;i++)
            if(use[i]&&fa[i]==i)k++;
        if(k==1)ans++;//如果所有亮灯都属于同一个集合
        return;
    }
    use[d]=1;//打开d这个灯，继续开关下一个灯
    dfs(d+1);
    use[d]=0;//关闭d这个灯，继续开关下一个灯
    dfs(d+1);
}
int main(){
    init();
    dfs(1);
    cout<<ans;
}

