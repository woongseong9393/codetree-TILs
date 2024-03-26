#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[2000];
vector<int> v;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n * 2; i++){
        cin >> arr[i];
    }

    sort(arr, arr + 2 * n);

    for(int i = 0; i < n ; i++){
        v.push_back(arr[i] + arr[2 * n -1 -i]);
        //cout << arr[i] << ' ' << arr[2 * n -1 -i] << endl;
    }

    int max = *max_element(v.begin(), v.end());

    cout << max;


    return 0;
}