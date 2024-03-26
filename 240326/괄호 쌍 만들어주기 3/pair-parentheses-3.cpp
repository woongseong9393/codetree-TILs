#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;
    int cnt = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '('){
            for(int j = i + 1; str[j] != '\0'; j++){
                if(str[j] == ')'){
                    cnt++;
                    //cout << i << ' ' << j << endl;
                }
            }
        }        
    }

    cout << cnt; 
    return 0;
}