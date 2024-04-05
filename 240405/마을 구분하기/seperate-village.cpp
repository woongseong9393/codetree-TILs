#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int mp[25][25];
vector<pair<int, int>> coord;
vector<int> v;
bool visited[25][25] = {0,};

int ans = INT_MIN;

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int DFS(int x, int y, int cnt){
    int temp_cnt = cnt;
    for(int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(inRange(newx, newy) && mp[newy][newx] == 1 && visited[newy][newx] == 0){
            visited[newy][newx] = 1;
            temp_cnt += DFS(newx, newy, cnt);
        }
    }
    
    cnt = temp_cnt + 1;

    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mp[i][j];
            if(mp[i][j]){
                coord.push_back(make_pair(j, i));
            }
        }
    }

    for(int i = 0; i < coord.size(); i++){
        int x = coord[i].first;
        int y = coord[i].second;

        if(visited[y][x]){
            continue;
        } else{
            visited[y][x] = 1;
            v.push_back(DFS(x, y, 0));
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}