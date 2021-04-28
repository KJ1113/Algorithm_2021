#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue <int> pq;
vector < pair<int ,int > > list;
vector <long long> bag;
int N , K , idx = 0;
long long  ans = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for(int i = 0 ; i < N ;i++){
        int a , b;
        cin >> a >> b;
        list.push_back( {a, b} );
    }
    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        bag.push_back(a);
    }
    sort(bag.begin(), bag.end());
    sort(list.begin(), list.end());
    
    for(int i  = 0 ; i < bag.size() ;i++){
        while (idx < N){ // 조건을 만족하는 보석들을 pq 에 넣는다.
                         // 가방의 무게가 오름차순으로 정렬 되어있어서 미리 pq에 넣어도 상관없다. 
                         // (다음 가방은 무조건 조건을 만족하기 때문.)
            int curW = list[idx].first;
            int curM = list[idx].second;
            
            if(curW <= bag[i] ){
                pq.push(curM);
                idx++;
            }else{
                break;
            }
        }
        if(!pq.empty()){ //조건을 만족하는 pq 에서 하나 더해준다.
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans ;
    return 0;
}