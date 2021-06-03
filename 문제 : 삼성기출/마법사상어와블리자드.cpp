#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , M , d, s;
int map[50][50];
int num_map[50][50];
int numbering_dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0}} ;
int del_dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1}};
int last_num = 1;
int ans = 0 ;
vector<pair <int,int > > number_pos;
void numbering_map(){
    int nextY = N/2 , nextX = N/2;
    int num = 1;
    int d = 0;
    int small_wave = 0;
    int max_small_wave = 1;
    int big_wave_cnt = 0;
    number_pos.push_back({N/2 , N/2});
    
    while (true){
        nextY = nextY + numbering_dir[d][0];
        nextX = nextX + numbering_dir[d][1];
        num_map[nextY][nextX] = num;
        number_pos.push_back({nextY , nextX});
        num++;
        small_wave++;

        if(nextY == 0 && nextX == 0) break;
        if(small_wave == max_small_wave){
            d ++;
            small_wave = 0 ;
            big_wave_cnt++;
            if(d == 4){
                d = 0;
            }
            if(big_wave_cnt == 2){
                big_wave_cnt = 0;
                max_small_wave++;
            }
        }
    }
}
void move(){
    vector <int> bead;
    // 한칸씩 당기는 방식 X (비효율)
    // map을 초기화하면서 (1 , 2 , 3) 만 순서대로 저장후 다시 재배열
    for(int num = 1; num < number_pos.size()-1 ; num++){
        int curY = number_pos[num].first;
        int curX = number_pos[num].second;
        if(map[curY][curX] != 0){
            bead.push_back(map[curY][curX]);
        }
        map[curY][curX] = 0;
    }
    for(int i = 0 ; i < bead.size();i++){
        int curY = number_pos[i+1].first;
        int curX = number_pos[i+1].second;
        map[curY][curX] = bead[i];
    }
}
void boom_bead(){
    while (true){
        bool flag = true;
        for(int num = 1; num < number_pos.size()-1; num++){
            int curY = number_pos[num].first;
            int curX = number_pos[num].second;
            int curBoom = map[curY][curX];
            int cnt = 1;
            if(curBoom == 0) continue;

            vector<pair<int,int>> boom_List;
            boom_List.push_back({curY,curX});
           
            for(int Nnum = num+1 ; Nnum < number_pos.size() ; Nnum++){
                if(map[number_pos[Nnum].first][number_pos[Nnum].second] == curBoom){
                    cnt++;
                    boom_List.push_back({number_pos[Nnum].first,number_pos[Nnum].second});
                }else{
                    break;
                }
            }
            if(cnt >= 4){
                flag = false;
                if(curBoom == 1) ans = ans + cnt;
                else if(curBoom == 2) ans = ans + (cnt*2);
                else ans = ans + (cnt*3);

                for(int idx = 0 ; idx <boom_List.size() ;idx++){
                    map[boom_List[idx].first][boom_List[idx].second] = 0;
                }
            }
        }
        move();
        if(flag) break;
    }
}
void init_map(){
    bool vist[51][51];
    for(int i = 0; i < N ;i++){
        for(int j = 0; j < N;j++){
            vist[i][j] = false;
        }
    }
    vector<  pair<int,int>  > make_list;
    for(int num = 1; num < number_pos.size(); num++){
        int curY = number_pos[num].first;
        int curX = number_pos[num].second;
        int A = 1 , B = map[curY][curX]; 

        if(map[curY][curX] == 0) break;
        if(vist[curY][curX]) continue;

        vist[curY][curX] = true;
        for(int Nnum = num+1 ; Nnum < number_pos.size() ; Nnum++){
            int nextY = number_pos[Nnum].first;
            int nextX = number_pos[Nnum].second;
            if(map[nextY][nextX] == B){
                A++;
                vist[nextY][nextX] = true;
            }else{
                break;
            }
        }
        make_list.push_back( {A ,B } );
    }


    for(int i = 0; i < N ;i++){
        for(int j = 0; j < N;j++){
            map[i][j] = 0;
        }
    }
    int make_idx = 0;
    for(int num = 1; num < number_pos.size()-1; num++){
        if(make_idx == make_list.size() ) break;
        int curY = number_pos[num].first;
        int curX = number_pos[num].second;
        if(map[curY][curX] == 0){
            map[curY][curX] = make_list[make_idx].first;
            int nextY = number_pos[num+1].first;
            int nextX = number_pos[num+1].second;
            map[nextY][nextX] = make_list[make_idx].second;
            make_idx++;
        }
    }
}
void del_bead(){
    int dirY = del_dir[d-1][0];
    int dirX = del_dir[d-1][1];
    int nextY = N/2;
    int nextX = N/2;
    int cnt = 0 ;
    // 마법발동 
    while (true){
        nextY += dirY;
        nextX += dirX;
        map[nextY][nextX] = 0;
        cnt ++;
        if(cnt == s) break;
    }
    move(); // 이동
}
int main(){
    //freopen("input.txt", "r",stdin);
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N ;i++){
        for(int j = 0; j < N;j++){
            cin >> map[i][j];
        }
    }
    numbering_map();
    for(int i = 0 ; i < M ;i++){
        cin >> d >> s;
        del_bead();
        boom_bead();
        init_map();
    }
    cout << ans;
}