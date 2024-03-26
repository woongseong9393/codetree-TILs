#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[100];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum;
    int res;
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            sum += abs(i - j) * arr[j];
        }
        if(min > sum){
            min = sum;
            res = i;
        }
    }

    cout << min;

    return 0;
}