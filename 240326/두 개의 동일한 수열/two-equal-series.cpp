#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr1[100];
int arr2[100];

int main() {
    // 여기에 코드를 작성해주세요.
    bool chk = true;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    for(int i = 0; i < n; i++){
        if(arr1[i] != arr2[i]){
            chk = false;
        }
    }

    if(chk) cout << "Yes";
    else cout << "No";

    return 0;
}