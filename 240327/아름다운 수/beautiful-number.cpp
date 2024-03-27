#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

int n;
int cnt = 0;

void Permute(int curr_n){
    if(curr_n == n + 1){
        cnt++;
        return;
    }

    for(int k = 1; k <= 4; k++){
        if(n + 1 - curr_n >= k){
            for(int idx = 0; idx < k; idx++){
                ans.push_back(k);
            }
            Permute(curr_n + k);
            for(int idx = 0; idx < k; idx++){
                ans.pop_back();
            }
        }
    }

    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    Permute(1);

    cout << cnt;

    return 0;
}