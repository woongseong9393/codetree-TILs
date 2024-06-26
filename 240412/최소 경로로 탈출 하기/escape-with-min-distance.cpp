#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int mp[100][100] = {0,};
int visited[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> q;

bool inRange(int x, int y){
    return 0 <= x && x < M && 0 <= y && y < N;
}

void BFS(int x, int y, int step){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(inRange(nx, ny) && mp[ny][nx] == 1 && visited[ny][nx] < 0){
            visited[ny][nx] = step+1;
            BFS(nx, ny, step + 1);
        }
    }

    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mp[i][j];
        }
    }

    memset(visited, -1, sizeof(visited));

    visited[0][0] = 0;
    BFS(0, 0, 0);

    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
    */
    
    cout << visited[N-1][M-1];

    return 0;
}