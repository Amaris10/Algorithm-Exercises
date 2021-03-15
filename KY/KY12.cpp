#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct mitery{
    int index;//移位次数
    string s;//密码字符串
    mitery(int i,string ss):index(i),s(ss){}
};
void BFS(string s){
    queue<mitery> myQueue;
    myQueue.push(mitery(0,s));//将初始状态压入队列头
    while(!myQueue.empty()){
        mitery current=myQueue.front();
        myQueue.pop();
        string currentString=current.s;
        if(currentString.find("2012")!=string::npos){
            cout<<current.index<<endl;//如果当前字符串以及可以找到2012
            return ;
        }
        for(int i=0;i<currentString.size()-1;i++){//状态转移的方式：每次只能移动相邻的两个数字
            swap(currentString[i],currentString[i+1]);//通过循环枚举字符串状态
            myQueue.push(mitery(current.index+1,currentString));//将移动后的状态字符串压进队列尾部
            swap(currentString[i],currentString[i+1]);//将字符串恢复原始状态，以便进行下一种字符串的枚举
        }
    }
    cout<<-1<<endl;
}
int main(){
    int n;
    string s;
    while(cin>>n>>s){
        BFS(s);
    }
    return 0;
}