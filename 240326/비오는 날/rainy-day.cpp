#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;

vector<tuple<string, string, string>> v;

int main() {
    // 여기에 코드를 작성해주세요.
    string date, day, wther;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> date >> day >> wther;
        v.push_back(make_tuple(date, day, wther));
    }

    sort(v.begin(), v.end());

    for(const auto& element : v){
        if(get<2>(element) == "Rain"){
            cout << get<0>(element) << ' ' << get<1>(element) << ' ' << get<2>(element);
            break;
        }
    }

    return 0;
}