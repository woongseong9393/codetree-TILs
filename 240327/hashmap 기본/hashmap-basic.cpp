#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n, k, v;
string order;

unordered_map<int, int> m;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> order >> k;
        if(order == "add"){
            cin >> v;
            if(m.find(k) == m.end()){
                m.insert({k, v});
            } else{
                m[k] = v;
            }
            
        } else if(order == "find"){
            if(m.find(k) == m.end()){
                cout << "None" << '\n';
            } else{
                cout << m.find(k)->second << '\n';
            }
        } else{
            m.erase(k);
        }
    }
    return 0;
}