
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF  = 87654321;
int N, M, a , b , ans ;
int abc =0, bac=0;

vector<pair<int, int> > graph[801];
int cost_table[801];
void init(){
    for(int i = 1; i <= N ;i++){
        cost_table[i] = INF;
    }
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int,int> > ,greater< pair<int,int> > > pq;
    pq.push({start, 0});
    cost_table[start] = 0;
    while (!pq.empty()) {
        int now = pq.top().first; // 현재 노드
        int dist = pq.top().second; // 현재 노드까지 비용
        pq.pop();

        if (cost_table[now] < dist) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            int nextV =  graph[now][i].first;
            if (cost < cost_table[nextV]) {
                cost_table[nextV] = cost;
                pq.push({nextV,cost});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0 ; i < M ;i++){
        int v1 ,v2 ,cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back( { v2, cost } );
        graph[v2].push_back( { v1, cost } );
    }

    cin >> a >> b;
    init();
    dijkstra(1);
    abc += cost_table[a];
    bac += cost_table[b];

    //init();
    dijkstra(a);
    abc += cost_table[b];
    bac += cost_table[N];

    //init();
    dijkstra(b);
    abc += cost_table[N];
    bac += cost_table[a];

    ans = min(abc,bac);

    if(ans >= INF){
        cout << -1;
    }
    else{
        cout << ans;
    }  
    return 0;
}