/**
 * 非常朴素的八皇后问题，问题规模也已经框定好了，
 * 只要把每次得到的列号转化成要比较的十进制数字即可
 */

#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

vector<int> solut;            //用来放最终的结果
int position[9];            //行号从1开始，其中下标代表行号，其中存放的内容代表列号

void DFS(int row)            //row代表要放入的行号,逐行放入，因为要用的是列号，而且按照习惯都是一列一列计算的
{
    if (row == 9)            //row==9意味着从1~8行全都放入,已完成解
    {
        int temp = 0;
        for (int i = 1; i <= 8; i++) {
            temp += position[i] * pow(10, 8 - i);    //非常朴素的计算方法_(:з」∠)_
        }
        solut.push_back(temp);                        //把得到的solution放进vector
    } else {
        for (int i = 1; i <= 8; i++) {
            position[row] = i;        //i在这里代表列号
            bool flag = true;        //用一个标志位来标记，是否冲突
            for (int j = 1; j < row; j++) {
                if (position[row] == position[j] || row - position[row] == j - position[j] ||
                    row + position[row] == j + position[j]) {
                    flag = false;
                    break;
                }        //这里的判断条件j - position[j]会把同一主对角线标记为同一个数字，与row - position[row]同时计算就能判断是否冲突
            }
            if (flag)
                DFS(row + 1);
        }
    }
}

int main() {
    DFS(1);                    //直接从第一行开始放
    sort(solut.begin(), solut.end());    //这里应该不用sort因为得到的solution应该都是从小到大
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", solut[n - 1]);    //因为vector是从0开始的
    }
    return 0;
}

