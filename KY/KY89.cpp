#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Ant {
    int position;
    int direct;    //方向
    bool operator<(const Ant &a) const {
        return position < a.position;
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<Ant> ant(n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &ant[i].position, &ant[i].direct);
        sort(ant.begin(), ant.end());
        int target, toLeft = 0;    //这里选用向左走的为基准来做
        for (int i = 0; i < n; i++)    //遍历所有蚂蚁
        {
            if (ant[i].direct == 0)
                target = i;
            if (ant[i].direct == -1)
                toLeft++;
        }//现在的target就是静止的蚂蚁左边的数量了
        bool flag = false;
        int ans;
        if (toLeft == target)
            flag = true;
        else if (toLeft > target)//这样的话我们要找的就是所有向左走的蚂蚁中，第target蚂蚁
        {
            int cnt = 0;//计数器
            for (int i = 0; i < n; i++) {
                if (ant[i].direct == -1 && cnt == target) {
                    ans = ant[i].position;
                    break;
                } else if (ant[i].direct == -1)
                    cnt++;
            }
        } else    //向左走的蚂蚁少，那么目标蚂蚁会向右落下
        {
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (ant[i].direct == 1 && cnt == n - target - 1)//相应的变化，cnt要变成静止蚂蚁右边的蚂蚁数量
                {
                    ans = 100 - ant[i].position;
                    break;
                } else if (ant[i].direct == 1)
                    cnt++;
            }
        }
        if (flag)
            printf("Cannot fall!\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}