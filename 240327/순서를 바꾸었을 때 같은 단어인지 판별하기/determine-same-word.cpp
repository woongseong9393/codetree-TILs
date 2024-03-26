#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str1, str2;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str1 >> str2;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if(str1.compare(str2) == 0){
        cout << "Yes";
    } else{
        cout << "No";
    }

    return 0;
}