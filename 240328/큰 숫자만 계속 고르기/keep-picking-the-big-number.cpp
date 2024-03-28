#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int n, m;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        pq.push(val);
    }

    while(m--){
        int tmp = pq.top();
        pq.pop();
        pq.push(--tmp);
    }

    cout << pq.top();
    
    return 0;
}