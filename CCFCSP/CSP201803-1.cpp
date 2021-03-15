#include<iostream>

using namespace std;

const int N=30;
int a[N];

int main()
{
    int x, sum = 0, weight=1;//sun为总分，weigth此次得分 ，初始化为1
    while((cin>>x)&&x){
        if(x==1)//跳到了方块上但是没有跳到中心 ，得1分
            weight=1;
        else if(x==2){ //跳到了方块中心
            if(weight==1)//若上一次的得分为1分或这是本局游戏的第一次跳跃则此次得分为2分，
                weight=2;
            else          //否则此次得分比上一次得分多两分
                weight+=2;
        }
        sum+=weight;
    }
    cout<<sum<<endl;
    return 0;
}