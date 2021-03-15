#include<iostream>
using namespace std;
int main(){
    int number;
    while(cin>>number){
        int* a=new int[number];
        int temp;
        for(int i=0;i<number;i++)
            cin>>a[i];
        int min=1000000,max=-1000000;
        for(int i=0;i<number;i++){
            if(a[i]<min)
                min=a[i];
            if(a[i]>max)
                max=a[i];
        }
        cout<<max<<' '<<min<<endl;
    }
}