#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;

int N, M;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        pq.push(make_tuple(x + y, x, y));
    }

    int dist;

    for(int i = 0; i < M; i++){
        tie(dist, x, y) = pq.top();
        pq.pop();
        pq.push(make_tuple(dist + 4, x + 2, y + 2));
    }

    tie(dist, x, y) = pq.top();
    cout << x << ' ' << y;

    return 0;
}