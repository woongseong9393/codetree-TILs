#include <iostream>
#include <vector>

using namespace std;

int n;
int max_lines = 0;

vector<pair<int, int>> lines;
vector<int> choosed;

bool chk_avail(int line_idx){
    if(choosed.size()==0){
        return true;
    }
    for(const auto& element : choosed){
        if(!(lines[element].first > lines[line_idx].second || lines[element].second < lines[line_idx].first)){
            return false;
        }
    }
    return true;
}

void Choose(int line_idx){
    if(line_idx == n){
        if(max_lines < choosed.size()) max_lines = choosed.size();
        return;
    }

    if(chk_avail(line_idx)){
        choosed.push_back(line_idx);
        Choose(line_idx + 1);
        choosed.pop_back();
    } else{
        Choose(line_idx + 1);
    }

    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x1, x2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> x2;
        lines.push_back(make_pair(x1, x2));
    }

    Choose(0);
    cout << max_lines;

    return 0;
}