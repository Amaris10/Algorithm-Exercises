#include <bits/stdc++.h>
using namespace std;
const int MAXN=60;
const int MOD=998244353;
int N,M,K,Len[MAXN];char s[MAXN][MAXN];char S[1010];
long long Ans[1010],F[1010][51][51];
int Out[MAXN][26],Next[MAXN][26];
bool Error;
void add(long long &x,long long v) {x+=v;if (x>=MOD) x-=MOD;}
struct TriT
{
    int ch[MAXN][26];
    int fail[MAXN];
    int cnt;
    bool Mark[MAXN];
    void newnode(int x)
    {
        for (int i=0;i<26;++i) ch[x][i]=0;
        fail[x]=0;
        Mark[x]=false;
    }
    void init()
    {
        cnt=0;
        newnode(0);
    }
    void insert(char *s)
    {
        int len=strlen(s);
        int x=0;
        for (int i=0;i<len;++i)
        {
            int k=s[i]-'a';
            if (!ch[x][k]) ch[x][k]=++cnt,newnode(ch[x][k]);
            x=ch[x][k];
        }
        Mark[x]=true;
    }
    vector<int> To[MAXN];
    int Q[MAXN];
    void build()
    {
        for (int i=0;i<=cnt;++i) To[i].clear();
        int L=0,R=0;
        for (int i=0;i<26;++i)
            if (ch[0][i])
            {
                To[0].push_back(ch[0][i]);
                Q[++R]=ch[0][i];
            }
        while (L<R)
        {
            int x=Q[++L];
            for (int i=0;i<26;++i)
                if (ch[x][i])
                {
                    fail[ch[x][i]]=ch[fail[x]][i];
                    Mark[ch[x][i]]|=Mark[fail[ch[x][i]]];
                    Q[++R]=ch[x][i];
                    To[fail[ch[x][i]]].push_back(ch[x][i]);
                }
                else ch[x][i]=ch[fail[x]][i];
        }
    }
    void solve()
    {
        F[0][0][1]=1;
        for (int i=0;i<=M;++i)
            for (int j=0;j<=cnt;++j)
                for (int k=1;k<=N;++k)
                    if (F[i][j][k])
                    {
                        F[i][j][k]%=MOD;
                        Ans[i]+=F[i][j][k];
                        bool f;
                        int tk;
                        int tj;
                        int x;
                        for (int l=0;l<K;++l)
                        {
                            if (i+Len[l]>M) continue;
                            f=true;
                            tk=k;
                            tj=j;
                            for (int _=0;_<Len[l];++_)
                            {
                                x=Out[tk][s[l][_]];
                                tk=Next[tk][s[l][_]];
                                tj=ch[tj][x];
                                if (Mark[tj]) {f=false;break;}
                            }
                            if (f) F[i+Len[l]][tj][tk]+=F[i][j][k];
                        }
                    }
        for (int i=1;i<=M;++i)
        {
            Ans[i]%=MOD;
            cout<<Ans[i]<<endl;
        }
    }
}T;
bool check(char *a,int len)
{
    for (int i=0;i<K;++i)
    {
        for (int j=0;j<=len-Len[i];++j)
        {
            bool f=true;
            for (int k=0;k<Len[i];++k)
            {
                if (a[j+k]!=s[i][k])
                {
                    f=false;
                    break;
                }
            }
            if (f) return true;
        }
    }
    return false;
}
int main()
{
    //freopen("a.in","r",stdin);
    T.init();
    cin>>N>>M;
    for (int i=0;i<26;++i)
    {
        for (int j=1;j<=N;++j)
        {
            scanf("%s",S);
            Out[j][S[0]-'a']=i;
            int len=strlen(S);
            int v=0;
            if (len==2) v=S[1]-'0';
            else v=(S[1]-'0')*10+S[2]-'0';
            Next[j][S[0]-'a']=v;
        }
    }
    while (scanf("%s",s[K])!=EOF)
    {
        T.insert(s[K]);
        Len[K]=strlen(s[K]);
        for (int i=0;i<Len[K];++i) s[K][i]-='a';
        ++K;
    }
    T.build();
    T.solve();
    return 0;
}