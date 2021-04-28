#include <iostream>
#include <algorithm>
using namespace std;
int N , M;
int ans = 1000001;
int dp[101][10001];
int c[101] , m[101];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        cin >> m[i+1];
    }
    for(int i = 0 ; i < N ;i++){
        cin >> c[i+1];
    }
    // ( 가치 ) dp[i][j] = max(dp[i-1][j] , 가치[i] + dp[i-1][j - 무게[i]]  );
    // ( 메모리 ) dp[i][j] = max(dp[][] , 메모리 + dp[i-1][j - 비용[i]] );
    
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= 10000 ;j++){ // 100 * 100 (N * c 최대값)
            if(c[i] <= j){
                dp[i][j] = max( dp[i-1][j] , m[i] + dp[i-1][j-c[i]]); 
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

            if( M <= dp[i][j]){ // 메모리가 처음으로 M 을 넘어 설때
                ans = min(ans ,j);
            }
        }
    }
    cout << ans;
    return 0;
}