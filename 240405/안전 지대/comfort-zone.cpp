#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std; 

int N, M, K;
int mp[50][50];
bool visited[50][50] = {0,};
priority_queue<pair<int, int>> pq;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inRange(int x, int y){
    return 0 <= x && x < M && 0 <= y && y < N;
}

void DFS(int x, int y){
    for(int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(inRange(newx, newy) && visited[newy][newx] == 0 && mp[newy][newx] > K){
            visited[newy][newx] = 1;
            DFS(newx, newy);
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

    for(K = 1; K <= 100; K++){
        int cnt = 0;
        bool chk = false;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(mp[i][j] > K && visited[i][j] == 0){
                    visited[i][j] = 1;
                    cnt++;
                    DFS(j, i);
                    chk = true;
                }
            }
        }
        if(!chk) break;
        pq.push(make_pair(cnt, -K));
    }

    cout << -pq.top().second << ' ' << pq.top().first;

    return 0;
}