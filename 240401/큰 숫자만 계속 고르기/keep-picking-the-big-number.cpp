#include <iostream>
#include <queue>

using namespace std;

int N, M;

priority_queue<int> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;

    int temp;
    for(int i = 0; i < N; i++){
        cin >> temp;
        pq.push(temp);
    }

    for(int i = 0; i < M; i++){
        temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
    }

    cout << pq.top();

    return 0;
}