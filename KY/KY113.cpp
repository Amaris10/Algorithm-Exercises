/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 20:51
 * @description:
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int number[26];

int main(){
    string str;
    while (cin>>str){
        memset(number,0,sizeof(number));
        for (int i = 0; i < str.size(); ++i) {
            if ('A' <= str[i] && str[i] <='Z'){
                number[str[i] - 'A']++;
            }
        }
        for(int i = 0; i < 26; ++i){
            printf("%c:%d\n",'A' + i, number[i]);
        }
    }
    return 0;
}

