#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class Person{
    public:
        string ID;
        int level;

        Person(string ID = "codetree", int level = 10){
            this->ID = ID;
            this->level = level;
        }

};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    string ID;
    int lv;

    cin >> ID >> lv;
    Person p;

    cout << "user " << p.ID << " lv " << p.level  << '\n';
    
    p = Person(ID, lv);
    cout << "user " << p.ID << " lv " << p.level << '\n';
    return 0;
}