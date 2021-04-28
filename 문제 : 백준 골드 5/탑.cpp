#include <iostream>

using namespace std;
int dp[500001];
int list[500001];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N ;
    cin >> N;
    for(int i =1 ; i<= N ;i++){
        cin >> list[i];
    }
    cout << dp[1]<<" ";
    for(int idx = 2 ; idx <= N ;idx++){
        int nextIdx = idx -1;
        while (true){
            if(list[idx] < list[nextIdx]){
                cout << nextIdx<<" ";
                dp[idx] = nextIdx;
                break;
            }
            else{
                nextIdx = dp[nextIdx];
            }

            if(nextIdx == 0){
                cout << 0 << " ";
                dp[idx] = 0;
                break;
            }
        }
    }
    return 0;
}