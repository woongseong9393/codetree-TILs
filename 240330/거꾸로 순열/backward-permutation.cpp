#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> v;
bool visited[9] = {0,};
void Permute(int curr_n){
    if(curr_n == N){
        for(const auto& element : v){
            cout << element << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = N; i >= 1; i--){
        if(visited[i] == 0){
            visited[i] = true;
            v.push_back(i);
            Permute(curr_n + 1);

            v.pop_back();
            visited[i] = false;
        }
    }

    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    Permute(0);

    return 0;
}