#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int>> v;
int N;

int ans[1000];

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
        ans[get<1>(v[i])] = i + 1;
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << ' ';
    }


    return 0;
}