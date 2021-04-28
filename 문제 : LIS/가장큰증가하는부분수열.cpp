#include <iostream>
#include <algorithm>
using namespace std;
int DP[1001];
int N , ans = -1;
int main(){
    cin >> N;
    for(int i = 0 ; i < N ;i++){
        cin >> DP[i];
    }
    for(int curIdx =1 ; curIdx < N; curIdx++){
        int curTmp = DP[curIdx];
        for(int checkIdx = 0; checkIdx < curIdx; checkIdx++){
            if(DP[checkIdx] < DP[curIdx]){
                DP[curIdx] = max( DP[checkIdx]+curTmp, DP[curIdx]);
            }
        }
    }
    for(int curIdx =0 ; curIdx < N; curIdx++){
        ans = max(ans,DP[curIdx]);
    }
    cout<<ans;
    return 0;
}