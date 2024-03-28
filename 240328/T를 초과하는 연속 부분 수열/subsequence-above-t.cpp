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
        if(arr[i] > t){
            cnt++;
        } else {
            cnt = 0;
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}