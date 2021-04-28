#include <iostream>
#include <queue>
using namespace std;
const int INF = 987654321;
int dist[100001];
int N , K;
void BFS(){ // 다익스트라
    priority_queue <pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push({N , 0});
    dist[N] = 0;

    while (!pq.empty()){
        int curPos = pq.top().first;
        int curTime = pq.top().second;
        pq.pop();
        if(dist[curPos] < curTime) continue;
        for(int k = 0; k < 3; k++){
            int nextPos;
            int nextTime;
            if(k ==0 ){
                nextPos = curPos +1;
                nextTime = curTime +1;
            }else if(k == 1){
                nextPos = curPos -1;
                nextTime = curTime +1;
            }else{
                nextPos = 2 * curPos;
                nextTime = curTime;
            }
            if(nextPos < 0 || nextPos > 100000) continue;
            if(nextTime < dist[nextPos]){
                dist[nextPos] = nextTime;
                pq.push({nextPos ,nextTime });
            }
        }
    }
}
int main(){
    cin >> N >> K;
    for(int i =0 ; i< 100001 ; i++ ){
        dist[i] = INF;
    }
    BFS();
    cout << dist[K];
    return 0;
}