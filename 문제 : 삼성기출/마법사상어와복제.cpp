#include <iostream>
#include <vector>
using namespace std;

int M , S , sY, sX;
int fish_cnt[4][4];

int fish_smell[4][4];
int fish_dir[9][2] = {{0,0}, {0,-1},{-1,-1},{-1,0},{-1,1} , {0,1},{1,1},{1,0},{1,-1}};
int s_dir[5][2] = {{0,0}, {-1,0}, {0,-1}, {1,0}, {0,1}};

// 상어 이동할때 필요한 전역변수
int max_eat = -1;
int tmp_cnt_map[4][4];
vector< pair<int,int> > max_move_list;

struct Fish{
    int y, x, dir;
};
vector<Fish>fish_list;
vector<Fish>tmp_fish_list; // 복제되는 물고기 리스트 + 살아남은 물고기 리스트
void fish_move(){

    tmp_fish_list.clear();
    tmp_fish_list = fish_list; // 복제

    for(int i = 0 ; i < fish_list.size();i++){
        
        int k = fish_list[i].dir;
        int first_dir = k;
    
        while (true){
            int ny = fish_list[i].y + fish_dir[k][0];
            int nx = fish_list[i].x + fish_dir[k][1];

            if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || (ny == sY && nx ==sX) || fish_smell[ny][nx] !=0) {
                k--;
                if(k == 0) k = 8;
                if(k == first_dir) break;
            }else{

                fish_cnt[fish_list[i].y][fish_list[i].x] --;

                fish_list[i].y = ny;
                fish_list[i].x = nx;
                fish_list[i].dir = k;
                
                fish_cnt[ny][nx] ++;

                break;
            }
        }
    }
}
void DFS(int cY , int cX , int cnt , int eat_cnt, vector< pair<int,int> > move_list ){
   
    if(cnt == 3){
        if(max_eat < eat_cnt){
            max_move_list = move_list;
            max_eat = eat_cnt;
        }
    }else{

        for(int  k = 1 ; k <= 4; k++){
            int ny = cY + s_dir[k][0];
            int nx = cX + s_dir[k][1];
            
            if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4 ) continue;

            int tmp = tmp_cnt_map[ny][nx];

            tmp_cnt_map[ny][nx] = 0;
            move_list.push_back({ny,nx});
            DFS(ny , nx, cnt+1 , eat_cnt + tmp , move_list);
            move_list.pop_back();
            tmp_cnt_map[ny][nx] = tmp;
        }
    }
}
void kill_fish(){
    for(int idx = 0 ;idx < max_move_list.size() ;idx++){
        int y = max_move_list[idx].first;
        int x = max_move_list[idx].second;

        if(fish_cnt[y][x] != 0){
            fish_cnt[y][x] = 0;
            fish_smell[y][x] = 3;
        }
    }
    
    for(int idx = 0 ;idx < fish_list.size() ;idx++){
        int y = fish_list[idx].y;
        int x = fish_list[idx].x;

        if(fish_cnt[y][x] != 0){
            tmp_fish_list.push_back(fish_list[idx]);
        }
    }
    
    // 상어 위치 조정
    sY = max_move_list[max_move_list.size()-1].first;
    sX = max_move_list[max_move_list.size()-1].second;
}
void del_smell(){

    // 냄새 -1 , cnt map 0 으로 초기화 (다시 그려줘야댐)
    for(int i = 0 ; i < 4;i++){
        for(int j = 0 ; j < 4; j++){
            fish_cnt[i][j] = 0;
            if(fish_smell[i][j]!=0) fish_smell[i][j]--;
        }
    }
}
void copy(){
    //cnt map 다시 그리는중
    for(int idx = 0 ;idx < tmp_fish_list.size() ;idx++){
        int y = tmp_fish_list[idx].y;
        int x = tmp_fish_list[idx].x;
        fish_cnt[y][x]++;
    }
    fish_list = tmp_fish_list;
}
void s_move(){
    max_eat = -1;
    max_move_list.clear();
    vector< pair<int,int> > move_list;
    for(int i = 0 ; i < 4;i++){
        for(int j = 0;j < 4;j++){
            tmp_cnt_map[i][j] = fish_cnt[i][j];
        }
    }
    DFS(sY,sX,0,0,move_list);
}
void sol(){
    for(int s = 0 ; s < S; s++){
        fish_move();
        s_move();
        kill_fish();
        del_smell();
        copy();
    }
    cout << fish_list.size() << endl;
}
int main(){
    cin >> M >> S;
    for(int i =0 ; i < M ;i ++){
        Fish f;
        cin >> f.y >> f.x >> f.dir;
        f.y --;
        f.x --;

        fish_cnt[f.y][f.x]++;
        fish_list.push_back(f);
    }

    cin >> sY >> sX ;
    sY --;
    sX --;
    sol();
    return 0;
}