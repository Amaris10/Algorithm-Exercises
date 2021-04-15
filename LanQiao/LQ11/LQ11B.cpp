/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-01 21:46
 * @description:既约分数
 */
#include<iostream>
using namespace std;
int gcd(int a,int b)  //辗转相除法(欧几里得算法)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}
int main()
{
    int i, j;
    int N = 0;
    for( i = 1; i <= 2020; i++)
    {
        for( j = 1; j <= 2020; j++)
        {
            if(gcd(i, j) == 1)
                N++;
        }
    }
    printf("N = %d\n", N);
    return 0;
}





