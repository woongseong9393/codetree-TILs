#include <iostream>
#include <vector>
using namespace std;

bool visited[100][100] = {0,};
bool mp[100][100];

int n, m;

bool inRange(int x, int y){
    return 0 <= x && x < m && 0 <= y && y < n;
}

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void DFS(int x, int y){
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inRange(nx, ny) && visited[ny][nx] == 0 && mp[ny][nx] == 1){
            visited[ny][nx] = true;
            DFS(nx, ny);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }

    DFS(0, 0);

    if(visited[n-1][m-1]){
        cout << 1;
    } else{
        cout << 0;
    }

    return 0;
}