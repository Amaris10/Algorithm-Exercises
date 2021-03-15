#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

long long m, n, r;

vector<long long> O;//存储黑洞中心
vector<long long> p[2000];//存储旅行点


long double dis[2000][2000];//两点间的旅行距离
long long dirdis2[2000][2000];//两点间直线距离的平方值
long long pr2[2000];//点到黑洞中心距离的平方值


//计算两点间直线距离的平方值（整型）
long long caldirdis2(int x, int y) {
    long long ans=0;
    for (int i = 0;i < n;i++) {
        ans += (p[x].at(i) - p[y].at(i))*(p[x].at(i) - p[y].at(i));
    }
    return ans;
}

//判断连线是否在黑洞外
bool isOut(int x,int y) {
    long double a,b,c,d,h;
    long long pm1=0,pm2=0;

    //根据公式计算O点到xy直线的距离h
    a = sqrt(pr2[x]);
    b = sqrt(pr2[y]);
    c = sqrt(dirdis2[x][y]);
    d = (a + b + c) / 2;
    h = 2 * sqrt(d * (d - a) * (d - b) * (d - c)) / c;

    //pm1为ox点乘yx；pm2为oy点乘yx；
    for(int i=0;i<n;i++){
        pm1+=p[x].at(i)*(p[x].at(i)-p[y].at(i));
        pm2+=p[y].at(i)*(p[y].at(i)-p[x].at(i));
    }

    //若h大于r或者pm1或pm2小于等于零，则连线在黑洞外；
    return (h >= r+0.000001||pm1<=0||pm2<=0);
}


//计算x，y两点与o点形成夹角的弧度值
long double caltheta(int x, int y) {
    int mult=0;
    long double theta;

    //求ox点乘oy的值（整型）
    for(int i=0;i<n;i++){
        mult+=p[x].at(i)*p[y].at(i);
    }


    if(mult*mult == pr2[x] * pr2[y]){//判断cos值是否为1或-1，避免sqrt精度问题导致的nan值结果
        if (mult>0){//cos值为1，theta=0；
            return 0;
        }else{//cos值为-1，theta=pi ；
            return 3.1415926535897932;
        }
    }else{//其余情况根据公式求theta值
        theta=acos(mult / sqrt(pr2[x] * pr2[y]));
        return theta;
    }
}


//两点间带曲线路程计算
long double calcirdis(int x, int y) {
    long double a = pr2[x], b = pr2[y], c = dirdis2[x][y],ans;

    /**分为三部分，黑洞表面曲线部分，x点到切点的距离，y点到切点的距离
    黑洞表面曲线求取略微复杂，先调用caltheta(x, y)求<XOY>的弧度thete0
        再用 acos(sqrt(r*r / a))求出<xo切点> 的弧度 thete1
        同理 acos(sqrt(r*r / b))求出<yo切点> 的弧度 thete2
    (thete0-thete1-thete2)*半径，则得出黑洞表面曲线的长度
    **/
    ans=caltheta(x, y)*r - acos(sqrt(r*r / a))*r - acos(sqrt(r*r / b))* r + sqrt(a - r * r) + sqrt(b - r * r);
    return ans;
}


//计算x点与y点之间的旅行距离，并将该距离赋值给dis[X][Y]和dis[Y][X]
void caldis(int x, int y) {
    dirdis2[x][y] = caldirdis2(x, y);//先计算两点间直线距离的平方值
    dirdis2[y][x] = dirdis2[x][y];
    if (isOut(x,y)) {//判定两点间连线是否在黑洞之外
        dis[x][y]=sqrt(dirdis2[x][y]);//若在黑洞之外则路程为dirdis2开平方
        dis[y][x]=dis[x][y];
    }else {
        dis[x][y] = calcirdis(x, y);//若在黑洞内则调用曲线路程函数计算
        dis[y][x] = dis[x][y];
    }
}

int main() {
    int in;
    long double ans;

    //n维，m个点，黑洞半径为r；
    cin >> n >> m >> r;


    //黑洞中心的坐标值
    for (int i = 0;i < n;i++) {
        cin >> in;
        O.push_back(in);
    }


    //输入m个n维的点
    for (int i = 0;i < m;i++) {
        pr2[i] = 0;
        for (int j = 0;j < n;j++) {
            cin >> in;
            p[i].push_back(in - O.at(j));//记录坐标值为相对于黑洞中心位置的坐标值
            pr2[i] += (in - O.at(j))*(in - O.at(j));//记录该点到黑洞中心距离的平方值（整型）
        }
    }


    //调用caldis函数对dis数组赋值
    for (int i = 0;i < m;i++) {
        for (int j = i + 1;j < m;j++) {
            caldis(i, j);
        }
    }


    //输出结果
    for (int i = 0;i < m;i++) {
        ans = 0;
        for (int j = 0;j < m;j++) {
            ans = ans + dis[i][j];
        }
        printf("%.14Lf\n",ans);
    }


    return 0;
}
