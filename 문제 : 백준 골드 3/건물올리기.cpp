#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N , K;
int input_cnt[501]; // 진입차수
int time_table[501]; // 단일 만드는 시간
int total_table[501]; // 총합 
vector <int> grahp[501];

void topologySort(){
    queue <pair <int,int> > q;
    for(int i = 1; i <= N; i++){
        if(input_cnt[i] == 0 ){
            q.push( { i , time_table[i] });
            total_table[i] += time_table[i];
        }
    }

    while (!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();

        for(int i = 0 ; i < grahp[now].size() ;i ++){
            int nextPos = grahp[now][i];
            int next_cost =  time_table[nextPos] + cost;
            input_cnt[nextPos]--;
            total_table[nextPos] = max( total_table[nextPos], next_cost );

            if(input_cnt[nextPos] == 0){
                q.push({ nextPos , total_table[nextPos]});
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << total_table[i] <<" ";
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N ;i ++){
        cin >> time_table[i];
        while (true){
            int idx;
            cin >> idx;
            if(idx == -1) break;
            grahp[idx].push_back(i);
            input_cnt[i] ++;
        }
    }
    topologySort();
    return 0;
}