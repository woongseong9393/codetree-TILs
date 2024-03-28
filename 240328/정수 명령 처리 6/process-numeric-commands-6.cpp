#include <iostream>
#include <queue>
#include <string>

using namespace std;

priority_queue<int> pq;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    string order;
    int val;
    for(int i = 0; i < n; i++){
        cin >> order;
        if(order == "push"){
            cin >> val;
            pq.push(val);
        } else if(order == "size"){
            cout << pq.size() << '\n';
        } else if(order == "empty"){
            cout << pq.empty() << '\n';
        } else if(order == "top"){
            cout << pq.top() << '\n';
        }else{
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
    return 0;
}