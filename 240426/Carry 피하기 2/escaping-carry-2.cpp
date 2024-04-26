#include <iostream>
#include <climits>
using namespace std;

int N;
int res = -1;
int arr[20];

bool chk_carry(int a, int b){
    bool flag = true;
    while(a != 0 && b != 0){
        int temp_a = a % 10;
        int temp_b = b % 10;

        a /= 10;
        b /= 10;

        if(temp_a + temp_b >= 10){
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N - 2; i++){
        for(int j = i + 1; j < N - 1; j++){
            if(!chk_carry(arr[i], arr[j])) continue;
            int temp = arr[i] + arr[j];

            for(int k = j + 1; k < N; k++){
                if(!chk_carry(temp, arr[k])) continue;

                res = max(res, temp + arr[k]);
            }
        }
    }

    cout << res;
    return 0;
}