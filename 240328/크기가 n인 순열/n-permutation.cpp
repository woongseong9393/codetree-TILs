#include <iostream>
#include <vector>

using namespace std;

int N;
bool visited[8] = {0,};

vector<int> v;

void Print(){
    for(const auto& element : v){
        cout << element << ' ';
    }
    cout << '\n';

    return;
}

void make_permute(int curr_n){
    if(curr_n == N){
        Print();
        return;
    }

    for(int i = 0; i < N; i++){
        if(visited[i]){
            continue;
        }

        v.push_back(i + 1);
        visited[i] = 1;
        make_permute(curr_n + 1);

        v.pop_back();
        visited[i] = 0;
    }

    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    make_permute(0);

    return 0;
}