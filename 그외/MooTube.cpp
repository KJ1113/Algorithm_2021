
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;
int N, Q;
vector<pair<int, int> > graph[5001];
int d[5001];
struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second>b.second;
	}
};
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int,int>> ,compare > pq;
    pq.push({start, 0});
    d[start] = 0;
    while (!pq.empty()) { // 큐가 비어있지 않다면
        int now = pq.top().first; // 현재 노드
        int dist = pq.top().second; // 현재 노드까지 비용
        pq.pop();
        if (d[now] < dist) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int cost;
            if (dist == 0){
                cost = graph[now][i].second ; 
            }
            else{
                cost = min( dist, graph[now][i].second);
            }
            if (cost < d[graph[now][i].first] && d[graph[now][i].first] == INF ) {
                d[graph[now][i].first] = cost;
                pq.push({graph[now][i].first,cost});
            }
        }
    }
}
int main(void) {
    cin >> N >> Q ;
    // 모든 간선 정보를 입력받기
    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for(int i =0 ; i < Q ; i++){
        int k , start ,cnt =0;
        cin >> k >> start;
        fill_n(d, N+1, INF);
        dijkstra(start);
        for(int idx = 1 ; idx <= N ; idx++ ){
            if(d[idx] >= k ) cnt++; 
        }
        cout<< cnt <<endl;
    }
}
