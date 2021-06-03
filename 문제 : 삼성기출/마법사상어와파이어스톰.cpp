#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
int N , Q ;
int maxNum ;
int iceSum =0 , iceSize = 0 ;
int map[130][130];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}};
bool vist[130][130];
vector <int> L_list;
vector <pair <int, int > > del_list;
void BFS(int y , int x){
    queue<pair <int, int > > q;
    q.push({y,x});
    vist[y][x] = true;
    int curSize = 0;

    while (!q.empty()){  
        int curY = q.front().first;
        int curX = q.front().second;
        curSize++;
        q.pop();
        for(int k = 0 ; k< 4 ; k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
            if(nextY < 0 || nextX < 0 || nextY >= maxNum|| nextX >= maxNum) continue;
            if(map[nextY][nextX] > 0 ){
                if(vist[nextY][nextX] == false){
                    q.push({nextY , nextX });
                    vist[nextY][nextX] = true;
                }
            }
        }
    }
    iceSize = max (iceSize , curSize);
}

void DFS(int y , int  x , int curNum , int target){
    if(curNum == target){
        int tmpMap[130][130];
        int mY = target + y;
        int mX = target + x;
        queue <int> q;
        for(int j = x ;j < mX ;j++){
            for(int i = mY-1  ; i >= y ;i--){
                q.push({map[i][j]});
            }
        }
        for(int i = y ; i < mY ;i++){
            for(int j = x ;j < mX ;j++){
                map[i][j] = q.front();
                q.pop();
            }
        }
       return;
    }
    int nextPos = curNum/2;
    DFS(y, x, nextPos ,target);
    DFS(y, x + nextPos,  nextPos ,target);
    DFS(y + nextPos, x,  nextPos ,target);
    DFS(y + nextPos, x + nextPos ,nextPos, target);
}
void del(){
    del_list.clear();
    for (int i = 0; i < maxNum; i++){
            for (int j = 0; j < maxNum; j++){
                if(map[i][j] == 0) continue;
                int ice_cnt = 0;
                for (int k = 0; k < 4; k++){
                    int nextY = i + dir[k][0];
                    int nextX = j + dir[k][1];
                    if (nextY < 0 || nextX < 0 || nextY >= maxNum || nextX >= maxNum) continue;
                    if (map[nextY][nextX] > 0){
                        ice_cnt++;
                }
            }
            if (ice_cnt < 3) del_list.push_back({i, j});
        }
    }
    for(int idx = 0 ; idx < del_list.size() ; idx++ ){
        map[del_list[idx].first][del_list[idx].second] --;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    maxNum = pow(2,N);
    for(int i = 0 ; i < maxNum ;i ++){
        for(int j = 0 ; j < maxNum ; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0 ; i < Q ;i++){
        int a;
        cin >> a;
        L_list.push_back(pow(2,a));
    }
    for(int idx = 0 ; idx < L_list.size() ;idx ++){
        DFS(0, 0, maxNum, L_list[idx]);
        del();
    }
    for(int i = 0 ; i < maxNum ;i ++){
        for(int j = 0 ; j < maxNum ; j++){
            if (vist[i][j] == false && map[i][j] != 0){
                BFS(i,j);
            }
            iceSum += map[i][j];
        }
    }
    cout << iceSum << "\n" << iceSize;
    return 0 ;
}