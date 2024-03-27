#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N;

vector<tuple<int, int, int>> v;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2){
    int h1, h2, w1, w2, n1, n2;
    tie(h1, w1, n1) = t1;
    tie(h2, w2, n2) = t2;

    if(h1 > h2){
        return true;
    } else if(h1 == h2){
        if(w1 > w2){
            return true;
        } else if(w1 == w2){
            return n1 < n2;
        } else return false;
    } else return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int h, w;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> h >> w;
        v.push_back(make_tuple(h, w, i+1));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++){
        int num;
        tie(h, w, num) = v[i];

        cout << h << ' ' << w << ' ' << num << '\n';
    }

    return 0;
}