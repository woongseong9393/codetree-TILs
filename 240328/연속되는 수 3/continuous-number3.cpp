#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
int ans = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(i >= 1 && ((arr[i-1] < 0 && arr[i] < 0)||(arr[i-1]> 0 && arr[i] > 0))){
            cnt++;
        }
        else{
            cnt = 1;
        }

        ans = max(ans, cnt);
    }

    cout << ans;


    return 0;
}