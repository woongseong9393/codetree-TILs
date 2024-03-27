#include <iostream>
#include <vector>

using namespace std;

int K, N;

vector<int> ans;

void Choose(int curr_N){
    if(curr_N == N + 1){
        for(const auto& element : ans){
            cout << element << ' ';
        }
        cout << '\n';

        return;
    }

    for(int idx_k = 1; idx_k <= K; idx_k++){
        ans.push_back(idx_k);
        Choose(curr_N + 1);
        ans.pop_back();
    }

    return;
}

int main(){
    cin >> K >> N;

    Choose(1);

    return 0;
}