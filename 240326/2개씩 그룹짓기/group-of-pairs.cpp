#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1000];
vector<int> v;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n / 2; i++){
        v.push_back(arr[i] + arr[n-1-i]);
    }

    int max = *max_element(v.begin(), v.end());

    cout << max;


    return 0;
}