#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;
int n,m,start;
int d[100001];
bool vist[100001];
vector <pair<int,int>> graph[100001];
int getSmallestNode(){
    int minIndex  =0;
    int tmp =INF;
    for(int i =1 ; i <= n; i++){
        if(tmp > d[i] && !vist[i]){
            tmp = d[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void dijkstra(int start){
    d[start] =0;
    vist[start] =true;

    for(int i =0; i < graph[start].size();i++){
        d[graph[start][i].first] = graph[start][i].second;
    }

    for(int i =0; i < n-1 ;i++){
        int now = getSmallestNode();
        vist[now]=true;

        for(int j =0; j < graph[now].size() ;j++){
            int cost = d[now] + graph[now][j].second;
            if (cost < d[graph[now][j].first]) {
                d[graph[now][j].first] = cost;
            }
        }
    }
}
int main(){
    cin >> n >> m >> start ;
    for(int i =0; i< m ;i++ ){
        int a ,b , c;
        cin >> a >> b >>c;
        graph[a].push_back({b,c});
    }
    fill_n(d, 100001,INF);

    dijkstra(start);
    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= n; i++) {
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << d[i] << '\n';
        }
    }
}