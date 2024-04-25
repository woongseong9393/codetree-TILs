#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int arr[100];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    int res = INT_MIN;

    for(int i = 0; i < N - 2; i++){
        for(int j = i + 2; j < N; j++){
            res = max(res, arr[i] + arr[j]);
        }
    }

    cout << res;

    return 0;
}