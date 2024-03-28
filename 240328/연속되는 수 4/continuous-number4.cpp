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

    int dist, cnt, curr;
    for(int i = 0; i < N; i++){
        curr = arr[i];
        cnt = 1;
        dist = 1;
        for(int j = i + 1; j < N; j++){
            if(curr + dist == arr[j]){
                curr = arr[j];
                dist++;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
    
    return 0;
}