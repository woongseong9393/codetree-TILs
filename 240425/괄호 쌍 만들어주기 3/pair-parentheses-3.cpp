#include <iostream>
#include <string>

using namespace std;

string st;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> st;

    int res = 0;

    for(int i = 0; i < st.size(); i++){
        if(st[i] == '('){
            for(int j = i + 1; j < st.size(); j++){
                if(st[j] == ')'){
                    res++;
                }
            }
        }
    }

    cout << res;

    return 0;
}