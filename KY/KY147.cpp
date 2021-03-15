/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 16:59
 * @description:
 */

#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    while(cin>>s){
        int len=s.size();
        len += 2;
        int l = len/3  - 1;//(len+2)/3就是n1和n2的值
        int mid=len-len/3*2;
        for(int i = 0;i < l; ++i){
            cout<<s[i];
            for(int j = 0;j < mid-2;++j){
                cout<<" ";
            }
            cout<<s[s.size()-1-i]<<endl;
        }
        for(int i = l;i < l+mid; ++i){
            cout<<s[i];
        }
    }
    return 0;
}