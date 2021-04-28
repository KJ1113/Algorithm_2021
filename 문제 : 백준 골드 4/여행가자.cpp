#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N , M;
bool vist[201];
vector<int> graph[201];
vector<int> t_list;
void BFS(int idx){
    queue <int > q;
    q.push(idx);
    vist[idx] = true;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0 ; i < graph[now].size() ; i++ ){
            int next = graph[now][i];
            if(vist[next] == false){
                vist[next] = true;
                q.push(next);
            }
        }
    }  
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int idx = 1; idx <= N ;idx++){
        for(int j = 1 ; j <= N ; j++){
            int input;
            cin >> input; 
            if(input ==1) {
                graph[idx].push_back(j);
                graph[j].push_back(idx);
            }
        }
    }
    for(int i = 0 ; i < M ;i++){
        int x;
        cin >> x;
        t_list.push_back(x);
    }
    BFS(t_list[0]);
    for(int i = 0 ; i < t_list.size() ; i++){
        if(vist[t_list[i]] == false ){
            cout << "NO" <<endl;
            return 0;
        }
    }
    cout << "YES" <<endl;
    return 0;
}