#include <iostream>

using namespace std;

int N;

/*북 동 남 서*/
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int char2num(char dir){
    int res;
    switch(dir)
    {
        case 'N':
            res = 0;
            break;
        case 'E':
            res  = 1;
            break;
        case 'S':
            res = 2;
            break;
        case 'W':
            res = 3;
            break;
    }

    return res;
}


int main() {
    // 여기에 코드를 작성해주세요.
    char dir;
    int dir_num, dist;
    bool flag = 0;
    int x = 0, y = 0;

    cin >> N;

    int t = 0;

    for(int i = 0; i < N; i++){
        cin >> dir >> dist;
        dir_num = char2num(dir);

        for(int dt = 0; dt < dist; dt++){
            t++;
            x += dx[dir_num];
            y += dy[dir_num];

            if(x == 0 && y == 0){
                flag = 1;
                break;
            }
        }
        if(flag) break;  
    }

    if(flag) cout << t;
    else cout << -1;

    return 0;
}