#include <iostream>
using namespace std;

string add(string sa, string sb)
{
    string result, sc, sd;
//下面是将两浮点数对齐
    int ia = sa.find(".", 0);
    int ib = sb.find(".", 0);
    sc = (ia>ib)?sa:sb;
    sd = (ia>ib)?sb:sa;
    int n = (ia>ib)?(ia-ib):(ib-ia);
    while(n--)
    {
        sd = "0"+sd;
    }
    int lenc = sc.length();
    int lend = sd.length();
    sa = (lenc>lend)?sc:sd;
    sb = (lenc>lend)?sd:sc;
    n = (lenc>lend)?(lenc-lend):(lend-lenc);
    while(n--)
    {
        sb+="0";
    }
//对对齐后的浮点数进行相加
    int carry = 0;
    for(int i = sa.length()-1; i>=0; i--)
    {
        if(sa[i]=='.')
        {
            result = "."+result;
            continue;
        }
        char value = sa[i]-'0'+sb[i]-'0'+carry;
        result = char(value%10+'0')+result;
        carry = value/10;
    }
    while(carry!=0)
    {
        result = char(carry%10+'0')+result;
        carry/=10;
    }
    return result;
}
int main()
{
    string sa, sb;
    while(cin>>sa)
    {
        cin>>sb;
        cout<<add(sa, sb)<<endl;
    }
    return 0;
}