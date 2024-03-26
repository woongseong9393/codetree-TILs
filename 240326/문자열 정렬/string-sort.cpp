#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    sort(str.begin(), str.end());

    cout << str;

    return 0;
}