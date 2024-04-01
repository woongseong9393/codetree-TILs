#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int a, b;

priority_queue<int> pq;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    while(!pq.empty() && pq.size() != 1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        if(a - b == 0) continue;
        else{
            pq.push(a-b);
        }
    }

    if(pq.empty()) cout << -1;
    else cout << pq.top();
    return 0;
}