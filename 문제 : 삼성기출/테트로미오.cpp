#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ans = 0;
int N , M;
int map[501][501];
bool vist[501][501];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};


void DFS(int y , int x , int cnt , int sum){
    if(cnt == 4){
        ans = max(ans,sum);
    }else{
        for(int k = 0 ; k < 4; k++){
            int ny = y + dir[k][0];
            int nx = x + dir[k][1];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M || vist[ny][nx]) continue;

            vist[ny][nx] = true;
            DFS(ny,nx, cnt+1, sum +map[ny][nx]);
            vist[ny][nx] = false;
        }
    }  
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j =0 ; j < M ;j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < N ;i++){
        for(int j =0 ; j < M ;j++){
            vist[i][j] = true;
            DFS(i,j,1,map[i][j]);
            vist[i][j] = false;

            int alpa = map[i][j];
            for(int k = 0 ; k < 4;k++){
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M ) continue;
                alpa += map[ny][nx];
            }

            for(int k = 0 ; k < 4;k++){
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M ) continue;
                int res = alpa - map[ny][nx];

                ans = max (ans , res);
            }

        }
    }
    cout << ans <<endl;
    return 0;
}