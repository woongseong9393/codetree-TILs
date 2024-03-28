#include <iostream>
#include <algorithm>

using namespace std;

int n, t;

int arr[1000];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(i >= 1 && arr[i] > t && arr[i-1] < arr[i]){
            cnt++;
        } else if(arr[i] <= t){
            ans = max(ans, cnt);
            cnt = 0;
        } else {
            cnt = 1;
        }
    }

    cout << ans;

    return 0;
}