#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V , E , maxw =0;
int ans = 0;
int parent[100001];
vector < pair< int , pair<int,int > > >  edges;
int find_parent(int x){
    if(parent[x] == x) return x;
    return find_parent(parent[x]);
}
void unionParent(int a , int b){
    /*
    int A = find_parent(a);
    int B = find_parent(b);

    if(A < B){
        parent[A] = B;
    }else{
        parent[B] = A;
    }
    */
    if(a < b){
        parent[a] = b;
    }else{
        parent[b] = a;
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
   
    for(int  i =0 ; i < E; i++){
        int v1, v2 , w ;
        cin >> v1 >> v2 >>  w ;
        edges.push_back( { w, { v1,v2 } } );
    }
    for(int i = 1; i <= V ; i++){
        parent[i] = i;
    }
    sort( edges.begin(), edges.end() );
    for(int i = 0 ; i < E ;i++){
        int w = edges[i].first;
        int a = find_parent(edges[i].second.first);
        int b = find_parent(edges[i].second.second);
        if(a != b){
            unionParent(a,b);
            ans += w;
            maxw = max(maxw,w);
        }
    }
    cout << ans - maxw ;
    return 0;
}