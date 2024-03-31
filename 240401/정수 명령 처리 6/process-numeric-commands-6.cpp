#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, val;
string st;
priority_queue<int> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> st;
        if(st == "push"){
            cin >> val;
            pq.push(val);
        } else if(st == "size"){
            cout << pq.size() << '\n';
        } else if(st == "empty"){
            cout << pq.empty() << '\n';
        } else if(st == "pop"){
            cout << pq.top() << '\n';
            pq.pop();
        } else{
            cout << pq.top() << '\n';
        }
    }
    
    return 0;
}