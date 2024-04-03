#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int N;
priority_queue<pair<int, int>> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    int x;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << 0 << endl;
            else {
                pair<int, int> temp = pq.top();
                pq.pop();
                cout << -temp.second << endl;
            }
        } else{
            pq.push(make_pair(-abs(x), -x));
        }
    }

    return 0;
}