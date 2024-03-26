#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string arr[100];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }


    return 0;
}