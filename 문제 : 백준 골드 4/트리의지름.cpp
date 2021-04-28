#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , ans = 0;
struct Node{
    int cost = 0;
    vector<int> leaf_list;
};
Node arr [10001];
int DFS(int Num){
    if(arr[Num].leaf_list.size() == 0 ) return arr[Num].cost;

    if(arr[Num].leaf_list.size() == 1){ // 자식이 하나밖에 없을때
        int leaf_cost = DFS(arr[Num].leaf_list[0]);
        ans = max(ans , leaf_cost);
        return leaf_cost + arr[Num].cost;
    }else{
        vector<int> sum_list;
        int last_idx = arr[Num].leaf_list.size()-1;
        for(int i = 0 ; i < arr[Num].leaf_list.size() ; i++){
            int leaf_cost = DFS(arr[Num].leaf_list[i]);
            sum_list.push_back(leaf_cost);
        }

        sort(sum_list.begin() , sum_list.end());
        ans = max(ans , sum_list[last_idx] + sum_list[last_idx-1]);
        return sum_list[last_idx] + arr[Num].cost;
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i =0 ;i < N-1 ;i++){
        int a , b, c;
        cin >> a >> b >> c;
        arr[a].leaf_list.push_back(b);
        arr[b].cost = c;
    }
    DFS(1);
    cout << ans <<endl;
    return 0;
}
