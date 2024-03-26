#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int k, n;
string T;
string temp;
bool chk;

vector<string> v;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    cin >> T;

    for(int i = 0; i < n; i++){
        cin >> temp;
        chk = 1;
        for(int word = 0; word < T.size(); word++){
            if(T[word] != temp[word]) chk = 0;
        }
        if(chk) v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cout << v[k-1];


    return 0;
}