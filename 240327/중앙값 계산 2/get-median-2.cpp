#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int temp;
vector<int> v;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
        sort(v.begin(), v.end());
        if(i%2 == 0){
            cout << v[i/2] << ' ';
        }
    }

    return 0;
}