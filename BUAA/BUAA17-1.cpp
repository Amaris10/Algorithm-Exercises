/*
 * 先输入一个整形数字N，接着输入N个无序的数字。
 * 要求输出升序排列后的中位数，以及该中位数输入的次序。
 * 如果N为偶数，则输出有二个中位数，如果N为奇数，输出最中间的数即可。
 */
#include <iostream>
#include <algorithm>

using namespace std;

int max(int x,int y){
    return x>y?x:y;
}

struct number{
    int value;
    int index;
    bool operator <(number b){
        return value<b.value;
    }
};
int main()
{
    int n;
    number num[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i].value;
        num[i].index=i;
    }
    sort(num,num+n);

    if(n&1==1) cout<<num[n/2].value<<" "<<num[n/2].index+1;
    else cout<<num[n/2-1].value<<" "<<num[n/2-1].index+1<<endl
             <<num[n/2].value<<" "<<num[n/2].index+1;
    return 0;
}

