#include <iostream>
using namespace std;

int N;
int cow[100] = {0,};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> cow[i];
    }

    int res = 0;

    for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
            for(int k = j + 1; k < N; k++){
                if(cow[i] <= cow[j] && cow[j] <= cow[k]){
                    res++;
                }
            }
        }
    }

    cout << res;

    return 0;
}