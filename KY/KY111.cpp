/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 18:39
 * @description:
 */
#include <iostream>
#include <cstdio>

using namespace std;

int daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

bool IsLeapYear(int year){
    return (year % 4 ==0 && year % 100 != 0 ) || (year % 400 == 0);
}

int NumberofYear(int year){
    if(IsLeapYear(year)){
        return 366;
    } else{
        return 365;
    }

}
int Date(int year, int month, int day) {
    int dateth = 0;
    for (int i = 0; i < year; i++) {
        dateth += NumberofYear(year);
    }
    for (int i = 0; i < month; i++) {
        int row = IsLeapYear(year);
        dateth += daytab[row][i];
    }
    dateth += day;
    return dateth;
}

int main(){
    int time1,year1,month1,day1;
    int time2,year2,month2,day2;

    while(scanf("%d%d",&time1,&time2)!=EOF){

        year1 = time1/10000;
        month1 = time1%10000/100;
        day1 = time1%100;
        year2 = time2/10000;
        month2 = time2%10000/100;
        day2 = time2%100;

        printf("%d\n", abs(Date(year1, month1, day1)-Date(year2, month2, day2))+1);
    }
    return 0;
}
