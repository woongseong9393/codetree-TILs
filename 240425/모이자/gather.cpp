#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int home[101] = {0,};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> home[i];
    }

    int res = INT_MAX;
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= N; j++){
            sum += home[j] * abs(i - j);
        }
        res = min(res, sum);
    }

    cout << res;

    return 0;
}