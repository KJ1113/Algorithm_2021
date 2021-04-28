#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int TC;
int V , E;
int vist[20001];
vector <int> graph[20001];

void init(int V){
    for(int i =1 ;i <= V;i++){
        graph[i].clear();
        vist[i] = 0;
    }
}
bool BFS(int v){
    queue <int> q;
    vist[v] = 1;
    q.push(v);

    while (!q.empty()){
        int curV = q.front();
        int curC = vist[curV];
        q.pop();

        for(int idx = 0 ; idx < graph[curV].size(); idx++){
            int nv = graph[curV][idx];
            if(vist[nv] == vist[curV]) return false; //이분 그래프가 아님 
            if(vist[nv] != 0 && vist[nv] != curC ) continue; // 이미 방문

            if(curC == 1) vist[nv] = -1; // 인접한다면 다른 집합으로 분리
            else vist[nv] = 1;
            q.push(nv);
        }
    }
    return true;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> TC;

    for(int tc = 0; tc < TC ; tc++){
        cin >> V >> E;
        bool flag = true;
        for(int i = 0; i < E; i ++){
            int v1 , v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2); // 양방향 그래프로 만들어야함
            graph[v2].push_back(v1);
        }

        for(int v=1; v<=V; v++){
            if(vist[v] == 0){
                if (BFS(v) == false){ //이분그래프가 아닐경우 NO 출력
                    cout<< "NO\n";
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout<<"YES\n";
        init(V);
    }
    return 0;
}