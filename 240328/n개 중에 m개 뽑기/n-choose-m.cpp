#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
void Combi(int curr_n, int cnt){
    if(curr_n == N+1){
        if(cnt==M){
            for(auto element : v) {
                cout << element << ' ';
            }
            cout << '\n';
        }
        return;
    }

    // case 1
    v.push_back(curr_n);
    Combi(curr_n + 1, cnt + 1);
    v.pop_back();

    // case 2
    Combi(curr_n + 1, cnt);

    return;    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    Combi(1, 0);
    return 0;
}