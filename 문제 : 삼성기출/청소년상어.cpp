#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int ans =0;
int dir[8][2] ={ {-1,0} ,{-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}};
struct Fish{
    int num , y , x , dir;
};
Fish fish_map[4][4];
vector <Fish> fish_list;
struct Shark{
    int y, x , dir;
    vector <Fish> eat_list;
    void eat(Fish f){
        this-> y = f.y;
        this-> x = f.x;
        this-> dir = f.dir;
        fish_list.clear();
        fish_map[y][x].num = 0;
        fish_map[y][x].dir = 0;
        for(int i  = 0; i < 4;i++){
            for(int j = 0; j < 4 ;j++){
                if(fish_map[i][j].num !=0 ) fish_list.push_back(fish_map[i][j]);
            }
        }
    }
};
Shark shark;
bool cmp(Fish a , Fish b){
    return a.num < b.num;
}
void changeFish(Fish &a , int change_Num){
    for(int i = 0 ; i < fish_list.size() ; i++){
        if(change_Num == fish_list[i].num){
            fish_map[a.y][a.x] = fish_list[i];
            fish_map[fish_list[i].y][fish_list[i].x] = a;

            int tmpY = fish_list[i].y;
            int tmpX = fish_list[i].x;
            fish_list[i].y = a.y;
            fish_list[i].x = a.x;

            a.y = tmpY;
            a.x = tmpX;
            break;
        }
    }
}
void change_map(int nextY , int nextX ,int idx){
    if (fish_map[nextY][nextX].num == 0){
        fish_map[fish_list[idx].y][fish_list[idx].x].num = 0;
        fish_list[idx].y = nextY;
        fish_list[idx].x = nextX;
        fish_map[nextY][nextX].dir = fish_list[idx].dir;
        fish_map[nextY][nextX].num = fish_list[idx].num;
    }
    else{
        changeFish(fish_list[idx], fish_map[nextY][nextX].num);
    }
}
void move(){
    sort(fish_list.begin() , fish_list.end(), cmp); // num 작은순으로 정렬
    vector <Fish> tmp_fish_list = fish_list;
    
    for(int idx = 0 ; idx < fish_list.size(); idx++ ){
        int curY = fish_list[idx].y;
        int curX = fish_list[idx].x;
        int curDir = fish_list[idx].dir-1;
        int curNum = fish_list[idx].num;
        int nextY = curY + dir[curDir][0];
        int nextX = curX + dir[curDir][1];

        if(nextY < 0 || nextX < 0 || nextY >=4 || nextX >= 4 || (shark.y == nextY && shark.x == nextX)){ // 이동할수있을때까지 탐색
            int end = curDir;
            int nextDir = curDir;
            while (true){
                nextDir = nextDir +1;
                if(nextDir == 8) nextDir = 0;
                if(end == nextDir) break;
                
                nextY = curY + dir[nextDir][0];
                nextX = curX + dir[nextDir][1];
                if(nextY < 0 || nextX < 0 || nextY >=4 || nextX >= 4 || (shark.y == nextY && shark.x == nextX)) continue;
                fish_list[idx].dir = nextDir+1;
                change_map( nextY ,  nextX , idx);
                break;
            }
        }
        else{
            change_map( nextY ,  nextX , idx);   
        }
    }

    for(int i =0 ;i < 4 ;i ++){
        for(int j =0 ;j < 4; j++){
            fish_map[i][j].y = i;
            fish_map[i][j].x = j;
        }
    }
}
void search(){ // 상어가 현재 바라보고 있는 방향에서 먹을수있는 물고기를 추가한다.
    shark.eat_list.clear();
    int nextY = shark.y;
    int nextX = shark.x;
    int curDir =shark.dir-1;
    while (true){
        nextY = nextY + dir[curDir][0];
        nextX = nextX + dir[curDir][1];
        if(nextY < 0 || nextX < 0 || nextY >=4 || nextX >= 4 ) break;
        if(fish_map[nextY][nextX].num != 0){
            shark.eat_list.push_back(fish_map[nextY][nextX]);
        }
    }
}
void DFS(int sum){
    move();
    search();
    if(shark.eat_list.size() == 0){
        ans = max(sum ,ans);
        return;
    }
    vector <Fish> tmp_eat_list = shark.eat_list;
    Fish tmp_fish_map[4][4];
    memcpy(tmp_fish_map, fish_map, sizeof(tmp_fish_map)); 
    
    for(int i = 0; i < tmp_eat_list.size(); i++){
        memcpy(fish_map, tmp_fish_map, sizeof(tmp_fish_map));
        shark.eat(tmp_eat_list[i]);
        DFS(sum + tmp_eat_list[i].num);
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i  = 0; i < 4;i++){
        for(int j = 0; j < 4 ;j++){
            int a, b;
            cin >> a >> b;
            fish_map[i][j].y = i;
            fish_map[i][j].x = j;
            fish_map[i][j].num = a;
            fish_map[i][j].dir = b;
        }
    }
    int startNum = fish_map[0][0].num;
    shark.eat(fish_map[0][0]);
    DFS(startNum);
    cout << ans;
    return 0;
}
// 1. 상어가 물고기를 먹음
// 2. 물고기 이동 
// 3. 상어가 현재바라보는 방향을 기준으로 먹을수있는 물고기 업데이트
    // 3-1 상어가 먹을수있는 물고기가 없다면 return;
// 4. DFS 내의 for문을 이용하여 선택
//   4-1 그전의 map정보를 저장하기 위하여 tmp fish map 이용하여 저장
// 2 ~ 4 반복