#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
void Combi(int curr_M, int ch_idx){
    if(curr_M == M){
        for(const auto& elem : v){
            cout << elem << ' ';
        }
        cout << '\n';
        return;
    }

    for(int k = ch_idx; k <= N; k++){
        v.push_back(k);
        Combi(curr_M + 1, k + 1);
        v.pop_back();
    }

    return;    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    Combi(0, 1);
    return 0;
}