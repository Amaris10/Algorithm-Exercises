/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/26 10:00
 * @description:
 */
#include<iostream>
using namespace std;

int main() {
    int r,y,g;
    int n;
    int sum=0;
    int k,t;
    cin>>r>>y>>g;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>k>>t;
        if(k==0)
            sum=sum+t;
        else if(k==1)
            sum=sum+t;
        else if(k==2)
            sum=sum+t+r;
        else if(k==3)
            continue;
    }
    cout<<sum<<endl;
    return 0;
}

