#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[101][101];

//북 동 남 서
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool inRange(int x ,int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }
    return false;
}

int main() {
    cin>>n>>m;
    arr[0][0] = 1;
    int x,y;
    x = 0, y = 0;
    int dict = 1;
    int idx = 1;
    for(; idx< n * m;){
        int nextX = x + dx[dict];
        int nextY = y + dy[dict];
        if(inRange(nextX,nextY) == false || arr[nextX][nextY] != 0){
            dict = (dict + 1) % 4;
            continue;
        }
        idx++;
        x = nextX;
        y = nextY;
        arr[x][y] = idx;
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}