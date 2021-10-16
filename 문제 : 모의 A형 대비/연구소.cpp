#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N , M , ans =0;
int map[9][9];
int dir[4][2] = { {1,0} , {0,1} , {0,-1} , {-1,0}};

vector<pair<int,int> > v_list;
void DFS(int wall_cnt){
    if(wall_cnt == 3){
        queue <pair<int,int> > q;
        for(int i = 0 ; i < v_list.size(); i++){
            q.push( { v_list[i].first , v_list[i].second });
        }

        int res = 0;
        int tmp_map[9][9];
        bool vist[9][9];
        
        for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < M;j++){
                vist[i][j] = false;
                tmp_map[i][j] = map[i][j];
            }
        }

        while (!q.empty()){
            int cY = q.front().first;
            int cX = q.front().second;
            q.pop();

            for(int k = 0 ; k < 4 ;k++){
                int nY = cY + dir[k][0];
                int nX = cX + dir[k][1];
                if(nY < 0 || nX < 0 || nY >= N|| nX >= M || vist[nY][nX]) continue;
                if(tmp_map[nY][nX] == 0){
                    vist[nY][nX] = true;
                    tmp_map[nY][nX] = 2;
                    q.push({nY,nX});
                }
            }
        }

        for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < M;j++){
                if(tmp_map[i][j] == 0) res++ ;
            }
        }

        ans = max (ans , res);

    }else{
        for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < M;j++){
                if(map[i][j] == 0){
                    map[i][j] = 1;
                    DFS(wall_cnt +1);
                    map[i][j] = 0;
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M;j++){
            cin >> map[i][j];
            if(map[i][j] == 2) v_list.push_back({i,j});
        }
    }
    DFS(0);
    cout << ans ;

    return 0;
}