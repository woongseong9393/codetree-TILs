#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N;
string order;
int key, val;

unordered_map<int, int> um;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> order >> key;
        if(order == "add"){
            cin >> val;
            if(um.find(key) != um.end()){
                um[key] = val;
            } else{
                um.insert({key, val});
            }
        } else if(order == "find"){
            if(um.find(key) != um.end()){
                cout << um.find(key)->second << endl;
            } else cout << "None" << endl;
        } else{
            if(um.find(key) != um.end()){
                um.erase(key);
            }
        }
    }

    return 0;
}