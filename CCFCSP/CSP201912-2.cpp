/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/4 22:49
 * @description:
 */
#include <iostream>
#include <utility>
#include <map>

using namespace std;

const int N = 1000;
pair<int, int>place[N];


int main()
{
    int n;
    int cnt[5] = {0,0,0,0,0};
    map<pair<int, int>, int> ps;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a;
        cin >> b;
        place[i] = make_pair(a,b);
        ps[place[i]] = 1;
    }

    for(int i=0;i<n;i++){
        int sum=0;
        int a = place[i].first;
        int b = place[i].second;
        if(ps[make_pair(a-1,b)]==1&&ps[make_pair(a+1,b)]==1&&ps[make_pair(a,b-1)]==1
           &&ps[make_pair(a,b+1)]==1)  //寻找有资格进行评分的选址
        {
            if(ps[make_pair(a-1,b-1)]==1) sum++;
            if(ps[make_pair(a+1,b+1)]==1) sum++;
            if(ps[make_pair(a-1,b+1)]==1) sum++;
            if(ps[make_pair(a+1,b-1)]==1) sum++;
            cnt[sum]++;    //计算该选址的评分
        }
    }
    for(int i=0;i<5;i++){
        cout << cnt[i] << endl;
    }
    return 0;
}
