#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int dp[102][100002];
int item[102][2];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K ;
    for(int i =1 ;i <= N; i++){
        cin >> item[i][0] >>item[i][1];
    }
    for(int i =1 ; i <= N; i++){
        int w = item[i][0];
        int v = item[i][1];
        for(int j =0; j<= K;j++){ // j는 검사하는 가방의 무게를 뜻함.
            if(j < w ){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
            }
        }
    }
    cout << dp[N][K];
    return 0;
}