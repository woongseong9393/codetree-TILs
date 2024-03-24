#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, dist, dir;
    char dirc;
    int x = 0, y = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> dirc >> dist;
        if(dirc == 'N') dir = 0;
        else if(dirc == 'E') dir = 1;
        else if(dirc == 'S') dir = 2;
        else dir = 3;

        x += dx[dir] * dist;
        y += dy[dir] * dist;
    }

    cout << x << ' ' << y;

    return 0;
}