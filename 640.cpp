#include <iostream>
using namespace std;

bool is_leap(int year) {
    return (year % 400 == 0) || (year %4 == 0 && year % 100 != 0);
}

int to_julian_day (int day, int month, int year) {
    int a = (14 - month) / 12;
    int y1 = year + 4800 - a;
    int m1 = month + 12*a - 3;

    return day + (153*m1 + 2)/5 + 365*y1 + y1/4 - y1/100 + y1/400 - 32045;
}


int main(){
    int brt_day, brt_month;
    int now_day, now_month, now_year;

    cin >> brt_day >> brt_month;
    cin >> now_day >> now_month >> now_year;

        if (brt_day == 29 && brt_month == 2) {
            int next_leap_year = now_year;
            if (brt_month < now_month || (brt_month == now_month && brt_day < now_day)) {
                next_leap_year = now_year + 1;
            }
            while (!is_leap(next_leap_year)) {
            next_leap_year++;
        }
        int jd_now = to_julian_day(now_day, now_month, now_year);
        int jd_brt = to_julian_day(29, 2, next_leap_year);
        int days_left = jd_brt - jd_now;

        cout << days_left << endl;
        return 0;
        }

    int jd_now = to_julian_day(now_day, now_month, now_year);
    int jd_brt_this_year = to_julian_day(brt_day, brt_month, now_year);

    int days_left;

    if (jd_brt_this_year >= jd_now) {
        days_left = jd_brt_this_year - jd_now;
    }

    else {
        int jd_brt_next_year = to_julian_day(brt_day, brt_month, now_year + 1);
        days_left = jd_brt_next_year - jd_now;
    }

    cout << days_left << endl;

    return 0;

}