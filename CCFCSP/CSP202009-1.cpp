#include<iostream>
#include<cstdio>
#include<algorithm>
struct Node {
    int dest;
    int no;
}position[201];
bool compare(Node a,Node b){
    if(a.dest != b.dest)
        return a.dest < b.dest;
    else if(a.no != b.no)
        return a.no < b.no;
}
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    int i,xi,yi;
    for ( i= 0; i < n; ++i)
    {
        scanf("%d %d", &xi, &yi);
        position[i].dest=(x-xi)*(x-xi)+(y-yi)*(y-yi);
        position[i].no=i+1;
    }
    std::sort(position,position+n,compare);
    for(int i = 0 ; i < 3;i++)
    {
        printf("%d\n",position[i].no);
    }

    return 0;
}