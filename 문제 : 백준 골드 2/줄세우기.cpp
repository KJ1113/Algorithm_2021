#include <iostream>
#include <vector>
#include <queue>
using namespace  std;
int V , E , N , M;
int indegree[32001];
vector <int> graph[32001];
void sol(){
    vector <int> res;
    queue<int> q;
    for(int i = 1 ; i<= N ; i++){
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()){
        int curNum = q.front();
        q.pop();

        for(int i = 0 ; i < graph[curNum].size() ; i++){
            int child = graph[curNum][i];
            indegree[child]--;

            if(indegree[child] == 0 ){
                q.push(child);
            }
        }
        res.push_back(curNum);
    }

    for(int i = 0 ;i < res.size() ;i++){
        cout << res[i]<<" ";
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int m = 0 ; m < M ; m++){
        int a , b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    sol();
    return 0;
}
