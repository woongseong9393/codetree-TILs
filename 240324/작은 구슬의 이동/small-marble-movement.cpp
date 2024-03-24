#include <iostream>

using namespace std;

int n, t;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inRange(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int r, c;
    int dir;
    char d;

    cin >> n >> t;
    cin >> r >> c >> d;

    if(d == 'D') dir = 0;
    else if(d == 'U') dir = 2;
    else if(d == 'R') dir = 1;
    else dir = 3;

    for(int i = 1; i <= t; i++){
        if(inRange(c + dx[dir], r + dy[dir])){
            r += dy[dir];
            c += dx[dir];
        }
        else{
            dir = (dir + 2) % 4;
        }
    }

    cout << r << ' ' << c;

    return 0;
}