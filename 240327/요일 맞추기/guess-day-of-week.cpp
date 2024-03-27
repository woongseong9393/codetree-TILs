#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m1, d1, m2, d2;

int elapsed;

string bunch = " Sun, Mon, Tue, Wed, Thu, Fri, Sat ";
vector<string> v;

int cal_day(int m, int d){
    int res = 0;
    for(int i = 1; i < m; i++){
        res += num_of_days[i];
    }
    res += d;

    return res;
}

int main() {
    bunch.erase(remove(bunch.begin(), bunch.end(), ' '), bunch.end());

    istringstream ss1(bunch);
    string buf;
    

    cin >> m1 >> d1 >> m2 >> d2;

    while(getline(ss1, buf, ',')){
        v.push_back(buf);
    }

    elapsed = cal_day(m2, d2) - cal_day(m1, d1);

    if(elapsed < 0){
        cout << v[(1 + 7 - (abs(elapsed) % 7))%7];
    } else{
        cout << v[(1 + elapsed%7)%7];
    }

    return 0;
}