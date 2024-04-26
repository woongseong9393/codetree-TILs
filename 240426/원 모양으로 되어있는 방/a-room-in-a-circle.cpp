#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1003];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    int res = 1003 * 1003 * 100;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(j < i){
                sum += arr[j] * (N - (i - j));
            } else{
                sum += arr[j] * (j - i);
            }
        }
        res = min(res, sum);
    }

    cout << res;
    return 0;
}