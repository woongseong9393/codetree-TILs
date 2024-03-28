#include <iostream>

using namespace std;

int N, M, dist;
char dir;

int A[1000001] = {0,};
int B[1000001] = {0,};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    int idx_A = 1;
    for(int i = 0; i < N; i++){
        cin >> dir >> dist;
        for(int k = 0; k < dist; k++){
            if(dir == 'L'){
                A[idx_A] = A[idx_A - 1] - 1;
            } else{
                A[idx_A] = A[idx_A - 1] + 1;
            }
            idx_A++;
        }
    }

    int idx_B = 1;
    for(int i = 0; i < M; i++){
        cin >> dir >> dist;
        for(int k = 0; k < dist; k++){
            if(dir == 'L'){
                B[idx_B] = B[idx_B - 1] - 1;
            } else{
                B[idx_B] = B[idx_B - 1] + 1;
            }
            idx_B++;
        }
    }

    int t = idx_A < idx_B ? idx_A : idx_B;

    bool chk = 0;
    for(int i = 1; i < t; i++){
        if(A[i] == B[i]){
            cout << i;
            chk = 1;
            break;
        }
    }

    if(!chk){
        cout << -1;
    }

    return 0;
}