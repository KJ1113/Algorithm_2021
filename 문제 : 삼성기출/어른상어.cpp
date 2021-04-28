#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int smell_map[21][21];
int time_map[21][21];
int N, M, K, Scnt;
int dir[4][2] = { {-1,0} ,{1,0}, {0,-1}, {0,1} }; // 상 하 좌 우
struct Shark {
    int y, x, num, dir;
    vector <int> pri_list[4]; // 우선순위
};
bool cmp(Shark a , Shark b){
    return a.num < b.num;
}
bool cmp2(Shark a , Shark b){
    return a.num > b.num;
}
vector <Shark> shark_list; // 상어 num 순으로 정렬
void move(){
    vector <Shark> tmp_shark_list; // 살아있는 상어만 담는 list
    for(int i = 0 ; i < N ;i++){ //먼저 time_map 의 시간을 줄여준다.
        for(int j = 0 ; j< N;j++){
            if(time_map[i][j] > 0) time_map[i][j] --;
            if(time_map[i][j] == 0 && smell_map[i][j] != 0 ) smell_map[i][j] = 0;
        }
    }
    for(int i = 0 ; i < shark_list.size(); i++){ //같은 곳을 겹치게되면 번호가 낮은 상어가 덮어쓴다. (처음에 내림차순 정렬했기 떄문)
        smell_map[shark_list[i].y][shark_list[i].x] = shark_list[i].num;
        time_map[shark_list[i].y][shark_list[i].x] = K;
    }
    for(int i = 0 ; i < shark_list.size(); i++){ //같은위치의 smell_map과 상어번호가 다르다면 그상어는 죽은 상어
        if(smell_map[shark_list[i].y][shark_list[i].x] == shark_list[i].num){
            tmp_shark_list.push_back(shark_list[i]);
        }
    }
    shark_list = tmp_shark_list; //shark_list 교체
}
void update_shark_pos(){
    for(int i = 0 ; i < shark_list.size(); i++){
        Shark s = shark_list[i];
        bool flag = false;
        for(int k =0 ;k<4 ; k++){
            int nextdir = s.pri_list[s.dir][k];
            int nextY = s.y + dir[nextdir][0];
            int nextX = s.x + dir[nextdir][1];
            if(nextY < 0 || nextX < 0|| nextY >= N || nextX >= N ) continue;
            if(smell_map[nextY][nextX] == 0){
                //cout << s.num <<"냄새 안 나는곳 찾음" <<endl;
                flag = true;
                shark_list[i].y = nextY;
                shark_list[i].x = nextX;
                shark_list[i].dir = nextdir;
                break;
            }
        }
        if(flag == true) continue; // 위치 찾으면 다음 상어 업데이트
        for(int k =0 ;k<4 ; k++){
            int nextdir = s.pri_list[s.dir][k];
            int nextY = s.y + dir[nextdir][0];
            int nextX = s.x + dir[nextdir][1];
            if(nextY < 0 || nextX < 0|| nextY >= N || nextX >= N ) continue;
            if(smell_map[nextY][nextX] == s.num){
                //cout << s.num <<"나의 냄새 나는곳 찾음" <<endl;
                shark_list[i].y = nextY;
                shark_list[i].x = nextX;
                shark_list[i].dir = nextdir;
                break;
            }
        }
    }
}
void input_data() {
    cin >> N >> M >>K;
    for(int i  =0; i < N ; i++){
        for(int j = 0 ; j < N ;j++){
            int x ;
            cin >> x;
            if(x != 0){
                Shark s;
                s.y = i;
                s.x = j;
                s.num = x;
                shark_list.push_back(s);
                smell_map[i][j] = x;
                time_map[i][j] = K;
            }
        }
    }
    sort(shark_list.begin(), shark_list.end(),cmp); // 1번 상어부터 입력 되므로 오름차순 정렬 수행
    for(int i = 0 ; i < shark_list.size() ;i++){
        cin >> shark_list[i].dir;
        shark_list[i].dir--;
    }
    for(int i = 0 ; i < shark_list.size() ; i++ ){
        for(int k = 0 ; k < 4 ; k++){
            for(int j = 0; j < 4; j++){
                int dir;
                cin >> dir;
                shark_list[i].pri_list[k].push_back(dir-1);
            }
        }
    }
}
void sol(){
    update_shark_pos();
    move();
}
int main() {
    input_data();
    sort(shark_list.begin(), shark_list.end(),cmp2); // 내림차순 정렬(한번만하면됨)
    for (int T = 0; T < 1001; T++ ) {
        if (shark_list.size() == 1){
            cout << T;
            return 0;
        }
        sol();
    }
    cout << -1;
    return 0;
}