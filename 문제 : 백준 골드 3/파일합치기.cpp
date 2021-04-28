#include <iostream>
#include <queue>
using namespace std;
int TC , N; 
int dp[501][501];
int cost[501];
int sum[501];
int main(){
    cin >> TC;
    for(int tc = 0 ; tc < TC ; tc++){
        cin >> N ;
        for(int i = 1 ; i<= N ;i++){
            cin >> cost[i];
        }

        for(int i = 1; i <= N ;i++){
            if(i == 1){
                sum[i] = cost[i];
            }else{
                sum[i] = sum[i-1] + cost[i]; 
            }
        }

        for(int k = 1; k <  N ; k++){
            for(int start = 1 ; start + k <= N ;start++){

                int end = start + k;

				dp[start][end] = 987654321;

                for(int mid = start  ; mid <end ; mid++ ){

                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start-1]);
                }
            }
        }
        cout << dp[1][N] << endl;
    }
    return 0;
}