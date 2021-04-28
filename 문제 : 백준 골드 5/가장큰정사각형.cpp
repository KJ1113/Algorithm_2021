#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N , M;
int dp[1001][1001];
int ans = 0; // 배열 원소가 모두 0 일수 있음

int main(){
    cin >> N >> M;
    for(int i =1 ;i <= N ;i ++){
        for(int j = 1 ; j <= M; j++){
            char x;
            cin >> x;
            if(x == '0'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1;
            }
        }
    }

    for(int i =1 ;i <= N ;i ++){
        for(int j =1 ; j<=M ;j++){
            if(dp[i][j] == 1){
                if( dp[i-1][j-1] > 0 && dp[i-1][j] >0 && dp[i][j-1] > 0){
                    dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] ,dp[i][j-1] )) +1;
                }
                ans = max (ans , dp[i][j] * dp[i][j]);
            }
        }
    }
    cout << ans ;
    return 0;
}