#include <iostream>
#include <vector>
using namespace std;
int N , M;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}};
int al[101];
char map[21][21];
int ans = 1;

void DFS(int y , int x ,int cnt){

    if(cnt > ans){ 
        ans = cnt;
    }

    for(int k = 0; k < 4; k++){
        int nextY = y + dir[k][0];
        int nextX = x + dir[k][1];

        if( nextY < 0 || nextX < 0 || nextY >= N || nextX >= M  || al[(int)map[nextY][nextX]] == 1) continue;

        al[(int)map[nextY][nextX]] = 1;
        DFS(nextY, nextX, cnt+1);
        al[(int)map[nextY][nextX]] = 0;
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N;i++){
        cin >> map[i];
    }
    
    al[(int)map[0][0] ] =1;
    DFS(0,0,1);
    cout << ans;
    return 0;
}