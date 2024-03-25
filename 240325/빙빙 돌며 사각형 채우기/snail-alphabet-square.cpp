#include <iostream>
#define MAX_NUM 100
using namespace std;

int N, M;
char mp[MAX_NUM][MAX_NUM] = {0,};

bool inRange(int x, int y){
    return 0 <= x && x < M && 0 <= y && y < N;
}

/*R D L U*/
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dir = 0;
int x = 0, y = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;

    int idx = 0;

    for(; idx < N * M; idx++){
        mp[y][x] = 'A' + (idx % ('Z'-'A' + 1));
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];

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