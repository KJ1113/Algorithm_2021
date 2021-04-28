#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int dp[1001][2];
int num[1001];
int ans = -1;
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> num[i+1];
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j < i ; j++){
            if(num[j] < num[i] ){
                dp[i][0] = max(dp[i][0] , dp[j][0] + 1 );
            }
        }
    }
    for(int i = N ; i >= 1 ; i--){
        for(int j = N; j > i ; j--){
            if(num[j] < num[i] ){
                dp[i][1] = max(dp[i][1] , dp[j][1] + 1 );
            }
        }
    }

    for(int i = 1 ; i <= N ; i++){
        ans = max(dp[i][0]+ dp[i][1] + 1, ans );
    }
    cout << ans;
    return 0;
}
