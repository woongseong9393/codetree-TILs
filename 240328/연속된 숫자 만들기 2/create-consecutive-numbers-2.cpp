#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int arr[3];

int main() {
    // 여기에 코드를 작성해주세요.
    
    for(int i = 0; i < 3; i++) cin >> arr[i];

    sort(arr, arr + 3);

    int ans = 2;

    if(arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1){
        ans = 0;
    } else if(arr[1] - arr[0] == 2 || arr[2] - arr[1] == 2){
        ans = 1;
    }

    cout << ans;
    
    return 0;
}