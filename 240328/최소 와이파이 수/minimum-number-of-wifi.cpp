#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int ppl[100] = {0,};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> ppl[i];
    }

    int ans = 0;
    int wifi_s = -1, wifi_f = -1;
    for(int i = 0; i < n; i++){
        if(ppl[i] == 1 && wifi_f < i){
            wifi_s = i + m;
            wifi_f = wifi_s + m;
            ans++;
        }
    }

    cout << ans;

    return 0;
}