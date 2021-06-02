#include <iostream>
#include <vector>
using namespace std;
int N , K;
int belt [101][2]; // 벨트 내구도
bool Rvist[101][2];
vector<pair <int,int> > robot; 
void belt_Move(){

    // 벨트이동
    int tmp_belt[101][2];
    for(int i = 1 ; i < N ; i++){
        tmp_belt[i][0] = belt[i-1][0];
    }
    for(int i = 0; i < N-1 ;i++){
        tmp_belt[i][1] = belt[i+1][1];
    }
    tmp_belt[0][0] = belt[0][1];
    tmp_belt[N-1][1] = belt[N-1][0];
    for(int i = 0 ; i < N ;i++){
        belt[i][0] = tmp_belt[i][0];
        belt[i][1] = tmp_belt[i][1];
    }

    // 로봇도 이동
    vector<pair <int,int> > tmp_robot; 
    for(int i = 0 ; i < N ; i++){
        Rvist[i][0] = false;
        Rvist[i][1] = false;
    }
    for(int idx = 0 ; idx < robot.size() ;idx++){
        int nextY = robot[idx].first;
        int nextX = robot[idx].second;
        if(nextY == 0){
            if( 0 <= nextX && nextX <= N-2){
                nextX++;
            }else if(nextX == N-1 ){
                nextY = 1;
            }
        }else{
            if( 1 <= nextX && nextX <= N-1){
                nextX--;
            }else if(nextX == 0 ){
                nextY = 0;
            }
        }
        robot[idx].first = nextY;
        robot[idx].second = nextX;
        if( ! (nextX == N-1 && nextY == 0) ){ // N 위치 로봇은 없어짐
            tmp_robot.push_back({nextY,nextX});
            Rvist[nextX][nextY] = true; // 현재 로봇위치저장
        }
    }
    robot = tmp_robot;
}

void robot_Move(){ // 로봇만 이동
    vector<pair <int,int> > tmp_robot; 
    for(int idx = 0 ; idx < robot.size() ;idx++){
        int curY = robot[idx].first;
        int curX = robot[idx].second;

        if(curY == 0){
            if( 0 <= curX && curX <= N-2){
                curX++;
            }else if(curX == N-1 ){
                curY = 1;
            }
        }else{
            if( 1 <= curX && curX <= N-1){
                curX--;
            }else if(curX == 0 ){
                curY = 0;
            }
        }
        
        if(belt[curX][curY] > 0 && Rvist[curX][curY] == false){// 움직일수있는 경우
            belt[curX][curY] --;
            Rvist[curX][curY] = true;
            Rvist[robot[idx].second][robot[idx].first] = false;

            if(!(curX == N-1 && curY == 0)){
                tmp_robot.push_back({curY,curX});
            }
        }else{
            Rvist[robot[idx].second][robot[idx].first] = true;
            tmp_robot.push_back({robot[idx].first,robot[idx].second});
        }
    }
    robot = tmp_robot;

    if(belt[0][0] > 0 && Rvist[0][0] == false){
        robot.push_back({0,0});
        belt[0][0] --;
    }
}
bool check(){
    int cnt =0;
    for(int i = 0 ; i < N ;i++){
        if( belt[i][0] == 0) cnt ++ ;
    }
    for(int i = 0; i < N ; i++){
        if( belt[i][1] == 0) cnt ++ ;
    }
    if(cnt >= K ){
        return true;
    }
    return false;
}
int main(){
    cin >> N >> K;
    for(int i = 0 ; i < N ;i++){
        cin >> belt[i][0];
    }
    for(int i = N-1 ; i >= 0 ;i--){
        cin >> belt[i][1];
    }
    int ans = 1;
    while (true){
        belt_Move();
        robot_Move();
        if(check()) break;
        ans++;
    }
    cout << ans;
    return 0;
}