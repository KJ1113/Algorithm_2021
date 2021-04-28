#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    vector < pair < int , int > > childs;
};
Node node [100001];
bool vist [100001];
int N , ans = 0;
int DFS(int V){
    vist[V] = true;
    vector <int> sum_list;
    for(int i = 0 ; i < node[V].childs.size() ;i++){
        int next = node[V].childs[i].first;
        int ncost = node[V].childs[i].second;
        if(vist[next]) continue;
        sum_list.push_back ( DFS(next) + ncost);
    }

    int lastIdx = 0 ;
    if(sum_list.size() == 0 ) return 0;

    if(sum_list.size() == 1){
        ans = max(ans , sum_list[lastIdx]);
        return sum_list[lastIdx];
    }else{

        sort(sum_list.begin() , sum_list.end());
        lastIdx = sum_list.size()-1;
        ans = max(ans , sum_list[lastIdx] + sum_list[lastIdx-1]);
        return sum_list[lastIdx] ;
    }
}
int main(){
    cin >> N;
    for(int i = 1 ; i <= N ;i++){
        int num;
        cin >> num;
        while (true){
            int a , c;
            cin >> a;
            if(a == -1) break;
            cin >> c;
            node[num].childs.push_back( { a , c } );
        }
    }
    for(int i = 1; i <= N ;i++){
        if(vist[i] == false) {
            DFS(i);
        }
    }
    cout << ans ;
}