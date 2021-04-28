#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N , M , X;
int ans = -1;
int dp[1001][1001];
void init(){
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ; j ++){
            dp[i][j] = INF;
            if(i == j ) dp[i][j] = 0;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> X;
    init();
    for(int i = 0 ; i < M ;i++){
        int a , b, c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }
    for(int k = 1 ; k <= N ;k++){
        for(int i = 1 ; i <= N ;i++){
            for(int j = 1 ; j <= N ; j ++){
                dp[i][j] = min (dp[i][j] , dp[i][k] + dp[k][j]);
            }
        }
    }
    for(int i = 1 ; i <= N ;i++){
        ans = max(ans , dp[i][X] + dp[X][i]);
    }
    cout << ans ;
    return 0;
}