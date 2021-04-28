#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V , E ;
int ans = 0;
int parent[10001];
vector <pair<int , pair <int,int> > > edges;
int findParent(int v){
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v]);
}
void unionParent(int v1_parent , int v2_parent ){
    if(v1_parent < v2_parent){
        parent[v2_parent] = v1_parent;
    }
    else{
        parent[v1_parent] = v2_parent;
    }
}
void init(){
    for(int v =1 ; v <= V ; v++){
        parent[v] = v;
    }
    sort(edges.begin() , edges.end());
}

int main(){
    cin  >> V >> E;
    for(int i = 0 ;i < E; i++){
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        edges.push_back({c,{v1,v2}});
    }
    init();
    for(int i = 0 ; i < edges.size() ; i ++){
        int v1_p = findParent(edges[i].second.first);
        int v2_p = findParent(edges[i].second.second);
        int cost = edges[i].first;
        if(v1_p == v2_p ) continue; // 사이클 발생
        unionParent(v1_p , v2_p);
        ans += cost;
    }
    cout << ans;
    return 0;
}