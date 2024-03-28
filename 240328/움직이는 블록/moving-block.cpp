#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[10000];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int target  = sum / N;
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] > target){
            ans += arr[i] - target;
        }
    }

    cout << ans;

    return 0;
}