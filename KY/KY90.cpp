/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 15:03
 * @description:
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        if(str == "ENDOFINPUT"){
            break;
        }
        getline(cin, str);
        for(int i = 0; i < str.size(); ++i){
            if('A' <= str[i] && str[i] <= 'Z'){
                //求解循环平移问题，对字母进行减法操作后，再对字母个数26取模
             str[i] = (str[i]-'A'-5+26)%26+'A';
            }
        }
        cout<< str << endl;
        getline(cin, str);
    }
    return 0;
}