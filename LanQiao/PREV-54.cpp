/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-09 17:46
 * @description: 合根植物
 */
#include <iostream>
#include <cstdio>
using  namespace std;
const int MAXN = 1000001;
int father[MAXN];//父亲结点高度
int height[MAXN];//结点高度
void Initial(int n){
    for (int i = 0; i <= n; ++i) {
        father[i] = i;
        height[i] = 0;
    }
}
int Find(int x){
    if (x != father[x]){
        father[x] = Find(father[x]);
    }
    return father[x];
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if (x != y){
        if (height[x]<height[y]){
            father[x] = y;
        }else if (height[x] < height[y]){
            father[y] = x;
        }else{
            father[y] = x;
            height[x]++;
        }
    }
    return;
}
int main(){
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    Initial(m*n);
    while (k--){
        int x, y;
        scanf("%d%d", &x, &y);
        Union(x,y);
    }
    int answer = 0;
    for (int i = 1; i <= n*m; ++i) {
        if (Find(i) == i) {
            answer++;
        }
    }
    printf("%d",answer);
}