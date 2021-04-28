#include <iostream>
#include <queue>
using namespace std;
int V ,E; // 정점의 갯수V, 간선의 갯수 E;
int start , INF = 999999;
int d [20001];
vector<pair<int,int> >graph[20001];
struct compare{
    bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second>b.second;
	}
};

void sol(int s ){
    priority_queue<pair<int, int>, vector<pair<int,int> > ,compare > pq;
    pq.push({s,0});
    d[s] = 0;
    while (!pq.empty()){
        int nowV = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        if(d[nowV] < dist) continue; // 현재보다 더 짧은 거리가있다면 패스

        for(int i = 0; i < graph[nowV].size() ; i++){ // 현재 위치와 연결된 간선들 검사
            int nextV = graph[nowV][i].first;
            int cost = dist + graph[nowV][i].second;
            if(cost < d[nextV]){
                pq.push({nextV,cost});
                d[nextV] = cost;
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E >> start ;
    for(int i = 0 ; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    fill_n(d, V+1, INF);
    sol(start);
    for(int i = 1; i <= V; i++){
        if(d[i] == INF){
            cout << "INF" <<endl;
        }
        else{
            cout << d[i]<<endl;
        }
    }
    return 0;
}