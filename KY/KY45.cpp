/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/10 21:05
 * @description:
 */

# include<stdio.h>
# include<string.h>
# include<math.h>

int skew(char str[])
{
    int len=strlen(str);
    int i;
    int sum=0;
    for(i=0;i<len;i++)
    {
        int num=str[i]-'0';
        sum=sum+num*(pow(2,len-i)-1);
    }
    return sum;
}

int main()
{
    char str[200];
    while(scanf("%s",str)!=EOF)
    {
        printf("%d\n",skew(str));
    }
    return 0;
}



