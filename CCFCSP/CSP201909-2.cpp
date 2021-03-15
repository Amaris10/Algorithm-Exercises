/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/4 23:02
 * @description:
 */
#include <iostream>
#include <vector>
using namespace std;
struct appletree
{
    //记录nums中的数据个数
    int num;
    //记录苹果树疏果后剩余的苹果数
    vector<int> nums;
    //1表示有苹果意外掉落的情况发生，0则表示无掉落情况发生
    bool flag;
};

int main()
{
    vector<appletree> appnums;
    int N, M;
    cin >> N;
    int T = 0;
    int errornum = 0;
    int listnum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> M;
        appletree appnum;
        appnum.num = 0;
        appnum.flag = 0;
        int mi;
        for (int j = 0; j < M; j++)
        {
            cin >> mi;
            //记录第一次统计苹果树的数量
            if (mi > 0 && appnum.num == 0)
            {
                appnum.nums.push_back(mi);
                appnum.num++;
            }
                //判断是否重新统计，若是则在nums后插入重新统计的数据
            else if (mi > 0 && appnum.num > 0)
            {
                appnum.nums.push_back(mi);
                //判断是否发生掉落情况，若是则flag=1
                if (mi != appnum.nums[appnum.num - 1])
                {
                    appnum.flag = 1;
                }
                appnum.num++;
            }
                //处理疏果情况，更新疏果后的苹果数
            else
            {
                appnum.nums[appnum.num - 1] += mi;
            }
        }
        //记录发生苹果意外掉落的树的棵树
        if (appnum.flag == 1)
            errornum++;
        //所有苹果树疏果后的苹果总数
        T += appnum.nums[appnum.num - 1];
        appnums.push_back(appnum);//将数据添加到苹果树集合中
    }

    //处理连续三个树发生苹果掉落的情况
    for (int i = 0; i < N; i++)
    {
        //当发现flag=1时表示有苹果意外从树上掉落
        if (appnums[i].flag == 1)
        {
            //判断该树的前后是否flag都等于1，若是则listnum++
            if (appnums[(i + 1 + N) % N].flag == 1 && appnums[(i - 1 + N) % N].flag == 1)
            {
                listnum++;
            }
        }
    }

    cout << T << " " << errornum << " " << listnum << endl;
    return 0;
}
