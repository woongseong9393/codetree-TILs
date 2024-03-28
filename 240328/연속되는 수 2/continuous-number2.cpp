#include <iostream>
#include <cstdlib>

using namespace std;

int N;
int ans = 0;

int arr[1001];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    arr[0] = -1;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    int st = 0;

    for(int i = 0; i <= N; i++){
        if(arr[i-1] != arr[i]){
            ans = max(ans, i - st);
            st = i;
        }
    }

    cout << ans;

    return 0;
}