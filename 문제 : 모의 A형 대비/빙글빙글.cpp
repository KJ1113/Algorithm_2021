#include <iostream>

using namespace std;
int map[51][51];
int dir[4][2] = {{0,-1},{ 1,0},{0,1},{-1,0}};
int main(){

    int N; // N 은 홀수
    cin >> N;

    // 1. 안에서 밖으로
    // MAX_CNT 가 두번 반복 되면 방향을 바꾼다.
    int number = N*N;
    
    int cnt = 0;
    int max_cnt = 1;
    int max_cnt_cnt = 0;
    int y = N/2;
    int x = N/2;
    int k = 0;

    map[y][x] = number;
    number--;

    while(true){
        int ny = y + dir[k][0];
        int nx = x + dir[k][1];
        
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) break;
        cout << ny << " " << nx <<endl;
        map[ny][nx] = number;

        cnt++;
        number--;
        y = ny;
        x = nx;

        if(cnt == max_cnt){
            cnt = 0;
            max_cnt_cnt++;
            
            k ++;
            if(k == 4) k = 0;
            if(max_cnt_cnt == 2){
                max_cnt++;
                max_cnt_cnt = 0;
            }
        }
    }

    for(int i =0 ; i < N ;i ++){
        for(int j = 0 ; j < N ;j++){
            cout << map[i][j] <<" ";
        }
        cout <<endl;
    }



    return 0;
}
