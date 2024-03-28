#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return abs(a.first) + abs(a.second) > abs(b.first) + abs(b.second);
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pq.push(make_pair(x, y));
    }

    while(m--){
        x = pq.top().first;
        y = pq.top().second;
        x += 2;
        y += 2;
        pq.pop();
        pq.push(make_pair(x, y));
    }

    x = pq.top().first;
    y = pq.top().second;
    cout << x  << ' ' << y;

    return 0;
}