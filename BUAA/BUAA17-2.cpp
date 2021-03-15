#include <iostream>
#include <string>
#include "math.h"
#include "stdio.h"
#include "string.h"
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int max(int x,int y){
    return x>y?x:y;
}

int nextvar(string str,int &curindex,string &nextstr){
    if(curindex>=str.size()-1) return 0;
    int startindex,endindex;
    int delindex;
    while(str[curindex]=='*'||str[curindex]==' ') curindex++;   //è￥3y±?á????°?àóàμ?????oí*
    startindex=curindex;
    endindex=str.find(",",startindex);
    if(endindex==string::npos) endindex=str.find(";",startindex);

    curindex=endindex+1;
    if(!(endindex>startindex)) return 0;
    nextstr=str.substr(startindex,endindex-startindex);

    delindex=nextstr.find("[");
    if(delindex!=string::npos){
        nextstr.erase(delindex,nextstr.size());
    }
    delindex=nextstr.find("=");
    if(delindex!=string::npos){
        nextstr.erase(delindex,nextstr.size());
    }
    if(!nextstr.empty()) return 1;
    else return 0;
}

int nextvar2(string str,int &curindex,string &nextstr){
    if(curindex>=str.size()-1) return 0;
    int startindex,endindex;
    while(str[curindex]=='*'||str[curindex]==' ') curindex++;   //è￥3y±?á????°?àóàμ?????oí*
    startindex=curindex;
    for(int i=startindex;i<str.size();i++){
        if(!( ((str[i]>='a')&&(str[i]<='z'))
              ||((str[i]>='A')&&(str[i]<='Z'))
              ||((str[i]>='0')&&(str[i]<='9'))
              ||(str[i]=='_')))
            break;
    }
    endindex=i;
    curindex=endindex;
    if(str[curindex]=='[') {
        curindex++;
        while(str[curindex]!=']') curindex++;
    }
    if(str[curindex]==']') curindex++;
    curindex++;
    while((str[curindex]>='0')&&(str[curindex]<='9')) curindex++;

    //cout<<curindex<<" "<<str[curindex]<<endl;
    if(!(endindex>startindex)) return 0;
    nextstr=str.substr(startindex,endindex-startindex);
    if(!nextstr.empty()) return 1;
    else return 0;
}
int main(int argc, char* argv[])
{
    string str1,str2,nextstr;
    char s[100];
    vector<string> var;

    gets(s);
    str1=s;
    gets(s);
    str2=s;
    int length=str1.size();
    int curindex=0;
    while(str1[curindex]==' '){
        str1.erase(curindex,curindex+1);
    }

    curindex=str1.find(" ");
    while(nextvar(str1,curindex,nextstr)){
        var.push_back(nextstr);
    }

    curindex=0;
    while(str2[curindex]==' '){
        str2.erase(curindex,curindex+1);
    }
    while(nextvar2(str2,curindex,nextstr)){
        int result=0;
        for(int i=0;i<var.size();i++){
            if(var[i]==nextstr) {
                result=1;
                break;
            }
        }

        if (result==0) cout<<nextstr<<" ";
    }


    return 0;
}