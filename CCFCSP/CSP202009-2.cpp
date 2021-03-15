#include<cstdio>
int main(){
    int n,k,t,xl,yd,xr,yu;
    scanf("%d%d%d%d%d%d%d",&n,&k,&t,&xl,&yd,&xr,&yu);
    int i,xi,yi,j,ans1=0,ans2=0;
    int cnt[20]={0};
    for(i=0;i<n;i++){
        bool flag = false;
        int temp = 0;//！！！
        for(j=0;j < t;j++)
        {
            scanf("%d%d", &xi, &yi);
            if((xi>=xl&&xi<=xr)&&(yi>=yd&&yi<=yu)){
                cnt[i]++;
                temp++;
                if (cnt[i] >= k){
                    flag = true;
                }
            }else{
                cnt[i]=0;
            }
        }
        if(flag){
            ans2++;
        }
        if(temp){
            ans1++;
        }
    }
    printf("%d\n%d",ans1,ans2);
    return 0;
}