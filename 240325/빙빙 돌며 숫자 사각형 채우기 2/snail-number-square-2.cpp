#include <iostream>
#define MAX_NUM 100
using namespace std;

int N, M;
int mp[MAX_NUM][MAX_NUM] = {0,};

bool inRange(int x, int y){
    return 0 <= x && x < M && 0 <= y && y < N;
}

/*D R U L*/
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    int dir = 0;
    int idx = 1;
    int x = 0, y = 0;
    int nextX, nextY;

    cin >> N >> M;

    for(;idx <= N*M; idx++){
        mp[y][x] = idx;
        nextX = x + dx[dir];
        nextY = y + dy[dir];
        if(!inRange(nextX, nextY) || mp[nextY][nextX] != 0){
            dir = (dir + 1) % 4;
            nextX = x + dx[dir];
            nextY = y + dy[dir];
        }
        x = nextX;
        y = nextY;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}