#include <iostream>
using namespace std;
int N , M , ans = 0;
int map[501][501];
int dp[501][501];
int dir [4][2] = { {-1,0},{0,-1},{1,0} ,{0,1}};
int DFS(int y , int x){

    if(y == N-1 && x == M-1) return 1;
    if(dp[y][x] != -1) return dp[y][x];

    // dp가 -1 일때
    dp[y][x] = 0;
    for(int k = 0; k <4 ;k++){
        int nY = y + dir[k][0];
        int nX = x + dir[k][1];
        if(nY < 0 || nX < 0 || nY >= N || nX >= M ) continue;
        if(map[nY][nX] < map[y][x]){
            dp[y][x] += DFS(nY ,nX);
        }
    }
    return dp[y][x];
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j= 0; j< M;j ++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << DFS(0,0);
    return 0;
}