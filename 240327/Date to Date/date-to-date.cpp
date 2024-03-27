#include <iostream>

using namespace std;

int m1, d1, m2, d2;
int m, d;
int elapsed_day = 1;
                        /* 1   2   3   4   5   6   7   8   9  10  11  12 */
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> m1 >> d1 >> m2 >> d2;

    m = m1;
    d = d1;
    while(1){
        if(m == m2 && d == d2){
            cout << elapsed_day;
            break;
        }

        elapsed_day++;
        d++;

        if(d > num_of_days[m]){
            d = 1;
            m++;
        }
    }
    return 0;
}