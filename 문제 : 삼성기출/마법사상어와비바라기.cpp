#include <iostream>
#include<vector>
using namespace std;
int map[51][51];
int N , M;
int d , s , ans = 0;
int dir[8][2] = { {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1} };
vector<pair<int,int> > Clist; //구름 위치  
bool Cvist[51][51];
void move (){
    vector<pair<int,int> > tmp_Clist; 
    for(int idx = 0 ; idx < Clist.size() ; idx++){
        int curY = Clist[idx].first;
        int curX = Clist[idx].second;
        for(int S  =0 ; S < s ; S++){
            curY += dir[d-1][0];
            curX += dir[d-1][1];
            if(curY == -1  || curY == N){
                if(curY == -1) curY = N-1;
                else if(curY == N) curY = 0;
            }
            if(curX == -1 || curX == N){
                if(curX == -1) curX = N-1;
                else if(curX == N) curX = 0;
            }
        }
        tmp_Clist.push_back({curY,curX});
    }
    Clist.clear();
    Clist = tmp_Clist;
}
void check(){
    vector<int> wCnt_list;
    for(int idx = 0 ; idx <  Clist.size() ;idx ++){
        map[Clist[idx].first][Clist[idx].second] ++;
    }

    for(int idx = 0 ; idx <  Clist.size() ;idx ++){
        int arr[4] ={1,3,5,7};
        int wCnt = 0;
        for(int i =0; i < 4;i++){
            int nextY = Clist[idx].first + dir[arr[i]][0];
            int nextX = Clist[idx].second + dir[arr[i]][1];
            if(nextY < 0 || nextY >= N || nextX <0 || nextX >= N) continue;
            if(map[nextY][nextX] > 0) wCnt++;
        }
        wCnt_list.push_back(wCnt);
        Cvist[Clist[idx].first][Clist[idx].second] =true;
    }

    for(int idx = 0 ; idx <  Clist.size() ;idx ++){
        map[Clist[idx].first][Clist[idx].second] +=wCnt_list[idx];
    }
}

int make_ans(){
    for(int i = 0 ; i < N; i ++){
        for(int j = 0 ; j < N ;j++){
            ans += map[i][j];
        }
    }
    return ans;
}
void makeCloud(){
    ans = 0;
    vector<pair<int,int> > tmp_Clist; 
    for(int i = 0 ; i < N; i ++){
        for(int j = 0 ; j < N ;j++){
            if(Cvist[i][j] == true){
                Cvist[i][j] =false;
            }else{
                if(map[i][j] >= 2){
                    map[i][j] -= 2;
                    tmp_Clist.push_back({i,j});
                }
            }
        }
    }
    Clist.clear();
    Clist = tmp_Clist;
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j <N ;j++){
            cin >> map[i][j];
        }
    }
    Clist.push_back({ N-1 ,0});
    Clist.push_back({ N-1 ,1});
    Clist.push_back({ N-2 ,0});
    Clist.push_back({ N-2 ,1});
    for(int tc = 0 ; tc < M ; tc++){
        cin >> d >> s;
        move();
        check();
        makeCloud();
    }
    cout << make_ans() <<endl;
}