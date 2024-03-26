#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

vector <tuple <char, int>> v;

bool cmp(tuple <char, int> &t1, tuple <char, int> &t2){
    return get<1>(t1) < get<1>(t2);
}

int main() {
    // 여기에 코드를 작성해주세요.
    char ID;
    int score;
    
    for(int i = 0; i < 5; i++){
        cin >> ID >> score;
        v.push_back(make_tuple(ID, score));
    }

    sort(v.begin(), v.end(), cmp);

    cout << get<0>(v[0]) << ' ' << get<1>(v[0]);

    return 0;
}