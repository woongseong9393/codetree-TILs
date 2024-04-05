#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int t;
int m;

priority_queue<int> pq_l;
priority_queue<int> pq_h;

void sol(int val){
    if(pq_h.empty()){
        pq_h.push(-val);
        return;
    }

    if(-pq_h.top() >= val){
        pq_l.push(val);
    } else{
        pq_h.push(-val);
    }

    if((int)(pq_h.size() - pq_l.size()) > 1){
        int temp_h = pq_h.top();
        pq_h.pop();
        pq_l.push(-temp_h);
    } else if((int)(pq_l.size() - pq_h.size()) > 1){
        int temp_l = pq_l.top();
        pq_l.pop();
        pq_h.push(-temp_l);
    }
}


void print_queue(){
    cout << "----------------" << endl;
    priority_queue<int> pl = pq_l;
    priority_queue<int> ph = pq_h;
    cout << "high " << endl;
    while(!ph.empty()){
        cout << -ph.top() << endl;
        ph.pop();
    }

    cout << "low " << endl;
    while(!pl.empty()){
        cout << pl.top() << endl;
        pl.pop();
    }
}



void midpoint(){
    if(pq_l.size() < pq_h.size()){
        cout << -pq_h.top() << ' ';
    } else {
        cout << pq_l.top() << ' ';
    }
}

void empty_queue(){
    while(!pq_h.empty()){
        pq_h.pop();
    }

    while(!pq_l.empty()){
        pq_l.pop();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> t;
    int temp;
    for(int test_case = 1; test_case <= t; test_case++){
        cin >> m;
        
        for(int i = 0; i < m; i++){
            cin >> temp;
            sol(temp);
            if(i%2 == 0){
                //print_queue();
                midpoint();
            }
        }
        empty_queue();
        cout << '\n';
    }

    return 0;
}