#include <iostream>
#include <string>
using namespace std;

class dobosev {
    public:
        string code;
        char place;
        int when;

        dobosev (string code, char place, int when){
            this->code = code;
            this->place = place;
            this->when = when;
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 여기에 코드를 작성해주세요.
    string code;
    char place;
    int time;

    cin >> code >> place >> time;

    dobosev order = dobosev(code, place, time);
    
    cout << "secret code : " << order.code << '\n';
    cout << "meeting point : " << order.place << '\n';
    cout << "time : " << order.when << '\n';

    return 0;
}