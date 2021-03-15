#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;

int N,M,K;
int need[maxn];
struct node{
    int v,w;
};
vector<node> adj[110];
int G[110][15];
int T[110];
int road = 0;
bool tag[110];
bool dp[12][1025],tmp[12][1025];
int dfs(int u,int fa){
    int mx = 0;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i].v;
        int w = adj[u][i].w;
        if(v == fa) continue;
        int re = dfs(v,u);
        if(tag[v]){
            tag[u] = 1;
            road += w;
            mx = max(mx,w + re);
        }
    }
    return mx;
}
void init(){
    for(int i = 1;i<=N;i++){
        for(int j = 0;j<K;j++){
            memset(tag,0,sizeof tag);
            for(int ii = 1;ii<=N;ii++){
                if(need[ii]>>j & 1) tag[ii] = 1;
            }

            road = 0;
            int mx = dfs(i,-1);
            G[i][j] = road*2 - mx;
        }
    }
}
bool judge(int mid){
    memset(T,0,sizeof T);
    memset(dp,0,sizeof dp);
    for(int i = 1;i<=N;i++){
        for(int j = 0;j<K;j++){
            if(G[i][j] <= mid) T[i]|= 1<<j;
        }
    }
    tmp[0][0] = dp[0][0] = 1;
    for(int i = 1;i<=N;i++){
        memcpy(tmp,dp,sizeof dp);
        for(int j = 1;j<=M;j++){
            for(int k = 0;k<(1<<K);k++){
                dp[j][k] |= tmp[j][k];
                dp[j][k|T[i]] |= tmp[j-1][k];
            }
        }
    }
    return dp[M][(1<<K)-1];
}
void solve(){
    int l = 1,r = 1e9,ans;
    while(l<=r){
        int mid = (l+r)>>1;
        if(judge(mid)) r = mid-1,ans = mid;
        else l = mid+1;
    }
    cout<<ans<<'\n';
}
int main(){
    cin>>N>>M>>K;
    for(int i = 1;i<=N;i++){
        for(int j = 0;j<K;j++){
            int x;scanf("%d",&x);
            if(x == 1) need[i] |= (1<<j);
        }
    }
    for(int i = 1;i<=N-1;i++){
        int x,y,c;scanf("%d %d %d",&x,&y,&c);
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }
    init();
    solve();



    return 0;
}

