#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int map[21][21];
int people_cost[21][21];
int dist[21][21];
int dir[4][2]= { {1,0} , {0,1} , {-1,0}, {0,-1}};
int N , M , L;
struct People{
    int pY , pX , dY ,dX;
};
struct Taxi{
    int Y , X , L;
};
vector < People > peoples;
Taxi taxi;
bool gotaxi(int y , int x , int pcost){
    int distY ,distX , dIdx;
    for(int i = 0 ; i < N ;i ++){ //초기화
        for(int j = 0 ; j < N ;j++){
            dist[i][j] = INF;
        }
    }
    for(int i = 0 ; i < peoples.size() ;i++){
        if(peoples[i].pY == y && peoples[i].pX == x){
            distY = peoples[i].dY;
            distX = peoples[i].dX;
            dIdx = i;
            break;
        }
    }
    int time = 1;
    queue <pair <int , int > > q;
    q.push({ y , x});
    dist[y][x] = 0;
    if(y == distY && x == distX){ // 승객의 목적지가 현재 위치 일 경우
        int totalCost = taxi.L - pcost - 0 ;
        if ( totalCost < 0  ){
                return false;
        }else{
            map[y][x] = 0;
            taxi.Y = distY;
            taxi.X = distX;
            taxi.L  = (totalCost) + (0 * 2);
            peoples.erase(peoples.begin()+dIdx);
            return true;
        }
    };

    while (!q.empty()){
        int qsize = q.size();
        for(int i = 0 ; i < qsize ;i++){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            for(int  k= 0 ; k < 4;k++){
                int nextY = curY + dir[k][0];
                int nextX = curX + dir[k][1];
                if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N || map[nextY][nextX] == 1) continue;
                if( (map[nextY][nextX] == 0 || map[nextY][nextX] == 2) && dist[nextY][nextX] > time){
                    dist[nextY][nextX] = time;
                    q.push({ nextY , nextX });
                    if(nextY == distY && nextX == distX){
                        int totalCost = taxi.L - pcost - time ;
                        if ( totalCost < 0  ){
                            return false;
                        }else{
                            map[y][x] = 0;
                            taxi.Y = distY;
                            taxi.X = distX;
                            taxi.L  = (totalCost) + (time * 2);
                            peoples.erase(peoples.begin()+dIdx);
                            return true;
                        }
                    };
                }
            }
        }
        time++;
    }
    return false;
}
bool find_people(int y , int x){
    for(int i = 0 ; i < N ;i ++){
        for(int j = 0 ; j < N ;j++){
            people_cost[i][j] = INF;
        }
    }
    queue <pair <int , int > > q;
    vector <pair < int , pair <int,int> > > p_list;
    q.push({ y , x});
    people_cost[y][x] = 0;
    if(map[y][x] == 2){ // 승객이 현재 택시 위치에 있을경우
        p_list.push_back( { 0, {y , x } });
        if(p_list.size() == 0 || taxi.L - p_list[0].first < 0 ){
            return false;
        }
        else{
            return gotaxi(p_list[0].second.first , p_list[0].second.second , p_list[0].first);
        }
    } 

    int time = 1;
    while (!q.empty()){
        int qsize = q.size();
        for(int i = 0 ; i < qsize ;i++){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            for(int  k= 0 ; k < 4;k++){
                int nextY = curY + dir[k][0];
                int nextX = curX + dir[k][1];
                if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N || map[nextY][nextX] == 1) continue;
                if( (map[nextY][nextX] == 0 || map[nextY][nextX] == 2) && people_cost[nextY][nextX] > time){
                    people_cost[nextY ][nextX] = time;
                    q.push({ nextY , nextX });
                    if(map[nextY][nextX] == 2) p_list.push_back( { time, {nextY , nextX } });
                }
            }
        }
        time++;
    }
    sort( p_list.begin() , p_list.end() );
    if(p_list.size() == 0 || taxi.L - p_list[0].first < 0 ){
        return false;
    }
    else{
        return gotaxi(p_list[0].second.first , p_list[0].second.second , p_list[0].first);
    }
}
void input_data(){
    cin >> N >> M >> taxi.L;
    for(int i = 0 ; i < N ;i ++){
        for(int j = 0 ; j < N ;j++){
            cin >> map[i][j];
        }
    }
    cin >> taxi.Y >> taxi.X;
    taxi.Y--;
    taxi.X--;
    for(int i = 0 ; i < M ;i++){
        People p;
        cin >> p.pY >> p.pX >> p.dY >>p.dX;
        p.pY--;
        p.pX--;
        p.dY--;
        p.dX--;
        peoples.push_back(p);
        map[p.pY][p.pX] = 2;
    }
}
void sol(){
    bool flag = true;
    while (true){
        if( peoples.size() == 0) break;
        if ( find_people(taxi.Y , taxi.X) == false ) {
            flag = false;
            break;
        }
    }
    if(flag){
        cout <<taxi.L;
    }else{
        cout << -1 ;
    }
}
int main(){
    input_data();
    sol();
    return 0;
}
