/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 14:47
 * @description:
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    string str;
    //如果直接按照string 进行输入，那么遇到空格就会停止输入。
    //使用getline()来获取一行字符串
    while (getline(cin, str)){
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == 'z' || str[i] == 'Z'){
                str[i] -= 25;
            }else if ((str[i] >= 'A'&& str[i] <= 'Y' )||(str[i] >= 'a'&& str[i] <= 'y' ) ){
                str[i]++;
            }
        }
        cout << str <<endl;
        return 0;
    }
}

