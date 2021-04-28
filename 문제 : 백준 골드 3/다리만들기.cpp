#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int ans = INF;
int N , islandCnt = 0;
int map[101][101];
int dir[4][2] ={ {1,0}, {0,1}, {0,-1}, {-1,0}};
bool vist[101][101][10001];
vector< pair <int,int> > island [10001];
void islandBFS( int num){
    queue <  pair <int ,int >  > q;
    for(int k = 0; k < island[num].size() ;k++){
        int nowY = island[num][k].first;
        int nowX = island[num][k].second;
        q.push({nowY, nowX} );
    }
    int time =0;
    while (!q.empty()){
        int qisze = q.size();
        time ++ ;
        for (int x = 0; x < qisze; x++){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++){
                int nextY = curY + dir[k][0];
                int nextX = curX + dir[k][1];
                int nextTime = time;
                if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N) continue;

                if (map[nextY][nextX] == 0 && vist[nextY][nextX][num] == false){
                    vist[nextY][nextX][num] = true;
                    q.push({ nextY, nextX});
                }

                if (map[nextY][nextX] != num && map[nextY][nextX] != 0){ // 다른섬 발견
                    ans = min(ans, time-1);
                }
            }
        }
    }
}

void BFS(int y , int x , int num){
    queue <pair <int ,int > > q;
    q.push( { y, x } );
    map[y][x] = num;
    vist[y][x][0] = true;
    island[num].push_back( { y,x });

    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int k = 0 ; k < 4 ;k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
            if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N || vist[nextY][nextX][0]) continue;
            if( map[nextY][nextX] != 0){
                map[nextY][nextX] = num;
                vist[nextY][nextX][0] = true;
                q.push( {nextY, nextX} );
                island[num].push_back( { nextY , nextX } );
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N ;
    for(int i  =0 ; i < N ;i++){
        for(int j =0 ; j < N ;j++){
            cin >> map[i][j];
        }
    }
    for(int i  =0 ; i < N ;i++){
        for(int j =0 ; j < N ;j++){
            if( vist[i][j][0] == false && map[i][j] == 1 ){
                islandCnt++;
                BFS(i,j,islandCnt);
            }
        }
    }
    for(int i = 1 ; i <= islandCnt ;i ++){
        islandBFS(i);
    }
    
    cout << ans ;
    return 0;
}