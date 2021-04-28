
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
using namespace std;
int n, m, start;
vector<pair<int, int> > graph[100001];
int cost_table[100001];
/*
struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second> b.second;
	}
};
*/
void dijkstra(int start) {
    //priority_queue<pair<int, int>, vector<pair<int,int> > ,compare > pq;
    priority_queue<pair<int, int>, vector<pair<int,int> > ,greater< pair<int,int> > > pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push({start, 0});
    cost_table[start] = 0;
    while (!pq.empty()) {
        int now = pq.top().first; // 현재 노드
        int dist = pq.top().second; // 현재 노드까지 비용
        pq.pop();
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (cost_table[now] < dist) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            int nextV =  graph[now][i].first;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < cost_table[nextV]) {
                cost_table[nextV] = cost;
                pq.push({nextV,cost});
            }
        }
    }
}
int main(void) {
    cin >> n >> m >> start;
    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int v1 , v2 , cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back( {v2, cost} );
    }

    fill_n(cost_table, 100001, INF);
    
    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (cost_table[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        else {
            cout << cost_table[i] << '\n';
        }
    }
}
