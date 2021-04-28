#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char map[51][51];
int vist[51][51];
int dir[4][2] ={ {0,1} ,{0,-1}, {1,0}, {-1,0}};
int N , M;
int ans = 0;
void init(){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0; j < M;j++){
            vist[i][j] = false;
        }
    }
}
int BFS(int Y , int X){
    int time = 0;
    int res = 0;
    queue<pair<int,int> > q;
    q.push({Y , X});
    vist[Y][X] = true;

    while (!q.empty()){
        time++;
        int qsize = q.size(); 
        for(int i = 0 ; i < qsize ;i++){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            for(int k = 0; k< 4 ;k++){
                int nextY = curY + dir[k][0];
                int nextX = curX + dir[k][1];
                if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= M || vist[nextY][nextX]) continue;
                if (map[nextY][nextX]== 'W') continue;
                vist[nextY][nextX] = true;
                q.push( {nextY , nextX});
                res = time;
            }
        }
    }
    
    return res;
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        cin >> map[i];
    }
    for(int i = 0 ; i < N ;i++){
        for(int j = 0; j < M;j++){
            if(map[i][j] == 'L'){
                ans = max (ans , BFS(i,j));
                init();
            }
        }
    }
    cout << ans;
}