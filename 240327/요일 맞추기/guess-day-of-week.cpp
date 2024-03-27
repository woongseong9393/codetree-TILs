#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vector<string> v;
string buffer;

string weth = "Sun,Mon,Tue,Wed,Thu,Fri,Sat";

int m1, m2, d1, d2;
int m, d, enum_wed = 1;
bool dirc = true;

int main() {
    // 여기에 코드를 작성해주세요.
    istringstream ss1(weth);

    while(getline(ss1, buffer, ',')){
        v.push_back(buffer);
    }
    cin >> m1 >> d1 >> m2 >> d2;

    if(m1 > m2){
        dirc = false;
    } else if(m1 == m2){
        if(d1 > d2){
            dirc = false;
        }
    }

    m = m1;
    d = d1;

    while(1){
        if(m == m2 && d == d2){
            cout << v[enum_wed];
            break;
        }

        if(dirc){
            d++;
            enum_wed = (enum_wed+1) % 7;
            if(d > num_of_days[m]){
                d = 1;
                m++;
            }
        } else{
            d--;
            enum_wed = (enum_wed+6) % 7;
            if(d == 0){
                m--;
                d = num_of_days[m];
            }
        }
        
    }



    return 0;
}