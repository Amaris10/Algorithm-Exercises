#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    string s;
    scanf("%d",&n);
    while(n--)
    {
        stack<int>q;
        cin>>s;
        int an=1;
        for(int i=0; i<(int)s.size(); i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                //做加减法
                q.push(an*(s[i]-'0'));
            }
            else if(s[i]=='+'||s[i]=='-')
            {
                //存储加减法的符号
                if(s[i]=='-')
                    an=-1;
                else an=1;
            }
            else
            {
                //计算乘除法
                int a=q.top();
                q.pop();
                i++;
                int b=s[i]-'0';
                if(s[i-1]=='/')
                {
                    q.push(a/b);
                }
                else
                {
                    q.push(a*b);
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            //取出栈的顶部就是最后的计算结果
            ans+=q.top();
            q.pop();
        }
        if(ans==24)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}