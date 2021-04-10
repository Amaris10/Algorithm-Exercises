/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-09 21:57
 * @description: 分考场
 */
#include<iostream>

const int  MAXN = 101;

using namespace std;

int graph[MAXN][MAXN];//关系表
bool visit[MAXN][MAXN];// 房间状态

int n = MAXN;//参加考试的人数
int answer = MAXN;//最终分配的考场数

bool DFS(int x,int room){//当前分配到第x个人，已分配了room个考场
    if(room>=answer){//分配考场数大于最大时，不合法
        return false;
    }
    if(x==n+1){//分配完n个人，即已经分配完所有的考生
        answer=min(answer,room);
        return true;
    }
    for (int i = 1; i <= room; ++i) {//遍历每一个当前分配好的考场
        bool flag=1;
        for (int j = 1; j < x; ++j) {//遍历之前分配的人都被分配到哪个考场
            if (graph[x][j]&&visit[i][j]) {//如果x与j有关系，且i号考场有j这个人，就不合法
                flag = 0;
                break;
            }
        }
        if(!flag){
            continue;//不合法就跳过
        }
        visit[i][x]= true;//到这里就这么当前考场是合法的，可以把他试放在这个考场
        DFS(x+1,room);
        visit[i][x] = false;//回溯
    }
    visit[room+1][x] = true;//给x号考生新分配一个考场
    DFS(x+1,room+1);// 如果所有房间都不满足条件增加房间
    visit[room+1][x] = false;//回溯
    return false;
}
int main()
{
    int m;
    int s1,s2;
    scanf("%d\n%d",&n,&m);
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            graph[i][j] = 0;
            visit[i][j] = false;
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&s1,&s2);
        graph[s1][s2] = 1;
        graph[s2][s1] = 1;
    }
    DFS(1,0);//初始状态，从第一个人开始分配考场
    cout<<answer<<endl;
    return 0;
}

