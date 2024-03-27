#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
string N;

void make_binary(int n){
    if(n/2 == 0){
        v.push_back(n);
        return;
    }

    make_binary(n/2);
    v.push_back(n%2);

    return;
}

int make_decimal(string n){
    int ans = 0;
    for(int i = 0; i < n.size(); i++){
        ans = ans * 2 + (n[i] - '0');
    }

    return ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    int deci = make_decimal(N);
    deci *= 17;

    make_binary(deci);

    for(const auto& ele : v){
        cout << ele;
    }

    return 0;
}