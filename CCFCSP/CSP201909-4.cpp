#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

struct Goods{ //商品信息
    int type;
    int id;
    int score;

    Goods(int _type, int _id, int _score){
        type=_type; id=_id; score=_score;
    }

    bool operator < (const Goods &rhs) const{
        if(score==rhs.score){
            if(type==rhs.type) return id<rhs.id;
            return type<rhs.type;
        }
        return score>rhs.score;
    }
};

struct Del{	//已删除的商品信息
    int type;
    int id;

    Del(int _type, int _id){
        type=_type; id=_id;
    }

    bool operator < (const Del &rhs) const{
        if(type==rhs.type) return id<rhs.id;
        return type<rhs.type;
    }
};

set<Goods> goods; //存放所有商品信息
set<Del> has_del; //存放所有已删除的商品信息

int m, n;
int id, score;
int opnum;
int type;
int K, k[52];

int cnt[52]; //计数，cnt[i]：第i类商品中已选数目， cnt[51]已选总数
vector<int> chosen[52]; //输出每类选中的商品的编号

int main(){
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; ++i){
        scanf("%d%d", &id, &score);
        for(int j=0; j<m; ++j){
            goods.insert(Goods(j, id, score));
        }
    }
    scanf("%d", &opnum);
    int op; //操作类型
    for(int i=0; i<opnum; ++i){
        scanf("%d", &op);
        if(op==1){ //添加操作
            scanf("%d%d%d", &type, &id, &score);
            goods.insert(Goods(type, id, score));
        }
        else if(op==2){ //删除操作
            scanf("%d%d", &type, &id);
            has_del.insert(Del(type, id)); //将该商品加入删除表中，实行惰性删除
        }
        else{ //查询操作
            scanf("%d", &K);
            for(int j=0; j<m; ++j){
                scanf("%d", &k[j]);
            }

            memset(cnt, 0, sizeof(cnt));
            for(int j=0; j<m; ++j) chosen[j].clear();

            //搜索开始！
            for(set<Goods>::iterator it=goods.begin(); cnt[51]<K && it!=goods.end();){
                //该类商品未选满，查看该商品是否已删除
                if(cnt[(*it).type]<k[(*it).type]){
                    if(has_del.find(Del((*it).type, (*it).id))!=has_del.end()){ //存在于删除表中
                        goods.erase(it++); //删除该元素，迭代器自增
                    }
                        //未删除
                    else{
                        ++cnt[(*it).type];
                        ++cnt[51];
                        chosen[(*it).type].push_back((*it).id);
                        it++;
                    }
                }
                else it++;
            }

            //输出！
            for(int j=0; j<m; ++j){
                if(cnt[j]==0) printf("-1\n");
                else{
                    for(vector<int>::iterator it=chosen[j].begin(); cnt[51]<=K && it!=chosen[j].end(); ++it){
                        printf("%d ", *it);
                    }
                    printf("\n");
                }
            }

        }
    }

    return 0;
}

