#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool mp[20][20] = {0,};

bool inRange(int x, int y){
    return 0 <= x - 1 && x + 1 < N && 0 <= y - 1 && y + 1 < N;
}

int calc_coin(int x, int y){
    int res = 0;
    for(int i = y - 1; i <= y + 1; i++){
        for(int j = x - 1; j <= x + 1; j++){
            if(mp[i][j]) res++;
        }
    }

    return res;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(inRange(j, i)){
                ans = max(ans, calc_coin(j, i));
            }
        }
    }

    cout << ans;

    return 0;
}