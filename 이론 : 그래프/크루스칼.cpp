#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V ,E ; // 노드의 갯수 , 간선의 갯수 
int parent[100001]; // 사이클 검사를 위한 부모노드 
int ans=0;
vector < pair < int , pair <int ,int> > > edge;

void init(){
    for(int i = 1 ;i <= V ;i++){ // 모든 노드들의 부모를 자기 자신으로 설정한다.
        parent[i] = i;
    }
    sort(edge.begin() ,edge.end()); // 간선들의 비용을 오름차순 정렬한다.
}
int findParent(int v){ // 재귀를 통하여 부모 탐색
    if(v == parent[v]) return v;
    return  parent[v] = findParent(parent[v]);

}
void unionParent(int v1 , int v2){
    int v1_p = findParent(v1);
    int v2_p = findParent(v2);

    if(v1_p < v2_p){
        parent[v2_p] = v1_p;
    }
    else{
        parent[v1_p] = v2_p;
    }
}
int main(){
    cin >> V >> E; // 노드의 
    for(int i =0 ; i < E ; i++){
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        edge.push_back({cost,{v1 ,v2} });  
    }
    init();

    for(int i = 0 ; i < edge.size() ; i++){
        int v1, v2, cost;
        cost = edge[i].first;
        v1 = edge[i].second.first;
        v2 = edge[i].second.second;

        if (findParent(v1) != findParent(v2)) {
            unionParent(v1, v2);
            ans += cost;
        }
    }
    cout << ans ; // 최소비용 출력
    return 0;
}