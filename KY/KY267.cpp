/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 16:00
 * @description:
 */
#include <iostream>

using namespace std;

int Reverse(int x){
    int revx = 0;
    while (x != 0){
        revx *= 10;
        revx += x % 10;
        x /= 10;
    }
    return revx;
}

int main(){
    for (int i = 0; i <= 256; ++i) {
        if (i * i == Reverse(i * i)){
            printf("%d\n",i);
        }
    }
    return 0;
}
