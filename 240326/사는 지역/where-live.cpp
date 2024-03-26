#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;

bool CmpName(tuple<string, string, string> &t1, tuple<string, string, string> &t2){
    return get<0>(t1) < get<0>(t2);
}

vector<tuple<string, string, string>> v;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    string name, addr, city;

    for(int i = 0; i < n; i++){
        cin >> name >> addr >> city;
        v.push_back(make_tuple(name, addr, city));
    }

    sort(v.begin(), v.end(), CmpName);

    cout << "name " << get<0>(v.back()) <<'\n';
    cout << "addr " << get<1>(v.back()) <<'\n';
    cout << "city " << get<2>(v.back()) <<'\n';

    return 0;
}