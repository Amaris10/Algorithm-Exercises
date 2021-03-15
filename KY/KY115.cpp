#include <iostream>
#include <set>
using namespace std;

int main()
{

    string str;
    while( cin>>str )
    {
        int len=str.size();
        set<string> solve;

        int loop=len;
        string temp;
        while( loop-- )
        {
            //求子串
            temp=str.substr(loop, len-loop );
            solve.insert( temp );
            temp.clear();
        }

        set<string>::iterator it=solve.begin();
        for(; it!=solve.end(); ++it)
        {
            cout<<(*it)<<endl;
        }
    }

    return 0;
}