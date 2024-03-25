#include <iostream>
#define MAX_NUM 102

using namespace std;

int N, M;
int r, c;

/*N E S W*/
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool mp[MAX_NUM][MAX_NUM] = {0,};

bool chk_state(int r, int c){
    int nextR, nextC;
    int cnt = 0;

    for(int i = 0; i < 4; i++){
        nextR = r + dy[i];
        nextC = c + dx[i];
        if(mp[nextR][nextC]) cnt++;
    }

    if(cnt == 3){
        return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> r >> c;
        mp[r][c] = 1;

        cout << chk_state(r, c) << '\n';
    }

    return 0;
}