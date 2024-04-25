#include <iostream>
#include <string>
using namespace std;

string st;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> st;
    
    int res = 0;

    for(int i = 0; i < st.size() - 3; i++){
        for(int j = i + 2; j < st.size() - 1; j++){
            if(st[i] == '(' && st[i+1] == '(' && st[j] == ')' && st[j+1] == ')'){
                res++;
            }
        }
    }

    cout << res; 

    return 0;
}