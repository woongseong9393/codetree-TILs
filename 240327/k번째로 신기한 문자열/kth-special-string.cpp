#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int k, n;
string T;
string temp;

vector<string> v;

bool Startswith(string a, string b){        // a is prefix
    if(a.size() > b.size()) return false;

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }

    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    cin >> T;

    for(int i = 0; i < n; i++){
        cin >> temp;
        if(Startswith(T, temp)) v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cout << v[k-1];


    return 0;
}