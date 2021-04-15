/**
 * @author: Qiuyue Zhang
 * @date: 2021-04-15 9:48
 * @description: 回文日期
 */
#include <iostream>
using namespace std;

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 判断日期的合法性
bool check_valid(int date) //形如20210305
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if (month <= 0 || month >= 13) return false;
    if (day == 0 || month != 2 && day > months[month]) return false;

    if (month == 2)
    {
        int leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
        if (day > 28 + leap) return false;
    }

    return true;
}

// 判断date是否满足ABABBABA形式
bool check(int date)
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;


    if (month % 10 == day / 10) return false; //A==B return false
    if ((month % 10 == day % 10) && (month / 10 == day / 10)) return true;

    return false;
}

bool st1, st2;
int ans1, ans2;

int main()
{
    int date;
    cin >> date;

    int year = date / 10000;
    while (true)
    {
        int new_date = year, x = year;
        for (int i = 0; i < 4; i++) {
            new_date = new_date * 10 + x % 10, x /= 10; //构造回文日期
        }

        if (new_date == date)  //构造出来的是同一天
        {
            year++;
            continue;
        }

        if (check_valid(new_date))
        {
            if (!st1){
                st1 = true;
                ans1 = new_date;
            }
            if (!st2 && check(new_date)) {
                st2 = true;
                ans2 = new_date;
            }

        }
        year ++;
        if (st1 && st2) break; //找到两个解则退出
    }

    printf("%d\n%d", ans1, ans2);
    return 0;
}
