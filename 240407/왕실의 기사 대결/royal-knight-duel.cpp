#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int L, N, Q;

int mp[41][41] = {0,};
int mp_kni[41][41] = {0,};
bool death[31] = {0,};

pair<int, int> knight_loc[31];
pair<int, int> knight_size[31];
int knight_hel[31];
int knight_damage[31] = {0, };

/*U R D L*/
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {-1, 0, 1, 0, 0};

void printMAP(){
    for(int i = 1; i <= L; i++){
        for(int j = 1; j <= L; j++){
            cout << mp_kni[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


bool possible(int num, int dirc){
    int kni_r = knight_loc[num].first; 
    int kni_c = knight_loc[num].second;
    int kni_h = knight_size[num].first;
    int kni_w = knight_size[num].second;

    //cout << "possible check : " << num << endl;
    //cout << " r c h w " << kni_r << ' ' << kni_c << ' ' << kni_h << ' ' << kni_w << endl;
    //cout << "dy dx " << dy[dirc] << ' ' << dx[dirc] << endl;
    //cout << kni_r + kni_h - 1  + dy[dirc] << endl;
    //cout << kni_c + kni_w - 1 + dx[dirc] << endl;
    if(1 > kni_r + dy[dirc] || kni_r + kni_h - 1  + dy[dirc] > L ||
     1 > kni_c + dx[dirc]|| kni_c + kni_w - 1 + dx[dirc] > L){
        //cout << "not possible : inrange " << endl;
        return false;
    }
    for(int i = 0; i < kni_h; i++){
        for(int j = 0; j < kni_w; j++){
            if(mp[kni_r + i + dy[dirc]][kni_c + j + dx[dirc]] == 2){
                return false;
            }
        }
    }

    return true;
}

void write_knight_loc(int kni_num, int dirc, bool pushed = 0){
    if(knight_hel[kni_num] <= 0){
        return;
    }

    int damage = 0;
    int init_r = knight_loc[kni_num].first;
    int init_c = knight_loc[kni_num].second;

    for(int i = 0; i < knight_size[kni_num].first; i++){
        for(int j = 0; j < knight_size[kni_num].second; j++){
            if(mp_kni[init_r + i][init_c + j] == kni_num){
                mp_kni[init_r + i][init_c + j] = 0;
            }
        }
    }


    for(int i = 0; i < knight_size[kni_num].first; i++){
        for(int j = 0; j < knight_size[kni_num].second; j++){
            mp_kni[init_r + i + dy[dirc]][init_c + j + dx[dirc]] = kni_num;
            if(mp[init_r + i + dy[dirc]][init_c + j + dx[dirc]] == 1){
                damage++;
            }
        }
    }

    if(pushed){
        //cout << "damage : " << kni_num << ' ' << damage << endl;
        knight_hel[kni_num] -= damage; 
        knight_damage[kni_num] += damage;
    }

    knight_loc[kni_num] = make_pair(init_r + dy[dirc], init_c + dx[dirc]);

    return;
}

void order_knight(int num, int dirc){
    //cout << "order : " << num << ' ' << dirc << endl;
    if(knight_hel[num] <= 0){
        return;
    }

    int kni_r = knight_loc[num].first; 
    int kni_c = knight_loc[num].second;
    int kni_h = knight_size[num].first;
    int kni_w = knight_size[num].second;

    queue<int> q;
    q.push(num);

    bool visited[31] = {0,};
    visited[num] = 1;

    while(!q.empty()){
        // knights can't move
        int curr_n = q.front();
        q.pop();

        int temp_r = knight_loc[curr_n].first;
        int temp_c = knight_loc[curr_n].second;
        int temp_h = knight_size[curr_n].first;
        int temp_w = knight_size[curr_n].second;

        for(int i = 0; i < temp_h; i++){
            for(int j = 0; j < temp_w; j++){
                int next = mp_kni[temp_r + i + dy[dirc]][temp_c + j + dx[dirc]];
                if(next > 0 && visited[next] == 0 ){
                    visited[next] = 1;
                    //cout << "next : " << next << endl;
                    q.push(next);
                }
            }
        }
    }

    for(int i = 1; i <= 30; i++){
        if(visited[i]){
            if(!possible(i, dirc)){
                return;
            }
        }
    }
    
    // knights can be pushed
    for(int i = 1; i <= N; i++){
        if(visited[i]){
            if(i == num){
                write_knight_loc(i, dirc, 0);
            } else{
                write_knight_loc(i, dirc, 1);
            }

            //cout << "knight : " << i << endl;
            //printMAP();
        }
    }

    return; 
}

void print_hel(){
    int sum = 0;
    for(int i = 1; i <= 30; i++){
        if(knight_hel[i] > 0){
            sum += knight_damage[i];
        }
    }

    cout << sum;
}

void erase_knight(){
    for(int num = 1; num <= N; num++){
        if(death[num] == 0 && knight_hel[num] <= 0){
            death[num] = 1;

            int init_r = knight_loc[num].first;
            int init_c = knight_loc[num].second;
            for(int i = 0; i < knight_size[num].first; i++){
                for(int j = 0; j < knight_size[num].second; j++){
                    mp_kni[init_r + i][init_c + j] = 0;
                }
            }
        }
    }
}

void print_knights_hel(){
    //cout << "healt check " << endl;
    for(int num = 1; num <= N; num++){
        cout << knight_hel[num] << ' ';
    }
    cout << endl;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> L >> N >> Q;
    // map info
    for(int i = 1; i <= L; i++){
        for(int j = 1; j <= L; j++){
            cin >> mp[i][j];
        }
    }

    //knights 
    for(int i = 1; i <= N; i++){
        int temp_y, temp_x, temp_w, temp_h;
        cin >> temp_y >> temp_x >> temp_h >> temp_w >> knight_hel[i];
        knight_loc[i] = make_pair(temp_y, temp_x);
        knight_size[i] = make_pair(temp_h, temp_w);
        write_knight_loc(i, 4, 0);
    }
    //printMAP();

    // order
    int knight_num, dirction;
    for(int i = 1; i <= Q; i++){
        cin >> knight_num >> dirction;
        order_knight(knight_num, dirction);
        //printMAP();
        erase_knight();
        //printMAP();
        //print_knights_hel();
    }

    print_hel();

    return 0;
}