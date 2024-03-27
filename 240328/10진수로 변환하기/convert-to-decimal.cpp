#include <iostream>
#include <string>

using namespace std;

int bin[8];
int n;
string str;

int ans = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;
    n = str.size();

    for(int i = 0; i < n; i++){
        bin[i] = str[i] - '0';
    }

    for(int i = 0; i < n; i++){
        ans = ans * 2 + bin[i];
    }
    

    cout << ans;

    return 0;
}