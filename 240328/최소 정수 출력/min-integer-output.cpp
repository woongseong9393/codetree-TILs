#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int n;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << -pq.top() << '\n';
                pq.pop();
            }

        } else{
            pq.push(-x);
        }
    }
    return 0;
}