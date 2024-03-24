#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t;
    int r, c;
    int dir;
    char d;
    bool chk = 0;

    cin >> n >> t;
    cin >> r >> c >> d;

    if(d == 'D') dir = 0;
    else if(d == 'U') dir = 2;
    else if(d == 'R') dir = 1;
    else dir = 3;

    for(int i = 1; i <= t; i++){
        if((((r==1||r==n)&&dy[dir])||((c==1||c==n)&&dx[dir])) && chk == 0){
            dir = (dir + 2) % 4;
            chk = 1;
        }
        else{
            r += dy[dir];
            c += dx[dir];
            chk = 0;
        }
        //cout << r << ' ' << c << endl;

    }

    cout << r << ' ' << c;

    return 0;
}