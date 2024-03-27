#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int num_of_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int m1, m2, d1, d2;
string wed;
int m, d;

string bunch = "Mon, Tue, Wed, Thu, Fri, Sat, Sun";

vector<string> v;

int main() {
    // 여기에 코드를 작성해주세요.
    bunch.erase(remove(bunch.begin(), bunch.end(), ' '), bunch.end());

    istringstream ss1(bunch);
    string buf;
    while(getline(ss1, buf, ',')){
        v.push_back(buf);
    }

    cin >> m1 >> d1 >> m2 >> d2;
    cin >> wed;

    m = m1;
    d = d1;
    int dd = 0;
    int cnt = 0;

    if(v[dd] == wed) cnt++;

    while(true){
        if(m == m2 && d == d2){
            cout << cnt;
            break;
        }

        dd = (dd + 1) % 7;
        d++;
        if(v[dd] == wed) cnt++;
        
        if(d > num_of_days[m]){
            m++;
            d = 1;
        }
    }


    return 0;
}