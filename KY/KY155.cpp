#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct station{
    double price;
    double distance;
};
bool cmp(const station &a,const station &b){
    return a.distance<b.distance;
}
int main(){
    int Cmax,D,N;
    double Davg;
    cin>>Cmax>>D>>Davg>>N;
    vector<station> sta(N+1);
    for(int i=0;i<N;i++){
        cin>>sta[i].price>>sta[i].distance;
    }
    sta[N].distance=D;//终点
    sta[N].price=0;
    sort(sta.begin(),sta.end(),cmp);
    if(sta[0].distance!=0){//起点无加油站
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    int cur=0;	//当前加油站号
    int fullCanGo=Cmax*Davg;//加满油能开的距离
    double result=0;
    double curC=0;//当前油量
    while(cur!=N){
        int next=cur+1;//目标加油站先设为下一个
        int cheap=next;
        //找到可达范围内最近的比本站更便宜的加油站
        while(next<=N&&sta[cur].price<sta[next].price&&(sta[cur].distance+fullCanGo>=sta[next].distance)){
            if(sta[next].price<sta[cheap].price)
                cheap=next;//标记可达范围内最便宜的（不一定比本站便宜）
            next++;
        }
        if(sta[cur].distance+fullCanGo<sta[cheap].distance){//无可达车站，上面的while没有执行
            printf("The maximum travel distance = %.2lf",sta[cur].distance+fullCanGo);
            return 0;
        }
        //最近的比本站更便宜的加油站，油加到刚好够到这个加油站就行
        if(sta[cur].distance+fullCanGo>=sta[next].distance){
            double need=(sta[next].distance-sta[cur].distance)/Davg;//需要的油量
            if(need>curC){//油不够开
                result+=(need-curC)*sta[cur].price;
                curC=0;
            }else{
                curC=curC-need;
            }
            cur=next;
        }else{//若都比本站贵，则在本站加满油，并将后面最便宜的一个设为目标
            result+=(Cmax-curC)*sta[cur].price;
            curC=Cmax-(sta[cheap].distance-sta[cur].distance)/Davg;
            cur=cheap;
        }

    }
    printf("%.2f",result);
    return 0;
}