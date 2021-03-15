#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    int score;
    int order;
};

bool CompareDescending(Student x, Student y){
    if(x.score == y.score){
        return x.order < y.order;
    }else{
        return x.score > y.score;
    }
}

bool CompareAscending(Student x, Student y){
    if(x.score == y.score){
        return x.order < y.order;
    }else{
        return x.score < y.score;
    }
}

int main() {
    int n;
    int type;
    while (scanf("%d%d",&n,&type)!= EOF) {
        Student stu[n];
        for (int i = 0; i < n; i++) {
            cin >> stu[i].name >> stu[i].score;
            stu[i].order = i;
        }
        if (type) {
          sort(stu,stu+n,CompareAscending);
        }
        else {//为0就降序输出
             sort(stu,stu+n,CompareDescending);
        }
        for(int i=0; i < n; ++i){
            cout<< stu[i].name<< " " << stu[i].score <<endl;
        }
    }
    return 0;
}
