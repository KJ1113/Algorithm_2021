#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map [126][126];
int vnumber [126][126];
int d[20000];
int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
int N , num , INF = 999999;
int tc = 1;
vector <pair<int,int> > graph[20000];
struct compare{
    bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second>b.second;
	}
};
void init(){
    num = 1;
    for(int i = 0; i < N*N+1 ; i++){
        graph[i].clear();
    }
}
void sol(int start){ // 다익스트라
    priority_queue<pair<int, int>, vector<pair<int,int> > ,compare > pq;
    pq.push({start,map[0][0]});
    d[start] = map[0][0];

    while (!pq.empty()){
        int nowV = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if (dist < d[nowV]) continue; // 이미 방문했으면 패스
        for(int i  =0 ; i < graph[nowV].size() ;i++){
            int nextV = graph[nowV][i].first;
            int cost = dist + graph[nowV][i].second;

            if(cost < d[nextV]){
                pq.push({ nextV, cost});
                d[nextV] = cost;
            }
        }
    }
}
void make_graph(){
    int idx  = 1 ;
        for(int i  =0 ; i < N ;i++){
            for (int j = 0 ; j < N;j++){
                int curY = i ;
                int curX = j ;
                for(int k = 0 ; k < 4;k++){
                    int nextY = curY + dir[k][0];
                    int nextX = curX + dir[k][1];
                    if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N ) continue;
                    graph[idx].push_back( { vnumber[nextY][nextX] , map[nextY][nextX]});
                }
                idx++;
            }
        }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        init();
        cin >> N;
        if(N == 0) break;
        for(int i  =0 ; i < N ;i++){
            for (int j = 0 ; j < N;j++){
                cin >> map[i][j];
                vnumber[i][j] = num;
                num++;
            }
        }
        fill_n(d, N*N+1 , INF);
        make_graph();
        sol(1);
        cout <<"Problem "<< tc<<": "<<d[N*N] <<endl;
        tc++;
    }
    return 0;
}