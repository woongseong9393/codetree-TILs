#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>

using namespace std;

int N;
long double sum = 0;
long double avg = INT_MIN;

priority_queue<int> pq;
int arr[100000];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sum += arr[N-1] + arr[N-2];
    pq.push(-arr[N-1]);
    pq.push(-arr[N-2]);

    avg = sum + pq.top();

    for(int i = N - 3; i >= 0; i--){
        sum += arr[i];
        pq.push(-arr[i]);

        long double temp_avg = (sum + pq.top()) / (N - i - 1);

        avg = avg > temp_avg ? avg : temp_avg;
    }

    printf("%.2Lf", avg);

    return 0;
}