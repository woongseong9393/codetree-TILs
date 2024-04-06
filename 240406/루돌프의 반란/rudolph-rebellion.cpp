#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int N, M, P, C, D;
pair<int, int> rudolf_loc;

/*U R D L UR DR DL UL */
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int curr_loc[51][51] = {0,};

pair<int, int> santa_loc[31];
pair<int, int> santa_state[31];

bool inRange(int r, int c){
    return 1 <= r && r <= N && 1 <= c && c <= N; 
}

int calc_dist(pair<int, int> p1, pair<int, int> p2){
    int a = p1.first - p2.first;
    int b = p1.second - p2.second;

    return a*a + b*b;
}


// rudolf -> santa
int find_dirc_r(pair<int, int> a, pair<int, int> b){
    int dist_min = INT_MAX;
    int res;
    for(int i = 0; i < 8; i++){
        int newr = a.first + dy[i];
        int newc = a.second + dx[i];
        
        if(inRange(newr, newc)){
            if(dist_min > calc_dist(make_pair(newr, newc), b)){
                dist_min = calc_dist(make_pair(newr, newc), b);
                res = i;
            }
        }
    }

    return res;
}

int find_dirc_s(pair<int, int> a){
    int dist_min = calc_dist(a, rudolf_loc);
    int res = -1;

    //cout << "curr cord " << a.first <<' ' << a.second << endl;
    for(int i = 0; i < 4; i++){
        int newr = a.first + dy[i];
        int newc = a.second + dx[i];

        //cout << "new cord " << newr <<' ' << newc << endl;
        
        if(inRange(newr, newc) && curr_loc[newr][newc] == 0){
            //cout << "dist : " << i << ' ' << calc_dist(make_pair(newr, newc), rudolf_loc) << endl;
            if(dist_min > calc_dist(make_pair(newr, newc), rudolf_loc)){
                dist_min = calc_dist(make_pair(newr, newc), rudolf_loc);
                res = i;
            }
        }
    }

    return res;
}

void print_santa_score(){
    //cout << endl;
    for(int i = 1; i <= P; i++){
        cout << santa_state[i].first << ' ';
    }
    //cout << endl;
}

void printMAP(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == rudolf_loc.first && j == rudolf_loc.second){
                cout << 'X' <<' ';
            } else{
                cout << curr_loc[i][j] << ' ' ;
            }
        }
        cout << '\n';
    }
    print_santa_score();
    cout << '\n';
}

void move_rudolf(){
    priority_queue<tuple<int, int, int, int>> pq;
    int curr_r = rudolf_loc.first;
    int curr_c = rudolf_loc.second;

    int temp_r, temp_c, temp_dist, temp_index;
    for(int i = 1; i <= P; i++){
        if(santa_state[i].second == -1){
            continue;
        }
        temp_r = santa_loc[i].first;
        temp_c = santa_loc[i].second;
        temp_dist = calc_dist(santa_loc[i], rudolf_loc);
        temp_index = i;

        //cout << "santa " << i << ' '<< temp_r <<' ' << temp_c <<' '<< temp_dist << endl;
        pq.push(make_tuple(-temp_dist, temp_r, temp_c, temp_index));
    }

    if(pq.empty()){
        return;
    }
    tie(temp_dist, temp_r, temp_c, temp_index) = pq.top();

    //cout << -temp_dist << temp_index << endl;

    int dirc = find_dirc_r(rudolf_loc, make_pair(temp_r, temp_c));

    //cout << "rudolf dirc : "<< dirc << endl;

    curr_r += dy[dirc];
    curr_c += dx[dirc];
    rudolf_loc = make_pair(curr_r, curr_c);

    if(temp_r == curr_r && temp_c == curr_c){
        santa_state[temp_index].first += C;
        santa_state[temp_index].second = 2;

        curr_loc[temp_r][temp_c] = 0;

        temp_r += dy[dirc] * C;
        temp_c += dx[dirc] * C;

        if(!inRange(temp_r, temp_c)){
            santa_state[temp_index].second = -1;
            return;
        }

        while(curr_loc[temp_r][temp_c]){
            int new_santa_r = temp_r, new_santa_c = temp_c;
            int new_santa_index = curr_loc[temp_r][temp_c];

            curr_loc[temp_r][temp_c] = temp_index;
            santa_loc[temp_index].first = temp_r;
            santa_loc[temp_index].second = temp_c;

            new_santa_r += dy[dirc];
            new_santa_c += dx[dirc];

            temp_r = new_santa_r;
            temp_c = new_santa_c;
            temp_index = new_santa_index;

            if(!inRange(temp_r, temp_c)){
                santa_state[temp_index].second = -1;
                break;
            }
        }

        if(curr_loc[temp_r][temp_c] == 0){
            curr_loc[temp_r][temp_c] = temp_index;
            santa_loc[temp_index].first = temp_r;
            santa_loc[temp_index].second = temp_c;
        }
    }
    //cout << "rudolf : " << dirc << endl; 
    //printMAP();
}

void santa_addup(){
    for(int i = 1; i <= P; i++){
        if(santa_state[i].second != -1){
            santa_state[i].first++;
        }
    }
}

void move_santa(){
    int dirc;
    for(int i = 1; i <= P; i++){
        //cout << "santa state : " << i << ' ' << santa_state[i].second << endl;
        if(santa_state[i].second == -1){
            continue;
        }
        if(santa_state[i].second > 0){
            santa_state[i].second--;
            continue;
        }
        dirc = find_dirc_s(santa_loc[i]);

        if(dirc == -1){
            continue;
        }

        int curr_r = santa_loc[i].first;
        int curr_c = santa_loc[i].second;

        curr_loc[curr_r][curr_c] = 0;

        //cout << "santa loc : " << i << ' ' << curr_r << ' '<< curr_c << ' ' << dirc << endl;

        curr_r += dy[dirc];
        curr_c += dx[dirc];

        int collap_dirc = (dirc + 2) % 4;

        if(curr_r == rudolf_loc.first && curr_c == rudolf_loc.second){
            santa_state[i].first += D;
            santa_state[i].second = 1;

            curr_r += dy[collap_dirc] * D;
            curr_c += dx[collap_dirc] * D;

            if(!inRange(curr_r, curr_c)){
                santa_state[i].second = -1;
                continue;
            }

            int curr_index = i;
            while(curr_loc[curr_r][curr_c]){
                //cout << "collapse :" << curr_index << ' ' << curr_loc[curr_r][curr_c] << endl;
                int temp_index = curr_loc[curr_r][curr_c];

                curr_loc[curr_r][curr_c] = curr_index;
                santa_loc[curr_index].first = curr_r;
                santa_loc[curr_index].second = curr_c;

                curr_r += dy[collap_dirc];
                curr_c += dx[collap_dirc];
                curr_index = temp_index;

                //cout << "new :" << curr_index << ' ' << curr_r << ' ' << curr_c << endl;
                //cout << "new coll : " << curr_loc[curr_r][curr_c] << endl;

                if(!inRange(curr_r, curr_c)){
                    santa_state[curr_index].second = -1;
                    break;
                }
            }

            if(curr_loc[curr_r][curr_c] == 0){
                santa_loc[curr_index].first = curr_r;
                santa_loc[curr_index].second = curr_c;
                curr_loc[curr_r][curr_c] = curr_index;
            }
        } else{
            curr_loc[curr_r][curr_c] = i;
            santa_loc[i].first = curr_r;
            santa_loc[i].second = curr_c;
        }

        //cout << "santa : " << i << ' ' << dirc << endl; 
        //printMAP();
    }
}

bool chk_santa_state(){
    bool res = false;
    for(int i = 1; i <= P; i++){
        if(santa_state[i].second != -1){
            res = true;
            break;
        }
    }
    return res;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int santa_num, s_r, s_c;

    cin >> N >> M >> P >> C >> D;
    cin >> rudolf_loc.first >> rudolf_loc.second;
    for(int i = 1; i <= P; i++){
        cin >> santa_num >> s_r >> s_c;
        santa_loc[santa_num] = make_pair(s_r, s_c);
        curr_loc[s_r][s_c] = santa_num;
        santa_state[santa_num] = make_pair(0, 0);
    }

    for(int num_of_games = 1; num_of_games <= M; num_of_games++){
        move_rudolf();
        move_santa();
        
        if(!chk_santa_state()){
            break;
        }
        santa_addup();
    }


    print_santa_score();
    
    return 0;
}