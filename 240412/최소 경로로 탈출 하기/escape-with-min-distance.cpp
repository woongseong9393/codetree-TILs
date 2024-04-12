#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int mp[100][100] = {0,};
int step[100][100] = {0,};
bool visited[100][100] = {0,};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> q;

bool inRange(int x, int y){
    return 0 <= x && x < M && 0 <= y && y < N;
}



void BFS(){
    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if(inRange(nx, ny) && visited[ny][nx] == 0 && mp[ny][nx] == 1){
                visited[ny][nx] = true;
                step[ny][nx] = step[curr_y][curr_x] + 1;
                q.push(make_pair(nx, ny));
            }
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

    visited[0][0] = 1;
    step[N-1][M-1] = -1;
    q.push({0, 0});
    BFS();

    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
    */
    
    cout << step[N-1][M-1]; 

    return 0;
}