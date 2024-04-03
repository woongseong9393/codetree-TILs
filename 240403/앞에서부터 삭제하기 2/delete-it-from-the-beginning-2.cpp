#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>

using namespace std;

int N;
long long sum = 0;
double avg = INT_MIN;

priority_queue<int> pq;
int arr[100000];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        pq.push(-arr[i]);
        sum += arr[i];
    }

    for(int i = 0; i < N - 2; i++){
        double temp_sum;
        sum -= arr[i];
        if(-arr[i] == pq.top()){
            pq.pop();
        }
        temp_sum = sum + pq.top();
        avg = avg > temp_sum / (N - i - 2) ? avg : temp_sum / (N - i - 2);
    }

    printf("%.2lf", avg);

    return 0;
}