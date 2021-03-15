#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int max(int x,int y){
    return x>y?x:y;
}
struct treeNode{
    treeNode *parent;
    char lchild[20];
    char rchild[20];
    char name[20];
    int depth;
    treeNode(){
        depth=0;
        parent=NULL;
    }
};

treeNode node[100];

int main(int argc, char* argv[])
{
    char line[100];
    char nametmp[3][20];
    int spaceindex,curstart=0;
    int n=0,curcount=0,c=0;
    int nodeindex=0;
    bool readend=false,find=0,find1=0,find2=0;
    while(getline(line)){
        for(int i=0;i<strlen(line);i++){
            if (line[i]==' '){
                spaceindex=i;
                strncpy(nametmp[curcount],line+curstart,spaceindex-curstart);
                nametmp[curcount][spaceindex-curstart]=0;
                //cout<<nametmp[curcount];
                curcount++;
                curstart=spaceindex+1;
            }
            if (i==strlen(line)-1){
                spaceindex=i+1;
                strncpy(nametmp[curcount],line+curstart,spaceindex-curstart);
                nametmp[curcount][spaceindex-curstart]=0;
                //cout<<nametmp[curcount];
                curcount++;
                if(curcount==2) readend=true;
            }
            if(curcount==3) {
                spaceindex=0;
                curstart=0;
                curcount=0;
                find=0;
                find1=0;
                find2=0;
                for(int j=0;j<n;j++){
                    if(strcmp(node[j].name,nametmp[0])==0){
                        find=1;
                        c=j;
                    }
                    if(strcmp(node[j].name,nametmp[1])==0){
                        find1=1;
                    }
                    if(strcmp(node[j].name,nametmp[2])==0){
                        find2=1;
                    }
                }
                if(find==0){
                    n++;
                    c=n;
                }
                strcpy(node[c].name,nametmp[0]);
                strcpy(node[c].lchild,nametmp[1]);
                strcpy(node[c].rchild,nametmp[2]);
                cout<<c<<":"<<node[c].name<<" "<<node[c].lchild<<" "<<node[c].rchild<<endl;
                if(find1==0){
                    n++;
                    c=n;
                    strcpy(node[c].name,nametmp[1]);
                    cout<<c<<":"<<node[c].name<<endl;
                }
                if(find2==0){
                    n++;
                    c=n;
                    strcpy(node[c].name,nametmp[2]);
                    cout<<c<<":"<<node[c].name<<endl;
                }

            }
            if(readend==true) break;

        }
        if(readend==true) {
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(strcmp(node[i].lchild,node[j].name)==0){
                        node[j].parent=&node[i];
                        node[j].depth=node[i].depth+1;
                    }
                    if(strcmp(node[i].rchild,node[j].name)==0){
                        node[j].parent=&node[i];
                        node[j].depth=node[i].depth+1;
                    }
                }
            }



            int dep1=0,dep2=0;
            treeNode *p1,*p2;
            for(int i=1;i<=n;i++){
                if(strcmp(node[i].name,nametmp[0])==0){
                    dep1=node[i].depth;
                    p1=&node[i];
                    cout<<"p1:"<<p1->name<<endl;
                }
                if(strcmp(node[i].name,nametmp[1])==0){
                    dep2=node[i].depth;
                    p2=&node[i];
                    cout<<"p2:"<<p2->name<<endl;
                }
            }

            cout<<"depth="<<dep1-dep2<<endl;
            while(p1!=p2){
                if(p1->depth>p2->depth)
                {
                    p1=p1->parent;
                    cout<<"p1:"<<p1->name<<endl;
                    continue;
                }
                if(p1->depth<p2->depth)
                {
                    p1=p1->parent;
                    cout<<"p2:"<<p2->name<<endl;
                    continue;
                }
                if(p1->depth==p2->depth&&p1!=p2)
                {
                    p1=p1->parent;
                    p2=p2->parent;
                    cout<<"p1:"<<p1->name<<endl;
                    cout<<"p2:"<<p2->name<<endl;
                }
            }
            cout<<"parent:"<<p1->name<<endl;
            break;
        }

    }

    return 0;
}