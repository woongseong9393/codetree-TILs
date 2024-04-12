#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool visited[100][100] = {0,};
int step[100][100];

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

queue<pair<int, int>> q;

void BFS(){
    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if(inRange(nx, ny) && visited[ny][nx] == 0){
                visited[ny][nx] = 1;
                step[ny][nx] = step[curr_y][curr_x] + 1;
                
                q.push(make_pair(nx, ny));
            }
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    visited[r1-1][c1-1] = 1;
    step[r1-1][c1-1] = 0;
    q.push(make_pair(r1-1, c1-1));
    
    step[r2-1][c2-1] = -1;

    BFS();

    cout << step[r2-1][c2-1];


    return 0;
}