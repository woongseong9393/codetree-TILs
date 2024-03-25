#include <iostream>
#include <string>

using namespace std;

string odr;
int dir_num = 0;
int x = 0, y = 0;

/* N E S W */
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool Move(char dir){
    if(dir == 'F'){
        x += dx[dir_num];
        y += dy[dir_num];
        if(x == 0 && y == 0){
            return true;
        }
    } else if(dir == 'L'){
        dir_num = (dir_num + 3) % 4;
    } else{
        dir_num = (dir_num + 1) % 4;
    }
    return false;
}


int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> odr;
    bool chk = false;

    for(int idx = 0; odr[idx] != '\0'; idx++){
        if(Move(odr[idx])){
            cout << idx + 1;
            chk = true;
            break;
        }
    }

    if(!chk){
        cout << -1;
    }

    return 0;
}