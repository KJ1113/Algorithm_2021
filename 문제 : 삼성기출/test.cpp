#include <stdio.h>
#include <iostream>

using namespace std;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };
const int wx[4][9] =
{
    {-1, 1, -1, 1, -1, 1, -2, 2, 0}, // LEFT
    {-1, -1, 0, 0, 1, 1, 0, 0, 2}, // DOWN
    {-1, 1, -1, 1, -1, 1, -2, 2, 0 }, // RIGHT
    {1, 1, 0, 0, -1, -1, 0, 0, -2 }, // UP
};
 
const int wy[4][9] =
{
    {1, 1, 0, 0, -1, -1, 0, 0, -2}, // LEFT
    {-1, 1, -1, 1, -1, 1, -2, 2, 0}, // DOWN
    {-1, -1, 0, 0, 1, 1, 0, 0, 2}, // RIGHT
    {-1, 1, -1, 1, -1, 1, -2, 2, 0}, // UP
};
int percent[] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };
 
const int MAX_N = 500;
int N, map[MAX_N][MAX_N], ans;
 
struct Node {
    int x, y, dir;
}windy;
 
void sprinkSand() {
    int initVal = map[windy.x][windy.y];
    for (int i = 0; i < 9; ++i) {
        int x = windy.x + wx[windy.dir][i];
        int y = windy.y + wy[windy.dir][i];
 
        int sand = (initVal * percent[i]) / 100;
        map[windy.x][windy.y] -= sand;
        // 격자 밖을 벗어나는 경우
        if (x < 0 || y < 0 || x >= N || y >= N) {
            ans += sand;
            continue;
        }
        map[x][y] += sand;
    }
    
    // 비율만큼 보내고 남은 모래 처리
    int x = windy.x + dx[windy.dir];
    int y = windy.y + dy[windy.dir];
    if (x < 0 || y < 0 || x >= N || y >= N) {
        ans += map[windy.x][windy.y];
        map[windy.x][windy.y] = 0;
        return;
    }
    // 격자를 벗어나지 않는 경우
    map[x][y] += map[windy.x][windy.y];
    map[windy.x][windy.y] = 0;
}
void show(){
    for(int i = 0; i < N;i++){
        for(int j= 0; j < N  ;j++){
            cout << map[i][j] <<" ";
        }
        cout <<endl;
    }
    cout << ans <<endl;
    cout <<endl;
}
 
void moveWindy(int len) {
    for (int i = 0; i < len; ++i) {
        windy.x += dx[windy.dir];
        windy.y += dy[windy.dir];
        sprinkSand();
        show();
    }
}

 
int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
 
    // 위치 방향
    windy = {N / 2, N / 2, 0};
    int len = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= 2; ++j) {
            // 현재 바라보고 있는 방향으로 len만큼 이동
            
            moveWindy(len);
    
            // 방향 전환
            windy.dir = (windy.dir + 1) % 4;
        }
        
        len++;
    }
    
    // 마지막 이동 (제일 상단에 위치한 행)
    moveWindy(len - 1);
    printf("%d\n", ans);
}