#include <iostream>
#include <vector>

using namespace std;

int N, B;

vector<int> v;

void make_B(int n){
    if(n/B == 0){
        v.push_back(n);
        return;
    }

    make_B(n/B);
    v.push_back(n%B);

    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> B;

    make_B(N);

    for(const auto& element : v){
        cout << element;
    }
    return 0;
}