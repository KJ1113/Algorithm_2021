#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 16;
int ans = - 1;
int first_map[4][4];
int dir[9][2] = { {0,0},{-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1} };

struct tmp_map_set{
    int sum = 0;
    int map[4][4];
    vector < pair<int,int> > fish_list;
};
void DFS(int sY , int sX , int sdir , tmp_map_set tm){

    // 1. 물고기 순서대로 정렬
    // 2. 갈수있는 방향 찾기.
    // 3. 갈수있다면 교환, 갈수없다면 제자리.

    sort(tm.fish_list.begin() , tm.fish_list.end());
    for(int index = 0 ; index < tm.fish_list.size() ; index++){
        
        int num = tm.fish_list[index].first;
        int k = tm.fish_list[index].second; // k 는 방향을 결정하는 상수
        int first_dir = k;
        int cY , cX;

        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4; j++){
                if(tm.map[i][j] == tm.fish_list[index].first) {
                    cY = i;
                    cX = j;
                } 
            }
        }
        while (true){
            int nY = cY + dir[k][0];
            int nX = cX + dir[k][1];
            
            if(nY < 0 || nX < 0 || nY >= 4 || nX >= 4|| (nY == sY && nX == sX)) {
                k++;
                if(k == 9) k = 1;
                if(first_dir == k) break;
            }else{
                int tmp = tm.map[nY][nX];
                tm.map[nY][nX] = num;
                tm.map[cY][cX] = tmp;
                tm.fish_list[index].second = k;
                break;
            }
        }
    }

    int c_sY = sY;
    int c_sX = sX;
    while (true){
        int nY = c_sY + dir[sdir][0];
        int nX = c_sX + dir[sdir][1];
        if(nY < 0 || nX < 0 || nY >= 4 || nX >= 4) break; // 상어가 범위를 벗어나면 

        if(tm.map[nY][nX] !=0) { // 상어가 갈수있는 경우
            int next_dir =0;
            tmp_map_set tms = tm; // tm 복사
            tms.sum += tm.map[nY][nX];

            // fish_list 초기화
            tms.fish_list.clear();
            for(int index = 0 ; index < tm.fish_list.size() ; index++){
                if(tm.fish_list[index].first == tm.map[nY][nX]){
                    next_dir = tm.fish_list[index].second;
                }else{
                    tms.fish_list.push_back(tm.fish_list[index]);
                }
            }

            tms.map[nY][nX] = 0;
            DFS(nY ,nX , next_dir,tms);
        }
        c_sY = nY;
        c_sX = nX;
    }
    ans = max(ans , tm.sum);
}
int main(){
    int first_dir = 0;
    tmp_map_set tm;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4; j++){
            int a , b;
            cin >> a >> b;
            
            if(i == 0 && j==0 ){
                tm.sum = a;
                tm.map[i][j] = 0;
                first_dir = b;
            }else{
                tm.map[i][j] = a;
                tm.fish_list.push_back({a,b});
            }
        }
    }
    DFS(0,0,first_dir,tm);
    cout << ans <<endl;
}