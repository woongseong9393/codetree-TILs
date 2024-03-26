#include <iostream>
#include <algorithm>

using namespace std;

bool cmpAsc(int a, int b){
    return a < b;
}

bool cmpDsc(int a, int b){
    return a > b;
}

int n;
int arr[100];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, cmpAsc);

    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    sort(arr, arr + n, cmpDsc);

    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';


    return 0;
}