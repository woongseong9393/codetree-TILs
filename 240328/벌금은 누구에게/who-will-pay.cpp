#include <iostream>
#define MAX_NUM 100
using namespace std;

int N, M, K;

int arr[MAX_NUM + 1] = {0,};
int stu_num;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> K;
    int ans = -1;
    for(int i = 0; i < M; i++){
        cin >> stu_num;
        if(++arr[stu_num]>= K && ans == -1){
            ans = stu_num;
        }
    }

    cout << ans;
    return 0;
}