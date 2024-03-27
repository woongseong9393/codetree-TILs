#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, int> um;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    
    int tmp;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        um[tmp]++;
    }

    for(int i = 0; i < m; i++){
        cin >> tmp;
        if(um.find(tmp) == um.end()){
            cout << 0 << ' ';
        } else{
            cout << um.find(tmp)->second << ' ';
        }
    }


    return 0;
}