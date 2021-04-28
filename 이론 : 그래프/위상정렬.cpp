#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V ,E;
int indegree[100001];
vector<int> graph[100001];

void topologySort(){
    vector<int> result; // 알고리즘 수행 결과를 담을 리스트
    queue<int> q; // 큐 라이브러리 사용

    for(int i = 1 ;i <= V ; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int now = q.front();
        q.pop();
        result.push_back(now);

        for(int i = 0 ; i < graph[now].size(); i++){
            int pri = graph[now][i]; // 현재 노드에 진입하는 노드들
            indegree[pri] --;
            if(indegree[pri] == 0 ){
                q.push(pri);
            }
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }

}
int main(){
    cin >> V >> E;
    for(int i = 0; i< E;i++){
        int v1 ,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        indegree[v2]+=1;
    }
    topologySort();
    return 0;
}