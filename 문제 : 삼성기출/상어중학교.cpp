#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N , M ,ans = 0;
int map[21][21];
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}};
bool vist[21][21];
void zero_init(){
    for(int i = 0 ; i < N ;i ++){
        for(int j = 0 ; j< N  ;j++){
            if(map[i][j] == 0 )vist[i][j] = false;
        }
    }
}
void map_init(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ;j++){
            vist[i][j] = false;
        }
    }
}
struct Node{
    vector<pair<int,int> > v; 
    int rcnt = 0;
};
Node findGroup(int Y , int X ,  int curC ){
    int rcnt = 0 ;
    queue< pair<int,int> > q;
    vector <pair<int,int> > v;
    q.push({Y,X});
    v.push_back({Y,X});
    vist[Y][X] = true;

    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int k = 0 ; k < 4; k++){
            int nY = curY + dir[k][0];
            int nX = curX + dir[k][1];
            if(nY < 0 || nY >= N || nX < 0 || nX >= N ) continue;
            if( map[nY][nX] == -2 || map[nY][nX] == -1 || vist[nY][nX] ) continue;
            if(map[nY][nX] == 0 || map[nY][nX] == curC){
                vist[nY][nX] = true;
                if(map[nY][nX] == 0 ) rcnt++;
                v.push_back({ nY , nX });
                q.push({nY,nX});
            }
        }
    }

    Node n;
    n.v = v;
    n.rcnt = rcnt;
    return n;
}
void gravity(){
    for (int i = N - 2; i >= 0; i--){
        for (int j = 0; j < N; j++){
            if (map[i][j] <= -1){
                continue;
            }
            int y = i;
            while (true){
                if (y == N){
                    break;
                }
                int cur = map[y][j];
                int next = map[y + 1][j];
                if (next != -2){
                    break;
                }
                map[y + 1][j] = cur;
                map[y][j] = -2;
                y++;
            }
        }
    }
}
void mat_turn(){
    int tempBoard[22][22];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            tempBoard[i][j] = map[i][j];
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            map[N - (j + 1)][i] = tempBoard[i][j];
        }
    }
}
void del(vector<pair<int,int> > &tv){
    for(int idx = 0 ; idx < tv.size() ;idx++){
        int cy = tv[idx].first;
        int cx = tv[idx].second;
        map[cy][cx] = -2;
    }
}
int main(){
    cin >> N >> M;
    for(int i  = 0 ; i < N ;i++){
        for(int j =0; j < N ;j++){
            cin >> map[i][j];
        }
    }
    
    while (true){
        map_init();
        int cY = -10;
        int cX = -10;
        int csize = -10;
        int crcnt = -10;
        vector<pair<int,int> > dv;
        for(int i = 0 ; i < N ;i ++){
            for(int j = 0 ; j< N  ;j++){
                zero_init(); // 0 초기화
                if( map[i][j] == 0|| map[i][j] == -2 || map[i][j] == -1 || vist[i][j] ) continue;
                Node tv = findGroup(i,j,map[i][j]);
                vist[i][j] = true;
                int tmpsize = tv.v.size();
                int tmprcnt = tv.rcnt ;

                if(tmpsize >= 2 ){
                    if(csize < tmpsize ){
                        cY = tv.v[0].first;
                        cX = tv.v[0].second;
                        csize = tmpsize;
                        crcnt = tmprcnt;
                        dv = tv.v;
                    }else if(csize == tmpsize){
                        if(crcnt < tmprcnt ){
                            cY = tv.v[0].first;
                            cX = tv.v[0].second;
                            csize = tmpsize;
                            crcnt = tmprcnt;
                            dv = tv.v;
                        }else if(crcnt == tmprcnt){
                            if(cY < tv.v[0].first ){
                                cY = tv.v[0].first;
                                cX = tv.v[0].second;
                                csize = tmpsize;
                                crcnt = tmprcnt;
                                dv = tv.v;
                            }else if(cY == tv.v[0].first ){
                                if(cY == tv.v[0].first && cX < tv.v[0].second ){
                                    cY = tv.v[0].first;
                                    cX = tv.v[0].second;
                                    csize = tmpsize;
                                    crcnt = tmprcnt;
                                    dv = tv.v;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(csize == -10) break;
        ans += (csize * csize);
        del(dv);
        gravity();
        mat_turn();
        gravity();
    }
    cout << ans ;
    return 0;
}