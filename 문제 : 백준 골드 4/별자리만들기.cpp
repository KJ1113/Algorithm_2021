#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N , E ;
int parents[101];
double ans ;
vector < pair < double , pair <int,int> > > graph;
vector < pair < double, double > > slist;

void init(){
    for(int v =1 ; v <= N ; v++){
        parents[v] = v;
    }
    
    for(int i = 0 ; i < slist.size() ;i++){
        double cY = slist[i].first;
        double cX = slist[i].second;
        for(int j = i+ 1 ; j < slist.size(); j++){
            if( i == j ) continue;
            
            double nY = slist[j].first;
            double nX = slist[j].second;
            double length = sqrt( pow( cY- nY , 2) + pow( cX- nX , 2) ); 
            graph.push_back( { length , { i+1 , j+1 }});
        }
    }
    
}
int findP(int a){
    if(parents[a] == a) return a;
    return parents[a] = findP(parents[a]);
}
void unionV(int a , int b){
    if( a < b) parents[b] = a;
    else parents[a] = b;
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        double a , b;
        cin >> a >> b;
        slist.push_back( { a ,b });
    }
    init();
    sort(graph.begin(), graph.end());

    for(int i = 0 ; i < graph.size() ; i++){
        int aP = findP ( graph[i].second.first);
        int bP = findP ( graph[i].second.second);
        double l = graph[i].first;
        if(aP != bP){
            unionV(aP, bP);
            ans += l;
        }
    }
    cout << ans ;
    return 0;
}