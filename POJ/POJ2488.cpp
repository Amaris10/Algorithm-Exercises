#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

const int MAXN = 30;//列数和行数均不超过8（即8×8）的棋盘
int p,q;
bool visit[MAXN][MAXN];
int direction[8][2]{//只能走日字
        {-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,-1},{-1,2},{1,2}
};
bool DFS(int x,int y,int step,string ans){
    if(step == p*q){//搜索成功
        cout<<ans<<endl<<endl;
        return true;
    }else{
        for (int i = 0; i < 8; ++i) {//遍历邻居节点
            int nx = x + direction[i][0];//计算下一步的状态(x,y)——>(nx,ny)
            int ny = y + direction[i][1];
            char col = ny + 'A';
            char row = nx + '1';//用A-Z来表示列，1-99来表示横行
            if(nx<0||nx>=p||ny<0||ny>=q||visit[nx][ny]){
                continue;//该点不合法或者已经被遍历过
            }
            visit[nx][ny]= true;//标记该点
            if(DFS(nx,ny,step+1,ans+col+row)){
                return true;//递归遍历
            }
            visit[nx][ny]=false;//取消该点
        }
    }
    return false;
}
int main(){
    int n;
    scanf("%d",&n);//第一行中有一个正整数n，代表数据有n组。
    int caseNumber = 0;
    while (n--){
        scanf("%d%d",&p,&q);//对于每组数据，都含有两个正整数p和q(1 <= p * q <= 26)，代表棋盘有p行q列。
        memset(visit,false,sizeof(visit));
        cout<<"Scenrio #"<<++caseNumber<<":"<<endl;
        visit[0][0]=true;//题目要求在所有可行的路径中输出字母表排序最小的那个解，这个解必定经过A1
        if(!DFS(0,0,1,"A1")){//初始状态的坐标是A1（0，0，1，“A1”）
            cout<<"impossible"<<endl<<endl;
        }

    }
}

