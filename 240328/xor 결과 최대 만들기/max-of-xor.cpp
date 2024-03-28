#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M;

vector<int> v;
vector<int> nums;

int ans = INT_MIN;

void calc_xor(){
    int res = 0;
    for(const auto& element: v){
        res = res ^ element;
    }

    ans = max(ans, res);
}

void find_xor(int curr_n, int cnt){
    if(curr_n == N){
        if(cnt == M){
            calc_xor();
        }
        return;
    }

    // case 1
    v.push_back(nums[curr_n]);
    find_xor(curr_n + 1, cnt + 1);
    v.pop_back();

    // case 2
    find_xor(curr_n + 1, cnt);
    
    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        nums.push_back(num);
    }

    find_xor(0, 0);

    cout << ans;

    return 0;
}