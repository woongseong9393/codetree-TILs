#include <iostream>

using namespace std;

int N;

int arr[1000];
int ans = 0;
int num_odd = 0, num_even = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(arr[i] % 2) num_odd++;
        else num_even++;
    }

    while(true){
        if(num_even >= num_odd){
            ans = num_odd + num_even;
            break;
        } else if (num_even + 1 == num_odd){
            ans = num_even * 2 - 1;
            break;
        } else{
            num_even++;
            num_odd -= 2;
        }
    }

    cout << ans;

    return 0;
}