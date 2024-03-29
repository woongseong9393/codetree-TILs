#include <iostream>
#include <vector>
using namespace std;

int N;

vector<int> v;

void make_binary(int n){
    if(n/2 == 0){
        v.push_back(n);
        return;
    }

    make_binary(n/2);
    v.push_back(n%2);
    
    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    
    make_binary(N);

    for(const auto& element : v){
        cout << element;
    }

    return 0;
}