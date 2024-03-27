#include <iostream>
#include <unordered_map>

#define MAX_NUM 100000

using namespace std;

int n, k;
int cnt = 0;
int arr[MAX_NUM];

unordered_map<int, int> um;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;

    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        if(um.find(arr[i])!= um.end()){
            um[arr[i]] = 1;
        } else{
            um[arr[i]]++;
        }
    }

    for(int i = 0; i < n; i++){
        int look = k - arr[i];
        if(um[arr[i]] > 0){
            um[arr[i]]--;
            if(um.find(look) != um.end()){
                cnt += um[look];
            }
        }
    }

    cout << cnt;

    return 0;
}