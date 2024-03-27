#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdlib>

using namespace std;

int N;

vector<tuple<int, int>> v;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        v.push_back(make_tuple(abs(x) + abs(y) , i + 1));
    }

    sort(v.begin(), v.end());

    for(const auto& element : v){
        cout << get<1>(element) << '\n';
    }

    return 0;
}