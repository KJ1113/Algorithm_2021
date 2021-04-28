#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N , M ;
int indgree[32001];
vector <int> graph[32001];
void sol(){
    vector <int> res;
    priority_queue <int , vector <int> , greater < int >  > q;
    for(int n = 1 ; n <= N ; n++){
        if(indgree[n] == 0 ) {
            q.push(n);
        }
    }
    while (!q.empty()){
        int curNum = q.top();
        q.pop();
        res.push_back(curNum);

        for(int i = 0; i < graph[curNum].size() ;i++){
            int child = graph[curNum][i];
            indgree[child]--;

            if(indgree[child] == 0){
                q.push(child);
            }
        }
    }
    for(int i = 0 ;i < res.size() ;i++){
        cout << res[i] <<" ";
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i  =0 ; i < M ; i++){
        int a , b;
        cin >> a >> b;
        graph[a].push_back(b);
        indgree[b]++;
    }
    sol();
    return 0;
}