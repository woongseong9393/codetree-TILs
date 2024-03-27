#include <iostream>

using namespace std;

int a, b, c;

int check_min(int day, int hour, int min){
    int res = 0;
    for(int i = 1; i < day; i++){
        res += 60 * 24;
    }
    res += 60 * hour;
    res += min;

    return res;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b >> c;

    int ans = check_min(a, b, c) - check_min(11, 11, 11); 

    if(ans){
        cout << ans;
    } else{
        cout << -1;
    }

    return 0;
}