#include <iostream>
#include <string>

using namespace std;

class Stock{
    public:
        string name;
        int code;
        
        Stock(string name = "codetree", int code = 88){
            this->name = name;
            this->code = code;
        }
};

int main() {
    // 여기에 코드를 작성해주세요.
    string name;
    int code;
    Stock s;

    cout << "product " << s.code << " is " << s.name << '\n';

    cin >> name >> code;
    s = Stock(name, code);
    cout << "product " << s.code << " is " << s.name << '\n';


    return 0;
}