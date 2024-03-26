#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<string, char, int> t;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    char ID;
    int sec;

    cin >> str >> ID >> sec;
    t = make_tuple(str, ID, sec);

    tie(str, ID, sec) = t;
    cout << "code : " << str << "\ncolor : " << ID << "\nsecond : " << sec;
    
    return 0;
}