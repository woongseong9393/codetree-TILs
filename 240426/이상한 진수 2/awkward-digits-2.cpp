#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string st;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> st;

    int n = st.size();

    int res = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(!flag && st[i] == '0'){
            st[i] = '1';
            flag = true;
        } else if(!flag && i == n - 1){
            st[i] = '0';
            flag = true;
        }

        res += (st[i] - '0') * pow(2, n - 1 - i);
    }

    cout << res; 

    return 0;
}