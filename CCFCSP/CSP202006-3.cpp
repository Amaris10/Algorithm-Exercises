#include <iostream>
#include <vector>
using namespace std;

struct Markdown{
    int type;//标记相应的类型 0 空行，1 项目列表第一行 2项目列表其余行 3段落
    string s;
};

bool isSpace(string s){//判断是否为空行
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=' ')
            return false;
    }
    return true;
}

string remove_space(string s){//去除首尾的空格
    int pos1=0,pos2=s.length()-1;
    for(int i=0;i<s.length();++i){
        if(s[i]!=' '){
            pos1 =i;
            break;
        }
    }
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]!=' '){
            pos2=i;
            break;
        }
    }
    string temp =s.substr(pos1,pos2-pos1+1);
    return temp;
}
vector<Markdown> vec;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    Markdown temp;
    int w,flag=0;//flag标记当前输入行的前一行类型
    string str;
    cin>>w;
    while(getline(cin,str))
    {
        if(isSpace(str)){//处理空行
            if(flag){//上一行不是空行，就添加一个空行
                temp.s="";
                temp.type=0;
                vec.push_back(temp);
                flag=0;
            }
            continue;
        }
        if(str.size()>=2 && str[0]=='*' && str[1]==' '){//处理项目列表的第一行
            if(flag==3){//上一行是一个段落，就插入一行空行隔开
                temp.s="";
                temp.type=0;
                vec.push_back(temp);
            }
            //把项目列表再放入vec中
            temp.type=1;temp.s=remove_space(str.substr(2,str.size()));
            vec.push_back(temp);
            flag=1;
        }
        else if(str.size()>=2 && str[0]==' ' && str[1]==' ' &&(flag==1 || flag==2)){
            if(vec[vec.size()-1].s==""){//项目列表第一行为空
                vec[vec.size()-1].s = remove_space(str);
            }
            else
            {
                vec[vec.size()-1].s =vec[vec.size()-1].s+" "+remove_space(str);
            }
            flag=2;
        }
        else{//处理段落
            if(flag==1 || flag==2){
                temp.s="";
                temp.type=0;
                vec.push_back(temp);
                temp.s=remove_space(str);
                temp.type=3;
                vec.push_back(temp);
            }else if(flag ==3){
                vec[vec.size()-1].s = vec[vec.size()-1].s+" " +remove_space(str);
            }
            else{
                temp.s = remove_space(str);
                temp.type = 3;
                vec.push_back(temp);
            }
            flag=3;
        }
    }
    long long int ans=0;
    for(int i=0;i<vec.size();++i){
        int type =vec[i].type;
        string s=vec[i].s;
        if(!type) {
            ans++;
            //cout<<endl;//空行
        }
        else if(type ==1 ||type ==2){//项目列表
            if(!s.size()){
                ans++;
                continue;
            }
            int t=0;
            while(t<s.size()){
                while(1){//保证每行的开头不是空格
                    if(t>=s.size()) break;
                    if(s[t]!=' ')break;
                    t++;
                }
                //cout<<s.substr(t,w-3)<<endl;
                t+=(w-3);
                ans++;
            }
        }
        else{
            int t=0;
            while(t<s.size()){
                while(1){//保证每行的开头不是空格
                    if(t>=s.size()) break;
                    if(s[t]!=' ')break;
                    t++;
                }
                //cout<<s.substr(t,w)<<endl;
                t+=w;
                ans++;
            }
        }
    }
    if(!vec[vec.size()-1].type)
        ans--;
    cout<<ans<<endl;
    return 0;
}