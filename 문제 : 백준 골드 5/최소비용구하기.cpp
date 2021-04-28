#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int N , M ,s ,e;
int map[1001][1001];
vector<pair<int,int> > graph[1001];
int cost_table[1001];
struct cmp{
    bool operator()(pair<int, int>a, pair<int, int>b){
        return a.second > b.second;
    }
};
void djistra(int start){
    for(int i = 1 ;i <= N ;i++){
        cost_table[i] = INF;
    }
    priority_queue<pair<int,int> >pq;
    pq.push({start,0});

    while (!pq.empty()){
        int now = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if( cost_table[now] < dist ) continue; //이미 처리된 경우
        for(int i = 0 ; i< graph[now].size(); i++){
            int v = graph[now][i].first;
            int cost = graph[now][i].second + dist;

            if(cost < cost_table[v] ){
                cost_table[v] = cost;
                pq.push({ v , cost});
            }
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < M ;i++){
        int a , b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    cin >> s >> e;
    djistra(s);
    cout << cost_table[e];
}
