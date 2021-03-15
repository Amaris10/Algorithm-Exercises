#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>

using namespace std;
stack<double> cal;//最后后缀表达式用来计算。
vector<string> v;//vector的每一个元素都是string，来存储未赋值的字符串变量。
int prio(char op) {                 //给运算符优先级排序
    int priority;
    if (op == '*' || op == '/')
        priority = 2;
    if (op == '+' || op == '-')
        priority = 1;
    if (op == '(')
        priority = 0;
    return priority;
}
bool Trans(string &str,string &str1,double* arr) {   //中缀转后缀
    stack<char> s;                   //定义一个char类型的栈s
    int i;
    for (i = 0; i<str.size(); i++) {
        if (str[i]!='+'&&str[i]!='-'&&str[i]!='/'&&str[i]!='*'&&str[i]!='('&&str[i]!=')')
        {    //如果是字母或者数字，先提取出变量，再直接入栈
            string tmp;
            int j=i;
            while(j<str.size()&&str[j]!='+'&&str[j]!='-'&&str[j]!='*'&&str[j]!='/'&&str[j]!=')'&&str[j]!='(')
            {
                tmp+=str[j];
                j++;
            }
            i=j-1;
            int k;
            for(k=0;k<v.size();k++)
            {
                if (v[k]==tmp) break;
            }
            ostringstream oo;//将变量的数值转换为string类型
            oo<<arr[k];
            string d2s=oo.str();
            str1+=d2s;
            str1+=" ";
        }
        else {                        //否则不是数字
            if (s.empty())            //栈空则入站
                s.push(str[i]);
            else if (str[i] == '(')   //左括号入栈
                s.push(str[i]);
            else if (str[i] == ')') {  //如果是右括号，只要栈顶不是左括号，就弹出并输出
                while (s.top() != '(') {
                    str1+= s.top();
                    str1+=" ";
                    s.pop();
                }
                s.pop();                 //弹出左括号，但不输出
            }
            else {
                while (prio(str[i]) <= prio(s.top())) { //栈顶优先级大于等于当前运算符，则输出
                    str1+= s.top();
                    str1+=" ";
                    s.pop();
                    if (s.empty())      //栈为空，停止
                        break;
                }
                s.push(str[i]);   //把当前运算符入栈
            }
        }
    }
    while (!s.empty()) {      //最后，如果栈不空，则弹出所有元素并输出
        str1+= s.top();
        str1+=" ";
        s.pop();
    }
    return true;
}
bool hasstr(string ss)//判断vector里是否已经有 某个字符串变量
{
    int flag=0;
    for(auto i:v)
    {
        if (i==ss) {
            flag=1;break;
        }
    }
    return flag;
}


int main()
{
    string exp;
    getline(cin,exp);
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]!='+'&&exp[i]!='-'&&exp[i]!='*'&&exp[i]!='/'&&exp[i]!=')'&&exp[i]!='(')
        {
            int j=i;string tmp;
            while(j<exp.size()&&exp[j]!='+'&&exp[j]!='-'&&exp[j]!='*'&&exp[j]!='/'&&exp[j]!=')'&&exp[j]!='(')
            {
                tmp+=exp[j];
                j++;
            }
            i=j-1;
            if(!hasstr(tmp)) v.push_back(tmp);
        }
    }
    int veclen=v.size();
    double *arr=new double[veclen];//字符串变量的数值
    for(int i=0;i<veclen;i++)
    {
        cin>>arr[i];
    }
    string res1;//后缀表达式
    Trans(exp,res1,arr);
    cout<<res1<<endl;
    stringstream ss;
    ss<<res1;
    string s2;

    while(ss>>s2)
    {
        if(s2[0]>='0'&&s2[0]<='9')
        {
            int i=0,t=0;
            while(s2[i]>='0'&&s2[i]<='9')
            {
                t=t*10+ s2[i]-'0';
                i++;
            }
            cal.push(t);
        }
        else if(s2[0]=='+'||s2[0]=='-'||s2[0]=='*'||s2[0]=='/')
        {
            double tmp1=cal.top();cal.pop();
            double tmp2=cal.top();cal.pop();
            double tmp3;
            switch (s2[0])
            {
                case '+':
                    tmp3=tmp1+tmp2;
                    cal.push(tmp3);
                    break;
                case '-':
                    tmp3=tmp2-tmp1;
                    cal.push(tmp3);
                    break;
                case '*':
                    tmp3=tmp2*tmp1;
                    cal.push(tmp3);
                    break;
                case '/':
                    tmp3=tmp2/tmp1;
                    cal.push(tmp3);
                    break;
            }

        }

    }
    cout<<cal.top()<<endl;

    system("pause");
}


