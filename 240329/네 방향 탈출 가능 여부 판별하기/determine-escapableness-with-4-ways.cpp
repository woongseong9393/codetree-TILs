#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

bool visited[100][100] = {0,};
bool map[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inRange(int x, int y){
    return 0 <= x && x < m && 0 <= y && y < n;
}

queue<pair<int, int>> q;

void BFS(){
    while(!q.empty()){
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(inRange(newx, newy)){
                if(map[newy][newx] == 1 && visited[newy][newx] == 0){
                    visited[newy][newx] = 1;
                    q.push(make_pair(newx, newy));
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    BFS();

    if(visited[n-1][m-1]){
        cout << 1;
    } else{
        cout << 0;
    }

    return 0;
}