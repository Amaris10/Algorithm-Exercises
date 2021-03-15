/*北航计算机学院2018年夏令营推免上机考试第一题*/
/*同时也是PAT甲级考试1024*/
/*真的很难，对字符串、模拟问题需要特别熟练，包括大整数运算等*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

static char s1[100];//数的范围在10^9以内，100应该是够了
static char s2[100];

int is_huiwen(char s[],int n)//判断该串是否是回文串
{
    int f=1;
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])
        {
            f=0;
            break;
        }
    return f;
}

int main()
{
    int k,ck;
    int i,j,u,ii;
    while(~scanf("%s%d",s1,&k))
    {
        int cn=0;//cn用于记录步骤数
        int flag=0;//flag用于判断是否已在k步之内完成
        for(ii=0;ii<k;ii++)//注意这里的循环变量是ii，因为循环里面也有i所以这里不能是i，很容易错而且不容易发现
        {
            int len=strlen(s1);//取长度
            if(is_huiwen(s1,len))//一进来先判断是不是回文，如果是输出然后退出for循环
            {
                cout<<s1<<endl;
                cout<<cn<<endl;
                flag=1;
                break;
            }
            cn++;//不然，就说明肯定要进行后续步骤，那么cn++，说明步骤加一
            /*注意，下面要进行的是大整数加法，要从个位开始加，因此是逆过来的方便从个位开始相加，因此现在的s1实际上是s1的逆，我将s1反过来，其实才是真正的s1*/
            /*s1倒过来，存入s2*/
            for(u=0,j=len-1;j>=0;u++,j--)
                s2[u]=s1[j];
            s2[u]='\0';
            /*大整数加法，s1+s2*/
            ck=0;//ck是进位
            for(i=0;i<len;i++)//一位一位地加
            {
                int r=s1[i]-'0'+s2[i]-'0'+ck;
                s1[i]=r%10+'0';
                ck=r/10;
            }
            if(ck)//加完之后要判断一下最高位有没有进位，如果有就填上，没有就倒退一格
                s1[i]=ck+'0';
            else
                i--;
            s1[++i]='\0';//最后在下一格填上'\0'
            for(int w=0;w<i/2;w++)//现在求得的s1，其实是相加后的逆序，为了求得真正相加之后的数，需要逆序一下
            {
                char t;
                t=s1[w];
                s1[w]=s1[i-w-1];
                s1[i-1-w]=t;
            }
        }//for循环结束
        if(flag==1)//如果flag为1说明是break退出来的，说明早就输出结束了，直接continue吧
            continue;
        if(ii>=k)//注意哦，这里的循环变量是ii不是i，再次强调！！！ii>=k说明k步之后仍然不是回文，那么就直接输出吧
        {
            cout<<s1<<endl;
            cout<<k<<endl;
            continue;
        }
    }
}