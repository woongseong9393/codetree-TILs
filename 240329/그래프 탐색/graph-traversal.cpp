#include <iostream>
#include <vector>
using namespace std;

bool visited[1001] = {0,};

int N, M;

vector<int> graph[1001];

vector<int> res;

void DFS(int vertex){
    for(int i = 0; i < graph[vertex].size(); i++){
        int curr_v = graph[vertex][i];

        if(!visited[curr_v]){
            res.push_back(curr_v);
            visited[curr_v] = true;
            DFS(curr_v);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int u, v;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited[1] = true;
    DFS(1);

    cout << res.size();

    return 0;
}