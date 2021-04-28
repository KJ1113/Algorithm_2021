#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> arr[501];
int dp[501][501];
int N ,ans = -1; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i =  0; i < N;i++){
        for(int j = 0 ; j < i+1 ; j++){
            int num;
            cin >> num;
            arr[i].push_back(num);
        }
    }
    dp[0][0] = arr[0][0];
    for(int i =  1; i < N;i++){
        for(int j = 0 ; j <= i ; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][0] + arr[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1] + arr[i][j] ,dp[i-1][j] + arr[i][j]);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans <<endl;
    return 0;
}