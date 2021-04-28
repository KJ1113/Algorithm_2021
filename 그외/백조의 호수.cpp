#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
using namespace std;
int R ,C ,cnt =0;
char map[1501][1501];
bool vist[1501][1501];
pair<int,int> swan_pos;
queue <pair<int,int>> waterq;
queue <pair<int,int>> swanq;
queue <pair<int,int>> next_waterq;
queue <pair<int,int>> next_swanq;

int dir [4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool swan_BFS(){
    while (!swanq.empty()){
        int curY = swanq.front().first;
        int curX = swanq.front().second;
        swanq.pop();
        for(int i =0; i < 4 ;i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if(nextY < 0 || nextX < 0 || nextY >= R || nextX >= C ) continue;
            if(vist[nextY][nextX] == false){
                if( map[nextY][nextX] =='.'  ){ // 녹는 얼음이라면
                    vist[nextY][nextX] = true;
                    swanq.push({nextY,nextX});
                }
                else if(map[nextY][nextX] == 'L'){
                    vist[nextY][nextX] = true;
                    swanq.push({nextY,nextX});
                    return true;
                }
                else if(map[nextY][nextX] =='X'){
                    vist[nextY][nextX] = true;
                    next_swanq.push({nextY,nextX});
                }
            }
        }
    }
    return false;
}
void water_BFS(){
    while (!waterq.empty()){
        int curY = waterq.front().first;
        int curX = waterq.front().second;
        waterq.pop();
        for(int i =0; i < 4 ;i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if(nextY < 0 || nextX < 0 || nextY >= R || nextX >= C ) continue;
          
            if(map[nextY][nextX] =='X'){
                map[nextY][nextX] = '.';
                next_waterq.push({nextY,nextX});
            }
        }   
    }
}
int sol(){
    bool flag = false;
    swanq.push({swan_pos.first,swan_pos.second});
    vist[swanq.front().first][swanq.front().second] =true;
    while (!flag){
        flag = swan_BFS();
        if(!flag){
            water_BFS();

            swanq =next_swanq;
            waterq = next_waterq;
            while (!next_swanq.empty())next_swanq.pop();
            while (!next_waterq.empty())next_waterq.pop();
            cnt++;
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for(int i =0; i < R ;i++){
        for(int j =0 ; j< C ;j++){
            cin >> map[i][j];
            if(map[i][j] != 'X'){
                waterq.push({i,j});
            }
            if(map[i][j]=='L'){
                swan_pos.first = i;
                swan_pos.second =j;
            }
        }
    }
    cout << sol();
    return 0;
}