#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
const int N = 100010, M = 2000010;
const LL INF = 2e9;
int n,m,S,T;
int h[N],tot;
struct Edge{
    int to,nxt;
    LL f;
}e[M];
int q[N],d[N],cur[N],w[N];
void add(int a,int b,LL c)
{
    e[tot].to = b, e[tot].f = c, e[tot].nxt = h[a], h[a] = tot ++;
    e[tot].to = a, e[tot].f = 0, e[tot].nxt = h[b], h[b] = tot ++;
}
bool bfs()
{
    memset(d, -1, sizeof d);
    int hh = 0, tt = -1;
    q[++ tt] = S; d[S] = 0; cur[S] = h[S];
    while(hh <= tt)
    {
        int u = q[hh ++];
        for(int i = h[u]; ~i; i = e[i].nxt)
        {
            int to = e[i].to;
            if(d[to] == -1 && e[i].f)
            {
                d[to] = d[u] + 1;
                cur[to] = h[to];
                q[++ tt] = to;
                if(to == T) return true;
            }
        }
    }
    return false;
}
LL dfs(int u,int limit)
{
    if(u == T) return limit;
    LL flow = 0;
    for(int i = cur[u]; ~i && flow < limit; i = e[i].nxt)
    {
        cur[u] = i;
        int to = e[i].to;
        if(d[to] == d[u] + 1 && e[i].f)
        {
            LL f = dfs(to, min(e[i].f, limit - flow));
            if(!f) d[to] = -1;
            e[i].f -= f, e[i ^ 1].f += f, flow += f;
        }
    }
    return flow;
}
LL dinic()
{
    LL r = 0, flow;
    while(bfs()) while(flow = dfs(S,INF)) r += flow;
    return r;
}
int gety(int a, int b, int c,int x)
{
    return a * x * x + b * x + c;
}
int cal(int a,int b, int c, int l, int r)
{
    int w = -INF;
    if(a > 0) w = max(gety(a, b, c, l), gety(a, b, c, r));

    else if(a < 0)
    {
        int p = round(-(double)b / (2 * a));
        if(p < l) w = gety(a, b, c, l);
        else if(p > r) w = gety(a, b, c, r);
        else w = gety(a, b, c, p);
    }
    else
    {
        if(b > 0) w = gety(a, b, c, r);
        else w = gety(a, b, c, l);
    }
    return w;
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    S = 0, T = n * 2 + 1;
    for(int i = 1; i <= n; ++i)
    {
        int l, r, a, b, c;
        scanf("%d%d%d%d%d",&l, &r, &a, &b, &c);
        w[i] = cal(a, b, c, l + 1, r - 1);
        w[i + n] = max(gety(a, b, c, l),gety(a, b, c, r)) - w[i];
        add(i + n, i, INF);
    }

    for(int i = 0; i < m; ++i)
    {
        int x, y, z; scanf("%d%d%d",&z, &x, &y);
        swap(x, y);
        if(z == 1) add(x, y, INF);
        else add(x + n, y, INF); // 2e5
    }
    LL sum = 0;
    for(int i = 1; i <= n * 2; ++i)
    {
        //cout << w[i] << ' '  << i << '\n';
        if(w[i] < 0) add(i, T, -w[i]);
        else if(w[i] > 0) add(S, i, w[i]), sum += w[i];
    }
    cout << sum - dinic();
}

