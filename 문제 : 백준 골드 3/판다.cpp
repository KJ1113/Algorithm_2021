#include <iostream>
#include <algorithm>
using namespace std;
int N;
int map[501][501];
int dp[501][501];
int dir[4][2] ={ {1,0}, {0,1}, {0,-1}, {-1,0}};
int ans = -1;
int DFS(int y , int x){
    if(dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 1;
    int tmp = 0;
    for(int k = 0; k <4 ;k++){
        int nY = y + dir[k][0];
        int nX = x + dir[k][1];
        if(nY < 0 || nX < 0 || nY >= N || nX >= N ) continue;
        if(map[nY][nX] > map[y][x]){
            tmp = max(tmp, DFS(nY ,nX) );
        }
    }
    return dp[y][x] = dp[y][x] + tmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0; j< N ;j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    for(int i = 0 ; i < N ;i++){
        for(int j = 0; j< N ;j++){
            if(dp[i][j] == -1){
                DFS(i,j);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}