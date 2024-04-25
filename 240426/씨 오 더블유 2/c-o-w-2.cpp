#include <iostream>
#include <string>

using namespace std;

int N;
string st;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> st;

    int res = 0;

    for(int i = 0; i < N-2; i++){
        for(int j = i + 1; j < N - 1; j++){
            for(int k = j + 1; k < N; k++){
                if(st[i] == 'C' && st[j] == 'O' && st[k] == 'W') res++;
            }
        }
    }

    cout << res; 
    
    return 0;
}