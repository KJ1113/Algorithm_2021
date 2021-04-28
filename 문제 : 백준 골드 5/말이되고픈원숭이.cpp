#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 999999;
int K , W , H; //maxX , maxY
int dir[4][2] = {{1,0} ,{0,1}, {0,-1}, {-1,0}};
int horseDir[8][2] = {{-1,-2} ,{1,-2}, {-2,-1}, {2,-1}, { -2, 1}, { 2,1}, { -1,2}, {1,2}};
bool vist[201][201][31];
int map[201][201][31];
int ans = INF;
struct Monkey{
    int y,x,k;
    void inputData(int y ,int x, int k){
        this ->y = y;
        this ->x = x;
        this ->k = k;
    }
};
void BFS( ){
    queue <Monkey> q;
    Monkey m;
    m.inputData(0,0,0);
    q.push(m);
    map[0][0][0] = 0;
    vist[0][0][0] = true;

    int time = 0;
    while (!q.empty()){
        time++;
        int qsize = q.size();
        for(int i = 0 ; i < qsize ; i++){
            int curY = q.front().y;
            int curX = q.front().x;
            int curK = q.front().k;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nextY = curY + dir[k][0];
                int nextX = curX + dir[k][1];
                if(nextY < 0 || nextX < 0 || nextY >= H || nextX >= W) continue;
                if(vist[nextY][nextX][curK]) continue;
                
                m.inputData(nextY,nextX,curK);
                q.push(m);
                vist[nextY][nextX][curK] = true;
                map[nextY][nextX][curK] = time;

                if(nextY == H-1 && nextX == W-1) ans = min(ans,time);
            }

            if(curK == K ) continue;
            for(int k = 0; k < 8; k++){
                int nextY = curY + horseDir[k][0];
                int nextX = curX + horseDir[k][1];
                if(nextY < 0 || nextX < 0 || nextY >= H || nextX >= W) continue;
                if(vist[nextY][nextX][curK+1] ) continue;
                
                m.inputData(nextY,nextX,curK+1);
                q.push(m);
                vist[nextY][nextX][curK+1] = true;
                map[nextY][nextX][curK+1] = time;

                if(nextY == H-1 && nextX == W-1) ans = min(ans,time);
            }
        }
    }
}
int main(){
    cin >> K >> W >> H;
    for(int i = 0 ; i < H ;i++){
        for(int j =0 ; j< W ; j++){
            int input ;
            cin >>input;
            if(input == 1){
                for(int k = 0; k <= K ;k ++){
                    map[i][j][k] = 0;
                    vist[i][j][k] = true;
                }
            }
            else{
                for(int k = 0; k <= K ;k ++){
                    map[i][j][k] = INF;
                }
            }
        }
    }
    BFS();
    if(ans == INF){
        cout << -1;
    }
    else{
        cout << ans ;
    }
    return 0;
}