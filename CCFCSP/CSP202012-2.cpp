#include<iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N=1e5+5;
int n,Max=0,res;
int sum[N]={0};
set<int>st;
pair<int,int>pr[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        pr[i]=make_pair(a,b);
    }
    sort(pr+1,pr+n+1);//1.先排序
    for(int i=1;i<=n;i++)
        sum[i] =sum[i-1]+ pr[i].second;//2.求挂科情况前缀和
    for(int i=1;i<=n;i++)
    {
        int a=pr[i].first;//选取阈值
        if(st.count(a)) continue;//set去重
        st.insert(a);
        int yuce1 = sum[n]-sum[i-1];//大于等于阈值时，应统计预测结果中为1的个数
        int yuce0 = i-1-sum[i-1];//小与阈值时，应统计预测结果中为0的个数
        int yuce = yuce1+ yuce0;//合计预测正确次数
        if(yuce >= Max) {
            Max=yuce;
            res=a;
        }
    }
    cout<<res;
    return 0;
}

