#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 100001;//N和K的范围都是0到100000

struct Status{
    int n,t;//定义当前状态两个参数，位置n，和时间t
    Status(int n,int t):n(n), t(t){}//结构体构造
};

bool visit[MAXN];

int BFS(int n,int k){
    queue<Status> myQueue;
    myQueue.push(Status(n, 0 ));//压入初始状态
    visit[n] = true;//起始点已被访问
    while(!myQueue.empty()){
        Status current = myQueue.front();//取出队列的头作为当前的状态
        myQueue.pop();//出队操作，将队列头删除，即删除当前的状态
        if(current.n == k){
            return current.t;//如果当前状态的n到达了搜索的最终条件，即返回时间t（题目所求的最短时间）
        }
        for (int i = 0; i < 3; ++i) {//题目中涉及到了3种状态转移函数
            Status next(current.n, current.t+1);//初始化下一个状态值（利用结构体构造函数，先初始化为当前的位置，但是时间+1）
            if(i == 0){
                next.n +=1 ;
            }else if(i == 1){
                next.n -= 1;
            }else{
                next.n *=2;
            }
            if(next.n < 0 || next.n >= MAXN || visit[next.n]){
                continue;//判断新状态是否合法以及是否以及被遍历过
            }
            myQueue.push(next);//进队操作，将新状态压入队列中
            visit[next.n] = true;// 将此状态的位置设置为被遍历过
        }
    }

}

int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    memset(visit,false,sizeof(visit));
    printf("%d\n",BFS(n,k));
}


