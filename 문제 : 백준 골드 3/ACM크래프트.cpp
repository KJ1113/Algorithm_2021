#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int TC , N , K ,W;
int indegree[100001]; // 진입차수
int make_time[100001]; //단일 만드는시간
int sum[100001]; // 총합 만드는시간
vector< int > graph[100001];
void topologySort(  ){
    queue< pair<int,int > > q;
    for(int i =1 ; i <= N ;i++){
        if(indegree[i] == 0 ){
            q.push( {i , make_time[i] });
            sum[i] = make_time[i];
        }
    }

    while (!q.empty()){
        int curPos = q.front().first;
        int cost = q.front().second;
        q.pop();
        if(curPos == W ) break; // W 에 도착하면 스톱

        for(int i = 0 ; i < graph[curPos].size() ; i++){
            int nextPos = graph[curPos][i];
            int nextCost =  make_time[nextPos] + cost;

            sum[nextPos] = max( sum[nextPos], nextCost);
            indegree[nextPos]--;

            if(indegree[nextPos] == 0){
                q.push({nextPos ,sum[nextPos]});
            }
        }
    }
    cout<< sum[W] << "\n";
}
void init(){
    for(int i = 0 ; i <= 100001 ;i++){
        make_time[i] =0;
        indegree[i] = 0;
        sum[i] = 0;
        graph[i].clear();
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
    for(int tc = 0 ; tc < TC ; tc++){
        cin >> N >> K;
        int a ,b;
        for(int idx = 1; idx <= N; idx++){
            cin >> a;
            make_time[idx] = a;
        }
        for(int k = 0; k < K; k++){
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }
        cin >> W;
        
        topologySort();
        init();
    }
}