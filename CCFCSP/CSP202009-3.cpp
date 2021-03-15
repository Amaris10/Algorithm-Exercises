#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
const int MAXV = 510;

typedef struct Node{
    int v;//边的终点
    Node(int _v):v(_v){}//初始化列表
}node;
vector<node> Adj[MAXV];//邻接表

int w[MAXV];//边权重
//bool inq[MAXV] = {false};//是否访问过
bool initV[MAXV] = {false};//是否初始化过边
int inDegree[MAXV] = {0};//入度
//int outDegree[MAXV] = {0};//出度（未使用）
string type[MAXV]; //器件类型
vector<int> testInput[10010];//测试输入
vector<int> testOutput[10010];//测试输出

//拓扑排序，判断环
bool TopologicalSort(int n, int m){
    int num = 0;
    queue<int> q;
    int tempInDegree[MAXV];//临时存储入度
    memcpy(tempInDegree, inDegree, (m+n)* sizeof(int));//复制的字节数
    for(int i = 0;i < n + m;i++){//将所有入度为0的顶点入队
        if(tempInDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //邻接表
        for(int i = 0;i < Adj[u].size();i++){
            int v = Adj[u][i].v;
            tempInDegree[v]--;
            if(tempInDegree[v] == 0){
                q.push(v);
            }
        }
        num++;
    }
    if(num == n + m) return true;
    else return false;
}
//计算值
void calculateValue(int n, int m){
    queue<int> q;
    int tempInDegree[MAXV];//临时存储入度
    memcpy(tempInDegree, inDegree, (m+n)* sizeof(int));//复制的字节数
    for(int i = 0;i < n + m;i++){//将所有入度为0的顶点入队
        if(tempInDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();//起始点
        q.pop();

        //邻接表
        for(int i = 0;i < Adj[u].size();i++){
            int v = Adj[u][i].v;
            tempInDegree[v]--;

            if(initV[v] == false){//之前没有被访问过
                w[v] = w[u];//赋予初始值
                if(type[v] == "NOT"){//最多或者最少都只有一个输入
                    w[v] = (!w[v]);
                }
                initV[v] = true;
            }else{
                if(type[v] == "AND" || type[v] == "NAND"){
                    w[v] &= w[u];
                }else if(type[v] == "OR" || type[v] == "NOR"){
                    w[v] |= w[u];
                }else if(type[v] == "XOR"){
                    w[v] ^= w[u];
                }
            }
            if(tempInDegree[v] == 0){
                if(type[v] == "NAND" || type[v] == "NOR"){
                    w[v] = (!w[v]);
                }
                q.push(v);
            }
        }
    }

}

int main(){
    int q, m, n;
    scanf("%d", &q);
    while(q--){//问题个数
        //初始化
        for(int i = 0;i < MAXV;i++){
            for(vector<node>::iterator j = Adj[i].begin();j != Adj[i].end();){
                j = Adj[i].erase(j);
            }
        }
        memset(inDegree, 0, sizeof(inDegree));
        fill(initV, initV + MAXV, false);
        for(int i = 0;i < MAXV;i++){
            type[i].clear();
        }
        for(int i = 0;i < 10010;i++){
            for(vector<int>::iterator j = testInput[i].begin();j != testInput[i].end();){
                j = testInput[i].erase(j);
            }
        }
        for(int i = 0;i < 10010;i++){
            for(vector<int>::iterator j = testOutput[i].begin();j != testOutput[i].end();){
                j = testOutput[i].erase(j);
            }
        }

        scanf("%d%d", &m, &n);//输入个数，器件个数
        for(int num = m;num < n + m;num++){
            string FUNC;//器件描述
            int k;
            cin>>FUNC;
            type[num] = FUNC;

            scanf("%d", &k);
            for(int i = 0;i < k;i++){
                string L;
                cin>>L;
                int startPoint = std::atoi(L.substr(1, L.length() - 1).c_str()) - 1;//计算起始点编号
                if(L[0] != 'I'){//如果是输出点，则加上输入点的偏移
                    startPoint += m;
                }
                Adj[startPoint].push_back(node(num));//构造图
                inDegree[num]++;//计算入度
            }
        }
        int s;//运算次数
        scanf("%d", &s);
        for(int i = 0;i < s;i++){//输入数据
            for(int j = 0;j < m;j++){
                int input;
                scanf("%d", &input);
                testInput[i].push_back(input);
            }
        }

        for(int i = 0;i < s;i++){//输出数据
            int OutNum;
            scanf("%d", &OutNum);
            while(OutNum--){
                int output;
                scanf("%d", &output);
                output = output + m - 1;
                testOutput[i].push_back(output);
            }
        }

        if(TopologicalSort(n, m) == false){//有环
            printf("LOOP\n");
        }else{//无环
            for(int i = 0;i < s;i++){
                memset(w, 0, sizeof(w));
                std::fill(initV, initV + MAXV, false);
                for(int j = 0;j < testInput[i].size();j++){//给初始输入点赋值
                    w[j] = testInput[i][j];
                }
                //计算点权
                calculateValue(n, m);
                for(int j = 0; j < testOutput[i].size();j++){
                    if(j != 0) printf(" ");
                    printf("%d", w[testOutput[i][j]]);
                }
                printf("\n");

            }
        }
    }

    return 0;
}

