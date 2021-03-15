/**
 * @author: Qiuyue Zhang
 * @date: 2021/2/2 17:51
 * @description:
 */

#include <iostream>

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

int main(){
    int year, month, day;
    int number;
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--){
        scanf("%d %d %d %d", &year, &month, &day, &number);
        int row = IsLeapYear(year);
        for (int i = 0; i < month; ++i) {
            number += daytab[row][i];
        }
        number += day;
        while (number > NumberofYear(year)){
            number -= NumberofYear(year);
            year++;
        }
        month = 0;
        row = IsLeapYear(year);
        while (number > daytab[row][month]){
            number -= daytab[row][month];
            month++;
        }
        day = number;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}