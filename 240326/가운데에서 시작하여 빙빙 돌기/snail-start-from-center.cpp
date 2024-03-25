#include <iostream>
#define MAX_NUM 100

using namespace std;

int N;

int mp[MAX_NUM][MAX_NUM] = {0,};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

/*L U R D*/
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    cin >> N;

    int x = N - 1 ;
    int y = N - 1 ;
    int idx = 1;
    int dir = 0;

    for(; idx <= N * N; idx++){
        mp[y][x] = N*N - idx + 1;
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
    
        if(!inRange(nextX, nextY)|| mp[nextY][nextX] != 0){
            dir = (dir + 1) % 4;
            nextX = x + dx[dir];
            nextY = y + dy[dir];
        }

        x = nextX;
        y = nextY;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }




    return 0;
}