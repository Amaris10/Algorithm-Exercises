#include<iostream>
#include <queue>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;
vector<string> callStack;	//相当于栈，存放函数名
unordered_map<string, int> numOfCalls;	//调用次数
unordered_map<string, unordered_set<string> > numOfCaller;	//统计有多少个父函数，用unordered_set的目的是去重
vector<vector<string> > ans;	//存放最终结果

int main() {
    callStack.resize(205);
    int type;
    string funcName;
    int depth = 0, maxdep = 0;	//分别是当前的调用深度和目前为止最大的调用深度
    while (cin >> type) {
        if (type == 1) {
            //函数调用
            cin >> funcName;
            numOfCalls[funcName]++;	//记录函数被调用的次数
            if (depth != 0) {
                //深度不为0，说明当前被调用的函数一定有调用者（如果当前被调用的函数是main，则无调用者）
                string caller = callStack[depth - 1];
                numOfCaller[funcName].insert(caller);//将funcName函数的所有调用者都保存起来
            }
            callStack[depth++] = funcName;//先将funcName入栈，再令调用深度加1
            if (depth > maxdep) {
                //更新最大深度
                ans.clear();
                ans.push_back(callStack);
                maxdep = depth;
            }
            else if (depth == maxdep) {
                //最大深度相同
                int flag = false;	//判断是否有同一个函数，存在多条最深路径的情况
                for (auto v : ans) {
                    if (v[maxdep - 1] == funcName) {
                        flag = true;
                        break;
                    }
                }
                if(flag == false)
                    ans.push_back(callStack);
            }
        }
        else {
            //调用结束
            depth--;
        }
    }
    for (int j = 0; j < ans.size(); j++) {
        funcName = ans[j][maxdep - 1];	//嵌套深度最大的函数
        cout << funcName << " " << ans[j][0];
        for (int i = 1; i < maxdep - 1; i++)	//输出调用路径
            cout << "-" << ans[j][i];
        cout << " " << numOfCaller[funcName].size() << " " << numOfCalls[funcName] << endl;
    }
    return 0;
}

