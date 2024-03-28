#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int A, B, x, y;

int ans;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> A >> B >> x >> y;

    ans = abs(A-B);
    ans = min(ans, abs(A-x) + abs(y - B));
    ans = min(ans, abs(A-y) + abs(x - B));

    cout << ans;

    return 0;
}