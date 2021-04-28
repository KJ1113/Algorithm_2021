#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9  
using namespace std;
int N , M , start;

vector <pair <int,int> > graph[100001];
int cost_table[100001]; //최단거리 테이블
struct cmp{
    bool operator()(pair<int, int>a, pair<int, int>b){
        return a.second > b.second;
    }
};
void dijkstra(int start ){
    priority_queue<pair<int, int>, vector<pair<int,int> > ,greater< pair<int,int> > > pq;
    
    pq.push( { start,0 } );
    cost_table[start] =0;

    while (!pq.empty()){
        int now = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
       
        // 현재노드가 이미 처리된적있다면 무시
        if(cost_table[now] < dist) continue;

        for(int idx = 0 ; idx < graph[now].size() ; idx++){
            int cost = dist + graph[now][idx].second;
            int nextV = graph[now][idx].first;
        
            if(cost < cost_table[nextV] ){
                cost_table[nextV] = cost;
                pq.push({ nextV,cost });
            }
        }
    }
}
int main(){
    cin >> N >> M >> start; // 노드의수 , 간선의 수 , 시작위치
    
    for(int i  =0 ; i < M ;i ++ ){
        int v1 , v2 , cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back( {v2, cost} );
    }
    
    fill_n(cost_table, 100001 ,INF);
   
    dijkstra(start);

    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= N; i++) {
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (cost_table[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << cost_table[i] << '\n';
        }
    }
    return 0;
}