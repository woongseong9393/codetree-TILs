#include <iostream>
#define MAX 102
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int map[MAX][MAX] = {0,};
    int res = 0;

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
            //cout << map[i][j];
        }
        //cout << '\n';
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                if(map[i + dx[k]][j + dy[k]]) cnt++;
            }
            if(cnt >= 3) res++;
        }
    }

    cout << res;

    return 0;
}