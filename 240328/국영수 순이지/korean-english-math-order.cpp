#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

int n;

tuple<int, int, int, string> t[10];

int main() {
    // 여기에 코드를 작성해주세요.
    string name;
    int kor, eng, math;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name >> kor >> eng >> math;
        t[i] = make_tuple(kor, eng, math, name);
    }

    sort(t, t + n);

    for(int i = n - 1; i >= 0; i--){
        tie(kor, eng, math, name) = t[i];
        cout << name << ' ' << kor << ' ' << eng << ' ' << math << '\n';
    }

    return 0;
}