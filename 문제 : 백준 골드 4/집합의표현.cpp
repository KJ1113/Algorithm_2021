#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V , E ;
int parent[1000001];
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
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin  >> V >> E;
    init();
    for(int i = 0 ;i < E; i++){
        int v1, v2, c;
        cin >>c>>v1>>v2;
        int v1P = findParent(v1);
        int v2P = findParent(v2);

        if(c == 0){ // 합집합
            unionParent(v1P , v2P);
        }else{
            if(v1P == v2P){
                cout<< "YES\n";
            }
            else{
                cout<< "NO\n";
            }
        }
    }
    return 0;
}