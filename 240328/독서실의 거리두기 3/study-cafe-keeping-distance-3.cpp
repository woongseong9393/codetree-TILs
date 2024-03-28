#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;

string str1;
vector<int> v;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    cin >> str1;

    int cnt = 0;
    for(int i = 1; i < N; i++){
        if(str1[i] == '0'){
            cnt++;
        }
        else {
            //cout << cnt << endl;
            v.push_back(cnt);
            cnt = 0;
        }
    }

    sort(v.begin(), v.end());
    v.back() = v.back() % 2 == 1 ? v.back() / 2 : v.back() / 2 - 1;
    sort(v.begin(), v.end());
    
    cout << v[0] + 1;
    return 0;
}