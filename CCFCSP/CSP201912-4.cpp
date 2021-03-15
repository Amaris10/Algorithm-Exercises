#include <iostream>
#include <queue>
#include <unordered_map>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, t, k;
vector<vector<int>> G;                          // 邻接表方式存图
map<int, unordered_map<int, vector<int>>> rec;  // 收到的链，按‘时间-节点-链’组织
vector<vector<int>> links;                      // 当前各节点的主链
map<int, unordered_map<int, vector<int>>> cre;  // 创建的新块，按‘时间-节点-块号链’组织。同一时刻，同一节点，可以产生多个块

vector<int> input() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> res;
    int x = 0;
    while (iss >> x) res.push_back(x);
    return res;
}

// 节点idx在时刻time接收到链vec的处理过程
void update(int time, int idx, const vector<int>& vec) {
    auto& cur = links[idx];
    if (cur.size() < vec.size() || cur.size() == vec.size() && cur.back() > vec.back()) {
        cur = vec;

        // links[idx]更新了，将新链推送给邻居
        for (int nei: G[idx]) {
            auto& temp = rec[time + t][nei];
            // 邻居在同一时刻可能收到多个链，只需保留最长且最后一个块号最小的链
            if (temp.size() < cur.size() || temp.size() == cur.size() && temp.back() > cur.back()) {
                temp = cur;
            }
        }
    }
}

// 按时间顺序处理积攒的rec和cre操作，直至时刻T
void proceedUntil(int T) {
    auto rec_p = rec.begin(); // rec_p将始终指向rec的第一个元素，或rec.end()，如果rec为空
    auto cre_p = cre.begin(); // cre_p将始终指向cre的第一个元素，或cre.end()，如果cre为空
    while (rec_p != rec.end() || cre_p != cre.end()) {
        if (cre_p == cre.end() || rec_p != rec.end() && rec_p->first <= cre_p->first) { // 先处理接收到的链
            if (rec_p->first > T) break;
            for (const auto& ele: rec_p->second) {
                update(rec_p->first, ele.first, ele.second);
            }
            rec_p = rec.erase(rec_p);
        } else { // 再处理新建操作，两者都划归到update上
            if (cre_p->first > T) break;
            for (const auto& ele: cre_p->second) {
                auto temp = links[ele.first];
                temp.insert(temp.end(), ele.second.begin(), ele.second.end());
                update(cre_p->first, ele.first, temp);
            }
            cre_p = cre.erase(cre_p);
            rec_p = rec.begin(); // 调用update之后，rec可能被修改，rec_p可能因此而失效
        }
    }
}

// 加快cin和cout的速度
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main() {
    cin >> n >> m;
    G.resize(n + 1);
    links.resize(n + 1, {0});
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> t >> k;
    cin.get(); // 去掉输入流里一个换行符
    while (k--) {
        vector<int> op = input();
        if (op.size() == 3) {   // 创建块，将操作缓存起来，不立刻处理
            cre[op[1]][op[0]].push_back(op[2]);
        } else {                // 等查询主链时，才依次处理完时刻op[1]及其之前的操作
            proceedUntil(op[1]);
            cout << links[op[0]].size();
            for (int x: links[op[0]]) cout << " " << x; cout << endl;
        }
    }
    return 0;
}
