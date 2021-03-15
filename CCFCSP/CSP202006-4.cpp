#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 30

using namespace std;
int n,l;
const int p=998244353;
char aa[100005];
struct no{
    int n,m;
    long long a[N][N];
}A,B,ans;
int dl[N][N],cnt,b[10],a[201][100006],c[100005];
int get_l(int x)
{
    if(!x)return 0;
    if(x<4) return pow(2,x);
    return (pow(2,x))/10;
}
int get_r(int x)
{
    if(!x)return 0;
    if(x<4)return pow(2,x);
    return (int)(pow(2,x))%10;
}
void work(no &A,no B)
{
    ans.n=A.n,ans.m=A.m;
    for(int i=1;i<=A.n;i++)
        for(int j=1;j<=A.m;j++) ans.a[i][j]=0;
    for(int i=1;i<=ans.n;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            for(int k=1;k<=cnt;k++)
            {
                ans.a[i][j]+=1ll*A.a[i][k]*B.a[k][j]%p;
            }
            ans.a[i][j]%=p;
        }
    }
    A=ans;
}
void ksm(int z,no A,no B)
{
    while(z)
    {
        if(z&1) work(A,B);
        work(B,B);
        z>>=1;
    }
    ans.n=A.n,ans.m=A.m;
    for(int i=1;i<=ans.n;i++)
        for(int j=1;j<=ans.m;j++)
            ans.a[i][j]=A.a[i][j];
}
int work2(int L,int dp)
{
    int cnt1=0;
    a[dp][L+1]=0;
    for(int i=1;i<=L;i++)
    {
        if(a[dp][i]==1||a[dp][i]==6)
        {
            if(a[dp][i]==1)
            {
                if(a[dp][i+1]!=6) return -1;
                else
                {
                    cnt1++;
                    c[cnt1]=4;
                }
            }
            else
            {
                if(a[dp][i+1]!=4) return -1;
                else
                {
                    cnt1++;
                    c[cnt1]=6;
                }
            }
            i++;
        }
        else
        {
            cnt1++;
            if(a[dp][i]==2) c[cnt1]=1;
            else c[cnt1]=2;
        }
    }
    return cnt1;
}
void work3(int L);
void dfs(int L,int n,int dp);
void work3(int L,int n,int dp)
{
    int tmp=work2(L,dp);
    if(tmp!=-1)
    {
        for(int i=1;i<=tmp;i++) a[dp+1][i]=c[i];
        dfs(tmp,n,dp+1);
    }
}
long long sum;
void dfs(int L,int n,int dp)
{
    if(n<0)return;
    if(L<=2)
    {
        ksm(n,A,B);
        if(L==1)
        {
            for(int i=1;i<=5;i++)
            {
                sum+=ans.a[1][dl[a[dp][1]][b[i]]];
                sum%=p;
            }
        }
        else
        {
            int x=a[dp][1],y=a[dp][2];
            sum+=ans.a[1][dl[x][y]];
            sum%=p;
        }
    }
    else
    {


        if(a[dp][1]==6||a[dp][1]==4)
        {
            for(int i=L;i;i--)
                a[dp][i+1]=a[dp][i];
            if(a[dp][1]==6) a[dp][1]=1;
            else a[dp][1]=6;
            if(a[dp][L+1]==1||a[dp][L+1]==6)
            {
                if(a[dp][L+1]==1) a[dp][L+2]=6;
                else a[dp][L+2]=4;
                work3(L+2,n-1,dp);
                a[dp][L+2]=0;
            }
            work3(L+1,n-1,dp);
            for(int i=1;i<=L;i++) a[dp][i]=a[dp][i+1];
            a[dp][L+1]=0;
        }
        if(a[dp][L]==1||a[dp][L]==6)
        {
            if(a[dp][L]==1) a[dp][L+1]=6;
            else a[dp][L+1]=4;
            work3(L+1,n-1,dp);
            a[dp][L+1]=0;
        }
        work3(L,n-1,dp);
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",aa+1);
    l=strlen(aa+1);
    for(int i=1;i<=l;i++) a[0][i]=aa[i]-'0';
    b[1]=1;
    b[2]=2;
    b[3]=4;
    b[4]=6;
    b[5]=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cnt++;
            dl[b[i]][b[j]]=cnt;
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            int x,y;
            x=b[i],y=b[j];
            B.a[dl[x][y]][dl[get_r(x)][get_l(y)]]++;
            if(x==4||x==6)
                B.a[dl[x][y]][dl[get_l(x)][get_r(x)]]++;
        }
    }
    B.n=B.m=cnt;
    A.n=1,A.m=cnt;
    A.a[1][dl[0][1]]=A.a[1][dl[1][0]]=1;
    dfs(l,n,0);
    printf("%lld\n",sum);
    return 0;
}