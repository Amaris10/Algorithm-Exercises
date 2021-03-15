/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 18:59
 * @description:
 */


#include <cstdio>
#include <cstring>

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
// 计算从公元1年1月1号到当前的天数
int Date(int year, int month, int day) {
    int dateth = 0;
    for (int i = 1; i < year; i++) {
        dateth += NumberofYear(i);
    }
    for (int i = 0; i < month; i++) {
        int row = IsLeapYear(year);
        dateth += daytab[row][i];
    }
    dateth += day-1;
    return dateth;
}

char month_name[13][20]={
        "","January","February","March","April","May","June","July","August",
        "September","October","November","December"
};
char week_name[7][20]={
        "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"
};

int main(){
    int year, month, day;
    char Month[20];
    while(scanf("%d%s%d", &day, &Month, &year)!=EOF){
        for (int i = 1; i <= 12; ++i) {
            if(strcmp(Month,month_name[i])==0){
                month = i;
                break;
            }
        }
        printf("%s\n",week_name[(Date(year,month,day))%7]);
    }
    return 0;
}