#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[20][20];
bool vist[20][20];
int dir[4][2] ={{0,-1},{-1,0},{1,0},{0,1}}; // 상 좌 우 하 순서 
int N , ans = 0;

struct Shark{
    int y, x , eatNum ,size = 2;
};
Shark shark;
bool BFS(int y , int x){
    int time = 0;
    int eatY , eatX;
    bool flag = false;

    queue <pair<int,int> > q;
    q.push({y,x});
    for(int i = 0 ; i < N;i++){
        for(int j =0 ; j< N ;j++){
            vist[i][j] = false;
        }
    }

    while(!q.empty()){
        time++;
        int qsize = q.size();
        for(int i = 0; i < qsize ;i++){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();

            for(int k = 0 ; k < 4; k++){
                int nextY = curY + dir[k][0];
                int nextX = curX + dir[k][1];
                if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N ) continue;
                if( vist[nextY][nextX] || shark.size < map[nextY][nextX]) continue;

                q.push({ nextY , nextX });
                vist[nextY][nextX] = true;
                if(map[nextY][nextX] != 0 && shark.size > map[nextY][nextX]){ // 먹을수있는 물고기면
                    if(flag == false){ // 처음 발견한 물고기라면
                        eatY = nextY;
                        eatX = nextX;
                        flag = true;
                    }
                    else{
                        if(nextY < eatY || (nextY == eatY && nextX < eatX)){
                            eatY = nextY;
                            eatX = nextX;
                        }
                    }
                }
            }
        }
        if(flag == true){
            shark.y = eatY;
            shark.x = eatX;
            shark.eatNum++;
            map[eatY][eatX] = 0;
            ans += time;
            
            if(shark.eatNum == shark.size){
                shark.eatNum = 0;
                shark.size++;
            }
            return true;
        }
    }
    return false;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N ;
    for(int i = 0 ; i < N; i++){ // 입력
        for(int j =0 ; j< N ; j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                shark.y = i;
                shark.x = j;
                shark.eatNum = 0;
                map[i][j] = 0;
            }
        }
    }
    while(true){
        if(BFS(shark.y, shark.x) == false)  break;
    }
    cout << ans ;
    return 0;
}