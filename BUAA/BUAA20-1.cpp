#include<iostream>
#include <queue>
#include <utility>

using namespace std;
int arr[105];
queue<pair<int, int> > q;

//求在arr数组中，从lIdx开始，长度为n的序列所构成的完全二叉排序树的根节点
void root(int lIdx, int n) {
    if (n <= 0)
        return;
    int h;          //树的高度，从0开始
    int lNum;       //左子树节点数目
    int remain;     //除去最后一层，其余节点的数目
    int last;       //最后一层的节点数目
    int lastMax;    //理论上，最后一层可以有的最大节点数目
    int rootIdx;    //根节点在数组中的下标
    h = log2(n);//在由float转为int的过程中，会自动实现向下取整
    remain = pow(2, h) - 1;
    last = n - remain;
    lastMax = pow(2, h);
    if (last >= lastMax / 2)
        lNum = pow(2, h) - 1;
    else
        lNum = pow(2, h - 1) - 1 + last;
    rootIdx = lIdx + lNum;
    cout << arr[rootIdx] << " ";
    q.push(make_pair(lIdx, lNum));
    q.push(make_pair(rootIdx + 1, n - lNum - 1));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    q.push(make_pair(1, n));
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        root(top.first, top.second);
    }
    return 0;
}
/*
18
56 987 -25 0 1021 -238 399 12 77 -1 72190 -25 -168 -41367 3218 12 0 -25

12 -1 987 -25 0 77 3218 -238 -25 0 12 56 399 1021 72190 -41367 -168 -25
*/
