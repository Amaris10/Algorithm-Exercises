/**
 * 法一 ：递归  把物品数目n和物品体积数组a[100]设为全局变量;
 * count(i,sum)表示从数组的第i个数开始往后统计的组合数和为sum的种类数，
 * sum为组合数的和,则：cout(i,sum)=cout(i+1,sum-a[i])+cout(i+1,sum）,
 * 其中cout(i+1,sum-a[i])表示包含了a[i]，即为从第i+1个数开始往后统计
 * 组合数的和为sum-a[i]的种类数, 而cout(i+1,sum）表示不包含a[i]， 即为从第i+1个数开始往后统计组合数的和为sum的种类数
 */
#include <iostream>
using namespace std;

int a[100];
int n=1;
int count(int i,int sum)
{
    if(sum==0){return 1;} //找到一组和为sum的组合数；
    if(i==n||sum<0) return 0;//i==n说明没有其他的数来组合，sum<0说明组合不出;
    return count(i+1,sum-a[i])+count(i+1,sum);//从数组的第i为开始，包含a[i],和不包含;
}

int main()
{
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<count(0,40)<<endl;
    }
    return 0;
}

