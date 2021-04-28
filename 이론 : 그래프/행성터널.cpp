#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , ans = 0; // ans = cost
int parent[100001];
struct Planet{
    int x,y,z,num ;
    void make(int x , int y , int z ,int num){
        this -> x = x;
        this -> y = y;
        this -> z = z;
        this -> num = num;
    }
};
vector <Planet> planets;
vector<pair<int , pair<int, int> > > edge;
bool cmp_x( Planet a , Planet b){return a.x < b.x;}
bool cmp_y( Planet a , Planet b){return a.y < b.y;}
bool cmp_z( Planet a , Planet b){return a.z < b.z;}
int find_parent(int a){
    if(parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}
void unionParent(int a ,int b){
    if(a < b) parent[a] = b;
    else parent[b] = a;
}
void init(){
    int w; // 간선 설치 비용
    sort(planets.begin() , planets.end() , cmp_x);
    for(int i = 1 ; i < planets.size() ; i ++){
        w = abs(planets[i-1].x - planets[i].x);
        edge.push_back({ w ,{ planets[i-1].num , planets[i].num}});
    }

    sort(planets.begin() , planets.end() , cmp_y);
    for(int i = 1 ; i < planets.size() ; i ++){
        w = abs(planets[i-1].y - planets[i].y);
        edge.push_back({ w ,{ planets[i-1].num , planets[i].num}});
    }

    sort(planets.begin() , planets.end() , cmp_z);
    for(int i = 1 ; i < planets.size() ; i ++){
        w = abs(planets[i-1].z - planets[i].z);
        edge.push_back({ w ,{ planets[i-1].num , planets[i].num}});
    }
    sort(edge.begin() , edge.end() );
}
void sol(){
    int w,a,b;
    for(int i = 0 ; i< edge.size(); i++ ){
        w = edge[i].first;
        a = find_parent(edge[i].second.first);
        b = find_parent(edge[i].second.second);
        if(a != b){
            ans += w;
            unionParent(a,b);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int x ,y, z;
    for(int i = 0; i< N; i++){
        Planet p ;
        cin >> x >> y >> z;
        p.make(x,y,z ,i+1);
        planets.push_back(p);
        parent[i+1] = i+1;
    }
    init();
    sol();
    cout << ans ;
    return 0 ;
}