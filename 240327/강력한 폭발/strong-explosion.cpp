#include <iostream>
#include <vector>

using namespace std;

int n;
int num_of_bomb = 0;

int visited[20][20] = {0, };
vector<pair<int, int>> coordinate;

int max_bomb = 0;

int dx1[4] = {0, 0, 0, 0};
int dy1[4] = {-2, -1, 1, 2};
int dx2[4] = {1, 0, -1, 0};
int dy2[4] = {0, 1, 0, -1};
int dx3[4] = {-1, -1, 1, 1};
int dy3[4] = {1, -1, 1, -1};

bool inRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void check_max(){
    int count = 0;
    //cout << " ----------------------- \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) count++;
            //cout << visited[i][j] << ' ';
        }
       // cout << '\n';
    }

    if(max_bomb < count) max_bomb = count;


    return;
}

void find_bomb(int bomb_idx){
    if(bomb_idx == num_of_bomb){
        check_max();
        return;
    }

    int x = coordinate[bomb_idx].second;
    int y = coordinate[bomb_idx].first;

    int nextx, nexty;

    vector<pair<int, int>> v;

    for(int k = 1; k <=3; k++){
        if(k == 1){
            int vsize;
            for(int i = 0; i < 4; i++){
                nextx = x + dx1[i];
                nexty = y + dy1[i];
                if(inRange(nextx, nexty) && visited[nexty][nextx] == 0){
                    visited[nexty][nextx] = 1;
                    v.push_back(make_pair(nextx, nexty));
                }
                vsize = v.size();
            }

            find_bomb(bomb_idx + 1);

            for(int i = 0; i < vsize; i++){
                auto p = v.back();
                visited[p.second][p.first] = 0;
                v.pop_back();
            }
        } else if( k == 2){
            int vsize;
            for(int i = 0; i < 4; i++){
                nextx = x + dx2[i];
                nexty = y + dy2[i];
                if(inRange(nextx, nexty) && visited[nexty][nextx] == 0){
                    visited[nexty][nextx] = 1;
                    v.push_back(make_pair(nextx, nexty));
                }
                vsize = v.size();
            }

            find_bomb(bomb_idx + 1);

            for(int i = 0; i < vsize; i++){
                auto p = v.back();
                visited[p.second][p.first] = 0;
                v.pop_back();
            }
        } else{
            int vsize;
            for(int i = 0; i < 4; i++){
                nextx = x + dx3[i];
                nexty = y + dy3[i];
                if(inRange(nextx, nexty) && visited[nexty][nextx] == 0){
                    visited[nexty][nextx] = 1;
                    v.push_back(make_pair(nextx, nexty));
                }
                vsize = v.size();
            }

            find_bomb(bomb_idx + 1);

            for(int i = 0; i < vsize; i++){
                auto p = v.back();
                visited[p.second][p.first] = 0;
                v.pop_back();
            }
        }
    }

    return;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> visited[i][j];
            if(visited[i][j]) {
                coordinate.push_back(make_pair(i, j));
                num_of_bomb++;
            }
        }
    }

    find_bomb(0);
    cout << max_bomb;

    return 0;
}