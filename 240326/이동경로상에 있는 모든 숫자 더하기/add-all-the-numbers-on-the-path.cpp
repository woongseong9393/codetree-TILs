#include <iostream>
#include <string>

#define MAX_NUM 100

using namespace std;

/*N E S W*/
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int mp[MAX_NUM][MAX_NUM] = {0,};

int N, T;
string str;

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    cin >> N >> T;
    cin >> str;

    int x = N / 2;
    int y = N / 2;
    int dir = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mp[i][j];
        }
    }

    int res = mp[y][x];

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'F'){
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];
            if(!inRange(nextX, nextY)){
                continue;
            } 

            x = nextX;
            y = nextY;
            res += mp[y][x];
        } else if(str[i] == 'R'){
            dir = (dir + 1) % 4;
        } else{
            dir = (dir + 3) % 4;
        }
        //cout << str[i] << ' '<<  x << ' ' << y << endl;
    }

    cout << res;


    return 0;
}