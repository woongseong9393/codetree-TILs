#include <iostream>

using namespace std;

int a, b, c, d;

int h, m;
int elapsed_time = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b >> c >> d;

    h = a;
    m = b;

    while(1){
        if(h == c && m == d){
            cout << elapsed_time;
            break;
        }

        elapsed_time++;
        m++;
        if(m % 60 == 0){
            m = 0;
            h++;
        }
    }

    return 0;
}