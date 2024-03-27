#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int>> v;
int N;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        v.push_back(make_tuple(num, i));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == get<1>(v[j])) cout << j + 1 << ' ';
        }
    }
    
    return 0;
}