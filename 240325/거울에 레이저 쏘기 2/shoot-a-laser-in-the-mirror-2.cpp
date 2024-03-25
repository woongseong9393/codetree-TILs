#include <iostream>
#define MAX_NUM 1000
using namespace std;

int N, K;
int x, y;

/*S W N E*/
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

char mp[MAX_NUM][MAX_NUM];

int change_dir(char state, int dir){
    if(state == '\\'){
        if(dir%2) return (dir + 1) % 4;
        else return (dir + 3) % 4;
    } else{
        if(dir%2) return (dir + 3) % 4;
        else return (dir + 1) % 4;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    cin >> N;
    
    int dirc;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mp[i][j];
        }
    }
    cin >> K; 

    dirc = K%N ? K/N + 1 : K/N;

    if(dirc == 0){
        y = 0;
        x = (K-1)%N;
    } else if(dirc == 1){
        x = N-1;
        y = (K-1)%N;
    } else if(dirc == 2){
        y = 0;
        x = N-1 - (K-1)%N;
    } else{
        x = 0;
        y = N-1 - (K-1)%N;
    }

    int cnt = 1;

    while(inRange(x, y)){
       cnt++;
       dirc = change_dir(mp[y][x], dirc);
       x += dx[dirc];
       y += dy[dirc];
    }

    cout << cnt;

    

    return 0;
}