#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
int mp[11][11] = {0,};
int mp_player[11][11] = {0,};
vector<int> v_player[11][11];

pair<int, int> player_loc[11];
pair<int, int> exit_loc;

int player_dist[11] ={0,};
bool player_state[11] ={0,};

/*U D R L*/
int dx[5] = {0, 0, 1, -1, 0};
int dy[5] = {-1, 1, 0, 0, 0};



bool chk_state(){
    bool res = false;
    for(int i = 1; i <= M; i++){
        if(player_state[i] == 0){
            res = true;
        }
    }

    return res;
}

void init_player_mp(){
    memset(mp_player, 0, sizeof(mp_player));
    memset(v_player, 0, sizeof(v_player));
    for(int i = 1; i <= M; i++){
        if(player_state[i] == 0){
            mp_player[player_loc[i].first][player_loc[i].second] = -i;
            v_player[player_loc[i].first][player_loc[i].second].push_back(i);
        }
    }

    mp_player[exit_loc.first][exit_loc.second] = 10;
}

void printMAP(){
    char cnt = 'A' - 1;
    init_player_mp();

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(mp_player[i][j] != 0){
                if(mp_player[i][j] == 10){
                    cout << 'X' << ' ';
                } else{
                    cout << (char)(cnt - mp_player[i][j]) << ' ';
                }
            } else{
                cout << mp[i][j] << ' ';
            }
        }
        cout << endl;
    }
    cout << '\n';

    cout << "SCORE : " << endl;
    for(int i = 1; i <= M; i++){
        cout << player_dist[i] << ' ';
    }
    cout << endl;
    cout << endl;
}


bool inRange(int r, int c){
    return 1 <= r && r <= N && 1 <= c && c <= N;
}

int calc_dist(pair<int, int> a, pair<int, int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int calc_dist_sq(pair<int, int> a, pair<int, int> b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

pair<int, int> find_min_square(){
    vector<pair<int, pair<int, int>>> v;

    for(int i = 1; i <= M; i++){
        if(player_state[i] == 1){
            continue;
        }
        v.push_back(make_pair(calc_dist_sq(player_loc[i], exit_loc), player_loc[i]));
    }

    sort(v.begin(), v.end());

    if(v.size() == 0){
        cout << "Empty Vector!!!\n";
        return {-1, -1};
    }

    return v[0].second;
}

void move_player(){
    for(int i = 1; i <= M; i++){
        if(player_state[i] == 1){
            continue;
        }

        int curr_r = player_loc[i].first;
        int curr_c = player_loc[i].second;

        vector<pair<int, int>> v;
        for(int dirc = 0; dirc < 5; dirc++){
            int new_r = curr_r + dy[dirc];
            int new_c = curr_c + dx[dirc];
            
            if(inRange(new_r, new_c) && mp[new_r][new_c] == 0){
                v.push_back(make_pair(calc_dist(make_pair(new_r, new_c), exit_loc), dirc));
            }
        }
        
        if(v.size() == 0){
            continue;
        }

        sort(v.begin(), v.end());
        int dirc = v[0].second;
    
        int new_r = curr_r + dy[dirc];
        int new_c = curr_c + dx[dirc];

        //cout << "player :" << i << ' ' << dirc << endl;
        //cout << "play loc :" << new_r << ' ' << new_c << endl;

        player_loc[i] = make_pair(new_r, new_c);

        if(dirc == 4){
            continue;
        }
        player_dist[i]++;
    
        if(player_loc[i] == exit_loc){
            player_state[i] = 1;
        }

        //printMAP();
    }
}

void turn_square(){
    if(!chk_state()){
        return;
    }

    init_player_mp();

    pair<int, int> person = find_min_square();
    pair<int, int> start_pt;

    int sq_size = max(abs(person.first - exit_loc.first), abs(person.second - exit_loc.second)) + 1;

    //cout << "PERSON : " << person.first << ' ' << person.second << endl;
    //cout << "EXIT : " << exit_loc.first << ' ' << exit_loc.second << endl;
    //cout << "SQSIZE : " << sq_size << endl;

    bool chk = false;
    for(int i = 1; i <= N - sq_size + 1; i++){
        for(int j = 1; j <= N - sq_size + 1; j++){
            if(i <= person.first && person.first < i + sq_size 
            && i <= exit_loc.first && exit_loc.first < i + sq_size){
                if(j <= person.second && person.second < j + sq_size 
                && j <= exit_loc.second && exit_loc.second < j + sq_size){
                    start_pt.first = i;
                    start_pt.second = j;
                    chk = true;
                    break;
                }
            }
        }
        if(chk){
            break;
        }
    }

    //cout << "selected start : " << start_pt.first << ' ' << start_pt.second << endl;

    int temp_mp[11][11]={0,};
    vector<int> temp_vp[11][11];
    
    for(int i = 0; i < sq_size; i++){
        for(int j = 0; j < sq_size; j++){
            if(mp[start_pt.first + i][start_pt.second + j]){
                temp_mp[i][j] = mp[start_pt.first + i][start_pt.second + j];
                mp[start_pt.first + i][start_pt.second + j] = 0;
            } else if(mp_player[start_pt.first + i][start_pt.second + j] < 0) {
                temp_vp[i][j] = v_player[start_pt.first + i][start_pt.second + j];
                temp_mp[i][j] = mp_player[start_pt.first + i][start_pt.second + j];
            } else{
                temp_mp[i][j] = mp_player[start_pt.first + i][start_pt.second + j];
            }
            //cout << temp_mp[i][j] << ' ';
        }
        //cout << endl;
    }

    int org_i = 0, org_j = 0;
    for(int j = 0; j < sq_size; j++){
        for(int i = sq_size - 1; i >= 0; i--){
            if(1 <= temp_mp[i][j] && temp_mp[i][j] <= 9){
                mp[start_pt.first + org_i][start_pt.second + org_j] = temp_mp[i][j] - 1;
            } else if(temp_mp[i][j] == 10){
                mp[start_pt.first + org_i][start_pt.second + org_j] = 0;
                exit_loc.first = start_pt.first + org_i;
                exit_loc.second = start_pt.second + org_j;
            } else if(temp_mp[i][j] < 0){
                mp[start_pt.first + org_i][start_pt.second + org_j] = 0;

                for(int ppp = 0; ppp < temp_vp[i][j].size(); ppp++){
                    player_loc[temp_vp[i][j][ppp]].first = start_pt.first + org_i;
                    player_loc[temp_vp[i][j][ppp]].second = start_pt.second + org_j;
                }
            } else{
                mp[start_pt.first + org_i][start_pt.second + org_j] = temp_mp[i][j];
            }

            //cout << mp[start_pt.first + org_i][start_pt.second + org_j] << ' ';
            org_j = (org_j + 1) % sq_size;
        }
        //cout << endl;
        org_i++;
    }
}

void print_res(){
    int sum = 0;
    for(int i = 1; i <= M; i++){
        sum += player_dist[i];
    }

    cout << sum << '\n';
    cout << exit_loc.first << ' ' << exit_loc.second;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> mp[i][j];
        }
    }
    // player
    for(int i = 1; i <= M; i++){
        cin >> player_loc[i].first >> player_loc[i].second;
    }

    // exit coordinate
    cin >> exit_loc.first >> exit_loc.second;
    //printMAP();

    for(int i = 0; i < K; i++){
        move_player();
        turn_square();

        //printMAP();
        if(!chk_state()){
            break;
        }
    }

    print_res();

    return 0;
}