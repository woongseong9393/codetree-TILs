#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int x[100] = {0,};
int y[100] = {0,};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    int res = 200001;
    int total = 0;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
        
        if(i > 0){
            total += abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        }
    }

    for(int i = 1; i < N - 1; i++){
        int temp = total;
        temp -= (abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]));
        temp -= (abs(x[i] - x[i+1]) + abs(y[i] - y[i+1]));
        temp += (abs(x[i-1] - x[i+1]) + abs(y[i-1] - y[i+1]));

        res = min(res, temp);
    }

    cout << res;

    return 0;
}