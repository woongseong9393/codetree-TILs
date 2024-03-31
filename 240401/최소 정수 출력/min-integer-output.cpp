#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(pq.size() == 0) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else{
            pq.push(x);
        }
    }
    return 0;
}