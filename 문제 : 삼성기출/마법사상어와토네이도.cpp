#include <iostream>
#include <vector>
using namespace std;
int map[500][500];
int number_map[500][500];
int numbuer_dir[4][2] ={ {0,-1} ,{1,0}, {0,1}, {-1,0}};

int N , ans = 0;
vector<pair<int , pair <int,int > > > number;
vector<pair<int, pair <int,int > > > send_moves[4];
void make_send(){
    send_moves[0].push_back( { 2,{-2 ,0 }});
    send_moves[0].push_back( { 10,{-1,-1}});
    send_moves[0].push_back( { 7,{ -1,0 }});
    send_moves[0].push_back( { 1,{ -1,1 }});
    send_moves[0].push_back( { 5,{ 0,-2 }});
    send_moves[0].push_back( { 10,{ 1,-1 }});
    send_moves[0].push_back( { 7,{ 1,0 }});
    send_moves[0].push_back( { 1,{ 1,1 }});
    send_moves[0].push_back( { 2,{ 2,0 }});

    send_moves[1].push_back( { 1,{ -1,-1 }});
    send_moves[1].push_back( { 1,{ -1,1 }});
    send_moves[1].push_back( { 2,{ 0,-2 }});
    send_moves[1].push_back( { 7,{ 0,-1 }});
    send_moves[1].push_back( { 7,{ 0,1 }});
    send_moves[1].push_back( { 2,{ 0,2 }});
    send_moves[1].push_back( { 10,{ 1, -1}});
    send_moves[1].push_back( { 10,{ 1, 1}});
    send_moves[1].push_back( { 5,{ 2,0 }});

    send_moves[2].push_back( { 2,{ -2,0 }});
    send_moves[2].push_back( { 1,{ -1,-1 }});
    send_moves[2].push_back( { 7,{ -1,0 }});
    send_moves[2].push_back( { 10,{ -1,1 }});
    send_moves[2].push_back( { 5,{ 0,2 }});
    send_moves[2].push_back( { 1,{ 1,-1 }});
    send_moves[2].push_back( { 7,{ 1,0 }});
    send_moves[2].push_back( { 10,{ 1, 1}});
    send_moves[2].push_back( { 2,{ 2,0 }});

    send_moves[3].push_back( { 5,{ -2,0}});
    send_moves[3].push_back( { 10,{-1,-1}});
    send_moves[3].push_back( { 10,{-1,1}});
    send_moves[3].push_back( { 2,{0,-2}});
    send_moves[3].push_back( { 7,{0,-1}});
    send_moves[3].push_back( { 7,{0,1 }});
    send_moves[3].push_back( { 2,{0,2 }});
    send_moves[3].push_back( { 1,{1, -1}});
    send_moves[3].push_back( { 1,{1, 1}});
}
void numbering(){
    int curDir = 0 , num = 0;
    int move_cnt = 0;
    int max_move_cnt = 1 ;
    int wave_cnt = 0;
    int max_wave_cnt = 2;
    int curY = N/2;
    int curX = N/2;
    number.push_back({0,{curY,curX}});

    while (true){
        curY += numbuer_dir[curDir][0];
        curX += numbuer_dir[curDir][1];
        if(curY < 0 || curY >= N || curX < 0 || curX >= N) break;
        num++;
        move_cnt++;
        number_map[curY][curX] = num;
        number.push_back({ curDir, {curY, curX}});
        if(move_cnt == max_move_cnt){
            curDir++;
            wave_cnt++;
            move_cnt = 0;
            if(curDir == 4) curDir = 0;
            if(wave_cnt == max_wave_cnt){
                wave_cnt = 0;
                max_move_cnt++;
            }
        }
    }
}
void show(){
    for(int i = 0; i < N;i++){
        for(int j= 0; j < N  ;j++){
            cout <<map[i][j] <<" ";
        }
        cout <<endl;
    }
    cout << ans <<endl;
    cout <<endl;
}

void move(){
    for(int num = 0 ; num < number.size() ; num++){
        int curY = number[num].second.first;
        int curX = number[num].second.second;
        int curS = map[curY][curX];
        int alpa = map[curY][curX];
        int curDir = number[num].first;
        for(int k = 0 ; k < 9 ;k++){
            int nY = curY + send_moves[curDir][k].second.first;
            int nX = curX + send_moves[curDir][k].second.second;
            int nS = curS * send_moves[curDir][k].first / 100;
            alpa -= nS;
            if(nY < 0 || nY >= N || nX < 0 || nX >= N){
                ans += nS;
            }else{
                map[nY][nX] += nS;
            }
        }

        int nY = curY + numbuer_dir[curDir][0];
        int nX = curX + numbuer_dir[curDir][1];
        if(nY < 0 || nY >= N || nX < 0 || nX >= N){
            ans += alpa;
        }else{
            map[nY][nX] += alpa;
        }
        map[curY][curX] = 0;

        show();
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N  ;j++){
            cin >> map[i][j];
        }
    }
    make_send();
    numbering();
    move();
    cout << ans ;
}