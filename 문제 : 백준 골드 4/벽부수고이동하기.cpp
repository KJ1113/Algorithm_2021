#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
char map[1001][1001];
int dist[1001][1001][2];
int dir[4][2]= { {1,0}, {-1,0}, {0,-1}, {0,1}};
int N, M;

struct Node{
    int y,x , time = 1;
    bool push = false;
};
void BFS(){
    queue <Node> q;
    Node n;
    n.y = 0;
    n.x = 0;
    q.push(n);
    dist[0][0][0] = 1;
    while (!q.empty()){
        int curY = q.front().y;
        int curX = q.front().x;
        int curTime = q.front().time;
        bool curPush = q.front().push;
        q.pop();
        for (int k = 0; k < 4; k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
            int nextTime = curTime +1;

            Node n;
            n.y = nextY;
            n.x = nextX;
            n.time = nextTime;
            n.push = curPush;
            if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)continue;
            if(curPush){ // 이미 한번 부순상태이면
                if(dist[nextY][nextX][1] > nextTime && map[nextY][nextX] == '0'){ // 오직 0 일때만 갈수있다
                    n.push = curPush;
                    q.push(n);
                    dist[nextY][nextX][1] = nextTime;
                }
            }
            else{ // 안뿌셨다면
                if(map[nextY][nextX] == '0' && dist[nextY][nextX][0] > nextTime){
                    n.push = curPush;
                    q.push(n);
                    dist[nextY][nextX][0] = nextTime;
                }else if (map[nextY][nextX] == '1' && dist[nextY][nextX][1] > nextTime){
                    n.push = true;
                    q.push(n);
                    dist[nextY][nextX][1] = nextTime;
                }
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ;i < N ; i++){
        cin >> map[i];
        for(int j = 0; j < M ;j++){ // dist INF 로 초기화
            dist[i][j][0] = INF;
            dist[i][j][1] = INF;
        }
    }
    BFS();
    if(dist[N-1][M-1][0] == INF && dist[N-1][M-1][1] == INF){
        cout << -1;
    }
    else{
        cout << min(dist[N-1][M-1][0],dist[N-1][M-1][1]);
    }
    return 0;
}