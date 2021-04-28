#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int sY , sX;
int N , M , year = 0;
int dir[4][2] = { {1,0} , {-1,0} , {0,1} , {0,-1}};
int map[301][301];
int tmpMap[301][301];
bool vist[301][301];

vector< pair < int, int > > ice_list;
int BFS(int y , int x){ // 체크 용
    queue< pair < int, int > > q;
    q.push( { y , x });
    vist[y][x] = true;
    int cnt = 0;
    while (!q.empty()){
        cnt++;
        int cY = q.front().first;
        int cX = q.front().second;
        q.pop();
        for(int k = 0 ; k < 4 ; k++){
            int nY = cY + dir[k][0];
            int nX = cX + dir[k][1];
            if(vist[nY][nX] == false && map[nY][nX] != 0 ){
                q.push({nY, nX});
                vist[nY][nX] = true;
            }
        }
    }
    return cnt;
}
void sol(){
    while (!ice_list.empty()){
        if(BFS(ice_list[0].first , ice_list[0].second) != ice_list.size()){
            cout << year;
            return;
        }
        year++;
        for(int i = 0 ;i < ice_list.size() ; i++){
            int cY = ice_list[i].first;
            int cX = ice_list[i].second;
            int mPoint = 0; // 주변의 0 갯수
            for(int k = 0 ; k < 4 ; k++){
                int nY = cY + dir[k][0];
                int nX = cX + dir[k][1];
                if(map[nY][nX] == 0 ){
                    mPoint++;
                    continue;
                }
            }
            if(mPoint > 0 ){ //삭제 가능
                tmpMap[cY][cX] = map[cY][cX] - mPoint;
                if(tmpMap[cY][cX] < 0) tmpMap[cY][cX] = 0;
            }
        }

        vector< pair < int, int > > tmp_ice_list;
        for(int i = 0 ;i < ice_list.size() ; i++){
            int cY = ice_list[i].first;
            int cX = ice_list[i].second;
            map[cY][cX] = tmpMap[cY][cX];
            vist[cY][cX] = false;
            if( map[cY][cX] != 0) tmp_ice_list.push_back({cY ,cX});
        }
        ice_list = tmp_ice_list;
    }
    cout << 0;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i< N ; i++){
        for(int j =0 ; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j] != 0){
                ice_list.push_back({i,j});
                tmpMap[i][j] = map[i][j];
            }
        }
    }
    sol();
    return 0;
}