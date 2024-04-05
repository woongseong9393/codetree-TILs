#include <iostream>
#include <vector>

using namespace std;

int N;
bool visited[100][100] = {0,};
int mp[100][100];

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int cnt;

void DFS(int x, int y){
    for(int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];

        if(inRange(newx, newy) && !visited[newy][newx] && mp[newy][newx] == mp[y][x]){
            visited[newy][newx] = 1;
            cnt++;
            DFS(newx, newy);
        }
    }

    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mp[i][j];
        }
    }
    
    vector<int> v;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 0){
                visited[i][j] = 1;
                cnt = 1;
                DFS(j, i);
                v.push_back(cnt);
            }
        }
    }

    int max = 0;
    int num_of_blast = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] >= 4) num_of_blast++;
        if(max < v[i]) max = v[i];
    }

    cout << num_of_blast << ' ' << max;

    return 0;
}