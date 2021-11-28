#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N , M , D , S;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int del_dir[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1}};
int number_map[51][51];
int map[51][51];
int num_pos_max;
int boom_num[4] ;
int ans = 0 ;
pair<int,int> num_pos[30000];

void make_number_map(){
    num_pos_max = N*N;
    int ny = 0;
    int nx = 0;
    int nd = 0;
    int cnt = num_pos_max -1;
    while (true){
        number_map[ny][nx] = cnt;
        num_pos[cnt] = { ny,nx };
        cnt--;
        int cy = ny;
        int cx = nx;
        ny = cy + dir[nd][0];
        nx = cx + dir[nd][1];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N || number_map[ny][nx] != 0){
            nd++;
            if(nd == 4) nd = 0;
            ny = cy + dir[nd][0];
            nx = cx + dir[nd][1];
        }
        if(cnt == 0 ){
            num_pos[cnt] = { N/2,N/2 };
            break;
        }
    }
}
void merge(){
    int same_cnt = 1;
    int same_num = map[num_pos[1].first][num_pos[1].second];
    if(same_num == 0) return;

    vector< pair<int,int> > m_list;
    m_list.push_back({same_cnt,same_num});

    for(int i = 2; i < num_pos_max; i++){
        int y = num_pos[i].first;
        int x = num_pos[i].second;
        
        if(map[y][x] == same_num){
            same_cnt++;
        }else{
            m_list.push_back({same_cnt,same_num});
            same_cnt = 1;
            same_num = map[y][x];
        }
    }

    int index =1;
    for(int i = 1 ; i < m_list.size();i++){
        
        int y = num_pos[index].first;
        int x = num_pos[index].second;
        map[y][x] = m_list[i].first;
        index++;
        if(y == 0 && x ==0) break;
        
        y = num_pos[index].first;
        x = num_pos[index].second;
        map[y][x] = m_list[i].second;
        index++;

        if(y == 0 && x ==0) break;
    }
}
void move(){

    while (true){
        vector<int> no_del_num;
        for(int i = 1; i < num_pos_max; i++){
            if(map[num_pos[i].first][num_pos[i].second] != -1){
                no_del_num.push_back( map[num_pos[i].first][num_pos[i].second]);
            }
        }
        int nd_idx = 0;
        for(int i = 1; i < num_pos_max; i++){
            int update_y = num_pos[i].first;
            int update_x = num_pos[i].second;

            if(nd_idx < no_del_num.size()) map[update_y][update_x]= no_del_num[nd_idx];
            else map[update_y][update_x] = 0;
            nd_idx++;
        }

        ////// 폭발
        vector< vector<pair<int,int> > > boom_list;
        vector< pair<int,int> > booms;
        bool flag = true;
        int cur_num = -1;
        for(int i = 1; i < num_pos_max; i++){
            int y = num_pos[i].first;
            int x = num_pos[i].second;
            int num = map[y][x];

            if(cur_num == num){
                booms.push_back({y,x});
            }else{
                if( booms.size() >= 4){
                    boom_list.push_back(booms);
                }
                booms.clear();
                cur_num = num;
                booms.push_back({y,x});
            }
        }

        for(int index = 0 ; index < boom_list.size(); index++){
            for(int idx = 0 ; idx < boom_list[index].size();idx++){
                int dy = boom_list[index][idx].first;
                int dx = boom_list[index][idx].second;

                boom_num[map[dy][dx]]++;

                map[dy][dx] = -1;
                flag = false;
            }
        }
        if(flag) break; // 이동할것이 없으면 스탑
    }
}
void sol(){
    map[N/2][N/2] = 9;
    for(int i = 0 ; i < M ;i++){
        cin >> D >> S;
        int ny = N/2;
        int nx = N/2;
        for(int s = 0 ; s < S;s++){
            int cy = ny;
            int cx = ny;
            ny = ny + del_dir[D][0];
            nx = nx + del_dir[D][1];
            map[ny][nx] = -1;
        }
        move();
        merge();
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            cin >> map[i][j];
        }
    }
    make_number_map();
    sol();
    ans += (boom_num[1]*1) + (boom_num[2] * 2) + (boom_num[3] * 3);
    cout << ans;
    return 0;
}