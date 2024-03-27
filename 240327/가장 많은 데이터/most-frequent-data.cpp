#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um;

int n;
string str1;
int ans = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str1;
        if(um.find(str1) == um.end()){
            um[str1] = 1;
            ans = max(ans, um[str1]);
        } else{
            um[str1]++;
            ans = max(ans, um[str1]);
        }
    }

    cout << ans;

    return 0;
}