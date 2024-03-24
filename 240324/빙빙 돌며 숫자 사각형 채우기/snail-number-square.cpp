#include <iostream>
#define MAX_NUM 100
using namespace std;

int n, m;
int map[MAX_NUM][MAX_NUM] = {0,};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool inRange(int x, int y){
    return 0 <= x && x < m && 0 <= y && y < n; 
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    int dir = 1;
    int x = 0, y = 0;
    int total = n*m;

    for(int idx = 1; idx <= total; idx++){
        map[y][x] = idx;
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        if(!inRange(nextX, nextY) || map[nextY][nextX] != 0){
            dir = (dir + 1) % 4;
        }
        x = x + dx[dir];
        y = y + dy[dir];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}