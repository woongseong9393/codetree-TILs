#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int mp[20][20] = {0,};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mp[i][j];
        }
    }

    int res = INT_MIN;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N-2; j++){
            int cnt = mp[i][j] + mp[i][j+1] + mp[i][j+2];
            res = max(res, cnt);
        }
    }

    cout << res;

    return 0;
}