#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
int N, M ,ans = 0;
set <pair<int,int>> s;
int dir [4][2] = {{0,0},{0,1},{-1,0},{-1,1}};
void masking(int y ,int x ,vector<string> &board ){
    char block = board[y][x];
    if (block == 'o') return  ;
    for(int d = 0; d<4 ;d++){
        int nextY = y +dir[d][0];
        int nextX = x +dir[d][1];
        if(nextY < 0 || nextX < 0 || nextY >=N || nextX >= M ) return ;
        if(block != board[nextY][nextX]) return ;   
    }
    for(int d = 0; d<4 ;d++){
        int nextY = y +dir[d][0];
        int nextX = x +dir[d][1];
        s.insert({nextY,nextX});
    }
    return ;
}
void down(vector<string> &board){
    for(int y = N-1 ; y >=1  ; y--){
        for(int x = 0 ; x < M ;x++){
            if(board[y][x] == 'o'){
                int curY = y;
                int curX = x;
                for(int nextY = curY-1; nextY >=0 ;nextY-- ){
                    if(board[nextY][curX] != 'o'){
                        char tmp = ' ';
                        tmp = board[curY][curX];
                        board[curY][curX] = board[nextY][curX];
                        board[nextY][curX] = tmp;
                        break;
                    }
                }
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    N = m;
    M = n;
    while(true){
        s.clear();
        for(int i =0 ;i < N ;i++){
            for(int j=0; j< M ;j++){
                masking(i,j,board);
            }
        }
        set<pair<int,int>>::iterator iter;
        for(iter = s.begin() ; iter!= s.end() ;iter++){
            int dely = iter->first;
            int delx = iter->second;
            board[dely][delx] = 'o';
        }
        down(board);
        ans += s.size();
        if (s.size() == 0) break;
    }
    return ans;
}