#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N , M;
int map[101][101];
int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1}};
bool vist[101][101];
vector< pair <int,int> > del_list;
vector< pair <int,int> > tmp_del_list;
void BFS(int Y , int X){
    queue<pair<int, int> > q;
    q.push({Y,X});
    vist[Y][X] =true;
    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
            if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= M || vist[nextY][nextX]) continue;
            if(map[nextY][nextX] == 0){
                q.push({ nextY, nextX });
                vist[nextY][nextX] = true;
            }else if (map[nextY][nextX] == 1){
                tmp_del_list.push_back( {nextY,nextX });
            }
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i =0; i < N ;i++){
        for(int j = 0; j < M ; j++){
            cin >> map[i][j];
        }
    }
    int time = 0 , cnt = 0;
    del_list.push_back({0,0});
    while (true){    
        for(int i = 0 ; i < del_list.size(); i ++){ //녹는 치즈 찾기
            int iY = del_list[i].first;
            int iX = del_list[i].second;
            if(vist[iY][iX]==false) BFS(iY,iX);
        }
        if(tmp_del_list.size() == 0) break; // 더이상 삭제할 치즈가 없을떄

        cnt=0;   
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (map[i][j] == 1) cnt++;
            }
        }
        for(int i = 0 ; i < tmp_del_list.size(); i ++ ){ // 치즈 녹이기
            int iY = tmp_del_list[i].first;
            int iX = tmp_del_list[i].second;
            map[iY][iX] = 0;
        }
        del_list = tmp_del_list;
        tmp_del_list.clear();
        time++;
    }
    cout << time<< " " << cnt <<"\n";
    return 0;
}