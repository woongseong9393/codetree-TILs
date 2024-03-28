#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int ans = 0;

int arr[1000];

int main() {
    // 여기에 코드를 작성해주세요
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(i >= 1 && arr[i-1] < arr[i]){
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