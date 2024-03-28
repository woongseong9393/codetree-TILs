#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[100][100] = {0,};
int mp[100][100];
queue<pair<int, int>> q;

int n, k;

bool inRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void BFS(){
    while(!q.empty()){
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(inRange(nx, ny)){
                if(mp[ny][nx] == 0 && visited[ny][nx] == 0){
                    visited[ny][nx] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mp[i][j];
        }
    }

    int x, y;
    for(int i = 0; i < k; i++){
        cin >> y >> x;
        q.push(make_pair(x-1, y-1));
        visited[y-1][x-1] = 1;
    }

    BFS();

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) ans++;
        }
    }

    cout << ans;
    return 0;
}