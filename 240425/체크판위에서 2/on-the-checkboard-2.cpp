#include <iostream>
using namespace std;

int R, C;
char mp[15][15];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> R >> C;
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> mp[i][j];
        }
    }

    int res = 0;
    int cnt = 0;
    char curr = mp[0][0];

    if(mp[0][0] != mp[R-1][C-1]){
        for(int i = 1; i < R-2; i++){
            for(int j = 1; j < C-2; j++){
                if(mp[i][j] != curr){
                    for(int k = i + 1; k < R - 1; k++){
                        for(int l = j + 1; l < C - 1; l++){
                            if(mp[k][l] == curr){
                                res++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << res;

    return 0;
}